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
    /*!
     *\brief Constructor
     *\param t_size Matrix size
     *\author imabramon
     *\version 0.1
     */
    Model2048(int t_size);
    
    /*!
     *\brief Destructor
     *\author imabramon
     *\version 0.1
     */
    ~Model2048();
    
    /*!
     *\brief Check if matrix is possible to combine
     *\return True if pocible to combine
     *\author imabramon
     *\version 0.1
     */
    int check() const;
    
    /*!
     *\brief Check if matrix is full
     *\return True if full
     *\author imabramon
     *\version 0.1
     */
    int isFull() const;
    
    /*!
     *\brief Getting the current score
     *\return Current score
     *\author imabramon
     *\version 0.1
     */
    int & score();
    
    /*!
     *\brief Getting the best score
     *\return Best score
     *\author imabramon
     *\version 0.1
     */
    int & bestScore();
    
    /*!
     *\brief Getting empty counts of matrix
     *\return Empty cell count
     *\author imabramon
     *\version 0.1
     */
    int & emptyCount();
    
    /*!
     *\brief Getting size of matrix
     *\return Size of matrix
     *\author imabramon
     *\version 0.1
     */
    int & size();
    
    /*!
     *\brief Move up all cell method
     *\author imabramon
     *\version 0.1
     */
    void moveUp();
    
    /*!
     *\brief Move down all cell method
     *\author imabramon
     *\version 0.1
     */
    void moveDown();
    
    /*!
     *\brief Move left all cell method
     *\author imabramon
     *\version 0.1
     */
    void moveLeft();
    
    /*!
     *\brief Move right all cell method
     *\author imabramon
     *\version 0.1
     */
    void moveRight();
    
    /*!
     *\brief Create cell method
     *\author imabramon
     *\version 0.1
     */
    void createCell();
    
    /*!
     *\brief Getting data of matrix
     *\author imabramon
     *\version 0.1
     */
    intMatrix_t & data();
    
    /*!
     *\brief Model2048 Action class
     *\author imabramon
     *\version 0.1
     */
    class Action : public AbstractAction{
    public:
        /*!
         *\brief Constructor
         *\param t_model Model pointer
         *\param t_function Model function pointer
         *\author imabramon
         *\version 0.1
         */
        Action(Model2048 * t_model, moveFunction t_function);
        
        /*!
         *\brief Call model function on model
         *\author imabramon
         *\version 0.1
         */
        void perform() override;
    private:
        moveFunction m_function;
        Model2048 * m_model;
    };
private:
    int m_score;
    int m_best;
    int m_emptyCount;
    int m_size;
    intMatrix_t m_data;
    
    /*!
     *\brief Set counted score to current score and if it bigger than best score, set to best score
     *\param count Counted score
     *\param flag Move succes flag
     *\author imabramon
     *\version 0.1
     */
    void countScore(int count, int flag);
    
    /*!
     *\brief Move up cell column method
     *\param t_column Column number
     *\return Pair of Counted score and Move succes flag
     *\author imabramon
     *\version 0.1
     */
    moveResult_t _columnMoveUp(int t_column);
    
    /*!
     *\brief Move down cell column method
     *\param t_column Column number
     *\return Pair of Counted score and Move succes flag
     *\author imabramon
     *\version 0.1
     */
    moveResult_t _columnMoveDown(int t_column);
    
    /*!
     *\brief Move left cell row method
     *\param t_row Row number
     *\return Pair of Counted score and Move succes flag
     *\author imabramon
     *\version 0.1
     */
    moveResult_t _rowMoveLeft(int t_row);
    
    /*!
     *\brief Move left cell row method
     *\param t_row Row number
     *\return Pair of Counted score and Move succes flag
     *\author imabramon
     *\version 0.1
     */
    moveResult_t _rowMoveRight(int t_row);
    
    /*!
     *\brief Counting number power
     *\param t_number Number
     *\param t_power Power
     *\return Number power
     *\author imabramon
     *\version 0.1
     */
    int _power(int t_number, int t_power);
};


#endif /* Model2048_hpp */
