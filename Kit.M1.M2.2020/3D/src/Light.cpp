#include "../include/Light.h"

Light::Light(int level, Vector pos, double intensity) {
    this->level = level;
    this->pos = pos;
    this->intensity = intensity;
}

Light::Light(int level, std::string description) {
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
    this->level = level;
    this->pos = Vector(pos_x, pos_y, pos_z);
    this->intensity = it;
}

Light::~Light() {

}

Color Light::colorIntensity(const Hit &hit, const double &dist) {
    Vector v = (this->pos - hit.pos).getNormalized();
    return hit.color 
    * intensity
    * max(0., v.scalarProduct(hit.normal)) 
    / dist;
}

Vector Light::getPos() const {
    return pos;
}

Light::operator std::string() const {
    stringstream ss;
    ss << "Light (level:" << level
    << ", position" << pos 
    << ", intensity:" << intensity << ")"; 
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const Light &light) {
    string text = light;
    os << text;
    return os;
}
