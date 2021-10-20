#ifndef Field_hpp
#define Field_hpp

#include <vector>
#include <utility>

#include "GameObject.hpp"
#include "Cell2048.hpp"
#include "RGB.hpp"

#include "../Fusion/Headers/TypeAlias.h"

class Field: public GameObject{
public:
    Field(int t_x, int t_y, GameObject * t_parent, int t_space, int t_size, int t_cellSize, int t_cellRound, string t_colorsPath);
    /*
     tx, ty - координаты
     p - указатель на родительский объект
     sp - расстояние мужду клетками
     sz - размер поля
     c_z - размер клетки
     c_r - скругление клетки
     */
    
    void init() override; //инициализация
    void createCell(); //создание клетки
    
    int getWidth() const; //получение ширины
    int getHeight() const; //получение высоты
    int isFull() const; //заполнено ли поле?
    int check() const; //проверка на возможность движения
    
    string getGameObjectType() const override; //получение типы объекта
    
    moveResult_t moveUp(); //движение всех клеток вверх, возвращет успешность движения и количество очков
    moveResult_t moveDown(); //движение всех клеток вниз, возвращет успешность движения и количество очков
    moveResult_t moveLeft(); //движение всех клеток влево, возвращет успешность движения и количество очков
    moveResult_t moveRight(); //движение всех клеток вправо, возвращет успешность движения и количество очков
protected:
    void _selfRender() const override; //отобржание самого объекта
private:
    int m_emptyCount; //количество свобожных клеток
    int m_width, m_height; //размеры
    int m_size; //размер поля
    int m_space; //растояние между клетками
    int m_cellSize; //размер клетки
    int m_cellRound; //скругление клетки
    
    int _power(int t_number, int t_power); //возведение в степень
    
    moveResult_t _columnMoveUp(int t_column); //движение клеток в столбце "i" вверх, возвращет успешность движения и количество очков
    moveResult_t _columnMoveDown(int t_column); //движение клеток в столбце "i" вниз, возвращет успешность движения и количество очков
    moveResult_t _rowMoveLeft(int t_row); //движение клеток в строке "i" влево, возвращет успешность движения и количество очков
    moveResult_t _rowMoveRight(int t_row); //движение клеток в строке "i" вправо, возвращет успешность движения и количество очков
    
    vector<vector<int>> m_data; //данные о клетках
    vector<RGB> m_colors; //цвета
};

#endif /* Field_hpp */
