/*
*   @Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/

#ifndef __POINT_HPP__
#define __POINT_HPP__

    #include <iostream>

    class Point {
        private:
            double x, y, z;

            friend std::ostream& operator<<(std::ostream&, const Point&);
        
        public:
            /*
             *  Constructs a Point with it's x, y, and z coordonates.
             *  @param x: double.
             *  @param y: double.
             *  @param z: double.
            */
            Point(double x, double y, double z);
            
            Point() : Point(0, 0, 0) {};

            /*
             *  Deletes Point.
            */
            ~Point();

    };


#endif