/**
 *  @authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
 *  Will create a Ray with it's origin and direction.
 *  This class will be use to see if a ray intersect a shape.
 *  @see Vector.h
*/

#ifndef __RAY_HPP__
#define __RAY_HPP__
    #include <iostream>
    #include <string>
    #include "Vector.h"

    using namespace std;

    class Vector;
    class Ray {
        private:
            Vector origin;
            Vector direction;

            friend std::ostream& operator<<(std::ostream&, const Ray&);
        public:
            /**
             *  @brief Constructs a Ray with it's origin and direction.
             *  @param origin: Vector
             *  @param direction: Vector
            */
            Ray(Vector origin, Vector direction);

            /**
             *  @brief Constructs a default Ray.
            */
            Ray();

            /**
             *  @brief Deletes Ray.
            */
            ~Ray();

            /**
             *  @brief Getter for origin.
             *  @return Vector
            */
            Vector getOrigin() const;

            /**
             *  @brief Getter for direction.
             *  @return Vector.
            */
            Vector getDirection() const;


            virtual operator std::string() const;
    };
#endif