#include "../include/Vector.h"
#include <cmath>

Vector::Vector(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector::Vector(const Point &a, const Point &b) {
    this->x = b.getX() - a.getX();
    this->y = b.getY() - a.getY();
    this->z = b.getZ() - a.getZ(); 
}

Vector::~Vector() { }

Vector Vector::operator+(const Vector &p) {
    return Vector(this->x + p.x, this->y + p.y, this->z + p.z);
}

Vector Vector::operator-(const Vector &p) {
    return Vector(this->x - p.x, this->y - p.y, this->z - p.z);
}

bool Vector::operator==(const Vector &p) {
    return this->x == p.x && this->y == p.y && this->z == p.z;
}

bool Vector::operator!=(const Vector &p) {
    return this->x != p.x || this->y != p.y || this->z != p.z;
}

Vector &Vector::operator=(const Vector &p) {
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;
    return (*this);
}

Vector Vector::operator*(double a) {
    return Vector(this->x * a, this->y * a, this->z * a);
}

Vector Vector::operator/(double a) {
    return Vector(this->x / a, this->y / a, this->z / a);
}

Point Vector::operator+(const Point &p) {
    return Point(this->x + p.getX(), this->y + p.getY(), this->z + p.getZ());
}

double Vector::scalarProduct(const Vector &v) {
    return this->x * v.x + this->y * v.y + this->z * v.z;
}

double Vector::normalize() {
    return sqrt(scalarProduct(*this));
}

Vector::operator std::string() const {
    stringstream ss;
    ss << "Vector (x:" << x << ", y:" << y << ", z:" << z << ")";
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Vector& vector) {
    string text = vector;
    os << text;
    return os;
}