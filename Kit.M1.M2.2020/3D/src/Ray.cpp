#include "../include/Ray.h"

Ray::Ray(Point origin, Vector direction) {
    this->origin = origin;
    this->direction = direction;

}

Ray::~Ray() {

}

Point Ray::getOrigin() const {
    return origin;
}

Vector Ray::getDirection() const {
    return direction;
}

Ray::operator std::string() const {
    stringstream ss;
    ss << "Ray (position:" << origin
    << ", direction:" << direction << ")";
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Ray& ray) {
    string text = ray;
    os << text;
    return os;
}