#include <g3x.h>
#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <Point.hpp>
#include <Parser.hpp>

using namespace std;

void init() {
    Point point = Point(0., 0., 0.);
}

void quit() {

}

void draw() {

}

void anim() {

}


int main(int argc, char **argv) {
    //Parser::parser(argc, argv);
    g3x_InitWindow(*argv, 800, 600);
	g3x_SetInitFunction(init);
	g3x_SetExitFunction(quit);
	g3x_SetDrawFunction(draw);
    return 0;
}
