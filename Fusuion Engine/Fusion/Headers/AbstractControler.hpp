#ifndef Controler_hpp
#define Controler_hpp

#include <vector>

#include "Glut.h"
#include "Keyboard.hpp"
#include "AbstractEvent.hpp"
#include "AbstractAction.hpp"

/*!
 *\brief Base Contoler class.
 *       Directly calls glut functions, giving the user an easier way to develop a game
 *       using a keyboard object, an event-action system
 *\author imabramon
 *\version 1.0
 */

class AbstractControler{
public:
    AbstractControler();
    ~AbstractControler();
    
    virtual void display() = 0; // интерфейс функции отобржанеия
    virtual void reshape(GLint t_width, GLint t_height)  = 0; // интерфейс функции изменения размера
    virtual void mouse(int t_button, int t_state, int t_x, int t_y)  = 0; // интерфейс функции обработки
    virtual void timer(int t_t) = 0; // интерфейс функции таймера
    void keyboard(unsigned char t_key, int t_x, int t_y); // интерфейс функции обработки
    
    virtual int getWidth() const = 0; // интерфейс получения ширины окна
    virtual int getHeight() const = 0; // интерфейс получения высоты окна
    
    /*!
     *\brief Connect Event to Action
     */
    
    void connect(AbstractEvent * t_event, AbstractAction * t_action);
protected:
    virtual void __destructor() = 0;
    Keyboard m_keyboard;
private:
    std::vector<AbstractAction *> m_actions;
};

#endif /* Controler_hpp */
