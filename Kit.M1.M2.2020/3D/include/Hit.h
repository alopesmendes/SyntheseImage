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
    class Hit {
        private:
            friend std::ostream& operator<<(std::ostream&, const Hit&);

        public:
            Vector pos;
            Vector normal;
            double t;
            Shape* shape;

            /*
            *   Constructs default Hit.
            */
            Hit();

            /*
            *   Deletes Hit
            */
            ~Hit();

            Hit &operator=(const Hit &p);

            virtual operator std::string() const;
    };
    
#endif