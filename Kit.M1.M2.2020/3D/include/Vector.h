/**
 *   @authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
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
            /**
             *   @brief Constructs a Vector with it's x, y, and z coordonates.
             *   @param x: double.
             *   @param y: double.
             *   @param z: double.
            */
            Vector(double x, double y, double z);

            /**
             *   @brief Constructs default Vector.
            */
            Vector() : Vector(0, 0, 0) {};

            /**
             *   @brief Deletes Vector.
            */
            ~Vector();

            /**
             *   @brief Calculates the scalar product.
             *   @param p: const Vector &
             *   @return double
            */
            double scalarProduct(const Vector &p);

            /**
             *   @brief Creates a cross version of this vector.
             *   @param v: const Vector&
             *   @return Vector
            */
            Vector cross(const Vector& v);
            
            /**
             *   @brief Normalize the Vector.
            */
            void normalize();

            /**
             *   @brief Returns the vector normalized.
             *   @return Vector.
            */
            Vector getNormalized();

            /**
             *   @brief Getter for x.
             *   @return double
            */
            const double getX() const;

            /**
             *   @brief Getter for y.
             *   @return double
            */
            const double getY() const;

            /**
             *   @brief Getter for z.
             *   @return double
            */
            const double getZ() const;

            Vector &operator=(const Vector &p);
            friend Vector operator+(const Vector&, const Vector&);
            friend Vector operator-(const Vector&, const Vector&);
            friend Vector operator-(const Vector&, const double&);
            friend Vector operator-(const double&, const Vector&);
            friend Vector operator*(const Vector&, const double&);
            friend Vector operator*(const double&, const Vector&);
            friend Vector operator/(const Vector&, const double&);
            friend Vector operator/(const double&, const Vector&);
            virtual operator std::string() const;

    };
    
#endif