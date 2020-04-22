/*
*   @Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/

#ifndef __CUBE_HPP__
#define __CUBE_HPP__

    #include "Point.h"
    #include "Vector.h"
    #include "Color.h"
    #include "Shape.h"

    class Cube: public Shape {
        public:
            /*
             *  Constructs a Cube with it's point and color.
             *  @param point: Point.
             *  @param color: Color.
            */
            Cube(Point point, Color color);

            /*
             * Constructs default Cube.
            */
            Cube();

            /*
             *  Deletes the cube.
            */
            ~Cube();
    };

#endif