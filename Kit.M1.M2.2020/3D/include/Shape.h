/*
*   @Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/


#ifndef __SHAPE_HPP__
#define __SHAPE_HPP__
    #include <iostream>
    #include <string>
    #include "Color.h"
    #include "Ray.h"
    #include "Hit.h"
    #include "Material.h"

    using namespace std;
    
    class Hit;
    class Color;
    class Material;
    class Ray;
    class Shape {
        private:
            
            friend std::ostream& operator<<(std::ostream& os, const Shape& shape);
            
        public:

            /*
            *   @brief Constructs a default Shape.
            */
            Shape();

            /*
            *   @brief Deletes the Shape.
            */
            ~Shape() {};
            
            /*
            *   @brief Getter for the color.
            *   @return Color.
            */
            virtual const Color getColor() const = 0;

            /*
            *   @brief Getter for material.
            *   @return Material
            */
            virtual const Material getMaterial() const = 0;

            /*
            *   @brief Checks if the ray intersect with our shape and saves it in hit.
            *   @param ray: const Ray&
            *   @param Hit: Hit&
            *   @return bool
            */
            virtual bool intersect(const Ray& ray, Hit& hit) = 0;

            virtual operator std::string() const;

    };

    

#endif