#include "../include/Sphere.h"
#include "../include/Utils.h"
#include "../include/Vector.h"
#include <sstream>
#include <cmath>


Sphere::Sphere(Point point, Color color, double radius) : Shape(point, color) {
    this->radius = radius;
}

Sphere::Sphere() : Shape() { 
    this->radius = 0;
}

Sphere::Sphere(string description) : Shape(description) {
    size_t pos = Utils::nthOccurrence(description, "|", 2);
    string line = description.substr(pos + 1);
    stringstream iss(line);
    iss >> this->radius;

}

bool Sphere::intersect(const Ray& ray, double& dist) {
    Vector dir = ray.getDirection();
    Vector ori(point, ray.getOrigin());
    double a = 1;
    double b = 2 * dir.scalarProduct(ori);
    double c = ori.scalarProduct(ori) - radius * radius;
    double delta = (b * b - 4 * a * c);
    if(delta < 0.) {
      return false;
	}
    double t1 = (-b - sqrt(delta)) / (2* a);
    double t2 = (-b + sqrt(delta)) / (2* a);
    if (t2 < 0.) {
        return false;
    }
    double t = t1 > 0. ? t1 : t2;
    Vector P = ray.getDirection() * t;
    Vector N = ori / ori.normalize();
    return true;
}

Sphere::operator std::string() const {
    stringstream ss;
    ss << "Sphere (position:" << point 
    << ", color:" << color 
    << ", radius:" << radius << ")";
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Sphere& sphere) {
    string text = sphere;
    os << text;
    return os;
}


