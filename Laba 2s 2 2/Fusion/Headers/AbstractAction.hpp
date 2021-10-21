#ifndef AbstractAction_hpp
#define AbstractAction_hpp

class AbstractAction{
public:
    virtual ~AbstractAction(){}
    virtual void perform() = 0;
};

#endif /* AbstractAction_hpp */
