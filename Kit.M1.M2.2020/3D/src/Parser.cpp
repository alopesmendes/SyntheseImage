#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <Parser.hpp>

using namespace std;

void Parser::parser(int argc, char **argv) {
    int opt;
    while ((opt = getopt(argc, argv, "n:i:o:")) != EOF) {
        switch (opt) {
            case 'n':
                cout << "value of n is "<< optarg <<endl ;
                break;
            case 'i':
                cout << "value of i is "<< optarg <<endl ;
                break;
            case 'o':
                cout << "value of o is "<< optarg <<endl ;
                break;
            default:
                break;
        }
    }
    
}

