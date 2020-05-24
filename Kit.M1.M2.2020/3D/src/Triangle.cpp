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
    /*double u, v;
    #ifdef MOLLER_TRUMBORE 
        Vector v0v1 = v1 - v0; 
        Vector v0v2 = v2 - v0; 
        Vector pvec = ray.getDirection().cross(v0v2); 
        double det = v0v1.scalarProduct(pvec); 
    #ifdef CULLING 
        // if the determinant is negative the triangle is backfacing
        // if the determinant is close to 0, the ray misses the triangle
        if (det < kEpsilon) return false; 
    #else 
        // ray and triangle are parallel if det is close to 0
        if (fabs(det) < kEpsilon) return false; 
    #endif 
        double invDet = 1 / det; 
    
        Vector tvec = ray.getOrigin() - v0; 
        u = tvec.scalarProduct(pvec) * invDet; 
        if (u < 0 || u > 1) return false; 
    
        Vector qvec = tvec.cross(v0v1); 
        v = ray.getDirection().scalarProduct(qvec) * invDet; 
        if (v < 0 || u + v > 1) return false; 
    
        hit.t = v0v2.scalarProduct(qvec) * invDet; 
        hit.shape = this;
        hit.pos = ray.getOrigin() + ray.getDirection()*hit.t;
        hit.normal = Vector(u, v, 1 - u - v);
    
        return true; 
    #else 
        // compute plane's normal
        Vector v0v1 = v1 - v0; 
        Vector v0v2 = v2 - v0; 
        // no need to normalize
        Vector N = v0v1.cross(v0v2); // N 
        double denom = N.scalarProduct(N); 
    
        // Step 1: finding hit.pos
    
        // check if ray and plane are parallel ?
        double NdotRayDirection = N.scalarProduct(ray.getDirection()); 
        if (fabs(NdotRayDirection) < kEpsilon) // almost 0 
            return false; // they are parallel so they don't intersect ! 
    
        // compute d parameter using equation 2
        double d = N.scalarProduct(v0); 
    
        // compute hit.t (equation 3)
        hit.t = (N.scalarProduct(ray.getOrigin()) + d) / NdotRayDirection; 
        // check if the triangle is in behind the ray
        if (hit.t < 0) return false; // the triangle is behind 
    
        // compute the intersection point using equation 1
        hit.pos = ray.getOrigin() + hit.t * ray.getDirection(); 
    
        // Step 2: inside-outside test
        Vector C; // vector perpendicular to triangle's plane 
    
        // edge 0
        Vector edge0 = v1 - v0; 
        Vector vp0 = hit.pos - v0; 
        C = edge0.cross(vp0); 
        if (N.scalarProduct(C) < 0) return false; // hit.pos is on the right side 
    
        // edge 1
        Vector edge1 = v2 - v1; 
        Vector vp1 = hit.pos - v1; 
        C = edge1.cross(vp1); 
        if ((u = N.scalarProduct(C)) < 0)  return false; // hit.pos is on the right side 
    
        // edge 2
        Vector edge2 = v0 - v2; 
        Vector vp2 = hit.pos - v2; 
        C = edge2.cross(vp2); 
        if ((v = N.scalarProduct(C)) < 0) return false; // hit.pos is on the right side; 
    
        u /= denom; 
        v /= denom; 
        hit.shape = this;
        hit.normal = Vector(u, v, 1 - u - v);
    
        return true; // this ray hits the triangle 
    #endif */
    
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
    else // On a bien une intersection de droite, mais pas de rayon.
        return false;
    
    /*
    Vector N = (v1-v0).cross(v2-v0);
    N.normalize();
    double D= N.scalarProduct(v0);
    const double NdotRayDir = N.scalarProduct(ray.getDirection());

	if (NdotRayDir < 0.000001 && NdotRayDir > -0.000001) // no hit
		return false;

	const double t = (D - N.scalarProduct(ray.getOrigin())) / (NdotRayDir);
	const Vector i = ray.getOrigin() + ray.getDirection()*t; // hit point with plane

	// for an edge v0<->v1, we check to see if the cross product of that edge
	// vector (v1-v0) and the vector from v0 to the hit point points
	// in the same direction as the normal vector
	if ((v1-v0).cross(i - v0).scalarProduct(N) >= 0 &&
		(v2-v1).cross(i - v1).scalarProduct(N) >= 0 &&
		(v0-v2).cross(i - v2).scalarProduct(N) >= 0)
	{
		// i is within the triangle
		hit.shape = this;
        hit.pos = i;
        hit.t = t;
        if (NdotRayDir > 0)
			hit.normal = -1 * N
            ;
		else
			hit.normal = N;

		return true;
	}
    */

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