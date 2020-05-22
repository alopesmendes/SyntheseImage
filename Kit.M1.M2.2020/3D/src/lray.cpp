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
    
    Scene scene = Parser::parser(argc, argv);
    cout << scene << endl;
    scene.render();
    scene.buildImage();
    return 0;
}
