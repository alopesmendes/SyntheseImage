/**
 *  @authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
 *  Will create an enumeration to regroup every element that can be added to the scene.
 *  The method resolveStandardFigure will verify the input is well written. 
*/

#ifndef __STANDARD_FIGURE_HPP__
#define __STANDARD_FIGURE_HPP__

    #include <iostream>
    #include <string>
    using namespace std;

    enum StandardFigure {
        INVALID,
        IMAGE,
        CAMERA,
        LIGHT,
        SPHERE,
        CUBE,
        TRIANGLE,
        PLANE,
        CONE,
        CYLINDER,
    };

    /**
     *  @brief According to input will return a StandardFigure.
     *  The input has to be the same name as the class.
     *  It can be in lower, upper or both cases. 
     *  @param input: string.
     *  @return: StandardFigure.
    */
    StandardFigure resolveStandardFigure(string input);


#endif