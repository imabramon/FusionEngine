#include "../Headers/GameObject.hpp"


#include <iostream>

using namespace std;


GameObject::GameObject(int t_x, int t_y, GameObject * t_parent){
    m_x = t_x;
    m_y = t_y;
    m_parent = t_parent;
    m_child = vector<GameObject *>(0);
    m_id = GameObject::m_objectCount++;
    m_visible = 1;
    
    if(GameObject::m_log) cout << getGameObjectType() << "[" << m_id << "] created" << endl;
}

GameObject::~GameObject(){
    if(GameObject::m_log) cout << getGameObjectType() << "[" << m_id << "] deleted" << endl;
    _delchilds();
}

void GameObject::init(){};
    
void GameObject::render() const{
    if(isVisible()) _selfRender();
    
    int size = (int) m_child.size();
    
    for(int i = 0; i < size; i++) m_child[i] -> render();
}

void GameObject::_delchilds(){
    int size = (int) m_child.size();
    
    for(int i = 0; i < size; i++)
        if(m_child[i]) {
            delete m_child[i];
        }
}

void GameObject::_selfRender() const{};
    
int GameObject::getX() const{
    if(m_parent == NULL){
        return m_x;
    }
    
    return m_parent->getX() + m_x;
}

int GameObject::getY() const{
    if(m_parent == NULL){
        return m_y;
    }
    
    return m_parent->getY() + m_y;
}

bool GameObject::isVisible() const{
    return m_visible;
}

string GameObject::getGameObjectType() const{
    return "GameObject";
}


GameObject & GameObject::operator +=(GameObject * t_object){
    m_child.push_back(t_object);
    return *this;
}


