#include "../include/Sphere.h"
#include "../include/Utils.h"
#include <sstream>
#include <cmath>


Sphere::Sphere(Vector pos, Color color, double radius, Material material) {
    this->pos = pos;
    this->color = color;
    this->material = material;
    this->radius = radius;
}

Sphere::Sphere() : Sphere(Vector(), Color(), 0) { 
}

Sphere* Sphere::create(string description) {
    string line;
    double radius;
    stringstream iss(description);

    Vector pos = Utils::decodeVector(iss, '|');
    Color color = Utils::decodeColor(iss, '|');

    getline(iss, line, '|');
    stringstream issRadius(line);
    issRadius >> radius;
    Material material = Utils::decodeMaterial(description, iss, '|', 3);
    return new Sphere(pos, color, radius, material);
}

bool Sphere::intersect(const Ray& ray, Hit& hit) {
    double a = 1;
    double b = 2 * ray.getDirection().scalarProduct(ray.getOrigin() - pos);
    double c = (ray.getOrigin()-pos).scalarProduct(ray.getOrigin()-pos) - radius*radius;
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
    hit.normal = (hit.pos - pos).getNormalized();
    hit.shape = &(*this);
    return true;
}


Sphere::operator std::string() const {
    stringstream ss;
    ss << "Sphere (position:" << pos 
    << ", radius:" << radius 
    << ", " << color 
    << ", " << material
    << ")";
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Sphere& sphere) {
    string text = sphere;
    os << text;
    return os;
}


