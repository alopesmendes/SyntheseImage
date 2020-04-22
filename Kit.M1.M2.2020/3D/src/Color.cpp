#include "../include/Color.h"

Color::Color(double red, double green, double blue) {
    this->red = red;
    this->green = green;
    this->blue = blue;
}

Color::Color() : Color(0, 0, 0) {
}

Color::~Color() { }

std::ostream& operator<<(std::ostream& os, const Color& color) {
    os << "Color (r:" << color.red << ", g:" << color.green << ", b:" << color.blue << ")";
    return os;
}