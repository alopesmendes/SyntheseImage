/*
*   @Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/

#ifndef __HIT_HPP__
#define __HIT_HPP__

    #include <iostream>
    #include <string>
    #include <sstream>
    #include "Vector.h"
    #include "Color.h"
    #include "Shape.h"

    using namespace std;

    class Shape;
    class Vector;
    class Color;
    class Hit {
        private:
            friend std::ostream& operator<<(std::ostream&, const Hit&);

        public:
            Vector pos;
            Vector normal;
            double t;
            Shape* shape;

            /*
            *   @brief Constructs default Hit.
            */
            Hit();

            /*
            *   @brief Deletes Hit
            */
            ~Hit();

            Hit &operator=(const Hit &p);

            virtual operator std::string() const;
    };
    
#endif