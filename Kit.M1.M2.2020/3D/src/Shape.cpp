#include "../include/Shape.h"
#include <sstream>

Shape::Shape(Point point, Color color) : point(point), color(color) {

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

    this->point = Point(x, y, z);
    this->color = Color(red, green, blue);

}

Shape::Shape() {
    point = Point();
    color = Color();
 }

Shape::~Shape() { }


std::ostream& operator<<(std::ostream& os, const Shape& shape) {
    os << "Shape (" << shape.point 
    << ", " << shape.color << ")";
    return os;
}