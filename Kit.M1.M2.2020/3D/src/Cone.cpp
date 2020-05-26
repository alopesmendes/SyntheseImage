#include "../include/Cone.h"
#include "../include/Utils.h"
#include <sstream>
#include <cmath>

Cone::Cone(Vector center, double radius, double height, Color color, Material material) {
    this->center = center;
    this->radius = radius;
    this->height = height;
    this->color = color;
    this->material = material;
    Vector p1 (center.getX()+radius, center.getY(), center.getZ());
	Vector p2 (center.getX(), center.getY()+height, center.getZ());
	double d = (p2-p1).norm(p2-p1);
	cosAlphaSq = height/d;
	sinAlphaSq = radius/d;
}

Cone::Cone() : Cone(Vector(), 0, 0, Color()) {
    cosAlphaSq = 0;
    sinAlphaSq = 0;
}

Cone::~Cone() {

}

Cone *Cone::create(std::string description) {
    stringstream iss(description);
    char separator = '|';
    Vector center = Utils::decodeVector(iss, separator);
    double radius = Utils::decodeDouble(iss, separator);
    double height = Utils::decodeDouble(iss, separator);
    Color color = Utils::decodeColor(iss, separator);
    Material material = Utils::decodeMaterial(description, iss, separator, 4);
    return new Cone(center, radius, height, color, material);
}

Vector Cone::normal_in(const Vector &p) {
    Vector c0 (center.getX(), p.getY(), center.getZ());
 	Vector c1 (center.getX(), center.getY()+height, center.getZ());

 	Vector v = p-center;
    v = Vector(v.getX(), 0, v.getZ());
 	v.normalize();

 	Vector n = Vector(
        v.getX()*height/radius,
        radius/height,
        v.getZ()*height/radius
    );

 	return n;
}

bool Cone::intersect_base(const Ray &ray, const Vector &c, Hit &hit) {
    Vector normal = normal_in (c);
	Vector p0 (ray.getOrigin().getX()-center.getX(), ray.getOrigin().getY()-center.getY(), ray.getOrigin().getZ()-center.getZ());
	double A = normal.getX();
	double B = normal.getY();
	double C = normal.getZ();
	double D = - (A*(c.getX()-center.getX()) +B*(c.getY()-center.getY())+C*(c.getZ()-center.getZ()));

	if (A*ray.getDirection().getX()+B*ray.getDirection().getY()+C*ray.getDirection().getZ()==0)
		return false;
	
	double dist = - (A*p0.getX()+B*p0.getY()+C*p0.getZ()+D)/(A*ray.getDirection().getX()+B*ray.getDirection().getY()+C*ray.getDirection().getZ());

	double epsilon = 0.00000001;
	if (dist < epsilon)
		return false;

	Vector p = Vector(
        p0.getX()+dist*ray.getDirection().getX(),
        p0.getY()+dist*ray.getDirection().getY(),
        p0.getZ()+dist*ray.getDirection().getZ()
    );
	if (p.getX()*p.getX()+p.getZ()*p.getZ()-radius*radius > epsilon)
		return false;

	hit.t = dist;
    hit.pos = ray.getOrigin()+hit.t*ray.getDirection();
    hit.normal = normal;
    hit.shape = this;
	return true;
}

bool Cone::intersect(const Ray &ray, Hit &hit) {
    // translate ray origin so that the cone vertex would be at the origin
	Vector p0 (ray.getOrigin().getX()-center.getX(), ray.getOrigin().getY()-center.getY()-height, ray.getOrigin().getZ()-center.getZ());

	// coefficients for the intersection equation
	// got them mathematically intersecting the line equation with the cone equation
	double a = cosAlphaSq*ray.getDirection().getX()*ray.getDirection().getX()+cosAlphaSq*ray.getDirection().getZ()*ray.getDirection().getZ()-sinAlphaSq*ray.getDirection().getY()*ray.getDirection().getY();
	double b = cosAlphaSq*ray.getDirection().getX()*p0.getX() +cosAlphaSq*ray.getDirection().getZ()*p0.getZ()-sinAlphaSq*ray.getDirection().getY()*p0.getY();
	double c = cosAlphaSq*p0.getX()*p0.getX()+cosAlphaSq*p0.getZ()*p0.getZ()-sinAlphaSq*p0.getY()*p0.getY();

	double delta = b*b - a*c;

	//use epsilon because of computation errors between doubles
	double epsilon = 0.00000001;

	// delta < 0 means no intersections
	if (delta < epsilon)
		return false;

	// nearest intersection
	hit.t = (-b - sqrt (delta))/a;

	// t<0 means the intersection is behind the ray origin
	// which we don't want
	if (hit.t<epsilon)
		return false;

	double y = p0.getY()+hit.t*ray.getDirection().getY();

	// if the intersection with the cone is lower than
	// the base of the cone (y<-height) or higher than the vertex (y>0)
	// it's not actually intersecting our cone
	// We use epsilon because of errors when doing operations with doubles
    if (y < -height-epsilon || y > epsilon)
		return false;

    hit.pos = ray.getOrigin()+hit.t*ray.getDirection();
    hit.normal = normal_in(hit.pos);
    hit.shape = this;
	return true;
}

Cone::operator std::string() const {
    stringstream ss;
    ss << "Cone (center:" << center
    << ", radius:" << radius
    << ", height:" << height
    << ", " << color
    << ", " << material
    << ")";
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const Cone &cone) {
    string text = cone;
    os << text;
    return os;
}