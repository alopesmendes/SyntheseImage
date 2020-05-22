#include "../include/Box.h"
#include <sstream>
#include "../include/Utils.h"


Box::Box(Vector bmin, Vector bmax, Color color, Material material) {
    this->bmin = bmin;
    this->bmax = bmax;
    this->color = color;
    this->material = material;
}

Box::Box() : Box(Vector(), Vector(), Color()) {

}

Box::~Box() {

}

Box *Box::create(std::string description) {
    stringstream iss(description);
    char seperator = '|';
    Vector bbmin = Utils::decodeVector(iss, seperator);
    Vector bbmax = Utils::decodeVector(iss, seperator);
    Color color = Utils::decodeColor(iss, seperator);
    Material material = Utils::decodeMaterial(description, iss, seperator, 3);
    return new Box(bbmin, bbmax, color, material);
}

const Color Box::getColor() const {
    return color;
}

const Material Box::getMaterial() const {
    return material;
}

bool Box::intersect(const Ray &ray, Hit &hit) {
    
    double t_1_x = (bmin.getX() - ray.getOrigin().getX()) / ray.getDirection().getX();
    double t_2_x = (bmax.getX() - ray.getOrigin().getX()) / ray.getDirection().getX();
    double t_min_x = std::min(t_1_x, t_2_x);
    double t_max_x = std::max(t_1_x, t_2_x);

    double t_1_y = (bmin.getY() - ray.getOrigin().getY()) / ray.getDirection().getY();
    double t_2_y = (bmax.getY() - ray.getOrigin().getY()) / ray.getDirection().getY();
    double t_min_y = std::min(t_1_y, t_2_y);
    double t_max_y = std::max(t_1_y, t_2_y);

    double t_1_z = (bmin.getZ() - ray.getOrigin().getZ()) / ray.getDirection().getZ();
    double t_2_z = (bmax.getZ() - ray.getOrigin().getZ()) / ray.getDirection().getZ();
    double t_min_z = std::min(t_1_z, t_2_z);
    double t_max_z = std::max(t_1_z, t_2_z);

    double tlast = std::min(std::min(t_max_x, t_max_y), t_max_z);
    if (tlast < 0) {
        return false;
    }

    if (tlast - std::max(std::max(t_min_x, t_min_y), t_min_z) >= -0.000001) {
        hit.t = tlast;
        hit.pos = ray.getOrigin() + ray.getDirection()*hit.t;
        Vector c = (bmin + bmax) * 0.5;
        Vector p = hit.pos - c;
        Vector d = (bmax - bmin) * 0.5;
        Vector absD = Vector(abs(d.getX()), abs(d.getY()), abs(d.getZ()));

        hit.normal = (p / absD).getNormalized();
        hit.shape = this;
        return true;
    }
    return false;
    
}

Box::operator std::string() const {
    stringstream ss;
    ss << "Box (bmin:" << bmin
    << ", bmax:" << bmax
    << ", " << color
    << ", " << material
    << ")";
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const Box &box) {
    string text = box;
    os << text;
    return os;
}