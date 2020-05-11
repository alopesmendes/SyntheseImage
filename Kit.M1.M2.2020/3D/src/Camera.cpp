#include "../include/Camera.h"
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
    string pos, target, theta, phi, dist;
    double pos_x, pos_y, pos_z;
    double target_x, target_y, target_z;
    double thetaD;
    double phiD;
    double distD;
    stringstream iss(description);
    getline(iss, pos, '|');
    getline(iss, target, '|');
    getline(iss, theta, '|');
    getline(iss, phi, '|');
    getline(iss, dist, '}');
    stringstream issPos(pos);
    stringstream issTarget(target);
    stringstream issTheta(theta);
    stringstream issPhi(phi);
    stringstream issDist(dist); 

    issPos >> pos_x >> pos_y >> pos_z;
    issTarget >> target_x >> target_y >> target_z;
    issTheta >> thetaD;
    issPhi >> phiD;
    issDist >> distD;
    return new Camera(Vector(pos_x, pos_y, pos_z), Vector(target_x, target_y, target_z),
        thetaD, phiD, distD
    );
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