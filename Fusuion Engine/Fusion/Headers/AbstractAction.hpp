#ifndef AbstractAction_hpp
#define AbstractAction_hpp

/*!
 *\brief Base class for Actions. Part of implementation of observer pattern
 *\author imabramon
 *\version 0.1
 */

class AbstractAction{
public:
    /*!
     *\brief Destructor
     *\author imabramon
     *\version 0.1
     */
    virtual ~AbstractAction(){}
    
    /*!
     *\brief Event Called Function
     *\author imabramon
     *\version 0.1
     */
    virtual void perform() = 0;
};

#endif /* AbstractAction_hpp */
