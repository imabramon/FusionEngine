#ifndef RGB_hpp
#define RGB_hpp

#include <string>

using namespace std;

class RGB{
public:
    RGB(int t_red = 0, int t_green = 0, int t_blue = 0);
    /*
     Цвет по кофенцентам
     tr - красный
     tg - зеленый
     tb - синий
     */
    RGB(string t_hex);
    /*
     Цвет по коду hex
     */
    
    int getRed() const; //Поучение красного
    int getGreen() const; //Получение зеленого
    int getBlue() const; // Получение синего
private:
    int m_red, m_green, m_blue; //коффиценты
    
    int _hexToDec(char t_hexDigit) const; //Приведение "с" в десятичную cc
};

#endif /* RGB_hpp */
