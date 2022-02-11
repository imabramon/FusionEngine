#ifndef Controler_hpp
#define Controler_hpp

#include <vector>

#include "Glut.h"
#include "Keyboard.hpp"
#include "AbstractEvent.hpp"
#include "AbstractAction.hpp"

/*!
 *\brief Base Contoler class. Directly calls glut functions, giving the user an easier way to develop a game using a keyboard object, an event-action system
 *\author imabramon
 *\version 0.2.1
 */

class AbstractControler{
public:
    AbstractControler();
    ~AbstractControler();
    
    /*!
     *\brief Glut display function interface
     *\author imabramon
     *\version 0.1
     */
    virtual void display() = 0;
    /*!
     *\brief glut reshape function interface
     *\param t_width Window width
     *\param t_height Winbdow heigh
     *\author imabramon
     *\version 0.1
     */
    virtual void reshape(GLint t_width, GLint t_height)  = 0;
    /*!
     *\brief Glut mouse function interface
     *\param t_button Pressed button
     *\param t_state mouse state
     *\param t_x mouse cursor x coordinate
     *\param t_y mouse cursor y coordinate
     *\author imabramon
     *\version 0.1
     */
    virtual void mouse(int t_button, int t_state, int t_x, int t_y)  = 0;
    /*!
     *\brief Glut timer function interface
     *\param t_t Time
     *\author imabramon
     *\version 0.1
     */
    virtual void timer(int t_t) = 0;
    /*!
     *\brief Glut keyboard function interface
     *\author imabramon
     *\version 0.1
     */
    void keyboard(unsigned char t_key, int t_x, int t_y);
    
    /*!
     *\brief Getting the current window width
     *\return Current window width
     *\author imabramon
     *\version 0.1
     */
    virtual int getWidth() const = 0;
    /*!
     *\brief Getting the current window height
     *\return Current window height
     *\author imabramon
     *\version 0.1
     */
    virtual int getHeight() const = 0;
    
    /*!
     *\brief Connect event to action
     *\param t_event Event
     *\param t_action Action
     *\author imabramon
     *\version 0.1
     */
    
    void connect(AbstractEvent * t_event, AbstractAction * t_action);
    
    /*!
     *\brief Returns a window title
     *\author imabramon
     *\version 0.1
     */
    virtual std::string getCurrentWindowTitle() = 0;
protected:
    /*!
     *\brief Destructor interface
     *\author imabramon
     *\version 0.1
     */
    virtual void __destructor() = 0;
    
    
    //! Keyboard object
    Keyboard m_keyboard;
private:
    //! Action storage
    std::vector<AbstractAction *> m_actions;
};

#endif /* Controler_hpp */
