/**
 *  @authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/


#ifndef __PLANE_HPP__
#define __PLANE_HPP__

    #include <iostream>
    #include <string>
    #include "Shape.h"
    #include "Vector.h"

    using namespace std;

    class Vector;
    class Shape;
    class Plane: public Shape {
        private:
            Vector pos;
            Vector normal;
            Color color;
            Material material;
            
            friend std::ostream& operator<<(std::ostream&, const Plane&);
        public:

            /**
             *  @brief Constructs a Plane with it's pos, normal, color and material.
             *  @param pos: Vector
             *  @param normal: Vector
             *  @param color: Color
             *  @param material: Material
            */
            Plane(Vector pos, Vector normal, Color color, Material material = Material());

            /**
             *  @brief Constructs default Plane.
            */
            Plane();

            /**
             *  @brief Deletes the Plane.
            */
            ~Plane();

            /**
             *  @brief Creates a Plane with it's description.
             *  The format of description should be:
             *  { pos | normal | color | material }
             *  { double double double | double double double | double double double | double double } 
             *  or
             *  { double double double | double double double | double double double | double }
             *  or
             *  { double double double | double double double | double double double } 
             *  @param description: string
             *  @return Plane*
            */
            static Plane* create(string description);


            virtual const Color getColor() const;
            virtual const Material getMaterial() const;
            virtual bool intersect(const Ray& ray, Hit& hit);

            virtual operator std::string() const;
    };

#endif