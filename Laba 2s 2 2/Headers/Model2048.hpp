#ifndef Model2048_hpp
#define Model2048_hpp

#include <vector>
#include <iostream>

#include "../Fusion/Headers/TypeAlias.h"
#include "../Fusion/Headers/AbstractAction.hpp"

class Model2048;

typedef moveResult_t (Model2048::*moveFunction)();

class Model2048 {
public:
    Model2048(int t_size);
    ~Model2048();
    
    void createCell(); //создание клетки
    
    int & score();
    int & bestScore();
    int & emptyCount();
    int & size();
    int check() const; //проверка на возможность движения
    int isFull() const; //заполнено ли поле?
    
    intMatrix_t & data();
    
    moveResult_t moveUp(); //движение всех клеток вверх, возвращет успешность движения и количество очков
    moveResult_t moveDown(); //движение всех клеток вниз, возвращет успешность движения и количество очков
    moveResult_t moveLeft(); //движение всех клеток влево, возвращет успешность движения и количество очков
    moveResult_t moveRight(); //движение всех клеток вправо, возвращет успешность движения и количество очков
    
    class Action : public AbstractAction{
    public:
        Action(Model2048 * t_model, moveFunction t_function);
        void perform() override;
    private:
        moveFunction m_function;
        //std::function<moveResult_t(void)> m_func;
        Model2048 * m_model;
    };
private:
    int m_score; //текущий счет
    int m_best; //лучший счет
    int m_emptyCount; //количество свобожных клеток
    int m_size; //размер поля
    
    intMatrix_t m_data; //данные о клетках
    
    moveResult_t _columnMoveUp(int t_column); //движение клеток в столбце "i" вверх, возвращет успешность движения и количество очков
    moveResult_t _columnMoveDown(int t_column); //движение клеток в столбце "i" вниз, возвращет успешность движения и количество очков
    moveResult_t _rowMoveLeft(int t_row); //движение клеток в строке "i" влево, возвращет успешность движения и количество очков
    moveResult_t _rowMoveRight(int t_row); //движение клеток в строке "i" вправо, возвращет успешность движения и количество очков
    
    int _power(int t_number, int t_power);
    
};


#endif /* Model2048_hpp */
