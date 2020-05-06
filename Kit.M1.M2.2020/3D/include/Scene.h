/*
*   @Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/


#ifndef __SCENE_HPP__
#define __SCENE_HPP__
    #include <iostream>
    #include <vector>
    #include <map>
    #include <sstream>
    #include <string>
    #include "Camera.h"
    #include "StandardFigure.h"
    #include "Shape.h"
    #include "Image.h"

    using namespace std;

    class Scene {
        private:
            Camera camera;
            map<StandardFigure, vector<Shape*>> shapes;

            friend std::ostream& operator<<(std::ostream&, const Scene&);

        public:
            /*
            *   Constructs a Scene.
            */
            Scene();

            /*
            *   Deletes a Scene.
            */
            ~Scene();

            /*
            *   Add camera to the scene.
            *   @param camera: const Camera&
            */
            void addCamera(const Camera& camera);

            /*
            *   Add shape according to it's standardFigure to the scene.
            *   @param standardFigure: const StandardFigure&
            *   @param shape: const Shape&
            */
            void addShape(const StandardFigure& standardFigure, Shape* shape);

            /*
            *   Updates the scene.
            */
            void update();

            virtual operator std::string() const;

    };
    
#endif