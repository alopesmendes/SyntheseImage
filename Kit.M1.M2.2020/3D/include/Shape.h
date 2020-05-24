/**
 *  @authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
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
        
        protected:
            Color color;
            Material material;

        public:

            /**
             *  @brief Deletes the Shape.
            */
            ~Shape() {};
            
            /**
             *  @brief Getter for the color.
             *  @return Color.
            */
            virtual const Color getColor() const;

            /**
             *  @brief Getter for material.
             *  @return Material
            */
            virtual const Material getMaterial() const;

            /**
             *  @brief Checks if the ray intersect with our shape and saves it in hit.
             *  @param ray: const Ray&
             *  @param hit: Hit&
             *  @return bool
            */
            virtual bool intersect(const Ray& ray, Hit& hit) = 0;

            virtual operator std::string() const;

    };

    

#endif