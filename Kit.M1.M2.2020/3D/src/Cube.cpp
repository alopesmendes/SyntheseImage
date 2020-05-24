#include "../include/Cube.h"
#include "../include/Utils.h"
#include <sstream>
#include <cmath>


Cube::Cube(Vector p1, Vector p2, Vector p3, Vector p4, Color color, Material material) {
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
    this->p4 = p4;
    this->color = color;
    this->material = material;
}

Cube::Cube() : Cube(Vector(), Vector(), Vector(), Vector(), Color()) {

}

Cube::~Cube() {

}


Cube *Cube::create(string description) {
    int nbPoints = 4;
    stringstream iss(description);
    Vector vs[nbPoints];
    for (int i = 0; i < nbPoints; i++) {
        vs[i] = Utils::decodeVector(iss, '|');
    }
    Color c = Utils::decodeColor(iss, '|');
    Material m = Utils::decodeMaterial(description, iss, '|', 5);
    return new Cube(vs[0], vs[1], vs[2], vs[3], c, m);
}

const double Cube::minX() const {
    double minVector = std::min(std::min(p1.getX(), p2.getX()), std::min(p3.getX(), p4.getX()));
	if(p1.getX() < p2.getX() && p1.getX()< p3.getX() && p1.getX()< p4.getX()){
		return p1.getX();
	}
	return p1.getX() - abs(minVector);
}

const double Cube::minY() const {
    double minVector = std::min(std::min(p1.getY(), p2.getY()), std::min(p3.getY(), p4.getY()));
	if(p1.getY() < p2.getY() && p1.getY()< p3.getY() && p1.getY()< p4.getY()){
		return p1.getY();
	}
	return p1.getY() - abs(minVector); 
}

const double Cube::minZ() const {
    double minVector = std::min(std::min(p1.getZ(), p2.getZ()), std::min(p3.getZ(), p4.getZ()));
	if(p1.getZ() < p2.getZ() && p1.getZ()< p3.getZ() && p1.getZ()< p4.getZ()){
		return p1.getZ();
	}
	return p1.getZ() - abs(minVector);
}

const double Cube::maxX() const {
    double maxVector = std::max(std::max(p1.getX(), p2.getX()), std::max(p3.getX(), p4.getX()));
	if(p1.getX() > p2.getX() && p1.getX() > p3.getX() && p1.getX() > p4.getX()){
		return p1.getX();
	}
	return p1.getX() + abs(maxVector);
}

const double Cube::maxY() const {
    double maxVector = std::max(std::max(p1.getY(), p2.getY()), std::max(p3.getY(), p4.getY()));
	if(p1.getY() > p2.getY() && p1.getY() > p3.getY() && p1.getY()> p4.getY()){
		return p1.getY();
	}
	return p1.getY() + abs(maxVector);
}

const double Cube::maxZ() const {
    double maxVector = std::max(std::max(p1.getZ(), p2.getZ()), std::max(p3.getZ(), p4.getZ()));
	if(p1.getZ() > p2.getZ() && p1.getZ() > p3.getZ() && p1.getZ() > p4.getZ()){
		return p1.getZ();
	}
	return p1.getZ() + abs(maxVector);
}

bool Cube::intersect(const Ray &ray, Hit &hit) {
    double invdx = 1. / ray.getDirection().getX();
    double invdy = 1. / ray.getDirection().getY();
    double invdz = 1. / ray.getDirection().getZ();
    double t_1_x = (minX() - ray.getOrigin().getX()) *invdx;
    double t_2_x = (maxX() - ray.getOrigin().getX()) *invdx;
    double t_min_x = std::min(t_1_x, t_2_x);
    double t_max_x = std::max(t_1_x, t_2_x);

    double t_1_y = (minY() - ray.getOrigin().getY()) *invdy;
    double t_2_y = (maxY() - ray.getOrigin().getY()) *invdy;
    double t_min_y = std::min(t_1_y, t_2_y);
    double t_max_y = std::max(t_1_y, t_2_y);

    double t_1_z = (minZ() - ray.getOrigin().getZ()) *invdz;
    double t_2_z = (maxZ() - ray.getOrigin().getZ()) *invdz;
    double t_min_z = std::min(t_1_z, t_2_z);
    double t_max_z = std::max(t_1_z, t_2_z);

    double tlast = std::min(std::min(t_max_x, t_max_y), t_max_z);
    if (tlast < 0) return false;

    double tfirst = std::max(std::max(t_min_x, t_min_y), t_min_z);

    hit.t = tfirst > 0 ? tfirst : 0;
    hit.pos = ray.getOrigin() + ray.getDirection()*hit.t;
    Vector pos = p1;
    hit.normal = (hit.pos - pos).getNormalized();
    hit.shape = &(*this);

    if (tlast - tfirst >= -0.000001) {
        return true;
    }
    return false;
}

Cube::operator std::string() const {
    stringstream ss;
    ss << "Rectangle (p1:" << p1
    << ", p2:" << p2
    << ", p3:" << p3
    << ", p4:" << p4 
    << ", " << color
    << ", " << material << ")";
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const Cube &rectangle) {
    string text = rectangle;
    os << text;
    return os;
}