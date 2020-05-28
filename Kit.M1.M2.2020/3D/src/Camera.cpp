#include "../include/Camera.h"
#include "../include/Utils.h"
#include <sstream>
#include <cmath>

/*Camera::Camera(Vector lookfrom, Vector target, Vector up, double theta, double phi, double dist)
 {
    this->lookfrom = lookfrom;
    this->target = target;
    this->up = up;
    this->theta = theta;
    this->phi = phi;
    this->dist = dist;


}

Camera::Camera() : Camera(Vector(0,0,1), Vector(), Vector(0, 1, 0), 40, 0, 0) {

}

Camera* Camera::create(string description) {
    
    stringstream iss(description);
    char seperator = '|';
    Vector lookfrom = Utils::decodeVector(iss, seperator);
    Vector target = Utils::decodeVector(iss, seperator);
    Vector up = Utils::decodeVector(iss, seperator);
    double theta = Utils::decodeDouble(iss, seperator) * M_PI / 180.;
    double phi = Utils::decodeDouble(iss, seperator);
    double dist = Utils::decodeDouble(iss, seperator);
    return new Camera();
}

*/

Camera::Camera(Vector lookfrom, Vector lookat, Vector vup, double vfov, double aspectRatio, double aperture, double dist) {
    this->lookfrom = lookfrom;
    this->lookat = lookat;
    this->vup = vup;
    this->vfov = vfov;
    this->aspectRatio = aspectRatio;
    this->aperture = aperture;
    this->dist = dist;
    
    auto theta = vfov * M_PI / 180;
    auto h = tan(theta/2);
    viewport_height = 2.0 * h;
    viewport_width = aspectRatio * viewport_height;

    w = (lookfrom - lookat).getNormalized();
    u = vup.cross(w).getNormalized();
    v = w.cross(u);

    horizontal = dist * viewport_width * u;
    vertical = dist * viewport_height * v;
    lowerLeftCorner = lookfrom - horizontal/2 - vertical/2 - dist*w;
    lensRadius = aperture / 2;
}

Camera::Camera() {

}
    
Camera::~Camera() {

}

Coord::Coord(Vector lookfrom, Vector lookat, Vector vup, double vfov, double aspectRatio, double aperture, double dist) {
    this->lookfrom = lookfrom;
    this->lookat = lookat;
    this->vup = vup;
    this->vfov = vfov;
    this->aspectRatio = aspectRatio;
    this->aperture = aperture;
    this->dist = dist;
}

Coord::~Coord() {

}

Camera* Camera::create(string description) {
    
    stringstream iss(description);
    char seperator = '|';
    Vector lookfrom = Utils::decodeVector(iss, seperator);
    Vector lookat = Utils::decodeVector(iss, seperator);
    Vector vup = Utils::decodeVector(iss, seperator);
    double vfov = Utils::decodeDouble(iss, seperator);
    double aspectRatio = Utils::decodeDouble(iss, seperator);
    double aperture = Utils::decodeDouble(iss, seperator);
    double dist = Utils::decodeDouble(iss, seperator);
    return new Camera(lookfrom, lookat, vup, vfov, aspectRatio, aperture, dist);
}


const Vector Camera::getPos() const {
    return lookfrom;
}

double random_double() {
    return rand() / (RAND_MAX + 1.0);
}

double random_double(double min, double max) {
    // Returns a random real in [min,max).
    return min + (max-min)*random_double();
}


Vector random_in_unit_disk() {
    while (true) {
        auto p = Vector(random_double(-1,1), random_double(-1,1), 0);
        if (p.scalarProduct(p) >= 1) continue;
        return p;
    }
}

Ray Camera::makeRay(const int &i, const int &j, const Image &im) {
    /*double u = j - im.getWidth() / 2., v = i - im.getHeight() / 2.;
    Vector dir = Vector(u, v, dist);
    dir.normalize();
    return Ray(lookfrom, dir);*/
    /*
    double normalized_i = (i / im.getWidth()) - 0.5;
    double normalized_j = (j / im.getWidth()) - 0.5;
    Vector image_point = normalized_i * right +
                            normalized_j * up +
                            lookfrom + target.getNormalized();
    Vector ray_direction = image_point - lookfrom;
    return Ray(lookfrom, ray_direction);*/

    double s = (j + random_double()) / (im.getHeight()-1), t = (i + random_double()) / (im.getWidth()-1);
    Vector rd = lensRadius * random_in_unit_disk();
    Vector offset = u * rd.getX() + v * rd.getY();
    Vector dir = lowerLeftCorner + s*horizontal + t*vertical - lookfrom - offset;
    return Ray(lookfrom + offset, dir.getNormalized());

}

Camera &Camera::operator=(const Camera &cam) {
    this->lookfrom = cam.lookfrom;
    this->lookat = cam.lookat;
    this->vup = cam.vup;
    this->vfov = cam.vfov;
    this->aspectRatio = cam.aspectRatio;
    this->aperture = cam.aperture;
    this->dist = cam.dist;
    
    auto theta = vfov * M_PI / 180;
    auto h = tan(theta/2);
    viewport_height = 2.0 * h;
    viewport_width = aspectRatio * viewport_height;

    w = (lookfrom - lookat).getNormalized();
    u = vup.cross(w).getNormalized();
    v = w.cross(u);

    horizontal = dist * viewport_width * u;
    vertical = dist * viewport_height * v;
    lowerLeftCorner = lookfrom - horizontal/2 - vertical/2 - dist*w;
    lensRadius = aperture / 2;
    return *this;
}

Camera operator+(Camera &cam, const Coord &coord) {
    
    return  Camera(
            cam.lookfrom+coord.lookfrom, 
            cam.lookat+coord.lookat, 
            coord.vup == Vector() ? cam.vup : coord.vup, 
            cam.vfov+coord.vfov,
            cam.aspectRatio+coord.aspectRatio, 
            cam.aperture+coord.aperture, 
            cam.dist+coord.dist
            );
}

Camera& Camera::newPlacedCamera(Vector pos, Vector target, Vector up, double fov, double ar, double ap, double d) {
    if (up == Vector()) {
        up = vup;
    }
    return *this = Camera(lookfrom+pos, lookat+target, up, vfov+fov, aspectRatio+ar, aperture+ap, dist+d);
}


Camera::operator std::string() const {
    stringstream ss;
    ss << "Camera (position:" << lookfrom
    << ", lower left corner:" << lowerLeftCorner
    << ", horizontal:" << horizontal
    << ", vertical:" << vertical
    << ", u:" << u
    << ", v:" << v
    << ", w:" << w
    << ", lens ratio:" << lensRadius
    << ")";
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Camera& camera) {
    string text = camera;
    os << text;
    return os;
}