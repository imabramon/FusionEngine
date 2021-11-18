#ifndef Game_hpp
#define Game_hpp

#include <string>
#include "Glut.h"

#include "AbstractControler.hpp"

using namespace std;

/*!
 *\brief A wrapper over glut functions that allows to implement a controller class
 *\author imabramon
 *\version 0.1
 *\todo Узнать что значат параметры glut функций
 */


class Game{
public:
    /*!
     *\brief Base constructor
     *\author imabramon
     *\version 0.1
     *\param t_controller  Game Controller
     */
    Game(AbstractControler * t_controller);
    
    /*!
     *\brief The function that glut calls to display
     *\author imabramon
     *\version 0.1
     */
    static void display(); //Функция отображения
    
    /*!
     *\brief The function that glut calls to reshape
     *\author imabramon
     *\version 0.1
     *\param t_width New window width
     *\param t_height New window height
     */
    static void reshape(GLint t_width, GLint t_height); //Функция перерисовки
    
    /*!
     *\brief The function that glut calls to interact with a mouse
     *\author imabramon
     *\version 0.1
     *\param t_button Mouse button
     *\param t_state Mouse state
     *\param t_x Mouse x coordinate
     *\param t_y Mouse y coordinate
     */
    static void mouse(int t_button, int t_state, int t_x, int t_y); //Функция обработки мыши
    
    /*!
     *\brief The timer function that glut calls
     *\author imabramon
     *\version 0.1
     *\param t_time Time
     */
    static void timer(int t_time); //Функция таймера
    
    /*!
     *\brief The function that glut calls to interact with  a keyboard
     *\author imabramon
     *\version 0.1
     *\param t_key Keyboard  key
     *\param t_x Mouse x coordinate
     *\param t_y Mouuse y coordinate
     */
    static void keyboard(unsigned char t_key, int t_x, int t_y); //Функция обработки клавиатуры
    
    /*!
     *\brief Set static variable
     *\author imabramon
     *\version 0.1
     */
    static void init(Game * t_game); //Инициализация игры
    
    /*!
     *\brief Calls glut function
     *\author imabramon
     *\version 0.1
     */
    void play(); //функция игры
private:
    static Game * m_game; //Указатель на игру, чтобы можно было получить данные
    
    AbstractControler * m_controler; //Контролер игры
    string m_windowName; //Имя игры
    GLint m_width, m_height; //Размеры окна
};

#endif /* Game_hpp */
