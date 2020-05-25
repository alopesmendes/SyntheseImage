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
    class Camera {
        private:
            Vector pos;
            Vector target;
            double theta,phi,dist;

            friend std::ostream& operator<<(std::ostream&, const Camera&);
        public:
            /**
             *  @brief Constructs a Camera with it's pos, target, theta, phi and distance.
             *  @param pos: Vector
             *  @param target: Vector
             *  @param theta: double
             *  @param phi: double
             *  @param dist:double
            */
            Camera(Vector pos, Vector target, double theta, double phi, double dist);

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
             *  { pos | target | theta | phi | dist }
             *  { double double double | double double double | double | double | double}
             *  @param description: string
             *  @return Camera*
            */
            static Camera* create(string description);

            /**
             *  @brief Getter for pos.
             *  @return Vector
            */
            const Vector getPos() const;

            /**
             *  @brief Makes a ray from the camera.
             *  @param i: const int&
             *  @param j: const int&
             *  @param im: const Image&
             *  @return: Ray.
            */
            Ray makeRay(const int &u, const int &v, const Image& im);

            virtual operator std::string() const;
    };
    
    
#endif