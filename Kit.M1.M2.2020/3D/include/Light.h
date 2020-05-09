/*
*   @Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/

#ifndef __LIGHT_HPP__
#define __LIGHT_HPP__

    #include <iostream>
    #include <string>
    #include <sstream>
    #include "Vector.h"
    #include "Color.h"
    #include "Hit.h"

    using namespace std;

    class Light {
        private:
            Vector pos;
            double intensity;

            friend std::ostream& operator<<(std::ostream&, const Light&);
            
        public:
            /*
            *   Constructs a Light with it's level, position and intensity.
            *   @param pos: Vector
            *   @param intensity: double
            */
            Light(Vector pos, double intensity);

            /*
            *   Constructs a Light with it's level and description.
            *   @param description: string
            */
            Light(string description);

            /*
            *   Constructs default Light.
            */
            Light() : Light(Vector(), 0) {};

            /*
            *   Deletes Light
            */
            ~Light();

            /*
            *   Getter for intensity.
            *   @return double
            */
            const double getIntensity() const;

            /*
            *   Getter for pos
            *   @return Vector.
            */
            Vector getPos() const;

            virtual operator std::string() const;
    };
    

#endif