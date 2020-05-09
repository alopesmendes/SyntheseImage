#include "../include/Light.h"
#include <cmath>

Light::Light(Vector pos, double intensity) {
    this->pos = pos;
    this->intensity = intensity;
}

Light::Light(std::string description) {
    string pos, intensity;
    double pos_x, pos_y, pos_z;
    double it;
    stringstream iss(description);
    getline(iss, pos, '|');
    getline(iss, intensity, '}');
    stringstream issPos(pos);
    stringstream issIntensity(intensity);
    issPos >> pos_x >> pos_y >> pos_z;
    issIntensity >> it;
    this->pos = Vector(pos_x, pos_y, pos_z);
    this->intensity = it;
}

Light::~Light() {

}

const double Light::getIntensity() const {
    return intensity;
}


Vector Light::getPos() const {
    return pos;
}

Light::operator std::string() const {
    stringstream ss;
    ss << "Light ( position:" << pos 
    << ", intensity:" << intensity << ")"; 
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const Light &light) {
    string text = light;
    os << text;
    return os;
}
