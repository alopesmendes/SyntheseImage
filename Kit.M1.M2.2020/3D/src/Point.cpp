#include "../include/Point.h"

Point::Point(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Point::~Point() { }

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

double Point::getZ() const {
    return z;
}

Point &Point::operator=(const Point &p) {
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;
    return (*this);
}

Point::operator std::__cxx11::string() const {
    stringstream ss;
    ss << "Point (x:" << x << ", y:" << y << ", z:" << z << ")";
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
    string text = point;
    os << text;
    return os;
}