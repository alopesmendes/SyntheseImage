#include "../include/Scene.h"
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <random>
#include <sstream>


std::default_random_engine engine;
std::uniform_real_distribution<double> uniform(0, 1);

Scene::Scene(int level, string file, string imName, int ps) {
    this->level = level;
    this->file = file;
    this->imageName = imName;
    this->ps = ps;
}

Scene::~Scene() {

}

void Scene::addCamera(const Camera &cam) {
    camera = cam;
}

void Scene::addShape(const StandardFigure &standardFigure, Shape* shape) {
    shapes[standardFigure].push_back(shape);
}

void Scene::addLight(const Light &l) {
    light = l;
}

void Scene::addImage(const Image &im) {
    image = im;
}

bool Scene::intersect(const Ray& ray, Hit& hit) {
    bool hasItersect = false;
    hit.t = INFINITY;
    for (auto categorie = shapes.begin(); categorie != shapes.end(); ++categorie) {
        for (auto shape = categorie->second.begin(); shape != categorie->second.end(); ++shape) {
            Hit localHit;
            bool localItersect = (**shape).intersect(ray, localHit);
            if (localItersect) {
                hasItersect = true;
                if (localHit.t < hit.t) {
                    hit = localHit;
                }
            }
        }
    }
    return hasItersect;
}

Color Scene::getColor(const Ray &ray, int nbonds) {
    if (nbonds == 0) {
        return image.backgroundColor();
    }
    Hit hit, hitLight;
    Color c;
    bool hasIter = intersect(ray, hit);
    
    if (hasIter) {
        if ( hit.shape->getMaterial().isMirror() ) {
            Vector dMirror = ray.getDirection() - hit.normal * 2 * hit.normal.scalarProduct(ray.getDirection());
            Ray rMirror = Ray(hit.pos + hit.normal*0.001, dMirror);
            c = getColor(rMirror, nbonds - 1);
        } else {
            if ( hit.shape->getMaterial().isTransparent() ) {
                double n1 = 1, n2 = 1.3;
                Vector nt = hit.normal;
                if (hit.normal.scalarProduct(ray.getDirection()) > 0) {
                    swap(n1, n2);
                    nt = hit.normal * (-1);
                }
                double radical = 1 - pow(n1 / n2, 2)*(1 - pow(nt.scalarProduct(ray.getDirection()), 2));
                if (radical > 0) {
                    Vector dirRef = (ray.getDirection() - nt * nt.scalarProduct(ray.getDirection())) * (n1/n2) - nt * sqrt(radical);
                    Ray rayRef = Ray(hit.pos - nt*0.001, dirRef);
                    c = getColor(rayRef, nbonds - 1);
                }
            } else {
                // contribution eclairage direct
                Vector v = light.getPos() - hit.pos;
                double d_light2 = v.scalarProduct(v);
                Ray rayLight = Ray(hit.pos + hit.normal*0.01, v.getNormalized());
                bool hasIterLight = intersect(rayLight, hitLight);
                if (hasIterLight && (hitLight.t*hitLight.t <= d_light2)) {
                    c = image.backgroundColor();
                } else {
                    //c = hit.shape->getColor() / M_PI * light.getIntensity() * max(0., v.getNormalized().scalarProduct(hit.normal)) / d_light2;
                    c = hit.shape->getColor() * light.getIntensity();
                } 

                // ajout contribution indirect
                if (level == 3) {
                    double r1 = uniform(engine), r2 = uniform(engine);
                    double x = cos(2 * M_PI * r1) * sqrt(1 - r2);
                    double y = sin(2 * M_PI * r1) * sqrt(1 - r2);
                    double z = sqrt(r2);
                    Vector dRandomLocal = Vector(x, y, z);
                    Vector ran = Vector(uniform(engine)-0.5, uniform(engine)-0.5, uniform(engine)-0.5);
                    Vector tangent1 = hit.normal.cross(ran); tangent1.normalize();
                    Vector tangent2 = tangent1.cross(hit.normal);
                    
                    Vector dRandom = hit.normal*z + tangent1*x + tangent2*y;
                    Ray rayRandom = Ray(hit.pos + hit.normal*0.001, dRandom);
                    c += hit.shape->getColor() * getColor(rayRandom, nbonds - 1);
                }
            }
        }
    }
    return c;
}

void Scene::generateScene() {
    double fov = 60. * M_PI / 180.;

    #pragma cmp parallel for
	for(int i = 0; i < image.getHeight(); ++i) {
		for(int j = 0; j < image.getWidth(); ++j) {
            Vector dir = Vector(
                j - image.getWidth() / 2.,
                i - image.getHeight() / 2.,
                -image.getWidth() / (2. * tan(fov / 2.))
            );
            dir.normalize();
            Ray ray = Ray(camera.getPos(), dir);
            Color c;
            int nrays = level == 3 ? ps : 1;
            for (int k = 0; k < nrays; ++k) {
                c += getColor(ray, 5) / nrays;
            }
            image.setPixel(i, j, c);
		}
	}
}

void Scene::buildImage() {
    Image::save(image, imageName);
}

Scene::operator std::string() const {
    stringstream ss;
    ss << image << endl;
    ss << camera << endl;
    ss << light << endl;
    ss << "Shapes {" << endl;
    for (auto i = shapes.begin(); i != shapes.end(); ++i) {
        for (auto j = i->second.begin(); j != i->second.end(); ++j) {
            ss << '\t' << (**j) << endl;
        }   
    }
    ss << "}";
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Scene& scene) {
    string text = scene;
    os << text;
    return os;
}