#include <iostream>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <stdlib.h>   
#include <getopt.h>
#include <cerrno>
#include <cstring>
#include "../include/Parser.h"
#include "../include/Camera.h"
#include "../include/Sphere.h"
#include "../include/Cube.h"
#include "../include/StandardFigure.h"
#include "../include/Ray.h"
#include "../include/Image.h"
#include "../include/Plane.h"
#include "../include/Triangle.h"
#include "../include/Cone.h"
#include "../include/Cylinder.h"
#include "../include/Utils.h"

using namespace std;

Parser::Parser(int level, string file, string imageName, int ps) {
    if (level <= 0) {
        cerr << "level was not purposed" << endl;
        exit(EXIT_FAILURE);
    }
    if (level < 1 || level > 3) {
        cerr << "level is not between 1 and 3" << endl;
        exit(EXIT_FAILURE);
    }
    if (!Utils::checkIfExtenstionCorrect(file, "txt")) {
        cerr << "input file format is not .txt" << endl;
        exit(EXIT_FAILURE);
    }
    if (!Utils::checkIfExtenstionCorrect(imageName, "ppm") && !Utils::checkIfExtenstionCorrect(imageName, "bmp")) {
        cerr << "output image name format is not .ppm or .bmp" << endl;
        exit(EXIT_FAILURE);
    }
    this->level = level;
    this->file = file;
    this->imageName = imageName;
    this->ps = ps;
}

Parser::~Parser() { }

string Parser::getImageName() {
    return imageName;
}

Parser Parser::init(int argc, char **argv, string opts) {
    int opt;
    int level = 0;
    string file = "";
    string imageName = "";
    int ps = 0;
    int this_option_optind = optind ? optind : 1;
    int option_index = 0;
    static struct option long_options[] = {
        {"ps",     required_argument, 0,  0 },
        {0,         0,                 0,  0 }
    };
    while ((opt = getopt_long_only(argc, argv, opts.c_str(), long_options, &option_index)) != EOF) {
        switch (opt) {
            case 0:
                if (long_options[option_index].name == "ps") {
                    ps = atoi(optarg);
                }
                break;
            case 'n':
                level = atoi(optarg);
                break;
            case 'i':
                file = optarg;
                break;
            case 'o':
                imageName = optarg;
                break;
            default:
                break;
        }
    }

    return Parser(level, file, imageName, ps);
}

void Parser::addToScene(Parser parser, StandardFigure sf, string description, Scene& scene) {
    switch (sf) {
        case IMAGE:
            scene.addImage((*Image::create(description)));
            break;
        case CAMERA:
            scene.addCamera((*Camera::create(description)));
            break;
        case LIGHT:
            scene.addLight((*Light::create(description)));
            break;
        case SPHERE:
            scene.addShape(sf, Sphere::create(description));
            break;
        case CUBE:
            scene.addShape(sf, Cube::create(description));
            break;
        case PLANE:
            scene.addShape(sf, Plane::create(description));
            break;
        case TRIANGLE:
            scene.addShape(sf, Triangle::create(description));
            break;
        case CONE:
            scene.addShape(sf, Cone::create(description));
            break;
        case CYLINDER:
            scene.addShape(sf, Cylinder::create(description));
            break;
        case INVALID:
            cout << "Invalid" << endl;
            break;
        default:
            break;
    }
}

Scene Parser::parser(int argc, char **argv) {
    string line, figure, descritption;
    Parser parser = Parser::init(argc, argv, "n:i:o:");
    Scene scene = Scene(parser.level, parser.file, parser.imageName, parser.ps);
    ifstream readFile(parser.file.c_str());

    if(!readFile.is_open()) {
        cerr << "unable to open: " << strerror(errno) << endl;
        exit(EXIT_FAILURE);
    }
   
    while(getline(readFile, line)) {
        stringstream iss(line);
        getline(iss, figure, '{');
        getline(iss, descritption, '}');
        addToScene(parser, resolveStandardFigure(figure), descritption, scene);
        
    }  
    readFile.close(); 
    return scene;
}


