#ifndef Keyboard_hpp
#define Keyboard_hpp

#include <map>

#include "Keys.h"
#include "AbstractEvent.hpp"

/*!
 *\brief Class for interacting with the keyboard
 *\author imabramon
 *\version 1.0
 */

class Keyboard{
public:
    Keyboard();
    ~Keyboard();
    
    void update(unsigned char t_key, int t_x, int t_y);
    
    AbstractEvent * keyPressed(Key t_key);
    AbstractEvent * notDoublePressed();
private:
    std::map<Key, AbstractEvent *> m_events;
    Key m_lastKey;
    AbstractEvent * m_notDoublePressedEvent = nullptr;
};

#endif /* Keyboard_hpp */
