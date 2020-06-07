#include "../include/Material.h"
#include <sstream>


Material::Material() : Material(Color(1, 1, 1), Color(1, 1, 1), Color(1, 1, 1), 1, false, false) {
    
}

Material::Material(Color ambience, Color diffuse, Color specular, double specularExponent, bool mirror, bool transparecy) {
    this->ambience = ambience;
    this->diffuse = diffuse;
    this->specular = specular;
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
            >> m.specularExponent 
            >> m.mirror 
            >> m.transparecy;
}