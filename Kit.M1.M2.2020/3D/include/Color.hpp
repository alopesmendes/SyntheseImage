/*
*   @Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/

#ifdef __cplusplus

    class Color {
        private:
            double red, green, blue;
        
        public:
            /*
             *  Constructs a Color with it's red, green, and blue coordonates.
             *  @param red: double.
             *  @param green: double.
             *  @param blue: double.
            */
            Color(double red, double green, double blue);

            /*
             * Constructs by default a Color.
            */
            Color();

            /*
             *  Deletes Color.
            */
            ~Color();
    };


#endif