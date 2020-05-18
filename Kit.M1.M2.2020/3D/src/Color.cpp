#include "../include/Color.h"
#include <sstream>
#include <cmath>


Color::Color(double red, double green, double blue) {
    this->red = red;
    this->green = green;
    this->blue = blue;
}

Color::Color() : Color(0, 0, 0) {
}

Color::~Color() { }

Color &Color::operator+=(const Color &c) {
    this->red += c.red;
    this->green += c.green;
    this->blue += c.blue;
    return (*this);
}

Color &Color::operator=(const Color &c) {
    this->red = c.red;
    this->green = c.green;
    this->blue = c.blue;
    return (*this);
}

const double Color::clamp(double value) const {
    return min(255., max(0., pow(value, 1/2.2)));
}

const double Color::getRed() const {
    return clamp(red);
}

const double Color::getBlue() const {
    return clamp(blue);
}

const double Color::getGreen() const {
    return clamp(green);
}

const Color operator*(const Color &a, const double &b) {
    return Color(a.red * b, a.green * b, a.blue * b);
}

const Color operator*(const double &a, const Color &b) {
    return Color(a * b.red, a * b.green, a * b.blue);
}

const Color operator*(const Color &a, const Color &b) {
    return Color(a.red * b.red, a.green * b.green, a.blue * b.blue);
}

const Color operator/(const Color &a, const double &b) {
    return Color(a.red / b, a.green / b, a.blue / b);
}

const Color operator/(const double &a, const Color &b) {
    return Color(a / b.red, a / b.green, a / b.blue);
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