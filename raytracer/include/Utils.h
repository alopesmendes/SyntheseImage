/**
 *  @authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
 *  Has globals methods that can be used in other classes.
 *  @see Vector.h
 *  @see Color.h
 *  @see Material.h
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

            /**
             *  @brief Returns the clamp of value according to vmin and vmax.
             *  @param value: double
             *  @param vmin: const double&
             *  @param vmax: const double&
             *  @return double
            */
            static double clamp(double value, const double& vmin, const double& vmax);

            /**
             *  @brief Returns the value with gamma correction.
             *  Raises to power 1/2.2.
             *  @param value: double
             *  @return double
            */
            static double gammaCorrection(double value);

            /**
             *  @brief  Checks if the extenstion of the file is correct.
             *  @param file: string
             *  @param extension: string
             *  @return true if the file extension is the same as extension.
            */
            static bool checkIfExtenstionCorrect(string file, string extension);
            
    };
#endif