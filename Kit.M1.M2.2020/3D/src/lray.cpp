//#include <g3x.h>
#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/lray.h"

using namespace std;




int main(int argc, char **argv) {
    vector<Shape*> shapes;
    Parser::parser(argc, argv, shapes);
    for (auto i = shapes.begin(); i != shapes.end(); ++i) {
        cout << **i << endl;
    }
    return 0;
}
