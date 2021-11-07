#ifndef Game_hpp
#define Game_hpp

#include <string>
#include "Glut.h"

#include "AbstractControler.hpp"

using namespace std;


class Game{
public:
    /*!
     *\brief some brief
     *\author imabramon
     */
    Game(AbstractControler * t_controller);
    
    static void display(); //Функция отображения
    static void reshape(GLint t_width, GLint t_height); //Функция перерисовки
    static void mouse(int t_button, int t_state, int t_x, int t_y); //Функция обработки мыши
    static void timer(int t_time); //Функция таймера
    static void keyboard(unsigned char t_key, int t_x, int t_y); //Функция обработки клавиатуры
    static void init(Game * t_game); //Инициализация игры
    
    void play(); //функция игры
private:
    static Game * m_game; //Указатель на игру, чтобы можно было получить данные
    
    AbstractControler * m_controler; //Контролер игры
    string m_windowName; //Имя игры
    GLint m_width, m_height; //Размеры окна
};

#endif /* Game_hpp */
