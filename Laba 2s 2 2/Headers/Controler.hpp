#ifndef Controler_hpp
#define Controler_hpp

#include "Glut.h"

class Controler{
public:
    virtual void display() = 0; // интерфейс функции отобржанеия
    virtual void reshape(GLint w, GLint h)  = 0; // интерфейс функции изменения размера
    virtual void mouse(int button, int state, int x, int y)  = 0; // интерфейс функции обработки
    virtual void timer(int t) = 0; // интерфейс функции таймера
    virtual void keyboard(unsigned char key, int x, int y) = 0; // интерфейс функции обработки
    
    virtual int getWidth() const = 0; // интерфейс получения ширины окна
    virtual int getHeight() const = 0; // интерфейс получения высоты окна
};

#endif /* Controler_hpp */
