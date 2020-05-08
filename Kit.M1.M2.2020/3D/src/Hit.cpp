#include "../include/Hit.h"

Hit::Hit() {
    this->pos = Vector();
    this->normal = Vector();
    this->t = 0;
    this->color = Color();
}

Hit::~Hit() {

}

Hit::operator std::string() const {
    stringstream ss;
    ss << "Hit (position:" << pos
    << ", normal" << normal << ")";
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const Hit &hit) {
    string text = hit;
    os << text;
    return os;
}