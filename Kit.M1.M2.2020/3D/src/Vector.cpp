#include "../include/Vector.h"
#include <cmath>
#include <sstream>

Vector::Vector(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector::~Vector() { }

Vector &Vector::operator=(const Vector &p) {
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;
    return (*this);
}

Vector operator+(const Vector &a, const Vector &b) {
    return Vector(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vector operator-(const Vector &a, const Vector &b) {
    return Vector(a.x - b.x, a.y - b.y, a.z - b.z);
}

Vector operator-(const Vector &a, const double &b) {
    return Vector(a.x - b, a.y - b, a.z - b);
}

Vector operator-(const double &a, const Vector &b) {
    return Vector(a - b.x, a - b.y, a - b.z);
}

Vector operator*(const Vector &a, const double &b) {
    return Vector(a.x * b, a.y * b, a.z * b);
}

Vector operator*(const double &a, const Vector &b) {
    return Vector(b.x * a, b.y * a, b.z * a);
}

Vector operator*(const Vector &a, const Vector &b) {
    return Vector(a.x * b.x, a.y * b.y, a.z * b.z);
}

Vector operator/(const Vector &a, const Vector &b) {
    return Vector(a.x / b.x, a.y / b.y, a.z / b.z);
}

Vector operator/(const Vector &a, const double &b) {
    return Vector(a.x / b, a.y / b, a.z / b);
}

Vector operator/(const double &a, const Vector &b) {
    return Vector(a / b.x, a / b.y, a / b.z);
}

bool operator==(const Vector &a, const Vector &b) {
    return a.x == b.x && a.y == b.y && a.z == b.z;
}

double Vector::scalarProduct(const Vector &v) {
    return this->x * v.x + this->y * v.y + this->z * v.z;
}

double Vector::norm(const Vector &v) {
    return sqrt(this->x * v.x + this->y * v.y + this->z * v.z);
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

std::istream &operator>>(std::istream &is, Vector &vector) {
    return is >> vector.x >> vector.y >> vector.z;
}