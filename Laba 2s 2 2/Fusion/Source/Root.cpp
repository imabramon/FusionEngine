#include "Root.hpp"

#include <cassert>

template <class T>
Root<T>::Root(){
    m_data = nullptr;
}

template <class T>
Root<T>::Root(T & t_object){
    m_data = new T(t_object);
}

template <class T>
Root<T>::Root(Root<T> & t_root){
    m_data = t_root.m_data;
}

template <class T>
Root<T>::~Root(){
    if(m_data != nullptr){
        delete m_data;
    }
}

template <class T>
Root<T> & Root<T>::operator =(T * t_pointer){
    if(m_data != nullptr){
        delete m_data;
    }
}

template <class T>
Root<T>::operator T&(){
    assert(m_data == nullptr);
    return *m_data;
}
