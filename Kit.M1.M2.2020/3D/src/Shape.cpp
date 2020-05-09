#include "../include/Shape.h"
#include <sstream>

Shape::Shape(Vector point, Color color, Material material) {
    this->point = point;
    this->color = color;
    this->material = material;
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
    this->material = Material();

}

Shape::Shape() {
    point = Vector();
    color = Color();
    material = Material();
 }

const Color Shape::getColor() const {
    return color;
}

const Material Shape::getMaterial() const {
    return material;
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