#include "../include/Point.hpp"
#include <iostream>

Point::Point(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Point::~Point() { }