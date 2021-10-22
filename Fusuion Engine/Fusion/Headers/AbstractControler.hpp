#ifndef Controler_hpp
#define Controler_hpp

#include "Glut.h"

class AbstractControler{
public:
    virtual void display() = 0; // интерфейс функции отобржанеия
    virtual void reshape(GLint t_width, GLint t_height)  = 0; // интерфейс функции изменения размера
    virtual void mouse(int t_button, int t_state, int t_x, int t_y)  = 0; // интерфейс функции обработки
    virtual void timer(int t_t) = 0; // интерфейс функции таймера
    virtual void keyboard(unsigned char t_key, int t_x, int t_y) = 0; // интерфейс функции обработки
    
    virtual int getWidth() const = 0; // интерфейс получения ширины окна
    virtual int getHeight() const = 0; // интерфейс получения высоты окна
};

#endif /* Controler_hpp */
