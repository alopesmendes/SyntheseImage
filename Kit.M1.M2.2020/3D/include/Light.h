/**
 *  @authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
 *  Will create a Light to illumate the scene.
 *  The method getColor will return the right color according to the hit information.
 *  @see Vector.h
 *  @see Color.h
 *  @see Hit.h
 *  @see Scene.h
*/

#ifndef __LIGHT_HPP__
#define __LIGHT_HPP__

    #include <iostream>
    #include <string>
    #include "Vector.h"
    #include "Color.h"
    #include "Hit.h"
    #include "Scene.h"
    #include "Ray.h"

    using namespace std;

    class Vector;
    class Color;
    class Hit;
    class Scene;
    class Ray;
    class Light {
        private:
            Vector pos;
            double intensity;

            friend std::ostream& operator<<(std::ostream&, const Light&);
            
        public:
            /**
             *  @brief Constructs a Light with it's level, position and intensity.
             *  @param pos: Vector
             *  @param intensity: double
            */
            Light(Vector pos, double intensity);

            /**
             *  @brief Constructs default Light.
            */
            Light();

            /**
             *  @brief Deletes Light
            */
            ~Light();

            /**
             *  @brief Creates a Light with it's description.
             *  The format of description should be:
             *  { pos | intensity }
             *  { double double double | double }
             *  @param description: string
             *  @return Light*
            */
            static Light* create(string description);

            /**
             *  @brief Getter for intensity.
             *  @return double
            */
            const double getIntensity() const;

            /**
             *  @brief Getter for pos
             *  @return Vector.
            */
            Vector getPos() const;

            /**
             *  @brief Calculates the color according to the hit in the scene.
             *  @param scene: const Scene&
             *  @param hit: const Hit&
             *  @return Color
            */
            virtual Color getColor(const Scene& scene, const Ray& ray, const Hit& hit);

            virtual operator std::string() const;
    };
    

#endif