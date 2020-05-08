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
    #include "Light.h"

    using namespace std;

    class Scene {
        private:
            Camera camera;
            Light light;
            map<StandardFigure, vector<Shape*>> shapes;

            friend std::ostream& operator<<(std::ostream&, const Scene&);

            /*
            *   Checks if the shapes intersect with the ray and light.
            *   @param image: Image&
            *   @param i: int 
            *   @param j: int
            *   @reyurn bool
            */
            bool intersect(const Ray& ray, Hit& hit);

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
            *   Add a light to the scene.
            *   @param l: const Light&
            */
            void addLight(const Light& l);

            /*
            *   Updates the scene.
            */
            void update();

            virtual operator std::string() const;

    };
    
#endif