//#include <g3x.h>
#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/lray.h"

using namespace std;




int main(int argc, char **argv) {
    /*auto value = new Value<Color>(Color());
    cout << *value << endl;*/
    
    Scene scene = Scene();
    Parser p = Parser::parser(argc, argv, scene);

    cout << scene << endl;
    scene.update();
    
    return 0;
}
