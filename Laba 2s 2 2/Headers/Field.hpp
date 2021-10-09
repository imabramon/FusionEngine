#ifndef Field_hpp
#define Field_hpp

#include <vector>
#include <utility>

#include "GameObject.hpp"
#include "Cell2048.hpp"
#include "RGB.hpp"

class Field: public GameObject{
public:
    Field(int tx, int ty, GameObject * p, int sp, int sz, int c_z, int c_r, string colorsPath);
    /*
     tx, ty - координаты
     p - указатель на родительский объект
     sp - расстояние мужду клетками
     sz - размер поля
     c_z - размер клетки
     c_r - скругление клетки
     */
    
    void init(); //инициализация
    void createCell(); //создание клетки
    
    int getWidth() const; //получение ширины
    int getHeight() const; //получение высоты
    int isFull() const; //заполнено ли поле?
    int check() const; //проверка на возможность движения
    
    string getGameObjectType() const; //получение типы объекта
    
    pair<int, int> moveUp(); //движение всех клеток вверх, возвращет успешность движения и количество очков
    pair<int, int> moveDown(); //движение всех клеток вниз, возвращет успешность движения и количество очков
    pair<int, int> moveLeft(); //движение всех клеток влево, возвращет успешность движения и количество очков
    pair<int, int> moveRight(); //движение всех клеток вправо, возвращет успешность движения и количество очков
protected:
    void _selfRender() const; //отобржание самого объекта
private:
    int _emptyCount; //количество свобожных клеток
    int _width, _height; //размеры
    int _size; //размер поля
    int _space; //растояние между клетками
    int _cellSize; //размер клетки
    int _cellRound; //скругление клетки
    
    int _power(int n, int q); //возведение в степень
    
    pair<int, int> _colMoveUp(int i); //движение клеток в столбце "i" вверх, возвращет успешность движения и количество очков
    pair<int, int> _colMoveDown(int i); //движение клеток в столбце "i" вниз, возвращет успешность движения и количество очков
    pair<int, int> _rowMoveLeft(int i); //движение клеток в строке "i" влево, возвращет успешность движения и количество очков
    pair<int, int> _rowMoveRight(int i); //движение клеток в строке "i" вправо, возвращет успешность движения и количество очков
    
    vector<vector<int>> _data; //данные о клетках
    vector<RGB> _colors; //цвета
};

#endif /* Field_hpp */
