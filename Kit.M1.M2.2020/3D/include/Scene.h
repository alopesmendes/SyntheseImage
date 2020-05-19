/**
 *  @authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/


#ifndef __SCENE_HPP__
#define __SCENE_HPP__
    #include <iostream>
    #include <vector>
    #include <map>
    #include <string>
    #include "Camera.h"
    #include "StandardFigure.h"
    #include "Shape.h"
    #include "Image.h"
    #include "Light.h"

    using namespace std;

    class Image;
    class Camera;
    class Light;
    class Shape;
    enum StandardFigure;
    class Scene {
        private:
            Image image;
            Camera camera;
            Light light;
            map<StandardFigure, vector<Shape*>> shapes;
            int level;
            string file;
            string imageName;
            int ps;

            friend std::ostream& operator<<(std::ostream&, const Scene&);

            /**
             *  @brief Checks if the shapes intersect with the ray and hit allow us to keep track of this shapes.
             *  @param ray: const Ray&
             *  @param hit: Hit&
             *  @return bool
            */
            bool intersect(const Ray& ray, Hit& hit);

            /**
             *  @brief Gets the right color for a pixel.
             *  @return Color.
            */
            Color getColor(const Ray& ray, int nbonds = 0);

        public:
            /**
             *  @brief Constructs a Scene with it's level, file, imName and ps.
             *  @param level is between 1-3: int
             *  @param file the name of the input file: string
             *  @param imName the name of file where the image generate will be saved: string
             *  @param ps the number of rays generate: ps
            */
            Scene(int level, string file, string imName, int ps);

            /**
             *  @brief Deletes a Scene.
            */
            ~Scene();

            /**
             *  @brief Add camera to the scene.
             *  @param camera: const Camera&
            */
            void addCamera(const Camera& camera);

            /**
             *  @brief Add shape according to it's standardFigure to the scene.
             *  @param standardFigure: const StandardFigure&
             *  @param shape: const Shape&
            */
            void addShape(const StandardFigure& standardFigure, Shape* shape);

            /**
             *  @brief Add a light to the scene.
             *  @param l: const Light&
            */
            void addLight(const Light& l);

            /**
             *  @brief Add the image showing the scene.
             *  @param im: const Image&
            */
            void addImage(const Image& im);

            /**
             *  @brief Generates the scene.
             *  Will set every pixel of the image it's color.
            */
            void generateScene();

            /**
             *  @brief Builds the scene.
            */
            void buildImage();

            virtual operator std::string() const;

    };
    
#endif