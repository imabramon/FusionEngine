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
    
    /*!
     *\brief Notification of all connected actions
     *\author imabramon
     *\version 0.1
     */
    void notify();
    /*!
     *\brief Connect action with this event
     *\author imabramon
     *\version 0.1
     *\param t_action Action
     */
    void connect(AbstractAction * t_action);
    /*!
     *\brief Dissconnect action from this event
     *\author imabramon
     *\version 0.1
     *\param t_action Action
     */
    void disconnect(AbstractAction * t_action);
protected:
    /*!
     *\brief Distructor interface
     *\author imabramon
     *\version 0.1
     */
    virtual void __destructor();
private:
    //! Actions subscribed to this event
    std::vector<AbstractAction *> m_actions;
};

#endif /* AbstractEvent_hpp */
