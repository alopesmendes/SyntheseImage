/*
*   @Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien
*/

#ifndef __UTILS_HPP__
#define __UTILS_HPP__

    #include <iostream>
    using namespace std;

    class Utils {
        public:
            /*
             *  Will return the position of `nth` occurence of `findMe` in `str`.
             *  If it does not find it it will return -1.
             *  @param: str.
             *  @param: str.
             *  @param: int.
             *  @return: size_t.
            */
            static size_t nthOccurrence(const string&, const string&, int);
    };
#endif