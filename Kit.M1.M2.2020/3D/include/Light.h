/*
*   @Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/

#ifndef __LIGHT_HPP__
#define __LIGHT_HPP__

    #include <iostream>
    #include <string>
    #include <sstream>
    #include "Point.h"
    #include "Color.h"
    #include "Hit.h"

    using namespace std;

    class Light {
        private:
            int level;
            Point pos;
            double intensity;

            friend std::ostream& operator<<(std::ostream&, const Light&);
            
        public:
            /*
            *   Constructs a Light with it's level, position and intensity.
            *   @param pos: Point
            *   @param intensity: double
            */
            Light(int level, Point pos, double intensity);

            /*
            *   Constructs a Light with it's level and description.
            *   @param description: string
            */
            Light(int level, string description);

            /*
            *   Constructs default Light.
            */
            Light() : Light(0, Point(), 0) {};

            /*
            *   Deletes Light
            */
            ~Light();

            /*
            *   Will determine the color according to the ligth.
            *   @param hit: const Hit&
            *   @param color: const Color&
            *   @return Color
            */
            Color colorIntensity(const Hit& hit, const Color& color);

            virtual operator std::string() const;
    };
    

#endif