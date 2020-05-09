#include <iostream>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include "../include/Parser.h"
#include "../include/Camera.h"
#include "../include/Sphere.h"
#include "../include/StandardFigure.h"
#include "../include/Ray.h"
#include "../include/Image.h"

using namespace std;

Parser::Parser(int level, string file, string imageName) {
    this->level = level;
    this->file = file;
    this->imageName = imageName;
}

Parser::~Parser() { }

string Parser::getImageName() {
    return imageName;
}

Parser Parser::init(int argc, char **argv, string opts) {
    int opt;
    int level;
    string file;
    string imageName;
    while ((opt = getopt(argc, argv, opts.c_str())) != EOF) {
        switch (opt) {
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
    return Parser(level, file, imageName);
}

void Parser::addToScene(Parser parser, StandardFigure sf, string description, Scene& scene) {
    switch (sf) {
        case IMAGE:
            scene.addImage(Image(description));
            break;
        case CAMERA:
            scene.addCamera(Camera(description));
            break;
        case SPHERE:
            scene.addShape(sf, new Sphere(description));
            break;
        case LIGHT:
            scene.addLight(Light(description));
            break;
        case INVALID:
            cout << "Invalid" << endl;
            break;
        default:
            break;
    }
}

Parser Parser::parser(int argc, char **argv, Scene& scene) {
    string line, figure, descritption;
    Parser parser = Parser::init(argc, argv, "n:i:o:");
    ifstream readFile(parser.file.c_str());

    while(getline(readFile, line)) {
        stringstream iss(line);
        getline(iss, figure, '{');
        getline(iss, descritption, '}');
        addToScene(parser, resolveStandardFigure(figure), descritption, scene);
        
    }  
    readFile.close(); 
    return parser;
}


