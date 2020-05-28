/**
 *  @authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
 *  Will create a scene with it's camera, lights and shapes.
 *  Will build a image after it traces it's rays to determine the color of the pixels.
 *  @see Camera.h
 *  @see StandardFigure.h"
 *  @see Shape.h
 *  @see Image.h
 *  @see Light.h
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
    class Coord;
    class Scene {
        private:
            Image image;
            Camera camera;
            vector<Light> lights;
            map<StandardFigure, vector<Shape*>> shapes;
            int level;
            string file;
            string imageName;
            int ps;

            friend std::ostream& operator<<(std::ostream&, const Scene&);

            /**
             *  @brief Gets the right color for a pixel.
             *  @return Color.
            */
            Color traceRay(const Ray& ray, int nbonds = 0);

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
             *  @brief Checks if the shapes intersect with the ray and hit allow us to keep track of this shapes.
             *  @param ray: const Ray&
             *  @param hit: Hit&
             *  @return bool
            */
            const bool intersect(const Ray& ray, Hit& hit) const;

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
            void render();

            /**
             *  @brief Builds the image of the scene (ppm).
            */
            void buildImage();

            /**
             *  @brief Builds the graphic window of the scene.
            */
            void buildWindow();

            /**
             *  @brief Builds the scene in a window, image or both.
            */
            void build();

            virtual operator std::string() const;

    };
    
#endif