/*
*   @Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/

#ifndef __HIT_HPP__
#define __HIT_HPP__

    #include <iostream>
    #include <string>
    #include <sstream>
    #include "Point.h"
    #include "Vector.h"

    using namespace std;

    class Hit {
        private:
            friend std::ostream& operator<<(std::ostream&, const Hit&);

        public:
            Point pos;
            Vector normal;

            /*
            *   Constructs default Hit.
            */
            Hit();

            /*
            *   Deletes Hit
            */
            ~Hit();

            virtual operator std::string() const;
    };
    
#endif