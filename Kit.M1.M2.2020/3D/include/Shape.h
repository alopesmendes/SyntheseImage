/**
 *  @authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
 *  Will create an `interface` Shape that will regroup every shape.
 *  Every shape as it's surface color and material.
 *  This class will use the method intersect to check if there's a ray intersection.
 *  @see Color.h
 *  @see Ray.h
 *  @see Hit.h
 *  @see Material.h
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