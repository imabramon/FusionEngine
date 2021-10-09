#ifndef Cell2048_hpp
#define Cell2048_hpp

#include "TextBox.hpp"
#include "RGB.hpp"

class Cell2048: public TextBox{
public:
    Cell2048(int tx, int ty, int w, int h, int r, GameObject * p, int * s, vector<RGB> & c);
    /*
     tx, ty - координаты
     p - указатель на родительский объект
     w, h - размеры
     r - радиус скругления
     s - указатель на данные для отображания
     c - ссылка на данные о цветах
    */

    bool isVisible() const; //отображаетмся ли объект?
    
    int getScore() const; //получение отображаемых данных
protected:
    RGB _getColor() const; //получение цвета
private:
    vector<RGB> & _colors;
};

#endif /* Cell2048_hpp */
