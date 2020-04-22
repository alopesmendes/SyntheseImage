#include <iostream>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include "../include/Parser.h"
#include "../include/Sphere.h"
#include "../include/StandardFigure.h"

using namespace std;

Parser::Parser(int level, string file, string imageName) {
    this->level = level;
    this->file = file;
    this->imageName = imageName;
}

Parser::~Parser() { }

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

void Parser::addShape(StandardFigure sf, string description, vector<Shape*>& shapes) {
    switch (sf) {
        case CAMERA:
            break;
        case RAY:
            break;
        case SPHERE:
  
            shapes.push_back(new Sphere(description));
            break;
        case CUBE:
            break;
        case INVALID:
            cout << "Invalid" << endl;
            break;
        default:
            break;
    }
}

void Parser::parser(int argc, char **argv, vector<Shape*>& shapes) {
    string line, figure, descritption;
    Parser parser = Parser::init(argc, argv, "n:i:o:");
    ifstream readFile(parser.file.c_str());

    while(getline(readFile, line)) {
        stringstream iss(line);
        getline(iss, figure, '{');
        getline(iss, descritption, '}');
        addShape(resolveStandardFigure(figure), descritption, shapes);
        
    }  
    readFile.close(); 
}


