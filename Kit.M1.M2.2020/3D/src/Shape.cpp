#include "../include/Shape.h"
#include <sstream>

Shape::Shape(Vector point, Color color) : point(point), color(color) {

}

Shape::Shape(string description) {
    string points, colors;
    double x, y, z;
    double red, green, blue;

    stringstream iss(description);
    getline(iss, points, '|');
    getline(iss, colors, '|');
    stringstream issPoints(points);
    stringstream issColors(colors);
    
    issPoints >> x >> y >> z;
    issColors >> red >> green >> blue;

    this->point = Vector(x, y, z);
    this->color = Color(red, green, blue);

}

Shape::Shape() {
    point = Vector();
    color = Color();
 }

const Color Shape::getColor() const {
    return color;
}

Shape::operator std::string() const {
    stringstream ss;
    ss << "Shape (" << point 
    << ", " << color << ")";
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Shape& shape) {
    string text = shape;
    os << text;
    return os;
}