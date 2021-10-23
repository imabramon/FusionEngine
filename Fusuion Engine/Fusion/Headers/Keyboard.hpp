#ifndef Keyboard_hpp
#define Keyboard_hpp

#include <map>

#include "Keys.h"
#include "AbstractEvent.hpp"

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
