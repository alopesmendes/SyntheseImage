/**
 *  @authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
 *  Will generate an Image by using the protocol to generate a ppm https://fr.wikipedia.org/wiki/Portable_pixmap
 *  The method save will construct the file ppm. Will need to use the setPixel to set a pixel color.
 *  @see Color.h 
*/

#ifndef __IMAGE_HPP__
#define __IMAGE_HPP__

    #include <iostream>
    #include <string>
    #include "Color.h"

    using namespace std;

    class Color;
    class Image {
        private:
            int width, height;
            Color bg;
            Color* pixels;

            friend std::ostream& operator<<(std::ostream&, const Image&);
        
        public:
            /**
             *  @brief Constructs a Image with it's width and height.
             *  Will set all pixels to bg by default.
             *  @param width: int
             *  @param height: int
             *  @param bg : const Color&
            */
            Image(int width, int height, const Color& bg = Color());

            /**
             *  @brief Constructs default Image.
            */
            Image();

            /**
             *  @brief Deletes Image.
            */
            ~Image();

            /**
             *  @brief Creates a Image with it's description.
             *  The format of description should be:
             *  { width height }
             *  { int int }
             *  @param description: string
             *  @return Image*
            */
            static Image* create(string description);

            /**
             *  @brief Sets the pixel at the position x, y to the following color.
             *  @param x: int
             *  @param y: int
             *  @param color: Color
            */
            void setPixel(int x, int y, Color color);

            /**
             *  @brief Gets the pixel color at the position x, y.
             *  @param x: int
             *  @param y: int
             *  @return: Color
            */
            Color getPixelColor(int x, int y);

            /**
             *  @brief Getter for width.
             *  @return int
            */
            const int getWidth() const;

            /**
             *  @brief Getter for height.
             *  @return int
            */
            const int getHeight() const;
            
            /**
             *  @brief Getter for background color.
             *  @return Color.
            */
            const Color backgroundColor() const;

            /**
             *  @brief Saves all the pixels of the image in the file in the format ppm.
             *  @param image: const Image&
             *  @param file: const string&
            */             
            static void save(const Image& image, const string& file);

            /**
             *  @brief Returns a int array of the image.
             *  @return: int*
            */
            const int *toIntArray() const;

            Image &operator=(const Image &c);
            virtual operator std::string() const;

    };


#endif