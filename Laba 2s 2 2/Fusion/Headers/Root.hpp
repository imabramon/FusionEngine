#ifndef Root_hpp
#define Root_hpp

template <class T>
class Root{
public:
    Root();
    Root(T & t_object);
    Root(Root<T> & t_root);
    ~Root();
    Root<T> & operator =(T * t_pointer);
    operator T&();
private:
    T * m_data;
};

#endif /* Root_hpp */
