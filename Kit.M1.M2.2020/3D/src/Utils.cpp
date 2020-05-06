#include "../include/Utils.h"

size_t Utils::nthOccurrence(const string& str, const string& findMe, int nth) {
    size_t  pos = 0;
    int     cnt = 0;

    while( cnt != nth ) {
        pos+=1;
        pos = str.find(findMe, pos);
        if ( pos == std::string::npos )
            return -1;
        cnt++;
    }
    return pos;
}