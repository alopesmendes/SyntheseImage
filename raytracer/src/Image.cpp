#include "../include/Image.h"
#include "../include/Utils.h"
#include <fstream>
#include <sstream>

Image::Image(int width, int height, const Color& bg) {
    this->width = width;
    this->height = height;
    this->bg = bg;
    pixels = new Color[width * height];
    for (int i = 0; i < width * height; ++i)
        pixels[i] = bg;
}

Image::Image() : width(0), height(0), bg(Color()), pixels(nullptr) {

}

Image::~Image() {
    if(pixels != NULL) { 
        delete []pixels; 
    }
}

Image* Image::create(string description) {
    string line;
    double width, height;
    double r, g, b;
    stringstream iss(description);
    getline(iss, line, '|');
    stringstream issDim(line);
    issDim >> width >> height;
    if (Utils::nthOccurrence(description, "|", 1) == -1) {
        return new Image(width, height);
    }
    Color color = Utils::decodeColor(iss, '|');
    return new Image(width, height, color);
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

Color Image::getPixelColor(int x, int y) {
    if(x * width + y > width * height) {
        return Color();
    }
    return pixels[(height - x - 1) * width + y];
}

const int *Image::toIntArray() const
{
    int *res = new int[width * height * sizeof(int)];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            res[j + i * width] = pixels[j + i * width].getRed() * 0x10000 + pixels[j + i * width].getGreen() * 0x100 + pixels[j + i * width].getBlue();
        }
    }
    return res;
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
            r = image.pixels[i].getRed();
            g = image.pixels[i].getGreen();
            b = image.pixels[i].getBlue();
            ofs << r << g << b;
        }
        ofs.close();
    } catch (const char *err) {
        fprintf(stderr, "%s\n", err);
        ofs.close();
    }
}

Image &Image::operator=(const Image &im) {
    this->width = im.width;
    this->height = im.height;
    this->bg = im.bg;
    if(this->pixels != NULL) { 
        delete [](this->pixels); 
    }
    this->pixels = new Color[im.width * im.height];
    for (int i = 0; i < im.width * im.height; ++i) {
        this->pixels[i] = im.bg;
    }
    return *this; 
    
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