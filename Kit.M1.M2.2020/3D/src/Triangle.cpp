#include "../include/Triangle.h"
#include "../include/Utils.h"
#include <sstream>
#include <cmath>

constexpr double kEpsilon = 1e-8; 

Triangle::Triangle(Vector v0, Vector v1, Vector v2, Color color, Material material ) {
    this->v0 = v0;
    this->v1 = v1;
    this->v2 = v2;
    this->color = color;
    this->material = material;
}

Triangle::Triangle() : Triangle(Vector(), Vector(), Vector(), Color()) {

}

Triangle::~Triangle() {

}

Triangle *Triangle::create(std::string description) {
    stringstream iss(description);
    char separator = '|';
    Vector v0 = Utils::decodeVector(iss, separator);
    Vector v1 = Utils::decodeVector(iss, separator);
    Vector v2 = Utils::decodeVector(iss, separator);
    Color color = Utils::decodeColor(iss, separator);
    Material material = Utils::decodeMaterial(description, iss, separator, 4);
    return new Triangle(v0, v1, v2, color, material);
}

bool Triangle::intersect(const Ray &ray, Hit &hit) {
    
    const double EPSILON = 0.0000001;
    Vector edge1, edge2, h, s, q;
    double a,f,u,v;
    edge1 = v1 - v0;
    edge2 = v2 - v0;
    h = ray.getDirection().cross(edge2);
    a = edge1.scalarProduct(h);
    if (a > -EPSILON && a < EPSILON) {
        return false;    // Le rayon est parallèle au triangle.
    }

    f = 1.0 / a;
    s = ray.getOrigin() - v0;
    u = f * (s.scalarProduct(h));
    if (u < 0.0 || u > 1.0)
        return false;
    q = s.cross(edge1);
    v = f * ray.getDirection().scalarProduct(q);
    if (v < 0.0 || u + v > 1.0) {
        return false;
    }

    // On calcule t pour savoir ou le point d'intersection se situe sur la ligne.
    double t = f * edge2.scalarProduct(q);
    if (t > EPSILON) // Intersection avec le rayon
    {
        hit.pos = ray.getOrigin() + ray.getDirection() * t;
        hit.t = t;
        hit.shape = this;
        hit.normal = edge2.cross(edge1).getNormalized();
        return true;
    }
    return false;    
}


Triangle::operator std::string() const {
    stringstream ss;
    ss << "Triangle (v0:" << v0
    << ", v1:" << v1
    << ", v2:" << v2
    << ", " << color
    << ", " << material
    << ")";
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const Triangle &triangle) {
    string text = triangle;
    os << text;
    return os;
}