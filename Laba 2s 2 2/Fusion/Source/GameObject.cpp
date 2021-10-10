#include "../Headers/GameObject.hpp"


#include <iostream>

using namespace std;


GameObject::GameObject(int tx, int ty, GameObject * p){
    _x = tx;
    _y = ty;
    _parent = p;
    _child = vector<GameObject *>(0);
    _id = GameObject::_objectCount++;
    _visible = 1;
    
    if(GameObject::_log) cout << getGameObjectType() << "[" << _id << "] created" << endl;
}

GameObject::~GameObject(){
    if(GameObject::_log) cout << getGameObjectType() << "[" << _id << "] deleted" << endl;
    _delchilds();
}

void GameObject::init(){};
    
void GameObject::render() const{
    if(isVisible()) _selfRender();
    
    int size = (int) _child.size();
    
    for(int i = 0; i < size; i++) _child[i] -> render();
}

void GameObject::_delchilds(){
    int size = (int) _child.size();
    
    for(int i = 0; i < size; i++)
        if(_child[i]) {
            delete _child[i];
        }
}

void GameObject::_selfRender() const{};
    
int GameObject::getX() const{
    if(_parent == NULL){
        return _x;
    }
    
    return _parent->getX() + _x;
}

int GameObject::getY() const{
    if(_parent == NULL){
        return _y;
    }
    
    return _parent->getY() + _y;
}

bool GameObject::isVisible() const{
    return _visible;
}

string GameObject::getGameObjectType() const{
    return "GameObject";
}


GameObject & GameObject::operator +=(GameObject * obj){
    _child.push_back(obj);
    return *this;
}


