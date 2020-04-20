/*
*   @Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/

#ifdef __cplusplus

    #include "Point.hpp"
    #include "Vector.hpp"
    #include "Color.hpp"
    #include "Shape.hpp"

    class Sphere: public Shape {
        public:
            /*
             *  Constructs a Sphere with it's point and color.
             *  @param point: Point.
             *  @param color: Color.
            */
            Sphere(Point point, Color color);

            /*
             *  Deletes the Sphere.
            */
            ~Sphere();
    };

#endif