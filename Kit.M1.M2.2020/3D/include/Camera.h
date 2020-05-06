/*
*   @Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/

#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

    #include <iostream>
    #include <string>
    #include <sstream>
    #include "Point.h"

    using namespace std;

    class Camera {
        private:
            Point pos;
            Point target;
            double theta;
            double phi;
            double dist;

            friend std::ostream& operator<<(std::ostream&, const Camera&);
        public:
            /*
            *   Constructs a Camera with it's pos, target, theta, phi and distance.
            *   @param pos: Point
            *   @param target: Point
            *   @param theta: double
            *   @param phi: double
            *   @param dist: double
            */
            Camera(Point pos, Point target, double theta, double phi, double dist);
            
            /*
            *   Constructs a Camera with it's description.
            *   @param description: string
            */
            Camera(string description);

            /*
            *   Constructs a default Camera.
            */
            Camera() : Camera(Point(), Point(), 0, 0, 0) {};

            /*
            *   Deletes Camera.
            */
            ~Camera();

            /*
            *   Getter for pos.
            *   @return Point
            */
            const Point getPos() const;

            virtual operator std::string() const;
    };
    
    
#endif