#include "../Headers/AbstractEvent.hpp"

#include <iostream>

AbstractEvent::AbstractEvent():m_actions(0){}

AbstractEvent::~AbstractEvent(){
    __destructor();
}

void AbstractEvent::notify(){
    for(auto i = m_actions.begin(); i != m_actions.end(); i++){
        (*i)->perform();
    }
}

void AbstractEvent::connect(AbstractAction * t_action){
    std::cout << "Event \"" << this << "\" connected to Action \"" << t_action << "\"" << std::endl;
    m_actions.push_back(t_action);
}

void AbstractEvent::disconnect(AbstractAction * t_action){
    for(auto i = m_actions.begin(); i != m_actions.end(); i++){
        if(*i == t_action){
            m_actions.erase(i);
        }
    }
}

void AbstractEvent::__destructor(){}
