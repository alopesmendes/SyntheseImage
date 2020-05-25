/**
 *  @authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
 *  Will create a Materal informating us of the accurate texture of the shape.
*/

#ifndef __MATERIAL_HPP__
#define __MATERIAL_HPP__
    #include <iostream>
    #include <string>

    using namespace std;

    class Material {
        private:
            bool mirror;
            bool transparecy;
            friend std::ostream& operator<<(std::ostream&, const Material&);

            friend std::istream& operator>>(std::istream&, Material&);
        public:
            double ambience;
            double diffuse;
            double specular;
            double reflectance;
            int specularExponent;
            
            /**
             *  @brief Constructs a Material with it's ambience, diffuse, specular, refletance and specularExponent.
            */
            Material(bool mirror, bool transparecy);

            /**
             *  @brief Constructs default Material.
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