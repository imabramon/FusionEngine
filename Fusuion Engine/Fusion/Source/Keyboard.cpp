#include "../Headers/Keyboard.hpp"

#include <iostream>

Keyboard::Keyboard(): m_events(){
    
}

Keyboard::~Keyboard(){
    
}

void Keyboard::update(unsigned char t_key, int t_x, int t_y){
    std::cout << "Keyboard update: " << t_key << " " << t_x << " " << t_y << std::endl;
    
    Key key = static_cast<Key>(t_key);
    
    if(m_events.find(key) != m_events.end()){
        m_events[key]->notify();
    }
    
    if(m_lastKey != key){
        if(m_notDoublePressedEvent != nullptr){
            m_notDoublePressedEvent->notify();
        }
    }
    
    std::cout << "No such register event" << std::endl;
}

AbstractEvent * Keyboard::keyPressed(Key t_key){
    if(m_events.find(t_key) == m_events.end()){
        std::cout << "Register event with key \"" << static_cast<char>(t_key) << "\"" << std::endl;
        m_events[t_key] = new AbstractEvent;
    }
    
    return m_events[t_key];
}

AbstractEvent * Keyboard::notDoublePressed(){
    if(m_notDoublePressedEvent == nullptr){
        m_notDoublePressedEvent = new AbstractEvent;
    }
    
    return m_notDoublePressedEvent;
}
