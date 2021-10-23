#define GL_SILENCE_DEPRECATION
#include "../Headers/AbstractControler.hpp"

AbstractControler::AbstractControler():m_actions(0), m_keyboard(){
    
}

AbstractControler::~AbstractControler(){
    for(auto i = m_actions.begin(); i != m_actions.end(); i++){
        if(*i != nullptr){
            delete *i;
        }
    }
}

void AbstractControler::keyboard(unsigned char t_key, int t_x, int t_y){
    m_keyboard.update(t_key, t_x, t_y);
    glutPostRedisplay();
}

void AbstractControler::connect(AbstractEvent * t_event, AbstractAction * t_action){
    t_event->connect(t_action);
    m_actions.push_back(t_action);
}
