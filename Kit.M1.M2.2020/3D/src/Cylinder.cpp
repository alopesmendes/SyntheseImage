#include "../include/Cylinder.h"
#include "../include/Utils.h"
#include <sstream>
#include <cmath>

Cylinder::Cylinder(Vector center, double radius, double height, Color color, Material material) {
    this->center = center;
    this->radius = radius;
    this->height = height;
    this->color = color;
    this->material = material;
}

Cylinder::Cylinder() : Cylinder(Vector(), 0, 0, Color()) {

}

Cylinder::~Cylinder() {

}

Cylinder *Cylinder::create(std::string description) {
    stringstream iss(description);
    char separator = '|';
    Vector center = Utils::decodeVector(iss, separator);
    double radius = Utils::decodeDouble(iss, separator);
    double height = Utils::decodeDouble(iss, separator);
    Color color = Utils::decodeColor(iss, separator);
    Material material = Utils::decodeMaterial(description, iss, separator, 4);
    return new Cylinder(center, radius, height, color, material);
}

bool Cylinder::intersect(const Ray &ray, Hit &hit) {
    Vector dir = ray.getDirection();
    Vector pos = ray.getOrigin();
    double a = (dir.getX() * dir.getX()) + (dir.getZ() * dir.getZ());
    double b = 2*(dir.getX()*(pos.getX()-center.getX()) + dir.getZ()*(pos.getZ()-center.getZ()));
    double c = (pos.getX() - center.getX()) * (pos.getX() - center.getX()) + (pos.getZ() - center.getZ()) * (pos.getZ() - center.getZ()) - (radius*radius);
    
    double delta = b*b - 4*(a*c);
	if(fabs(delta) < 0.001) {
        return false;
    } 
    if(delta < 0.0)  {
        return false;
    } 
    
    double t1 = (-b - sqrt(delta))/(2*a);
    double t2 = (-b + sqrt(delta))/(2*a);
    double t;
    
    if (t1>t2) t = t2;
    else t = t1;
    
    double r = pos.getY() + t*dir.getY();
    
    if ((r >= center.getY()) and (r <= center.getY() + height)) {
        hit.t = t;
        hit.pos = hit.pos = ray.getOrigin() + ray.getDirection()*hit.t;
        hit.shape = this;
        hit.normal = Vector(hit.pos.getX()-center.getX(), 0 ,hit.pos.getZ()-center.getZ()).getNormalized();
        return t;
    }
    return false;
}

Cylinder::operator std::string() const {
    stringstream ss;
    ss << "Cylinder (center:" << center
    << ", radius:" << radius
    << ", height:" << height
    << ", " << color
    << ", " << material
    << ")";
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const Cylinder &cylinder) {
    string text = cylinder;
    os << text;
    return os;
}