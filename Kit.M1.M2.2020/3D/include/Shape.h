/*
*   @Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/


#ifndef __SHAPE_HPP__
#define __SHAPE_HPP__
    #include <iostream>
    #include <string>
    #include <sstream>
    #include "Vector.h"
    #include "Color.h"
    #include "Ray.h"
    #include "Hit.h"
    #include "Material.h"

    using namespace std;
    
    class Hit;
    class Shape {
        private:
            
            friend std::ostream& operator<<(std::ostream& os, const Shape& shape);
            
        protected:
            Vector point;
            Color color;
            Material material;
        public:
            /* 
             *  Constructs a Shape with it's point and color.
             *  @param point: Vector.
             *  @param color: Color.
            */
            Shape(Vector point, Color color, Material material = Material());

            /*
             * Constructs a Shape with it's description.
             * @param description: string.
            */
            Shape(string description);

            /*
             * Constructs a default Shape.
            */
            Shape();

            /*
             * Deletes the Shape.
            */
            ~Shape() {};
            
            const Color getColor() const;

            /*
            *   Getter for material.
            *   @return Material
            */
            const Material getMaterial() const;

            /*
            *   Checks if the ray intersect with our shape.
            *   @param ray: Ray
            *   @param Hit: Hit&
            *   @return bool
            */
            virtual bool intersect(const Ray& ray, Hit& hit) = 0;

            virtual operator std::string() const;

    };

    

#endif