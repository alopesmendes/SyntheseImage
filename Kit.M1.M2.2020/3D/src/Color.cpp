#include "../include/Color.h"


Color::Color(double red, double green, double blue) {
    this->red = red;
    this->green = green;
    this->blue = blue;
}

Color::Color() : Color(0, 0, 0) {
}

Color::~Color() { }



double Color::getRed() {
    return (red);
}

double Color::getBlue() {
    return (blue);
}

double Color::getGreen() {
    return (green);
}

const Color Color::operator*(double a) const {
    return Color(
        red * a,
        green * a,
        blue * a
    );
}

const Color Color::operator/(double a) const {
    return Color(
        red / a,
        green / a,
        blue / a
    );
}


Color::operator std::string() const {
    stringstream ss;
    ss << "Color (r:" << red << ", g:" << green << ", b:" << blue << ")";
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Color& color) {
    string text = color;
    os << text;
    return os;
}