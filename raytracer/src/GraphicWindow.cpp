#include "../include/GraphicWindow.h"
#include "../include/Vector.h"
#include "../include/Image.h"
#include <SDL2/SDL.h>
#include <sstream>

GraphicWindow::GraphicWindow(int w, int h) {
    this->width = w;
    this->height = h;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cerr << "Error when initialising: " << SDL_GetError() << endl;
        return;
    }
    window = SDL_CreateWindow("RayTracing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);

    if (window == nullptr)
    {
        cerr << "Error when create window: " << SDL_GetError() << endl;
    }

    _render_ = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (_render_ == nullptr)
    {
        cerr << "Error when create renderer " << SDL_GetError() << endl;
    }

    texture = SDL_CreateTexture(_render_, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, width, height);
    if (texture == nullptr)
    {
        cerr << "Could not create texture " << SDL_GetError() << endl;
    }
    if (SDL_SetRenderDrawColor(_render_, 0, 0, 0, SDL_ALPHA_OPAQUE)) {
        cerr << "Error could not set the color for the drawing functions." << endl;
    }
    if (SDL_RenderClear(_render_)) {
        cerr << "Error could not clear." << endl;
    }
}

GraphicWindow::GraphicWindow() {
    this->width = 0;
    this->height = 0;
    this->window = nullptr;
    this->_render_ = nullptr;
    this->texture = nullptr;
}

GraphicWindow::~GraphicWindow()
{
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(_render_);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

GraphicWindow &GraphicWindow::operator=(const GraphicWindow &g)
{
    this->width = g.width;
    this->height = g.height;
    this->window = g.window;
    this->_render_ = g._render_;
    this->texture = g.texture;
    return *this;
}

void GraphicWindow::setPixel(int x, int y, const Color &color)
{
    if (SDL_SetRenderDrawColor(_render_, color.getRed(), color.getGreen(), color.getBlue(), SDL_ALPHA_OPAQUE) == -1) {
        cerr << "Error could not set the color for the drawing functions." << endl;
    }
    if (SDL_RenderDrawPoint(_render_, x, y) == -1) {
        cerr << "Error could not draw point in current render" << endl;
    }
}

void GraphicWindow::render(const Image &img, const Camera &cam) {
    Vector pos = cam.getPos();
    SDL_Rect location = {int(pos.getX()), int(pos.getY()), img.getWidth(), img.getHeight()};
    if (SDL_RenderSetViewport(_render_, &location) == -1) {
        cerr << "Error could not set camera." << endl;
    }
    if (SDL_UpdateTexture(texture, NULL, img.toIntArray(), width * sizeof(Uint32)) == -1) {
        cerr << "Error could not update texture is not valid." << endl;
    }
    if (SDL_RenderClear(_render_) == -1) {
        cerr << "Error could not clear." << endl;
    }
    
    if (SDL_RenderCopy(_render_, texture, NULL, NULL) == -1) {
        cerr << "Error could not copy texture into the current render." << endl;
    }
    SDL_RenderPresent(_render_);
}

void GraphicWindow::update() {
    
}

GraphicWindow::operator std::string() const {
    stringstream ss;
    ss << "Graphic Window (width:" << width
    << ", height:" << height
    << ")";
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const GraphicWindow &g) {
    string text = g;
    os << text;
    return os;
}