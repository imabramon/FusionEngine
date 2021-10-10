#ifndef TextBox_hpp
#define TextBox_hpp

#include "GameObject.hpp"
#include "RGB.hpp"

class TextBox: public GameObject{
public:
    TextBox(int tx, int ty, int w, int h, int r, GameObject * p, int * s);
    /*
     tx, ty - координаты
     p - указатель на родительский объект
     w, h - размеры
     r - радиус скругления
     s - указатель на данные для отображания
    */
    
    virtual int getScore() const; //получение данных для отображения
    
    virtual bool isVisible() const; //отображается ли объект?
    
    virtual string getGameObjectType() const; //получение типа объекта
protected:
    void _selfRender() const; //отобржание самого объекта
    int * _score = NULL; //указатель на данные
    int _width, _height; //размеры
    int _r; //радиус скругления
    
    virtual RGB _getColor() const; //получение цвета
};

#endif
