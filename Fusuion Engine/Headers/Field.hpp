#ifndef Field_hpp
#define Field_hpp

#include <vector>
#include <utility>

#include "GameObject.hpp"
#include "Cell2048.hpp"
#include "RGB.hpp"

#include "../Fusion/Headers/TypeAlias.h"

/*!
 *\brief The class responsible for displaying the field
 *\author imabramon
 *\version 1.0
 */

class Field: public GameObject{
    /*!
        @brief: Call
     */
public:
    Field(int t_x, int t_y, GameObject * t_parent, int t_space, int t_size, int t_cellSize, int t_cellRound, string t_colorsPath, intMatrix_t & t_matrix);
    /*
     tx, ty - координаты
     p - указатель на родительский объект
     sp - расстояние мужду клетками
     sz - размер поля
     c_z - размер клетки
     c_r - скругление клетки
     */
    
    int getWidth() const; //получение ширины
    int getHeight() const; //получение высоты
    
    
    string getGameObjectType() const override; //получение типы объекта
    
protected:
    void _selfRender() const override; //отобржание самого объекта
private:
    int m_emptyCount; //количество свобожных клеток
    int m_width, m_height; //размеры
    int m_space; //растояние между клетками
    int m_cellSize; //размер клетки
    int m_cellRound; //скругление клетки
    
    int m_size;
    
    vector<vector<int>> & m_data; //данные о клетках
    vector<RGB> m_colors; //цвета
};

#endif /* Field_hpp */
