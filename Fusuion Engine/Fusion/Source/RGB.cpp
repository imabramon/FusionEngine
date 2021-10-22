#include "../Headers/RGB.hpp"

RGB::RGB(int t_red, int t_green, int t_blue): m_red(t_red), m_green(t_green), m_blue(t_blue) {};

RGB::RGB(string t_hex){
    m_red = _hexToDec(t_hex[0])*16 + _hexToDec(t_hex[1]);
    m_green = _hexToDec(t_hex[2])*16 + _hexToDec(t_hex[3]);
    m_blue = _hexToDec(t_hex[4])*16 + _hexToDec(t_hex[5]);
};

int RGB::getRed() const{
    return m_red;
}

int RGB::getGreen() const{
    return m_green;
}

int RGB::getBlue() const{
    return m_blue;
}

int RGB::_hexToDec(char t_hexDigit) const{
    if(t_hexDigit >= '0' && t_hexDigit <= '9') return t_hexDigit - '0';
    
    if(t_hexDigit >= 'A' && t_hexDigit <= 'F') return 10 + (t_hexDigit - 'A');
    
    return 0;
}
