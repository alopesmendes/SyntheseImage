#include "../include/Color.h"

double clamp(double value);

Color::Color(double red, double green, double blue) {
    this->red = red;
    this->green = green;
    this->blue = blue;
}

Color::Color() : Color(0, 0, 0) {
}

Color::~Color() { }

double clamp(double value) {
    return value;
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

const Color Color::operator*(double a) const {
    return Color(
        this->red * a,
        this->green * a,
        this->blue * a
    );
}

const Color Color::operator*(const Color& c) const {
    return Color(
        this->red * c.red,
        this->green * c.green,
        this->blue * c.blue
    );
}

Color &Color::operator+=(const Color &c) {
    red += c.red;
    green += c.green;
    blue += c.blue;
    return (*this);
}

Color &Color::operator=(const Color &c) {
    red = c.red;
    green = c.green;
    blue = c.blue;
    return (*this);
}

const Color Color::operator/(double a) const {
    return Color(
        this->red / a,
        this->green / a,
        this->blue / a
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