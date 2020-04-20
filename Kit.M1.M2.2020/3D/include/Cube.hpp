/*
*   @Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/

#ifdef __cplusplus

    #include "Point.hpp"
    #include "Vector.hpp"
    #include "Color.hpp"
    #include "Shape.hpp"

    class Cube: public Shape {
        public:
            /*
             *  Constructs a Cube with it's point and color.
             *  @param point: Point.
             *  @param color: Color.
            */
            Cube(Point point, Color color);

            /*
             *  Deletes the cube.
            */
            ~Cube();
    };

#endif