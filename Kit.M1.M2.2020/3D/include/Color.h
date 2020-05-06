/*
*   @Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/

#ifndef __COLOR_HPP__
#define __COLOR_HPP__

    #include <iostream>
    #include <string>
    #include <sstream>

    using namespace std;

    class Color {
        private:
            unsigned char red, green, blue;

            friend std::ostream& operator<<(std::ostream&, const Color&);
        
        public:
            /*
             *  Constructs a Color with it's red, green, and blue coordonates.
             *  @param red: unsigned char.
             *  @param green: unsigned char.
             *  @param blue: unsigned char.
            */
            Color(unsigned char red, unsigned char green, unsigned char blue);

            /*
             * Constructs by default a Color.
            */
            Color();

            /*
             *  Deletes Color.
            */
            ~Color();

            /*
            *   Getter for red.
            *   @return red;
            */
            unsigned char getRed();

            /*
            *   Getter for blue.
            *   @return blue;
            */
            unsigned char getBlue();

            /*
            *   Getter for green.
            *   @return green;
            */
            unsigned char getGreen();

            virtual operator std::string() const;

    };


#endif