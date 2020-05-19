#include "../include/Triangle.h"
#include <sstream>

Triangle::Triangle() {

}

Triangle::~Triangle() {

}

const Color Triangle::getColor() const {
    return Color();
}

const Material Triangle::getMaterial() const {
    return Material();
}

bool Triangle::intersect(const Ray &ray, Hit &hit) {
    return true;
}

Triangle::operator std::string() const {
    stringstream ss;
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const Triangle &triangle) {
    string text = triangle;
    os << text;
    return os;
}