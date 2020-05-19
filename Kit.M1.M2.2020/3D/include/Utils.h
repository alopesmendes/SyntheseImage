/**
 *  @authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/

#ifndef __UTILS_HPP__
#define __UTILS_HPP__

    #include <iostream>
    #include <string>
    #include <sstream>
    #include "Vector.h"
    #include "Color.h"
    #include "Material.h"

    using namespace std;

    class Vector;
    class Color;
    class Material;
    class Utils {
        private:
            /**
             *  @brief Will decode iss according to the seperator and attribuate the 3 values to x, y, z.
             *  The format of has to be three doubles seperated by spaces. 
             *  @param iss: stringstream&
             *  @param separator: const char&
             *  @param x: double&
             *  @param y: double&
             *  @param z: double&
            */
            static void decode3double(stringstream& iss, const char& separator, double& x, double& y, double& z);
        public:
            /**
             *  @brief Will return the position of `nth` occurence of `findMe` in `str`.
             *  @brief If it does not find it it will return -1.
             *  @param: str.
             *  @param: str.
             *  @param: int.
             *  @return: size_t.
            */
            static size_t nthOccurrence(const string&, const string&, int);

            /**
             *  @brief Will decode iss according to the seperator and return a Vector.
             *  The format of has to be three doubles seperated by spaces. 
             *  @param iss: stringstream&
             *  @param separator: const char&
             *  @return Vector
            */
            static Vector decodeVector(stringstream& iss, const char& separator);

            /**
             *  @brief Will decode iss according to the seperator and return a Color.
             *  The format of has to be three doubles seperated by spaces. 
             *  @param iss: stringstream&
             *  @param separator: const char&
             *  @return Color
            */
            static Color decodeColor(stringstream& iss, const char& separator);

            /**
             *  @brief Will decode iss according to the seperator and return a Material.
             *  The format of has to be three doubles seperated by spaces. 
             *  @param description: const string&
             *  @param iss: stringstream&
             *  @param separator: const char&
             *  @param position: const int&
             *  @return Material
            */
            static Material decodeMaterial(const string& description, stringstream& iss, const char& separator, const int& position);

            /**
             *  @brief Will decode iss according to the seperator and return a double.
             *  The format of has only one double. 
             *  @param iss: stringstream&
             *  @param separator: const char&
             *  @return double
            */
            static double decodeDouble(stringstream& iss, const char& separator);
            
    };
#endif