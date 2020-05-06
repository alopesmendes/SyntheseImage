/*
*   @Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/


#ifndef __SHAPE_HPP__
#define __SHAPE_HPP__

    #include <string>
    #include <sstream>
    #include "Point.h"
    #include "Color.h"
    #include "Ray.h"

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
             * Deletes the Shape.
            */
            ~Shape() {};

            /*
            *   Getter for Color.
            *   @return Color
            */
            const Color getColor() const;

            /*
            *   Checks if the ray intersect with our shape.
            *   @param ray: Ray
            *   @param dist: double
            */
            virtual bool intersect(const Ray& ray, double& dist) = 0;

            virtual operator std::string() const;

    };

    

#endif