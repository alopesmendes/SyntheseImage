/**
 *  @authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
 *  Will generate a Cube that implements Shape.
 *  And will verify if a ray intersect this shape.
 *  @see Vector.h
 *  @see Shape.h
*/


#ifndef __CUBE_HPP__
#define __CUBE_HPP__

    #include <iostream>
    #include <string>
    #include "Shape.h"
    #include "Vector.h"

    using namespace std;

    class Vector;
    class Shape;
    class Cube: public Shape {
        private:
            Vector p1;
            Vector p2;
            Vector p3;
            Vector p4;
            
            friend std::ostream& operator<<(std::ostream&, const Cube&);
        public:
            /**
             *  @brief Constructs a Cube with it's p1, p2, p3, p4, color and Material.
             *  @param p1: Vector
             *  @param p2: Vector
             *  @param p3: Vector
             *  @param p4: Vector
             *  @param color: Color
             *  @param material: Material
            */
            Cube(Vector p1, Vector p2, Vector p3, Vector p4, Color color, Material material = Material());

            /**
             *  @brief Constructs default Cube.
            */
            Cube();

            /**
             *  @brief Deletes the Cube.
            */
            ~Cube();

            /**
             *  @brief Creates a Cube with it's description.
             *  The format of description should be:
             *  { p1 | p2 | p3 | p4 | color | material }
             *  { double double double | double double double | double double double | double double double |  double double double | double double }
             *  or
             *  { double double double | double double double | double double double | double double double | double double double }
             *  @param description: string
             *  @return Cube*
            */
            static Cube* create(string description);

            /**
             *  @brief Finds the min x form it's points.
             *  @return double
            */
            const double minX() const;

            /**
             *  @brief Finds the min y form it's points.
             *  @return double
            */
            const double minY() const;

            /**
             *  @brief Finds the min z form it's points.
             *  @return double
            */
            const double minZ() const;

            /**
             *  @brief Finds the max x form it's points.
             *  @return double
            */
            const double maxX() const;

            /**
             *  @brief Finds the max y form it's points.
             *  @return double
            */
            const double maxY() const;

            /**
             *  @brief Finds the max z form it's points.
             *  @return double
            */
            const double maxZ() const;


            virtual bool intersect(const Ray& ray, Hit& hit);

            virtual operator std::string() const;
    };

#endif