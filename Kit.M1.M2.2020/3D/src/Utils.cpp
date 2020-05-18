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

void Utils::decode3double(std::stringstream &iss, const char &separator, double &x, double &y, double &z) {
    string line;
    getline(iss, line, '|');
    stringstream issPoints(line);
    issPoints >> x >> y >> z;
}

Vector Utils::decodeVector(std::stringstream &iss, const char &separator) {
    double x, y, z;
    decode3double(iss, separator, x, y, z);
    return Vector(x, y, z);
}

Color Utils::decodeColor(std::stringstream &iss, const char &separator) {
    double red, green, blue;
    decode3double(iss, separator, red, green, blue);
    return Color(red, green, blue);
}

Material Utils::decodeMaterial(const std::string &description, std::stringstream &iss, const char &separator, const int &position) {
    bool m = false, t = false;
    string line;
    stringstream ss;
    ss << separator;
    size_t posIndex = Utils::nthOccurrence(description, ss.str(), position);
    if (posIndex == -1) {
        return Material();
    }

    getline(iss, line, separator);
    stringstream issMirror(line);
    issMirror >> m;
    posIndex = Utils::nthOccurrence(description, ss.str(), position + 1);
    if (posIndex == -1) {
        return Material(m);;
    }
    getline(iss, line, separator);
    stringstream issTransperecy(line);
    issTransperecy >> t;
    return Material(m, t);
}

double Utils::decodeDouble(std::stringstream &iss, const char &separator) {
    string line;
    double value;
    getline(iss, line, separator);
    stringstream issValue(line);
    issValue >> value;
    return value;

}