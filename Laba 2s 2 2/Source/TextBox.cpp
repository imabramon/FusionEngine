#include "../Headers/TextBox.hpp"

#include "../Headers/Glut.h"
#include "../Headers/Draw.hpp"
#include "../Headers/Colors.h"

#include <iostream>

using namespace std;

TextBox::TextBox(int tx, int ty, int w, int h, int tr, GameObject * p, int * s):GameObject(tx, ty, p), _score(s), _width(w), _height(h), _r(tr) {};

bool TextBox::isVisible() const{
    return 1;
}

int TextBox::getScore() const{
    return *_score;
}

void TextBox::_selfRender() const{
    draw::roundRect(getX(), getY(), _width, _height, _r, _getColor());
    string str = std::to_string(getScore());
    draw::text(getX()+_width/2, getY()+_height/2, str, RGB(BLACK));
}

RGB TextBox::_getColor() const{
    return RGB(WHITE);
}

string TextBox::getGameObjectType() const{
    return "TextBox";
}
