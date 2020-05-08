/*
*   @Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/

#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

    #include <iostream>
    #include <string>
    #include <sstream>
    #include "Vector.h"

    using namespace std;

    class Camera {
        private:
            Vector pos;
            Vector target;
            double theta;
            double phi;
            double dist;

            friend std::ostream& operator<<(std::ostream&, const Camera&);
        public:
            /*
            *   Constructs a Camera with it's pos, target, theta, phi and distance.
            *   @param pos: Vector
            *   @param target: Vector
            *   @param theta: double
            *   @param phi: double
            *   @param dist: double
            */
            Camera(Vector pos, Vector target, double theta, double phi, double dist);
            
            /*
            *   Constructs a Camera with it's description.
            *   @param description: string
            */
            Camera(string description);

            /*
            *   Constructs a default Camera.
            */
            Camera() : Camera(Vector(), Vector(), 0, 0, 0) {};

            /*
            *   Deletes Camera.
            */
            ~Camera();

            /*
            *   Getter for pos.
            *   @return Vector
            */
            const Vector getPos() const;

            virtual operator std::string() const;
    };
    
    
#endif