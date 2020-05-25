/**
 *  @authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
 *  Will generate a Cone that implements a Shape.
 *  And will verify if a ray intersect this shape.
 *  @see Shape.h
 *  @see Vector.h
*/


#ifndef __CONE_HPP__
#define __CONE_HPP__

    #include <iostream>
    #include <string>
    #include "Shape.h"
    #include "Vector.h"

    using namespace std;
    
    class Shape;
    class Vector;
    class Cone : public Shape {
        private:
            Vector center;
            double radius;
            double height;
            friend std::ostream& operator<<(std::ostream&, const Cone&);
        public:

            /**
             *  @brief Constructs a Cone with it's center, radius, height, color and material.
             *  @param center: Vector
             *  @param radius: double
             *  @param height: double
            */
            Cone(Vector center, double radius, double height, Color color, Material material = Material());

            /**
             *  @brief Constructs default Cone.
            */
            Cone();

            /**
             *  @brief Deletes a Cone.
            */
            ~Cone();

            /**
             *  @brief Creates a Cone with it's description.
             *  The format of description should be:
             *  { center | radius | height | color  | material }
             *  { double double double | double | double | double double double | double double double | double | double}
             *  or
             *  { double double double | double | double | double double double | double double double | double }
             *  or
             *  { double double double | double | double | double double double | double double double }
             *  @param description: string
             *  @return Cone*
            */
            static Cone* create(string description);

            virtual bool intersect(const Ray& ray, Hit& hit);

            virtual operator std::string() const;
    };

#endif