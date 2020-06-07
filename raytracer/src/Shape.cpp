#include "../include/Shape.h"
#include <sstream>


const Color Shape::getColor() const {
    return color;
}

const Material Shape::getMaterial() const {
    return material;
}

Shape::operator std::string() const {
    stringstream ss;
    ss << "Shape";
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Shape& shape) {
    string text = shape;
    os << text;
    return os;
}