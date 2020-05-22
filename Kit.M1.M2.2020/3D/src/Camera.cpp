#include "../include/Camera.h"
#include "../include/Utils.h"
#include <sstream>
#include <cmath>

Camera::Camera(Vector pos, Vector target, double theta, double phi, double dist)
 {
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
    double theta = Utils::decodeDouble(iss, seperator) * M_PI / 180.;
    double phi = Utils::decodeDouble(iss, seperator);
    double dist = Utils::decodeDouble(iss, seperator);
    return new Camera(pos, target, theta, phi, dist);
}

const Vector Camera::getPos() const {
    return pos;
}

Ray Camera::makeRay(const int &i, const int &j, const Image &im) {
    double u = j - im.getWidth() / 2., v = i - im.getHeight() / 2.;
    Vector dir = Vector(u, v, -im.getWidth() / (2. * tan(theta / 2.)));
    dir.normalize();
    return Ray(pos, dir);
    /*
    double normalized_i = (i / im.getWidth()) - 0.5;
    double normalized_j = (j / im.getWidth()) - 0.5;
    Vector image_point = normalized_i * right +
                            normalized_j * up +
                            pos + target.getNormalized();
    Vector ray_direction = image_point - pos;
    return Ray(pos, ray_direction);*/

}

Camera::operator std::string() const {
    stringstream ss;
    ss << "Camera (position:" << pos
    << ", target:" << target
    << ", theta:" << theta 
    << ", phi:" << phi
    << ", dist:" << dist
    << ")";
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Camera& camera) {
    string text = camera;
    os << text;
    return os;
}