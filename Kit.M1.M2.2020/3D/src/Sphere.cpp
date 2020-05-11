#include "../include/Sphere.h"
#include "../include/Utils.h"
#include "../include/Vector.h"
#include <sstream>
#include <cmath>


Sphere::Sphere(Vector point, Color color, double radius, Material material) {
    this->point = point;
    this->color = color;
    this->material = material;
    this->radius = radius;
}

Sphere::Sphere() : Sphere(Vector(), Color(), 0) { 
    this->radius = 0;
}

Sphere* Sphere::create(string description) {
    string line;
    double x, y, z;
    double red, green, blue;
    double radius;
    stringstream iss(description);

    getline(iss, line, '|');
    stringstream issPoints(line);
    issPoints >> x >> y >> z;

    getline(iss, line, '|');
    stringstream issColors(line);
    issColors >> red >> green >> blue;

    getline(iss, line, '|');
    stringstream issRadius(line);
    issRadius >> radius;
    bool m = false, t = false;
    size_t pos = Utils::nthOccurrence(description, "|", 3);
    if (pos == -1) {
        return new Sphere(Vector(x, y, z), Color(red, green, blue), radius, Material());
    }

    getline(iss, line, '|');
    stringstream issMirror(line);
    issMirror >> m;
    pos = Utils::nthOccurrence(description, "|", 4);
    if (pos == -1) {
        return new Sphere(Vector(x, y, z), Color(red, green, blue), radius, Material(m));;
    }
    getline(iss, line, '|');
    stringstream issTransperecy(line);
    issTransperecy >> t;
    return new Sphere(Vector(x, y, z), Color(red, green, blue), radius, Material(m, t));
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

const Color Sphere::getColor() const {
    return color;
}

const Material Sphere::getMaterial() const {
    return material;
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


