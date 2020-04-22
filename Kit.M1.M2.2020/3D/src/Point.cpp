#include "../include/Point.h"

Point::Point(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Point::~Point() { }

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "Point (x:" << point.x << ", y:" << point.y << ", z:" << point.z << ")";
    return os;
}