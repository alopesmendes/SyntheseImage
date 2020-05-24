/**
 *  @authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/


#ifndef __BOX_HPP__
#define __BOX_HPP__

    #include <iostream>
    #include <string>
    #include "Shape.h"
    #include "Vector.h"

    using namespace std;

    class Vector;
    class Shape;
    class Box: public Shape {
        private:
            Vector bmin;
            Vector bmax;
            Color color;
            Material material;
            
            friend std::ostream& operator<<(std::ostream&, const Box&);
        public:
            /**
             *  @brief Constructs a Box with it's bmin, color, radius and Material.
             *  @param bmin: Vector
             *  @param bmax: Vector
             *  @param color: Color
             *  @param material: Material
            */
            Box(Vector bmin, Vector bmax, Color color, Material material = Material());

            /**
             *  @brief Constructs default Box.
            */
            Box();

            /**
             *  @brief Deletes the Box.
            */
            ~Box();

            /**
             *  @brief Creates a Box with it's description.
             *  The format of description should be:
             *  { bmin | bmax | color  | material }
             *  { double double double | double double double | double double double | double | double}
             *  or
             *  { double double double | double double double | double double double | double }
             *  or
             *  { double double double | double double double | double double double }
             *  @param description: string
             *  @return Box*
            */
            static Box* create(string description);

            virtual bool intersect(const Ray& ray, Hit& hit);

            virtual operator std::string() const;
    };

#endif