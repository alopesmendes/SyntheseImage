#include "../include/Plane.h"
#include "../include/Utils.h"
#include <sstream>

Plane::Plane(Vector pos, Vector normal, Color color, Material material) {
    this->pos = pos;
    this->normal = normal;
    this->color = color;
    this->material = material;
}

Plane::Plane() : Plane(Vector(), Vector(), Color()) {

}

Plane::~Plane() {

}

Plane *Plane::create(string description) {
    stringstream iss(description);
    Vector pos = Utils::decodeVector(iss, '|');
    Vector normal = Utils::decodeVector(iss, '|');
    Color color = Utils::decodeColor(iss, '|');
    Material material = Utils::decodeMaterial(description, iss, '|', 3);
    return new Plane(pos, normal, color, material);
}


bool Plane::intersect(const Ray &ray, Hit &hit) {
    double dDotN = ray.getDirection().scalarProduct(normal);

	if (dDotN == 0.) {
		return false;
	}

	// Find point of intersection
	double t = (pos - ray.getOrigin()).scalarProduct(normal) / dDotN;
    if (t < 0.00001) {
        return false;
    }
	hit.t = t;
	hit.shape = this;
    hit.pos = ray.getOrigin() + ray.getDirection()*hit.t;
    hit.normal = normal.getNormalized();
	return true;
}

Plane::operator string() const {
    stringstream ss;
    ss << "Plane (position:" << pos
    << ", normal:" << normal
    << ", " << color
    << ", " << material
    << ")"; 
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const Plane &plane) {
    string text = plane;
    os << text;
    return os;
}