/*
*   @Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/

#ifndef __STANDARD_FIGURE_HPP__
#define __STANDARD_FIGURE_HPP__

    #include <iostream>
    #include <string>
    using namespace std;

    enum StandardFigure {
        CAMERA,
        RAY,
        SPHERE,
        CUBE,
        INVALID
    };

    /*
     * According to input will return a StandardFigure.
     * @param input: string.
     * @return: StandardFigure.
    */
    StandardFigure resolveStandardFigure(string input);

#endif