#ifndef Model2048_hpp
#define Model2048_hpp

#include <vector>
#include <iostream>

#include "../Fusion/Headers/TypeAlias.h"
#include "../Fusion/Headers/AbstractAction.hpp"
#include "../Fusion/Headers/AbstractEvent.hpp"

class Model2048;

typedef void (Model2048::*moveFunction)(void);

/*!
 *\brief A class that contains all the 2048 game data
 *\author imabramon
 *\version 1.0
 */

class Model2048 {
public:
    Model2048(int t_size);
    ~Model2048();
    int check() const; //проверка на возможность движения
    int isFull() const; //заполнено ли поле?
    int & score();
    int & bestScore();
    int & emptyCount();
    int & size();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void createCell();
    intMatrix_t & data();
    //Move to MACROS
    class Action : public AbstractAction{
    public:
        Action(Model2048 * t_model, moveFunction t_function);
        void perform() override;
    private:
        moveFunction m_function;
        Model2048 * m_model;
    };
private:
    int m_score; //текущий счет
    int m_best; //лучший счет
    int m_emptyCount; //количество свобожных клеток
    int m_size; //размер поля
    
    intMatrix_t m_data; //данные о клетках
    
    void countScore(int count, int flag);
    
    moveResult_t _columnMoveUp(int t_column); //движение клеток в столбце "i" вверх, возвращет успешность движения и количество очков
    moveResult_t _columnMoveDown(int t_column); //движение клеток в столбце "i" вниз, возвращет успешность движения и количество очков
    moveResult_t _rowMoveLeft(int t_row); //движение клеток в строке "i" влево, возвращет успешность движения и количество очков
    moveResult_t _rowMoveRight(int t_row); //движение клеток в строке "i" вправо, возвращет успешность движения и количество очков
    
    int _power(int t_number, int t_power);
};


#endif /* Model2048_hpp */
