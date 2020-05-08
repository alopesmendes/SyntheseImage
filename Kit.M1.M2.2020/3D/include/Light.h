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
            int level;
            Vector pos;
            double intensity;

            friend std::ostream& operator<<(std::ostream&, const Light&);
            
        public:
            /*
            *   Constructs a Light with it's level, position and intensity.
            *   @param pos: Vector
            *   @param intensity: double
            */
            Light(int level, Vector pos, double intensity);

            /*
            *   Constructs a Light with it's level and description.
            *   @param description: string
            */
            Light(int level, string description);

            /*
            *   Constructs default Light.
            */
            Light() : Light(0, Vector(), 0) {};

            /*
            *   Deletes Light
            */
            ~Light();

            /*
            *   Will determine the color according to the ligth.
            *   @param hit: const Hit&
            *   @param dist: const double&
            *   @return Color
            */
            Color colorIntensity(const Hit& hit, const double& dist);

            /*
            *   Getter for pos
            *   @return Vector.
            */
            Vector getPos() const;

            virtual operator std::string() const;
    };
    

#endif