/*
*   @Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/


#ifndef __SPHERE_HPP__
#define __SPHERE_HPP__

    #include <iostream>
    #include "Point.h"
    #include "Vector.h"
    #include "Color.h"
    #include "Shape.h"
    #include <string>

    using namespace std;

    class Sphere: public Shape {
        private:
            double radius;
            
            friend std::ostream& operator<<(std::ostream&, const Sphere&);
        public:
            /*
             *  Constructs a Sphere with it's point and color.
             *  @param point: Point.
             *  @param color: Color.
            */
            Sphere(Point point, Color color, double radius);

            /*
             * Constructs a Sphere with it's description.
             * Will use Shape constructor.
             * @param description: string.
            */
            Sphere(string description);

            /*
             * Constructs default Sphere.
            */
            Sphere();

            /*
             * Read Shape.h comment.
            */
            //virtual Shape init(string description);

            /*
             *  Deletes the Sphere.
            */
            ~Sphere();
    };

#endif