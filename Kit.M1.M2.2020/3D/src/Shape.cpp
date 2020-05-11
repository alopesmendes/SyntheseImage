#include "../include/Shape.h"
#include <sstream>

Shape::Shape() {

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