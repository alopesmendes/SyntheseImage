/**
 *  @authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
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
        public:
            /**
             *  @brief Constructs default Material.
            */
            Material(bool mirror = false, bool transparecy = false);

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