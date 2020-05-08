#include "../include/Image.h"
#include <fstream>

Image::Image(int width, int height, const Color& color) {
    this->width = width;
    this->height = height;
    pixels = new Color[width * height];
    for (int i = 0; i < width * height; ++i)
        pixels[i] = color;
}

/*Image::Image() : width(0), height(0), pixels(nullptr) {

}*/

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
            r = min(255., max(0., image.pixels[i].getRed()));
            g = min(255., max(0., image.pixels[i].getGreen()));
            b = min(255., max(0., image.pixels[i].getBlue()));
            ofs << r << g << b;
        }
        ofs.close();
    } catch (const char *err) {
        fprintf(stderr, "%s\n", err);
        ofs.close();
    }
}

Image::operator std::string() const {
    stringstream ss;
    ss << "Image (width:" << width << ", height:" << height << ")";
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Image& image) {
    string text = image;
    os << text;
    return os;
}