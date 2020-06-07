/**
 *  @authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
 *  Creates a graphic window that will represent the image in real time and will allow us to navigate the scene with the camera.
 *  @see Color.h
 *  @see Image.h
 *  @see Camera.h
*/

#ifndef __GRAPHICWINDOW_HPP__
#define __GRAPHICWINDOW_HPP__

    #pragma once

    #include <iostream>
    #include <string>
    #include <SDL2/SDL.h>
    #include "Color.h"
    #include "Image.h"
    #include "Camera.h"

    using namespace std;

    class Color;
    class Image;
    class Camera;
    class GraphicWindow {
        private:
            SDL_Window *window;
            SDL_Renderer *_render_;
            SDL_Texture *texture;
            int width;
            int height;

            friend std::ostream& operator<<(std::ostream&, const GraphicWindow&);

        public:
            /**
             *  @brief Constructs a Graphique Window with it's width and height.
             *  Uses SDL library and initialises the window, render and texture.
             *  @param width: int
             *  @param height: int
            */
            GraphicWindow(int w, int h);

            /**
             *  @brief Constructs a default Graphique Window.
            */
            GraphicWindow();

            /**
             *  @brief Deletes a Graphique Window.
            */
            ~GraphicWindow();

            /**
             *  @brief Will set the graphic window.
            */
            void render(const Image &img, const Camera& cam);

            /**
             *  @brief Sets the pixel.
            */
            void setPixel(int x, int y, const Color &color);
            
            /**
             *  @brief Updates the window.
            */
            void update();

            GraphicWindow &operator=(const GraphicWindow &g);
            virtual operator std::string() const;
    };

#endif 