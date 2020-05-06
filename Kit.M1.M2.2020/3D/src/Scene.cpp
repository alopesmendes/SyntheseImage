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


void Scene::update() {
    Image image = Image(1024, 1024);
    Point posCam = camera.getPos();
    double fov = 60 * M_PI / 180;
	double dist = 0;
    double dir_z = -image.getWidth() / (2 * tan(fov / 2)); 
	for(int i = 0; i < image.getHeight(); ++i) {
		double dir_y = i - image.getHeight() / 2;
		for(int j = 0; j < image.getWidth(); ++j){
			float dir_x = j - image.getWidth() / 2;
			Vector dir = Vector(dir_x, dir_y, dir_z);
			Ray r = Ray(posCam, dir / dir.normalize());
            for (auto categorie = shapes.begin(); categorie != shapes.end(); ++categorie) {
                for (auto shape = categorie->second.begin(); shape != categorie->second.end(); ++shape) {
                    if ((**shape).intersect(r, dist)) {
                       image.setPixel(i, j, (**shape).getColor()); 
                    }
                }
            }	
		}
	}
    Image::save(image, "image.ppm");

}

Scene::operator std::__cxx11::string() const {
    stringstream ss;
    ss << camera << endl;
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