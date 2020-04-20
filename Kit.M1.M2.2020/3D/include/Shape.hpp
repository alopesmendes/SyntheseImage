/*
*   @Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/

#ifdef __cplusplus

    #include "Point.hpp"
    #include "Color.hpp"

    class Shape {
        protected:
            Point point;
            Color color;
        public:
            /* 
             *  Constructs a Shape with it's point and color.
             *  @param point: Point.
             *  @param color: Color.
            */
            Shape(Point point, Color color);

            /*
             * Constructs a default Shape.
            */
            Shape();

            /*
             * Deletes the Shape.
            */
            virtual ~Shape();
    };

    

#endif