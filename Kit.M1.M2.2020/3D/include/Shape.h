/*
*   @Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/


#ifndef __SHAPE_HPP__
#define __SHAPE_HPP__

    #include <string>
    #include "Point.h"
    #include "Color.h"

    using namespace std;

    class Shape {
        private:
            
            friend std::ostream& operator<<(std::ostream& os, const Shape& shape);
            
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
             * Constructs a Shape with it's description.
             * @param description: string.
            */
            Shape(string description);

            /*
             * Constructs a default Shape.
            */
            Shape();

            /*
             * Constructs a Shape via it's description.
             * @param description: string
            */
            //virtual Shape init(string description);

            /*
             * Deletes the Shape.
            */
            ~Shape();

    };

    

#endif