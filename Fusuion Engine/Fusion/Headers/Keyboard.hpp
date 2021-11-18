#ifndef Keyboard_hpp
#define Keyboard_hpp

#include <map>

#include "Keys.h"
#include "AbstractEvent.hpp"

/*!
 *\brief Class for interacting with the keyboard
 *\author imabramon
 *\version 0.1
 */
class Keyboard{
public:
    /*!
     *\brief Constructor
     *\author imabramon
     *\version 0.1
     */
    Keyboard();
    
    /*!
     *\brief Destructor
     *\author imabramon
     *\version 0.1
     */
    ~Keyboard();
    
    /*!
     *\brief Method interface to the glut
     *\author imabramon
     *\version 0.1
     */
    void update(unsigned char t_key, int t_x, int t_y);
    
    /*!
     *\brief Getting a pointer to a keypress event
     *\param t_key Key
     *\return Pointer to this event
     *\author imabramon
     *\version 0.1
     */
    AbstractEvent * keyPressed(Key t_key);
    
    /*!
     *\brief Getting a pointer to a not double press of key
     *\return Pointer to this event
     *\author imabramon
     *\version 0.1
     */
    AbstractEvent * notDoublePressed();
private:
    std::map<Key, AbstractEvent *> m_events;
    Key m_lastKey;
    AbstractEvent * m_notDoublePressedEvent = nullptr;
};

#endif /* Keyboard_hpp */
