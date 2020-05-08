/*
*   @Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/

#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

    #include <iostream>
    #include <string>
    #include <sstream>
    #include "Point.h"

    using namespace std;
    
    class Vector {
        private:
            double x, y, z;

            friend std::ostream& operator<<(std::ostream&, const Vector&);
        public:
            /*
             *  Constructs a Vector with it's x, y, and z coordonates.
             *  @param x: double.
             *  @param y: double.
             *  @param z: double.
            */
            Vector(double x, double y, double z);

            /*
            *   Constructs a Vector from two points a and b.
            *   @param a: Point
            *   @param b: Point
            */
            Vector(const Point &a, const Point &b);

            /*
            *   Constructs default Vector.
            */
            Vector() : Vector(0, 0, 0) {};

            /*
             *  Deletes Vector.
            */
            ~Vector();

            /*
            *   Calculates the scalar product.
            *   @param p: const Vector &
            *   @return double
            */
            double scalarProduct(const Vector &p);
            
            /*
            *   Normalize the Vector.
            */
            void normalize();

            /*
            *   Returns the vector normalized.
            *   @return Vector.
            */
            Vector getNormalized();

            bool operator==(const Vector &p);
            bool operator!=(const Vector &p);
            Vector &operator=(const Vector &p);
            Vector operator+(const Vector &p);
            Point operator+(const Point &p);
            Vector operator-(const Vector &p);
            Vector operator*(double a);
            Vector operator/(double b);
            virtual operator std::string() const;

    };
    
#endif