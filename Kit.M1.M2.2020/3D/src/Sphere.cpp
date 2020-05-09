#include "../include/Sphere.h"
#include "../include/Utils.h"
#include "../include/Vector.h"
#include <sstream>
#include <cmath>


Sphere::Sphere(Vector point, Color color, double radius, Material material) : Shape(point, color, material) {
    this->radius = radius;
}

Sphere::Sphere() : Shape() { 
    this->radius = 0;
}

Sphere::Sphere(string description) : Shape(description) {
    size_t pos = Utils::nthOccurrence(description, "|", 2);
    string line = description.substr(pos + 1);
    stringstream issRadius(line);
    issRadius >> this->radius;

    pos = Utils::nthOccurrence(description, "|", 3);
    if (pos == -1) {
        return;
    }
    bool m, t;
    line = description.substr(pos + 1);
    stringstream issMirror(line);
    issMirror >> m;
    this->material = Material(m);
    pos = Utils::nthOccurrence(description, "|", 4);
    if (pos == -1) {
        return;
    }
    line = description.substr(pos + 1);
    stringstream issTransperecy(line);
    issTransperecy >> t;
    this->material = Material(m, t);
}

bool Sphere::intersect(const Ray& ray, Hit& hit) {
    double a = 1;
    double b = 2 * ray.getDirection().scalarProduct(ray.getOrigin() - point);
    double c = (ray.getOrigin()-point).scalarProduct(ray.getOrigin()-point) - radius*radius;
    double delta = b*b - 4 * a*c;
    if(delta < 0) {
      return false;
	}
    double t1 = (-b - sqrt(delta)) / (2* a);
    double t2 = (-b + sqrt(delta)) / (2* a);
    if (t2 < 0) {
        return false;
    }
    hit.t = t1 > 0 ? t1 : t2;
    hit.pos = ray.getOrigin() + ray.getDirection()*hit.t;
    hit.normal = (hit.pos - point).getNormalized();
    hit.shape = &(*this);
    return true;
}

Sphere::operator std::string() const {
    stringstream ss;
    ss << "Sphere (position:" << point 
    << ", color:" << color 
    << ", radius:" << radius 
    << ", material:" << material
    << ")";
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Sphere& sphere) {
    string text = sphere;
    os << text;
    return os;
}


