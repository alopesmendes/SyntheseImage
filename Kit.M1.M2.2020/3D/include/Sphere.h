/*
*   @Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
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
            Vector point;
            Color color;
            Material material;
            double radius;
            
            friend std::ostream& operator<<(std::ostream&, const Sphere&);
        public:
            /*
            *   @brief Constructs a Sphere with it's point, color, radius and Material.
            *   @param point: Vector.
            *   @param color: Color.
            */
            Sphere(Vector point, Color color, double radius, Material material = Material());

            /*
            *   @brief Constructs default Sphere.
            */
            Sphere();

            /*
            *   @brief Deletes the Sphere.
            */
            ~Sphere() {};

            /*
            *   @brief Creates a Sphere with it's description.
            *   The format of description should be:
            *   { pos | color | radius | material }
            *   { double double double | double double double | double | double | double}
            *   or
            *   { double double double | double double double | double | double }
            *   or
            *   { double double double | double double double | double }
            *   @param description: string
            *   @return Sphere*
            */
            static Sphere* create(string description);

            virtual const Color getColor() const;
            virtual const Material getMaterial() const;
            virtual bool intersect(const Ray& ray, Hit& hit);

            virtual operator std::string() const;
    };

#endif