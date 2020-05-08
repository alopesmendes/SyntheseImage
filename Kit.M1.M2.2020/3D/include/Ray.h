/*
*   @Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/

#ifndef __RAY_HPP__
#define __RAY_HPP__
    #include <iostream>
    #include <string>
    #include <sstream>
    #include "Vector.h"
    #include "Vector.h"

    using namespace std;

    class Ray {
        private:
            Vector origin;
            Vector direction;

            friend std::ostream& operator<<(std::ostream&, const Ray&);
        public:
            /*
            *   Constructs a Ray with it's origin and direction.
            *   @param origin: Vector
            *   @param direction: Vector
            */
            Ray(Vector origin, Vector direction);

            /*
            *   Constructs a default Ray.
            */
            Ray() : Ray(Vector(), Vector()) {};

            /*
            *   Deletes Ray.
            */
            ~Ray();

            /*
            *   Getter for origin.
            *   @return Vector
            */
            Vector getOrigin() const;

            /*
            *   Getter for direction.
            *   @return Vector.
            */
            Vector getDirection() const;


            virtual operator std::string() const;
    };
#endif