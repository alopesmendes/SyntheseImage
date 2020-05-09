/*
*   @Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/

#ifndef __IMAGE_HPP__
#define __IMAGE_HPP__

    #include <iostream>
    #include <string>
    #include <sstream>
    #include "Color.h"

    using namespace std;

    class Image {
        private:
            int width, height;
            Color bg;
            Color* pixels;

            friend std::ostream& operator<<(std::ostream&, const Image&);
        
        public:
            /*
            *   Constructs a Image with it's width and height.
            *   Will set all pixels to Color() by default.
            */
            Image(int width, int height, const Color& bg = Color());

            /*
            *   Constructs a Image with it's description
            *   @param description: string
            */
            Image(string description);

            /*
            *   Constructs default Image.
            */
            Image();

            /*
            *   Deletes Image.
            */
            ~Image();

            /*
            *   Sets the pixel at the position x, y to the following color.
            *   @param x: int
            *   @param y: int
            *   @param color: Color
            */
            void setPixel(int x, int y, Color color);

            /*
            *   Getter for width.
            *   @return int
            */
            const int getWidth() const;

            /*
            *   Getter for height.$
            *   @return int
            */
            const int getHeight() const;
            
            /*
            *   Getter for background color.
            *   @return Color.
            */
            const Color backgroundColor() const;

            /*
            *   Saves all the pixels of the image in the file
            *   @param image: const Image&
            *   @param file: const string&
            */             
            static void save(const Image& image, const string& file);
            
            Image &operator=(const Image &c);
            virtual operator std::string() const;

    };


#endif