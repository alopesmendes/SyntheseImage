/**
 *  @authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
 *  Will create a Materal informating us of the accurate texture of the shape.
*/

#ifndef __MATERIAL_HPP__
#define __MATERIAL_HPP__
    #include <iostream>
    #include <string>

    #include "Color.h"

    using namespace std;

    class Color;
    class Material {
        private:
            friend std::ostream& operator<<(std::ostream&, const Material&);

            friend std::istream& operator>>(std::istream&, Material&);
        public:
            bool mirror;
            bool transparecy;
            Color ambience;
            Color diffuse;
            Color specular;
            double specularExponent;

            /**
             *  @brief Constructs a Material with it's ambience, diffuse, specular and specularExponent.
             *  @param ambience: Color
             *  @param diffuse: Color
             *  @param specular: Color
             *  @param reflectance: Color
             *  @param specularExponent: double
             *  @param mirror: bool
             *  @param transparecy: bool
            */
            Material(Color ambience, Color diffuse, Color specular, double specularExponent, bool mirror, bool transparecy);

            /**
             *  @brief Constructs a default Material.
            */
            Material();

            /**
             *  @brief Deletes Material.
            */
            ~Material();
            
            /**
             *  @brief Return true if it's a mirror.
             *  @return bool
            */
            const bool isMirror() const;

            /**
             *  @brief Return true if it's transparent.
             *  @return bool
            */
            const bool isTransparent() const;

            virtual operator std::string() const;
    };

#endif