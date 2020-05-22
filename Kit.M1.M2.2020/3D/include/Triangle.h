/**
 *  @authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/

#ifndef __TRIANGLE_HPP__
#define __TRIANGLE_HPP__

    #include <iostream>
    #include <string>
    #include "Shape.h"
    #include "Vector.h"

    using namespace std;

    class Vector;
    class Shape;
    class Triangle : public Shape{
        private:
            Vector v0;
            Vector v1;
            Vector v2;
            friend std::ostream& operator<<(std::ostream&, const Triangle&);
        public:
            /**
             *  @brief Constructs a Triangle with it's v0, v1, v2, color and material.
             *  @param v0: Vector
             *  @param v1: Vector
             *  @param v2: Vector
             *  @param color: Color
             *  @param material: Material
            */
            Triangle(Vector v0, Vector v1, Vector v2, Color color, Material material = Material());

            /**
             *  @brief Constructs a default Triangle.
            */
            Triangle(/* args */);

            /**
             *  @brief Deletes the Triangle.
            */
            ~Triangle();

            /**
             *   @brief Creates a Triangle with it's description.
             *   The format of description should be:
             *   { v0 | v1 | v2 | color | radius | material }
             *   { double double double | double double double | double double double | double double double | double | double double}
             *   or
             *   { double double double | double double double | double double double | double double double | double }
             *   @param description: string
             *   @return Triangle*
            */
            static Triangle* create(string description);

            virtual const Color getColor() const;
            virtual const Material getMaterial() const;
            virtual bool intersect(const Ray& ray, Hit& hit);
            virtual operator std::string() const;
    };
    
    

#endif