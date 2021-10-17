#ifndef TextBox_hpp
#define TextBox_hpp

#include "GameObject.hpp"
#include "RGB.hpp"

class TextBox: public GameObject{
public:
    TextBox(int t_x, int t_y, int t_width, int t_height, int t_radius, GameObject * t_parent, int * t_score);
    /*
     tx, ty - координаты
     p - указатель на родительский объект
     w, h - размеры
     r - радиус скругления
     s - указатель на данные для отображания
    */
    
    virtual int getScore() const; //получение данных для отображения
    
    virtual bool isVisible() const override; //отображается ли объект?
    
    virtual string getGameObjectType() const override; //получение типа объекта
protected:
    void _selfRender() const override; //отобржание самого объекта
    int * m_score = NULL; //указатель на данные
    int m_width, m_height; //размеры
    int m_radius; //радиус скругления
    
    virtual RGB _getColor() const; //получение цвета
};

#endif
