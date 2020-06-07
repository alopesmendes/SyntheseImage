/**
 *  @authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
 *  Will generate a Cylinder that implements Shape.
 *  And will verify if a ray intersect this shape.
 *  @see Vector.h
 *  @see Shape.h
*/


#ifndef __CYLINDRE_HPP__
#define __CYLINDRE_HPP__

    #include <iostream>
    #include <string>
    #include "Shape.h"
    #include "Vector.h"

    using namespace std;
    
    class Shape;
    class Vector;
    class Cylinder : public Shape {
        private:
            Vector center;
            double radius;
            double height;
            friend std::ostream& operator<<(std::ostream&, const Cylinder&);

            Vector normal_in(const Vector &p);

            bool intersect_base(const Ray& ray, const Vector &c, Hit &hit);

        public:

            /**
             *  @brief Constructs a Cylinder with it's center, radius, height, color and material.
             *  @param center: Vector
             *  @param radius: double
             *  @param height: double
            */
            Cylinder(Vector center, double radius, double height, Color color, Material material = Material());

            /**
             *  @brief Constructs default Cylinder.
            */
            Cylinder(/* args */);

            /**
             *  @brief Deletes a Cylinder.
            */
            ~Cylinder();

            /**
             *  @brief Creates a Cylinder with it's description.
             *  The format of description should be:
             *  { center | radius | height | color  | material }
             *  { double double double | double | double | double double double | double double double | double | double}
             *  or
             *  { double double double | double | double | double double double | double double double | double }
             *  or
             *  { double double double | double | double | double double double | double double double }
             *  @param description: string
             *  @return Cylinder*
            */
            static Cylinder* create(string description);

            virtual bool intersect(const Ray& ray, Hit& hit);

            virtual operator std::string() const;
    };

#endif