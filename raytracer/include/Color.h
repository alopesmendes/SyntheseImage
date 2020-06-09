/**
 *  @authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
 *  Will define the Color for our world objects.
 *  The color must have three factors red, green and blue.
 *  They must be double values between 0 and 1.
 *  And gives access to this 3 factors from the getters in this class.
*/

#ifndef __COLOR_HPP__
#define __COLOR_HPP__

    #include <iostream>
    #include <string>
    
    using namespace std;
    class Color {
        private:
            double red, green, blue;

            friend std::ostream& operator<<(std::ostream&, const Color&);

            friend std::istream& operator>>(std::istream&, Color&);
        
        public:
            /**
            *   @brief Constructs a Color with it's red, green, and blue coordonates.
            *   @param red: double.
            *   @param green: double.
            *   @param blue: double.
            *   @param opacity: double.
            */
            Color(double red, double green, double blue);

            /**
             *  @brief Constructs by default a Color where every coordonate values 0.
            */
            Color();

            /**
             *  @brief Deletes Color.
            */
            ~Color();

            /**
             *  @brief Getter for red.
             *  @return red;
            */
            const double getRed() const;

            /**
             *  @brief Getter for blue.
             *  @return blue;
            */
            const double getBlue() const;

            /**
             *  @brief Getter for green.
             *  @return green;
            */
            const double getGreen() const;

            friend const Color operator*(const Color&, const double&);
            friend const Color operator*(const double&, const Color&);
            friend const Color operator*(const Color& a, const Color& b);
            friend const Color operator/(const Color&, const double&);
            friend const Color operator/(const double&, const Color&);
            friend const Color operator+(const Color&, const Color&);
            Color &operator+=(const Color &c);
            Color &operator=(const Color &c);

            virtual operator std::string() const;

    };


#endif