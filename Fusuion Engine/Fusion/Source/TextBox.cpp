#include "../Headers/TextBox.hpp"

#include "../Headers/Glut.h"
#include "../Headers/Draw.hpp"
#include "../Headers/Colors.h"

#include <iostream>

using namespace std;

TextBox::TextBox():GameObject(), m_score(NULL), m_width(0), m_height(0), m_radius(0) {};

void TextBox::setPosition(int t_x, int t_y){
    m_x = t_x;
    m_y = t_y;
}

void TextBox::setSize(int t_width, int t_height){
    m_width = t_width;
    m_height = t_height;
}

void TextBox::setRadius(int t_radius){
    m_radius = t_radius;
}

void TextBox::setText(int * t_score){
    m_score = t_score;
}

void TextBox::setParent(GameObject * t_parent){
    m_parent = t_parent;
}

bool TextBox::isVisible() const{
    return 1;
}

int TextBox::getScore() const{
    return *m_score;
}

void TextBox::_selfRender() const{
    draw::roundRect(getX(), getY(), m_width, m_height, m_radius, _getColor());
    string str = std::to_string(getScore());
    draw::text(getX()+m_width/2, getY()+m_height/2, str, RGB(BLACK));
}

RGB TextBox::_getColor() const{
    return RGB(WHITE);
}

string TextBox::getGameObjectType() const{
    return "TextBox";
}
