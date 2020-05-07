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

const Color Color::operator*(double a) const {
    return Color(
        min(255., max(0., red * a)),
        min(255., max(0., green * a)),
        min(255., max(0., blue * a))
    );
}

const Color Color::operator/(double a) const {
    return Color(
        min(255., max(0., red / a)),
        min(255., max(0., green / a)),
        min(255., max(0., blue / a))
    );
}


Color::operator std::string() const {
    stringstream ss;
    ss << "Color (r:" << (int)red << ", g:" << (int)green << ", b:" << (int)blue << ")";
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Color& color) {
    string text = color;
    os << text;
    return os;
}