/**
 *  @authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
 *  Will keep the intersection information as the point, the normal, t and the shape
 *  @see Vector.h
 *  @see Shape.h
*/
#ifndef __HIT_HPP__
#define __HIT_HPP__

    #include <iostream>
    #include <string>
    #include <sstream>
    #include "Vector.h"
    #include "Shape.h"

    using namespace std;

    class Shape;
    class Vector;
    class Hit {
        private:
            friend std::ostream& operator<<(std::ostream&, const Hit&);

        public:
            Vector pos;
            Vector normal;
            double t;
            Shape* shape;

            /**
             *  @brief Constructs default Hit.
            */
            Hit();

            /**
             *  @brief Deletes Hit
            */
            ~Hit();

            Hit &operator=(const Hit &p);

            virtual operator std::string() const;
    };
    
#endif