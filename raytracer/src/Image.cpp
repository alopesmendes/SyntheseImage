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
    return bg * 3e+07;
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
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char r, g, b;
            r = Utils::clamp(Utils::gammaCorrection(pixels[j + i * width].getRed()), 0., 255.);
            g = Utils::clamp(Utils::gammaCorrection(pixels[j + i * width].getGreen()), 0., 255.);
            b = Utils::clamp(Utils::gammaCorrection(pixels[j + i * width].getBlue()), 0., 255.);
            res[j + i * width] = r * 0x10000 + g * 0x100 + b;
        }
    }
    return res;
}

void Image::savePPM(const Image &image, const std::string &file) {
    if (image.width == 0 || image.height == 0) { 
        fprintf(stderr, "Can't save an empty image\n"); 
        return;
    }
    std::ofstream ofs;
    try {
        ofs.open(file.c_str(), std::ios::binary); // need to spec. binary mode for Windows users
        if (ofs.fail()) throw("Can't open output file");
        ofs << "P6\n" << image.width << " " << image.height << "\n255\n";
        unsigned char r, g, b;
        // loop over each pixel in the image, clamp and convert to byte format
        for (int i = 0; i < image.width * image.height; ++i) {
            r = Utils::clamp(Utils::gammaCorrection(image.pixels[i].getRed()), 0., 255.);
            g = Utils::clamp(Utils::gammaCorrection(image.pixels[i].getGreen()), 0., 255.);
            b = Utils::clamp(Utils::gammaCorrection(image.pixels[i].getBlue()), 0., 255.);
            ofs << r << g << b;
        }
        ofs.close();
    } catch (const char *err) {
        fprintf(stderr, "%s\n", err);
        ofs.close();
    }
}

void Image::saveBMP(const Image &image, const std::string &file) {
    if (image.width == 0 || image.height == 0) {
        fprintf(stderr, "Can't save an empty image\n");
        return;
    }
    unsigned char bmpFileHeader[14] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
    unsigned char bmpInfoHeader[40] = {40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0};
    unsigned char bmpPad[3] = {0, 0, 0};

    int fileSize = 54 + 3 * image.width * image.height;
    bmpFileHeader[2] = (unsigned char)(fileSize);
    bmpFileHeader[3] = (unsigned char)(fileSize >> 8);
    bmpFileHeader[4] = (unsigned char)(fileSize >> 16);
    bmpFileHeader[5] = (unsigned char)(fileSize >> 24);

    bmpInfoHeader[4] = (unsigned char)(image.width);
    bmpInfoHeader[5] = (unsigned char)(image.width >> 8);
    bmpInfoHeader[6] = (unsigned char)(image.width >> 16);
    bmpInfoHeader[7] = (unsigned char)(image.width >> 24);
    bmpInfoHeader[8] = (unsigned char)(image.height);
    bmpInfoHeader[9] = (unsigned char)(image.height >> 8);
    bmpInfoHeader[10] = (unsigned char)(image.height >> 16);
    bmpInfoHeader[11] = (unsigned char)(image.height >> 24);

    FILE *f;
    f = fopen(file.c_str(), "wb");
    if (f != nullptr) {
        fwrite(bmpFileHeader, 1, 14, f);
        fwrite(bmpInfoHeader, 1, 40, f);
        std::vector<unsigned char> bgrPixels(image.width * image.height * 3);
        for (int i = 0; i < image.height * image.width; i++) {
            bgrPixels[i * 3] = Utils::clamp(Utils::gammaCorrection(image.pixels[i].getBlue()), 0., 255.);
            bgrPixels[i * 3 + 1] = Utils::clamp(Utils::gammaCorrection(image.pixels[i].getGreen()), 0., 255.);
            bgrPixels[i * 3 + 2] = Utils::clamp(Utils::gammaCorrection(image.pixels[i].getRed()), 0., 255.);
        }

        for (int i = 0; i < image.height; i++)
        {
            fwrite(&bgrPixels[0] + (image.width * (image.height - i - 1) * 3), 3, image.width, f);
            fwrite(bmpPad, 1, (4 - (image.width * 3) % 4) % 4, f);
        }
        fclose(f);
    }

}

void Image::save(const Image& image, const string& file) {
    if (Utils::checkIfExtenstionCorrect(file, "ppm")) {
        savePPM(image, file);
    } else if (Utils::checkIfExtenstionCorrect(file, "bmp")) {
        saveBMP(image, file);
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