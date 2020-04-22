/*
*   @Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/

#ifndef __PARSER_HPP__
#define __PARSER_HPP__

    #include <iostream>
    #include <string>
    #include <vector>
    #include "Shape.h"
    #include "StandardFigure.h"

    using namespace std;

    class Parser {
        private:
            int level;
            string file;
            string imageName;

        public:
            /*
             * Constructs default Parser.
            */
            Parser(int level, string file, string imageName);

            /*
             * Deletes the Parser.
            */
            ~Parser();

            /*
             * Initiazes a Parser with it's parameters.
             * Will recuperate the level, file, imageName from the argc and argv.
             * The opts precise how to get those elements from the argc and argv.
             * @param argc: int.
             * @param argv: char **.
             * @return: Parser.
            */
            static Parser init(int argc, char **argv, string opts);

            /*
             * Will determine which subclass of Shape it will add to shapes.
             * @param sf: StandardFigure.
             * @param description: string.
             * @param shapes: vector<Shape>&.
            */
            static void addShape(StandardFigure sf, string description, vector<Shape*>& shapes);

            /*
             * Parses the according arguments in the argv.
             * Will add the parse shape to shapes.
             * @param argc: int.
             * @param argv: char**.
             * @param shapes: vector<Shape>.
            */
            static void parser(int argc, char **argv, vector<Shape*>& shapes);
    };


#endif