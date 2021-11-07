#ifndef AbstractAction_hpp
#define AbstractAction_hpp

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
