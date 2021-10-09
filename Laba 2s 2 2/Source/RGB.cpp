#include "../Headers/RGB.hpp"

RGB::RGB(int tr, int tg, int tb): _red(tr), _green(tg), _blue(tb) {};

RGB::RGB(string hex){
    _red = _hexToDec(hex[0])*16 + _hexToDec(hex[1]);
    _green = _hexToDec(hex[2])*16 + _hexToDec(hex[3]);
    _blue = _hexToDec(hex[4])*16 + _hexToDec(hex[5]);
};

int RGB::getRed() const{
    return _red;
}

int RGB::getGreen() const{
    return _green;
}

int RGB::getBlue() const{
    return _blue;
}

int RGB::_hexToDec(char c) const{
    if(c >= '0' && c <= '9') return c - '0';
    
    if(c >= 'A' && c <= 'F') return 10 + (c - 'A');
    
    return 0;
}
