#include "../include/Light.h"
#include "../include/Utils.h"
#include <cmath>
#include <sstream>

Light::Light(Vector pos, Color color,  double intensity) {
    this->pos = pos;
    this->color = color;
    this->intensity = intensity;
}

Light::Light() : Light(Vector(), Color(), 0) {
    
}

Light::~Light() {

}

Light* Light::create(string description) {
    char separator = '|';
    stringstream iss(description);
    Vector pos = Utils::decodeVector(iss, separator);
    Color color = Utils::decodeColor(iss, separator);
    double intensity = Utils::decodeDouble(iss, separator);
    return new Light(pos, color, intensity);
}

const Color Light::calcIntensity(const double &norm) const {
    return color * intensity / (4 * M_PI * norm);
}


Vector Light::getPos() const {
    return pos;
}
/*
version 1
Color Light::getColor(const Scene &scene, const Ray& ray, const Hit &hit) {
    Color diffuse, specular, c;
    Hit hitLight;
    c = hit.shape->getColor() * 0.01;
    Vector v = pos - hit.pos;
    double d_light2 = v.scalarProduct(v);
    Ray rayLight = Ray(hit.pos + hit.normal*0.01, v.getNormalized());
    Vector normal = hit.normal;
    Vector dir = rayLight.getDirection() - 2 * rayLight.getDirection().scalarProduct(normal) * normal;
    Ray rRefl = Ray(hit.pos, -1 * dir);
    double kd = max(0.0, normal.scalarProduct(rayLight.getDirection()));
    double ks = pow(max(0.0, (rayLight.getDirection().scalarProduct(rRefl.getDirection()))), 2.);
    diffuse = kd * hit.shape->getColor();
    specular = ks * hit.shape->getColor();
    c += hit.shape->getColor() + intensity * (hit.shape->getMaterial().ambience+ diffuse + specular);
    return c;
}
*/

/*
version 2
Color Light::getColor(const Scene &scene, const Ray& ray, const Hit &hit) {
    Vector n,l,v,r;
    Color diffuse, specular, ambience;
    double nl, exponent;
    diffuse = hit.shape->getMaterial().diffuse;
    ambience = hit.shape->getMaterial().ambience;
    specular = hit.shape->getMaterial().specular;
    l = (hit.pos - pos).getNormalized();
    n = hit.normal;

    v = -1.0*(hit.pos - ray.getOrigin());
    v.normalize();
    
    nl = n.scalarProduct(l);
    r = (2*nl*n) - l;
    r.normalize();
    return hit.shape->getColor() * intensity + (diffuse*nl + specular*pow(v.scalarProduct(r),exponent));
}
*/

Color Light::getColor(const Scene &scene, const Ray& ray, const Hit &hit) {
    Color ambient = hit.shape->getMaterial().ambience * color;
    Vector n = hit.normal;
    Vector lightDir = (pos - hit.pos);
    n.normalize();
    double diff = max(n.scalarProduct(lightDir.getNormalized()), 0.);
    Color diffuse = diff * hit.shape->getMaterial().diffuse;

    Vector viewDir = (scene.getCam().getLookAt() - pos).getNormalized();
    Vector reflectDir = (-1*lightDir.getNormalized()).reflect(n);
    double spec = pow(max(viewDir.scalarProduct(reflectDir), 0.), hit.shape->getMaterial().specularExponent);
    Color specular = hit.shape->getMaterial().specular * spec * color;
    return (ambient + diffuse + specular) * hit.shape->getColor() * calcIntensity(lightDir.norm(lightDir));
}
Light::operator std::string() const {
    stringstream ss;
    ss << "Light ( position:" << pos 
    << ", " << color
    << ", intensity:" << intensity
    << ")"; 
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const Light &light) {
    string text = light;
    os << text;
    return os;
}
