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

Vector Utils::decodeVector(std::stringstream &iss, const char &separator) {
    string line;
    getline(iss, line, separator);
    stringstream issVector(line);
    Vector v;
    issVector >> v;
    return v;
}

Color Utils::decodeColor(std::stringstream &iss, const char &separator) {
    string line;
    getline(iss, line, separator);
    stringstream issColor(line);
    Color c;
    issColor >> c;
    return c;
}

Material Utils::decodeMaterial(const std::string &description, std::stringstream &iss, const char &separator, const int &position) {
    string line;
    stringstream ss;
    ss << separator;
    size_t posIndex = Utils::nthOccurrence(description, ss.str(), position);
    Material m;
    if (posIndex == -1) {
        return m;
    }

    getline(iss, line, separator);
    stringstream issMaterial(line);
    issMaterial >> m;
    return m;
}

double Utils::decodeDouble(std::stringstream &iss, const char &separator) {
    string line;
    double value;
    getline(iss, line, separator);
    stringstream issValue(line);
    issValue >> value;
    return value;

}