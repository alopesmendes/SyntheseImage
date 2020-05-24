#include "../include/Cone.h"
#include "../include/Utils.h"
#include <sstream>
#include <cmath>

Cone::Cone(Vector center, double radius, double height, Color color, Material material) {
    this->center = center;
    this->radius = radius;
    this->height = height;
    this->color = color;
    this->material = material;
}

Cone::Cone() : Cone(Vector(), 0, 0, Color()) {

}

Cone::~Cone() {

}

Cone *Cone::create(std::string description) {
    stringstream iss(description);
    char separator = '|';
    Vector center = Utils::decodeVector(iss, separator);
    double radius = Utils::decodeDouble(iss, separator);
    double height = Utils::decodeDouble(iss, separator);
    Color color = Utils::decodeColor(iss, separator);
    Material material = Utils::decodeMaterial(description, iss, separator, 4);
    return new Cone(center, radius, height, color, material);
}

bool Cone::intersect(const Ray &ray, Hit &hit) {
    double A = ray.getOrigin().getX() - center.getX();
    double B = ray.getOrigin().getZ() - center.getZ();
    double D = height - ray.getOrigin().getY() + center.getY();
    
    double tan = (radius / height) * (radius / height);
    
    double a = (ray.getDirection().getX() * ray.getDirection().getX()) + (ray.getDirection().getZ() * ray.getDirection().getZ()) - (tan*(ray.getDirection().getY() * ray.getDirection().getY()));
    double b = (2*A*ray.getDirection().getX()) + (2*B*ray.getDirection().getZ()) + (2*tan*D*ray.getDirection().getY());
    double c = (A*A) + (B*B) - (tan*(D*D));
    
    double delta = b*b - 4*(a*c);
	if(fabs(delta) < 0.001) {
        return false;
    }  
    if(delta < 0.0) {
        return false;
    }
    
    double t1 = (-b - sqrt(delta))/(2*a);
    double t2 = (-b + sqrt(delta))/(2*a);
    double t;
    
    if (t1>t2) t = t2;
    else t = t1;
    
    double r = ray.getOrigin().getY() + t*ray.getDirection().getY();
    
    if ((r > center.getY()) and (r < center.getY() + height)) {
        hit.t = t;
        hit.pos = ray.getOrigin() + ray.getDirection()*hit.t;
        double r = sqrt((hit.pos.getX()-center.getX())*(hit.pos.getX()-center.getX()) + (hit.pos.getZ()-center.getZ())*(hit.pos.getZ()-center.getZ()));
        Vector n = Vector (hit.pos.getX()-center.getX(), r*(radius/height), hit.pos.getZ()-center.getZ());
        hit.normal = n.getNormalized();
        hit.shape = this;
        return true;
    } 
    return false;
}

Cone::operator std::string() const {
    stringstream ss;
    ss << "Cone (center:" << center
    << ", radius:" << radius
    << ", height:" << height
    << ", " << color
    << ", " << material
    << ")";
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const Cone &cone) {
    string text = cone;
    os << text;
    return os;
}