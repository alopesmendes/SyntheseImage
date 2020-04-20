/*
*   @Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/

#ifdef __cplusplus

    class Point {
        private:
            double x, y, z;
        
        public:
            /*
             *  Constructs a Point with it's x, y, and z coordonates.
             *  @param x: double.
             *  @param y: double.
             *  @param z: double.
            */
            Point(double x, double y, double z);

            /*
             *  Constructs by default a Point.
            */
            Point();

            /*
             *  Deletes point.
            */
            ~Point();
    };


#endif