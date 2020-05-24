#include "../include/StandardFigure.h"
#include <iostream>
#include <iterator>
#include <map>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
#include <cctype>
using namespace std;




StandardFigure resolveStandardFigure(string input) {
    /*static std::map<std::string, StandardFigure> sf;
    sf.insert(pair<string, StandardFigure>("camera", CAMERA));
    sf.insert(pair<string, StandardFigure>("ray", RAY ));
    sf.insert(pair<string, StandardFigure>("sphere", SPHERE));
    sf.insert(pair<string, StandardFigure>("cube", CUBE));*/
    static const map<string, StandardFigure> sf {
        { "image", IMAGE },
        { "camera", CAMERA },
        { "sphere", SPHERE },
        { "cube", CUBE },
        { "plane", PLANE }, 
        { "light", LIGHT },
        { "triangle", TRIANGLE},
        { "box", BOX},
        { "cone", CONE },
        { "cylinder", CYLINDER }, 
    };
    
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());
    transform(input.begin(), input.end(), input.begin(), ::tolower);

    auto itr = sf.find(input);
    if( itr == sf.end() ) {
        return INVALID;
    }
    return itr->second;
}