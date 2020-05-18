#include "../include/Camera.h"
#include "../include/Utils.h"
#include <sstream>

Camera::Camera(Vector pos, Vector target, double theta, double phi, double dist) {
    this->pos = pos;
    this->target = target;
    this->theta = theta;
    this->phi = phi;
    this->dist = dist;
}

Camera::Camera() : Camera(Vector(), Vector(), 0, 0, 0) {

}
    
Camera::~Camera() {

}

Camera* Camera::create(string description) {
    
    stringstream iss(description);
    char seperator = '|';
    Vector pos = Utils::decodeVector(iss, seperator);
    Vector target = Utils::decodeVector(iss, seperator);
    double theta = Utils::decodeDouble(iss, seperator);
    double phi = Utils::decodeDouble(iss, seperator);
    double dist = Utils::decodeDouble(iss, seperator);
    return new Camera(pos, target, theta, phi, dist);
}

const Vector Camera::getPos() const {
    return pos;
}

Camera::operator std::string() const {
    stringstream ss;
    ss << "Camera (position:" << pos
    << ", target:" << target
    << ", theta:" << theta 
    << ", phi:" << phi 
    << ", distance:" << dist << ")";
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Camera& camera) {
    string text = camera;
    os << text;
    return os;
}