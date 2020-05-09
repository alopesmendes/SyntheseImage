#include "../include/Image.h"
#include <fstream>
#include <cmath>

Image::Image(int width, int height, const Color& color) {
    this->width = width;
    this->height = height;
    this->bg = color;
    pixels = new Color[width * height];
    for (int i = 0; i < width * height; ++i)
        pixels[i] = color;
}

Image::Image(string description) {
    string line;
    double width, height;
    double r, g, b;
    stringstream iss(description);
    getline(iss, line, '|');
    stringstream issDim(line);
    issDim >> width >> height;
    getline(iss, line, '|');
    stringstream issColor(line);
    issColor >> r >> g >> b;
    new (this) Image(width, height, Color(r, g, b));
}

Image::Image() : width(0), height(0), bg(Color()), pixels(nullptr) {

}

Image::~Image() {
    if(pixels != NULL) { 
        delete []pixels; 
    }
}

const int Image::getWidth() const {
    return width;
}

const int Image::getHeight() const {
    return height;
}

const Color Image::backgroundColor() const {
    return bg;
}

void Image::setPixel(int x, int y, Color color) {
    if(x * width + y > width * height) {
        return;
    }
    pixels[(height - x - 1) * width + y] = color;
}

void Image::save(const Image& image, const string& file) {
    if (image.width == 0 || image.height == 0) { fprintf(stderr, "Can't save an empty image\n"); return; }
    std::ofstream ofs;
    try {
        ofs.open(file.c_str(), std::ios::binary); // need to spec. binary mode for Windows users
        if (ofs.fail()) throw("Can't open output file");
        ofs << "P6\n" << image.width << " " << image.height << "\n255\n";
        unsigned char r, g, b;
        // loop over each pixel in the image, clamp and convert to byte format
        for (int i = 0; i < image.width * image.height; ++i) {
            r = min(255., max(0., pow(image.pixels[i].getRed(), 1/2.2)));
            g = min(255., max(0., pow(image.pixels[i].getGreen(), 1/2.2)));
            b = min(255., max(0., pow(image.pixels[i].getBlue(), 1/2.2)));
            ofs << r << g << b;
        }
        ofs.close();
    } catch (const char *err) {
        fprintf(stderr, "%s\n", err);
        ofs.close();
    }
}

Image &Image::operator=(const Image &im) {
    width = im.width;
    height = im.height;
    bg = im.bg;
    if(pixels != NULL) { 
        delete []pixels; 
    }
    pixels = new Color[im.width * im.height];
    for (int i = 0; i < im.width * im.height; i++) {
        pixels[i] = im.bg;
    }
    
}

Image::operator std::string() const {
    stringstream ss;
    ss << "Image (width:" << width 
    << ", height:" << height
    << ", background:" << bg << ")";
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Image& image) {
    string text = image;
    os << text;
    return os;
}