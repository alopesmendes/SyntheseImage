#include "../include/Cylinder.h"
#include "../include/Utils.h"
#include <sstream>
#include <cmath>

Cylinder::Cylinder(Vector center, double radius, double height, Color color, Material material) {
    this->center = center;
    this->radius = radius;
    this->height = height;
    this->color = color;
    this->material = material;
}

Cylinder::Cylinder() : Cylinder(Vector(), 0, 0, Color()) {

}

Cylinder::~Cylinder() {

}

Cylinder *Cylinder::create(std::string description) {
    stringstream iss(description);
    char separator = '|';
    Vector center = Utils::decodeVector(iss, separator);
    double radius = Utils::decodeDouble(iss, separator);
    double height = Utils::decodeDouble(iss, separator);
    Color color = Utils::decodeColor(iss, separator);
    Material material = Utils::decodeMaterial(description, iss, separator, 4);
    return new Cylinder(center, radius, height, color, material);
}
/*
bool Cylinder::intersect(const Ray &ray, Hit &hit) {
    Vector dir = ray.getDirection();
    Vector pos = ray.getOrigin();
    double a = (dir.getX() * dir.getX()) + (dir.getZ() * dir.getZ());
    double b = 2*(dir.getX()*(pos.getX()-center.getX()) + dir.getZ()*(pos.getZ()-center.getZ()));
    double c = (pos.getX() - center.getX()) * (pos.getX() - center.getX()) + (pos.getZ() - center.getZ()) * (pos.getZ() - center.getZ()) - (radius*radius);
    
    double delta = b*b - 4*(a*c);
	if(fabs(delta) < 0.001) {
        return false;
    } 
    if(delta < 0.0)  {
        return false;
    } 
    
    double t1 = (-b - sqrt(delta))/(2*a);
    double t2 = (-b + sqrt(delta))/(2*a);
    double t;
    
    if (t1>t2) t = t2;
    else t = t1;
    
    double r = pos.getY() + t*dir.getY();
    
    if ((r >= center.getY()) and (r <= center.getY() + height)) {
        hit.t = t;
        hit.pos = hit.pos = ray.getOrigin() + ray.getDirection()*hit.t;
        hit.shape = this;
        hit.normal = Vector(hit.pos.getX()-center.getX(), 0 ,hit.pos.getZ()-center.getZ()).getNormalized();
        return t;
    }
    return false;
}
*/

bool Cylinder::intersect(const Ray &ray, Hit &hit) {
// translate the ray origin
	Vector origin = ray.getOrigin(), dir = ray.getDirection();
	Vector p0 (origin.getX()-center.getX(), origin.getY()-center.getY(), origin.getZ()-center.getZ());

	// coefficients for the intersection equation
	// got them mathematically intersecting the line equation with the cylinder equation
	double a = dir.getX()*dir.getX()+dir.getZ()*dir.getZ();
	double b = dir.getX()*p0.getX() +dir.getZ()*p0.getZ();
	double c = p0.getX()*p0.getX()+p0.getZ()*p0.getZ()-radius*radius;

	double delta = b*b - a*c;

	//use epsilon because of computation errors between doubles
	double epsilon = 0.00000001;

	// delta < 0 means no intersections
	if (delta < epsilon)
		return false;

	// nearest intersection
	double t = (-b - sqrt (delta))/a;

	// t<0 means the intersection is behind the ray origin
	// which we don't want
	if (t<=epsilon)
		return false;

	
	double y = p0.getY()+t*dir.getY();

	// check if we intersect one of the bases
	if (y > height+epsilon || y < -epsilon) {
		Hit h;
		Vector center2 = Vector(center.getX(), center.getY()+height, center.getZ());
		bool b1 = intersect_base (ray, center2, h);
		if(b1) t=h.t;
		bool b2 = intersect_base (ray, center, h);
		if(b2 && h.t>epsilon && t>=h.t)
			t=h.t;
		h.t = t;
		hit = h;
		return b1 || b2;
	}
	hit.t = t;
	hit.pos = origin+t*dir;
	hit.normal = normal_in(hit.pos);
	hit.shape = this;

	return true;


}

// Calculate intersection with the base having center c
// We do this by calculating the intersection with the plane
// and then checking if the intersection is within the base circle
bool Cylinder::intersect_base (const Ray& ray, const Vector& c, Hit &hit)
{
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

// Calculate the normal in a Vector on the surface
// it is a vertical vector in the bases and a vector
// having the direction of the vector from the axis to the Vector
Vector Cylinder::normal_in(const Vector& p)
{
	// Vector is on one of the bases
	if (p.getX()<center.getX()+radius && p.getX()>center.getX()-radius && p.getZ()<center.getZ()+radius && p.getZ()>center.getZ()-radius)
	{
		double epsilon = 0.00000001;
		if (p.getY() < center.getY()+height+epsilon && p.getY()>center.getY()+height-epsilon){
			return Vector (0,1,0);
		}
		if (p.getY() < center.getY()+epsilon && p.getY()>center.getY()-epsilon){
			return Vector (0,-1,0);
		}
	}

	// Vector is on lateral surface
 	Vector c0 (center.getX(), p.getY(), center.getZ());
 	Vector v = p-c0;
 	v.normalize();
 	return v;
}


Cylinder::operator std::string() const {
    stringstream ss;
    ss << "Cylinder (center:" << center
    << ", radius:" << radius
    << ", height:" << height
    << ", " << color
    << ", " << material
    << ")";
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const Cylinder &cylinder) {
    string text = cylinder;
    os << text;
    return os;
}