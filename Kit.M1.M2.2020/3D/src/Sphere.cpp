#include "../include/Sphere.h"
#include <sstream>

int nthOccurrence(const std::string& str, const std::string& findMe, int nth);

Sphere::Sphere(Point point, Color color, double radius) : Shape(point, color) {
    this->radius = radius;
}

Sphere::Sphere() : Shape() { 
    this->radius = 0;
}

Sphere::Sphere(string description) : Shape(description) {
    int pos = nthOccurrence(description, "|", 2);
    string line = description.substr(pos + 1);
    stringstream iss(line);
    iss >> this->radius;

    cout << *this << endl;    
}

Sphere::~Sphere() { }

std::ostream& operator<<(std::ostream& os, const Sphere& sphere) {
    os << "Sphere (" << sphere.point 
    << ", " << sphere.color 
    << ", radius:" << sphere.radius << ")";
    return os;
}


int nthOccurrence(const std::string& str, const std::string& findMe, int nth)
{
    size_t  pos = 0;
    int     cnt = 0;

    while( cnt != nth )
    {
        pos+=1;
        pos = str.find(findMe, pos);
        if ( pos == std::string::npos )
            return -1;
        cnt++;
    }
    return pos;
}