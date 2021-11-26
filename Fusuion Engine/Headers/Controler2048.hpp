#ifndef Controler2048_hpp
#define Controler2048_hpp

#include "Glut.h"

#include "../Fusion/Headers/AbstractControler.hpp"
#include "../Fusion/Headers/GameObject.hpp"
#include "../Fusion/Headers/AbstractAction.hpp"

#include "Model2048.hpp"
#include "Field.hpp"

#include <string>

using namespace std;

/*!
 *\brief Conкtoler implementation for 2048 game
 *\author imabramon
 *\version 1.0
 */

class Controler2048: public AbstractControler{
public:
    /*!
     *\brief Constructor. Load game settings
     *\param t_path Settings file path
     *\author imabramon
     *\version 0.1
     */
    Controler2048(string t_path);
    
    /*!
     *\brief Glut display function implemenation
     *\author imabramon
     *\version 0.1
     */
    void display() override;
    
    /*!
     *\brief glut reshape function implemenation
     *\param t_width Window width
     *\param t_height Winbdow heigh
     *\author imabramon
     *\version 0.1
     */
    void reshape(GLint t_width, GLint t_height) override;
    
    /*!
     *\brief Glut mouse function implementation
     *\param t_button Pressed button
     *\param t_state mouse state
     *\param t_x mouse cursor x coordinate
     *\param t_y mouse cursor y coordinate
     *\author imabramon
     *\version 0.1
     */
    void mouse(int t_button, int t_state, int t_x, int t_y) override;
    
    /*!
     *\brief Glut timer function implemenation
     *\param t_time Time
     *\author imabramon
     *\version 0.1
     */
    void timer(int t_time) override;
    
    /*!
     *\brief Getting the current window width
     *\author imabramon
     *\version 0.1
     */
    int getWidth() const override;
    
    /*!
     *\brief Getting the current window height
     *\author imabramon
     *\version 0.1
     */
    int getHeight() const override;
protected:
    /*!
     *\brief Destructor interface
     *\author imabramon
     *\version 0.1
     */
    void __destructor() override;
private:
    GameObject * m_scene;
    Model2048 m_model;
    int m_space;
    int m_cellSize, m_cellRound;
    int m_width;
    int m_height;
    bool m_gameOver = false;
    string m_bestPath;
    
};

#endif /* Controler2048_hpp */
