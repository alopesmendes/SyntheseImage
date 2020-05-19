/**
 *  @authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/

#ifndef __TRIANGLE_HPP__
#define __TRIANGLE_HPP__

    #include <iostream>
    #include <string>
    #include "Shape.h"

    using namespace std;
    class Triangle : public Shape{
        private:
            friend std::ostream& operator<<(std::ostream&, const Triangle&);
        public:
            /**
             *  @brief Constructs a default Triangle.
            */
            Triangle(/* args */);

            /**
             *  @brief Deletes the Triangle.
            */
            ~Triangle();

            virtual const Color getColor() const;
            virtual const Material getMaterial() const;
            virtual bool intersect(const Ray& ray, Hit& hit);
            virtual operator std::string() const;
    };
    
    

#endif