#include "../include/Material.h"
#include <sstream>


Material::Material() : Material(Color(), Color(), Color(), Color(), 0, false, false) {
    
}

Material::Material(Color ambience, Color diffuse, Color specular, Color reflectance, double specularExponent, bool mirror, bool transparecy) {
    this->ambience = ambience;
    this->diffuse = diffuse;
    this->specular = specular;
    this->reflectance = reflectance;
    this->specularExponent = specularExponent;
    this->mirror = mirror;
    this->transparecy = transparecy;
}


Material::~Material() {

}

const bool Material::isMirror() const {
    return mirror;
}

const bool Material::isTransparent() const {
    return transparecy;
}

Material::operator std::string() const {
    stringstream ss;
    ss << "Material (ambience:" << ambience
    << ", diffuse:" << diffuse
    << ", specular:" << specular
    << ", reflectance:" << reflectance
    << ", exponent:" << specularExponent
    << ", mirror:" << mirror 
    << ", transparecy:" << transparecy << ")";
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const Material &material) {
    string text = material;
    os << text;
    return os;
}

std::istream &operator>>(std::istream &is, Material &m) {
    return  is >> m.ambience
            >> m.diffuse 
            >> m.specular 
            >> m.reflectance 
            >> m.specularExponent 
            >> m.mirror 
            >> m.transparecy;
}