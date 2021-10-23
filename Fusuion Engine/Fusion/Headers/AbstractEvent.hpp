#ifndef AbstractEvent_hpp
#define AbstractEvent_hpp

#include "AbstractAction.hpp"
#include <vector>

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
