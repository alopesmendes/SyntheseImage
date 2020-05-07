#include "../include/Light.h"

Light::Light(int level, Point pos, double intensity) {
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
    this->pos = Point(pos_x, pos_y, pos_z);
    this->intensity = it;
}

Light::~Light() {

}

Color Light::colorIntensity(const Hit &hit, const Color &color) {
    Vector v = Vector(hit.pos, this->pos);
    Vector vNorm = v / v.normalize();
    double sc = intensity * max(0., vNorm.scalarProduct(hit.normal)) / (v.scalarProduct(v));
    return color * sc;
    //return color;
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
