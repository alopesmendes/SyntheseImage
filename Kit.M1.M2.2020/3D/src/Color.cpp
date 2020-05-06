#include "../include/Color.h"


Color::Color(unsigned char red, unsigned char green, unsigned char blue) {
    this->red = red;
    this->green = green;
    this->blue = blue;
}

Color::Color() : Color(0, 0, 0) {
}

Color::~Color() { }

unsigned char Color::getRed() {
    return red;
}

unsigned char Color::getBlue() {
    return blue;
}

unsigned char Color::getGreen() {
    return green;
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