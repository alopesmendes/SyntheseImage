/*
*   @Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/

#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

    #include <iostream>
    #include <string>

    using namespace std;
    
    class Vector {
        private:
            double x, y, z;

            friend std::ostream& operator<<(std::ostream&, const Vector&);
        public:
            /*
            *   @brief Constructs a Vector with it's x, y, and z coordonates.
            *   @param x: double.
            *   @param y: double.
            *   @param z: double.
            */
            Vector(double x, double y, double z);

            /*
            *   @brief Constructs default Vector.
            */
            Vector() : Vector(0, 0, 0) {};

            /*
            *   @brief Deletes Vector.
            */
            ~Vector();

            /*
            *   @brief Calculates the scalar product.
            *   @param p: const Vector &
            *   @return double
            */
            double scalarProduct(const Vector &p);

            /*
            *   @brief Creates a cross version of this vector.
            *   @param v: const Vector&
            *   @return Vector
            */
            Vector cross(const Vector& v);
            
            /*
            *   @brief Normalize the Vector.
            */
            void normalize();

            /*
            *   @brief Returns the vector normalized.
            *   @return Vector.
            */
            Vector getNormalized();

            bool operator==(const Vector &p);
            bool operator!=(const Vector &p);
            Vector &operator=(const Vector &p);
            Vector operator+(const Vector &p);
            Vector operator-(const Vector &p);
            Vector operator-(double a);
            Vector operator*(double a);
            Vector operator/(double b);
            virtual operator std::string() const;

    };
    
#endif