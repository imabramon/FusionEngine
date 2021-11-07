#ifndef AbstractAction_hpp
#define AbstractAction_hpp

/*!
 *\brief Base class for Actions. Part of implementation of observer pattern
 *\author imabramon
 *\version 1.0
 */

class AbstractAction{
public:
    /*!
     *\brief some brief
     *\author imabramon
     */
    virtual ~AbstractAction(){}
    
    /*!
     *\brief some brief
     *\author imabramon
     */
    virtual void perform() = 0;
};

#endif /* AbstractAction_hpp */
