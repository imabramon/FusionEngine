#ifndef Cell2048_hpp
#define Cell2048_hpp

#include "TextBox.hpp"
#include "RGB.hpp"

/*!
 *\brief A class that displays a cell and changes its color depending on the cell data
 *\author imabramon
 *\version 1.0
*/

class Cell2048: public TextBox{
public:
    
    Cell2048(int t_x, int t_y, int t_width, int t_height, int t_radius, GameObject * t_parent, int * t_score, vector<RGB> & t_colors);
    
    
    /*! Калл
    @brief Находит сумму двух чисел
    \return Сумму двух чисел, переданных в качестве аргументов
    */

    bool isVisible() const override; //отображаетмся ли объект?
    
    
    int getScore() const override; //получение отображаемых данных
protected:
    RGB _getColor() const override; //получение цвета
private:
    vector<RGB> & m_colors;
};

#endif /* Cell2048_hpp */
