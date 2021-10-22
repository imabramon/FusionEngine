#include "../Headers/TextBox.hpp"

#include "../Headers/Glut.h"
#include "../Headers/Draw.hpp"
#include "../Headers/Colors.h"

#include <iostream>

using namespace std;

TextBox::TextBox(int t_x, int t_y, int t_width, int t_height, int t_radius, GameObject * t_parent, int * t_score):GameObject(t_x, t_y, t_parent), m_score(t_score), m_width(t_width), m_height(t_height), m_radius(t_radius) {};

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
