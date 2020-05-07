/*
*   @Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/

#ifndef __POINT_HPP__
#define __POINT_HPP__

    #include <iostream>
    #include <string>
    #include <sstream>

    using namespace std;

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
            
            /*
            *   Constructs default Point.
            */
            Point() : Point(0, 0, 0) {};

            /*
             *  Deletes Point.
            */
            ~Point();

            /*
            *   Getter for x
            *   @return double.
            */
            double getX() const;

            /*
            *   Getter for y
            *   @return double.
            */
            double getY() const;

            /*
            *   Getter for z
            *   @return double.
            */
            double getZ() const;

            Point &operator=(const Point &p);

            virtual operator std::string() const;

    };


#endif