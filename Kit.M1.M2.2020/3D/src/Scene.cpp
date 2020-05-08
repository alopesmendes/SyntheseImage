#include "../include/Scene.h"
#include <cmath>


Scene::Scene() {

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
                    hit.t = localHit.t;
                    hit.pos = localHit.pos;
                    hit.normal = localHit.normal;
                    hit.color = localHit.color;
                }
            }
        }
    }
    return hasItersect;
}

void Scene::update() {
    Image image = Image(1024, 1024);
    double fov = 60. * M_PI / 180.;
	for(int i = 0; i < image.getWidth(); ++i) {
		for(int j = 0; j < image.getHeight(); ++j) {
            Vector dir = Vector(
                j - image.getWidth() / 2.,
                i - image.getHeight() / 2.,
                -image.getWidth() / (2. * tan(fov / 2.))
            );
            dir.normalize();
            Hit hit, hitLight;
            Ray ray = Ray(camera.getPos(), dir);
            bool hasIter = intersect(ray, hit);
            if (hasIter) {
                Vector v = light.getPos() - hit.pos;
                double d_light2 = v.scalarProduct(v);
                Ray rayLight = Ray(hit.pos + hit.normal*0.01, v.getNormalized());
                bool hasIterLight = intersect(rayLight, hitLight);
                if (hasIterLight && (hitLight.t*hitLight.t <= d_light2)) {
                    continue;
                }
                Color c = light.colorIntensity(hit, d_light2);
                image.setPixel(i, j, c);
            }
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