/*
*   @Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/

#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

    class Vector {
        private:
            double x, y, z;
        
        public:
            /*
             *  Constructs a Vector with it's x, y, and z coordonates.
             *  @param x: double.
             *  @param y: double.
             *  @param z: double.
            */
            Vector(double x, double y, double z);

            /*
             *  Deletes Vector.
            */
            ~Vector();
    };


#endif