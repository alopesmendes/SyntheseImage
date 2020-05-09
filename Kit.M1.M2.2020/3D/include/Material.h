/*
*   @Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/

#ifndef __MATERIAL_HPP__
#define __MATERIAL_HPP__
    #include <iostream>
    #include <string>
    #include <sstream>

    using namespace std;

    class Material {
        private:
            bool mirror;
            bool transparecy;
            friend std::ostream& operator<<(std::ostream&, const Material&);
        public:
            /*
            *   Constructs default Material.
            */
            Material(bool mirror = false, bool transparecy = false);

            /*
            *   Deletes Material.
            */
            ~Material();
            
            /*
            *   Return true if it's a mirror.
            *   @return bool
            */
            const bool isMirror() const;

            /*
            *   Return true if it's transparent.
            *   @return bool
            */
            const bool isTransparent() const;

            virtual operator std::string() const;
    };

#endif