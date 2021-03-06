/**
 *  @authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
 *  Will generate a Sphere that implements Shape.
 *  And will verify if a ray intersect this shape.
 *  @see Vector.h
 *  @see Shape.h
*/


#ifndef __SPHERE_HPP__
#define __SPHERE_HPP__

    #include <iostream>
    #include <string>
    #include "Shape.h"
    #include "Vector.h"

    using namespace std;

    class Vector;
    class Shape;
    class Sphere: public Shape {
        private:
            Vector pos;
            double radius;
            
            friend std::ostream& operator<<(std::ostream&, const Sphere&);
        public:
            /**
             *  @brief Constructs a Sphere with it's pos, color, radius and Material.
             *  @param pos: Vector
             *  @param color: Color
             *  @param radius: double
             *  @param material: Material
            */
            Sphere(Vector pos, Color color, double radius, Material material = Material());

            /**
             *  @brief Constructs default Sphere.
            */
            Sphere();

            /**
             *  @brief Deletes the Sphere.
            */
            ~Sphere() {};

            /**
             *  @brief Creates a Sphere with it's description.
             *  The format of description should be:
             *  { pos | color | radius | material }
             *  { double double double | double double double | double | double  double}
             *  or
             *  { double double double | double double double | double }
             *  @param description: string
             *  @return Sphere*
            */
            static Sphere* create(string description);

            virtual bool intersect(const Ray& ray, Hit& hit);

            virtual operator std::string() const;
    };

#endif