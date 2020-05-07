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

void Scene::subDraw(Image &image, int i, int j) {
    Hit hit;
    double fov = 60. * M_PI / 180.;
    Vector dir = Vector(
        j - image.getWidth() / 2.,
        i - image.getHeight() / 2.,
        -image.getWidth() / (2. * tan(fov / 2.))
    );
	Ray r = Ray(camera.getPos(), dir / dir.normalize());
    for (auto categorie = shapes.begin(); categorie != shapes.end(); ++categorie) {
        for (auto shape = categorie->second.begin(); shape != categorie->second.end(); ++shape) {
            if ((**shape).intersect(r, hit)) {
                Color c = light.colorIntensity(hit, (**shape).getColor());
                image.setPixel(i, j, c); 
            }
        }
    }
}

void Scene::update() {
    Image image = Image(1024, 1024);
	for(int i = 0; i < image.getHeight(); ++i) {
		for(int j = 0; j < image.getWidth(); ++j){
            subDraw(image, i, j);
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