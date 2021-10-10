#ifndef Cell2048_hpp
#define Cell2048_hpp

#include "TextBox.hpp"
#include "RGB.hpp"

/*!
    @brief Дочерний класс
    @author im_abramon
    @version 1.0
    @date Февраль 2021
    @warning Данный класс создан только в учебных целях

    Обычный дочерний класс, который отнаследован от ранее созданного класса Parent
*/

class Cell2048: public TextBox{
public:
    
    Cell2048(int tx, int ty, int w, int h, int r, GameObject * p, int * s, vector<RGB> & c);
    
    
    /*! Калл
    @brief Находит сумму двух чисел
    \return Сумму двух чисел, переданных в качестве аргументов
    */

    bool isVisible() const; //отображаетмся ли объект?
    
    
    int getScore() const; //получение отображаемых данных
protected:
    RGB _getColor() const; //получение цвета
private:
    vector<RGB> & _colors;
};

#endif /* Cell2048_hpp */
