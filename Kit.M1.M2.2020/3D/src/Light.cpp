#include "../include/Light.h"
#include <cmath>
#include <sstream>

Light::Light(Vector pos, double intensity) {
    this->pos = pos;
    this->intensity = intensity;
}

Light::Light() : Light(Vector(), 0) {
    
}

Light::~Light() {

}

Light* Light::create(string description) {
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
    return new Light(Vector(pos_x, pos_y, pos_z), it);
}

const double Light::getIntensity() const {
    return intensity;
}


Vector Light::getPos() const {
    return pos;
}

Color Light::getColor(const Scene &scene, const Hit &hit) {
    Color diffuse, specular, c;
    Hit hitLight;
    c = hit.shape->getColor() * 0.01;
    Vector v = pos - hit.pos;
    double d_light2 = v.scalarProduct(v);
    Ray rayLight = Ray(hit.pos + hit.normal*0.01, v.getNormalized());
    bool hasIterLight = scene.intersect(rayLight, hitLight);
    if (hasIterLight && (hitLight.t*hitLight.t <= d_light2)) {
        return Color();
    } 
    Vector normal = hit.normal;
    Vector dir = rayLight.getDirection() - 2 * rayLight.getDirection().scalarProduct(normal) * normal;
    Ray rRefl = Ray(hit.pos, -1 * dir);
    double kd = max(0.0, normal.scalarProduct(rayLight.getDirection()));
    double ks = pow(max(0.0, (rayLight.getDirection().scalarProduct(rRefl.getDirection()))), 2.);
    diffuse = kd * hit.shape->getColor();
    specular = ks * hit.shape->getColor();
    c += hit.shape->getColor() + intensity * (diffuse + specular);
    return c;
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
