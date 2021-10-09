#ifndef RGB_hpp
#define RGB_hpp

#include <string>

using namespace std;

class RGB{
public:
    RGB(int tr = 0, int tg = 0, int tb = 0);
    /*
     Цвет по кофенцентам
     tr - красный
     tg - зеленый
     tb - синий
     */
    RGB(string hex);
    /*
     Цвет по коду hex
     */
    
    int getRed() const; //Поучение красного
    int getGreen() const; //Получение зеленого
    int getBlue() const; // Получение синего
private:
    int _red, _green, _blue; //коффиценты
    
    int _hexToDec(char c) const; //Приведение "с" в десятичную cc
};

#endif /* RGB_hpp */
