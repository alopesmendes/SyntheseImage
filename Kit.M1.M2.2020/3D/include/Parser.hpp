/*
*   @Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/

#ifdef __cplusplus
    class Parser {
        public:
            /*
             * Constructs default Parser.
            */
            Parser();

            /*
             * Deletes the Parser.
            */
            ~Parser();

            /*
             *
            */
            static void parser(int argc, char **argv);
    };


#endif