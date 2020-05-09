#include "../include/Scene.h"
#include <cmath>

#define W 1024
#define H 1024

Scene::Scene() : image(Image(W, H)) {
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
                Vector v = light.getPos() - hit.pos;
                double d_light2 = v.scalarProduct(v);
                Ray rayLight = Ray(hit.pos + hit.normal*0.01, v.getNormalized());
                bool hasIterLight = intersect(rayLight, hitLight);
                if (hasIterLight && (hitLight.t*hitLight.t <= d_light2)) {
                    c =image.backgroundColor();
                } else {
                    c = light.colorIntensity(hit, d_light2);
                }
            }
        }
    }
    return c;
}

void Scene::update() {
    double fov = 60. * M_PI / 180.;
	for(int i = 0; i < image.getWidth(); ++i) {
		for(int j = 0; j < image.getHeight(); ++j) {
            Vector dir = Vector(
                j - image.getWidth() / 2.,
                i - image.getHeight() / 2.,
                -image.getWidth() / (2. * tan(fov / 2.))
            );
            dir.normalize();
            Ray ray = Ray(camera.getPos(), dir);
            image.setPixel(i, j, getColor(ray, 5));
		}
	}
    Image::save(image, "image.ppm");

}

Scene::operator std::__cxx11::string() const {
    stringstream ss;
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