/*
*   @Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/

#ifndef __COLOR_HPP__
#define __COLOR_HPP__

    #include <iostream>

    class Color {
        private:
            double red, green, blue;

            friend std::ostream& operator<<(std::ostream&, const Color&);
        
        public:
            /*
             *  Constructs a Color with it's red, green, and blue coordonates.
             *  @param red: double.
             *  @param green: double.
             *  @param blue: double.
            */
            Color(double red, double green, double blue);

            /*
             * Constructs by default a Color.
            */
            Color();

            /*
             *  Deletes Color.
            */
            ~Color();
    };


#endif