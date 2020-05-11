#include "../include/Material.h"
#include <sstream>

Material::Material(bool mirror, bool transparecy) {
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
    ss << "Material (mirror:" << mirror
    << ", transparecy:" << transparecy << ")";
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const Material &material) {
    string text = material;
    os << text;
    return os;
}
