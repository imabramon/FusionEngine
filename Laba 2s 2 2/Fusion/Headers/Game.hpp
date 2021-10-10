#ifndef Game_hpp
#define Game_hpp

#include <string>
#include "Glut.h"

#include "Controler.hpp"

using namespace std;


class Game{
public:
    Game(Controler * c);
    
    static void display(); //Функция отображения
    static void reshape(GLint w, GLint h); //Функция перерисовки
    static void mouse(int button, int state, int x, int y); //Функция обработки мыши
    static void timer(int t); //Функция таймера
    static void keyboard(unsigned char key, int x, int y); //Функция обработки клавиатуры
    static void init(Game * g); //Инициализация игры
    
    void play(); //функция игры
private:
    static Game * _game; //Указатель на игру, чтобы можно было получить данные
    
    Controler * _controler; //Контролер игры
    string _windowName; //Имя игры
    GLint _width, _height; //Размеры окна
};

#endif /* Game_hpp */
