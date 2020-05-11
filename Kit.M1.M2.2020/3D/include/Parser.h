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
    #include "Scene.h"

    using namespace std;

    class Shape;
    class Scene;
    enum StandardFigure;
    class Parser {
        private:
            int level;
            string file;
            string imageName;
            int ps;

            /*
             * Constructs default Parser.
            */
            Parser(int level, string file, string imageName, int ps);

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
             * Will add elements to scene.
             * @param sf: StandardFigure.
             * @param description: string.
             * @param scene: Scene&.
            */
            static void addToScene(Parser parser, StandardFigure sf, string description, Scene& scene);

        public:

            /*
             * Deletes the Parser.
            */
            ~Parser();

            /*
            *   Getter for imageName;
            *   @return string
            */
            string getImageName();


            /*
             * Parses the according arguments in the argv.
             * Will add the parse shape to shapes.
             * @param argc: int.
             * @param argv: char**.
             * @param scene: Scene&.
            */
            static Scene parser(int argc, char **argv);
    };


#endif