/**
 *  @authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
 *  Will create the camera that will be place on the scene.
 *  Will also generate the rays that will hit the shapes of the scene.
 *  @see Vector.h
 *  @see Ray.h
 *  @see Image.h
*/

#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

    #include <iostream>
    #include <string>
    #include "Vector.h"
    #include "Ray.h"
    #include "Image.h"

    using namespace std;

    class Vector;
    class Ray;
    class Image;

    class Coord {
        public:
            Vector lookfrom;
            Vector lookat;
            Vector vup;
            double vfov;
            double aspectRatio;
            double aperture;
            double dist;

            /**
             *  @brief Constructs Coord.
             *  @param lookfrom will determine the position of the camera: Vector
             *  @param lookat will allow us to determine the direction in which the camera is looking at: Vector
             *  @param vup will determine in which axis the camera is placed: Vector
             *  @param vfov will determine the fov for the camera is in degrees: double
             *  @param aspectRatio will determine the aspect ratio of the camera: double
             *  @param aperture will determine the lens radius: double
             *  @param dist will determine the focus distance of the camera: double
            */
            Coord(Vector lookfrom, Vector lookat, Vector vup, double vfov, double aspectRatio, double aperture, double dist);
            ~Coord();
    };
    class Camera {

        private:

            Vector lookfrom;
            Vector lookat;
            Vector vup;
            Vector lowerLeftCorner;
            Vector horizontal;
            Vector vertical;
            Vector u, v, w;
            double vfov;
            double aspectRatio;
            double aperture;
            double dist;
            double lensRadius;
            double viewport_height, viewport_width;

            friend std::ostream& operator<<(std::ostream&, const Camera&);
        public:

            /**
             *  @brief Constructs a Camera with the different values.
             *  @param lookfrom will determine the position of the camera: Vector
             *  @param lookat will allow us to determine the direction in which the camera is looking at: Vector
             *  @param vup will determine in which axis the camera is placed: Vector
             *  @param vfov will determine the fov for the camera is in degrees: double
             *  @param aspectRatio will determine the aspect ratio of the camera: double
             *  @param aperture will determine the lens radius: double
             *  @param dist will determine the focus distance of the camera: double
            */
            Camera(Vector lookfrom, Vector lookat, Vector vup, double vfov, double aspectRatio, double aperture, double dist);

            /**
             *  @brief Constructs a default Camera.
            */
            Camera();

            /**
             *  @brief Deletes Camera.
            */
            ~Camera();

            /**
             *  @brief Creates a Camera with it's description.
             *  The format of description should be:
             *  { lookfrom | target | theta | phi | dist }
             *  { double double double | double double double | double | double | double}
             *  @param description: string
             *  @return Camera*
            */
            static Camera* create(string description);

            /**
             *  @brief Getter for lookfrom.
             *  @return Vector
            */
            const Vector getPos() const;

            /**
             *  @brief Getter for 
            */

            /**
             *  @brief Makes a ray from the camera.
             *  @param i: const int&
             *  @param j: const int&
             *  @param im: const Image&
             *  @return: Ray.
            */
            Ray makeRay(const int &u, const int &v, const Image& im);

            /**
             *  @brief Sets the camera.
             *  @param pos: Vector
             *  @param target: Vector
             *  @param up: Vector
             *  @param fov: double
             *  @param ar: double
             *  @param ap: double
             *  @param d: double
             *  @return: Camera
            */
            Camera& newPlacedCamera(Vector pos = Vector(), Vector target = Vector(), Vector up = Vector(), double fov = 0, double ar = 0, double ap = 0, double d = 0);

            friend Camera operator+(Camera& cam, const Coord& coord);
            Camera& operator=(const Camera& cam);
            virtual operator std::string() const;

            class Coord {
            public:
                Vector lookfrom;
                Vector lookat;
                Vector vup;
                double vfov;
                double aspectRatio;
                double aperture;
                double dist;
                Coord(Vector lookfrom, Vector lookat, Vector vup, double vfov, double aspectRatio, double aperture, double dist);
                ~Coord();
        };
    };
    
    
#endif