#ifndef AbstractEvent_hpp
#define AbstractEvent_hpp

#include "AbstractAction.hpp"
#include <vector>

/*!
 *\brief Base class for Events. Part of implementation of observer pattern
 *\author imabramon
 *\version 1.0
 */


class AbstractEvent{
public:
    AbstractEvent();
    ~AbstractEvent();
    
    void notify();
    void connect(AbstractAction * t_action);
    void disconnect(AbstractAction * t_action);
protected:
    virtual void __destructor();
private:
    std::vector<AbstractAction *> m_actions;
};

#endif /* AbstractEvent_hpp */
