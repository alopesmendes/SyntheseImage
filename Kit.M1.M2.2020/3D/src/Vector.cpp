#include "../include/Vector.h"
#include <cmath>
#include <sstream>

Vector::Vector(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
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

Vector Vector::operator-(double a) {
    return Vector(this->x - a, this->y - a, this->z - a);
}

Vector Vector::operator*(double a) {
    return Vector(this->x * a, this->y * a, this->z * a);
}

Vector Vector::operator/(double a) {
    return Vector(this->x / a, this->y / a, this->z / a);
}

double Vector::scalarProduct(const Vector &v) {
    return this->x * v.x + this->y * v.y + this->z * v.z;
}

void Vector::normalize() {
    double norm = sqrt(scalarProduct(*this));
    x /= norm;
    y /= norm;
    z /= norm;
}

Vector Vector::getNormalized() {
    Vector result(*this);
    result.normalize();
    return result;
}

Vector Vector::cross(const Vector &v) {
    return Vector(
        this->y * v.z - this->z * v.y,
        this->z * v.x - this->x * v.z,
        this->x * v.y - this->y * v.x);
}

const double Vector::getX() const {
    return x;
}

const double Vector::getY() const {
    return y;
}

const double Vector::getZ() const {
    return z;
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