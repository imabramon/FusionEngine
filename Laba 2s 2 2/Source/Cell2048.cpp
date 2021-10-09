#include "../Headers/Cell2048.hpp"

Cell2048::Cell2048(int tx, int ty, int w, int h, int r, GameObject * p, int * s, vector<RGB> & c):TextBox(tx, ty, w, h, r, p, s), _colors(c){};

bool Cell2048::isVisible() const{
    if(_score == NULL) return 0;
    return *_score > 0;
}

int Cell2048::getScore() const{
    int p = 1;
    for(int i = 0; i < *_score; i++) p *= 2;
    return p;
}

RGB Cell2048::_getColor() const{
    return _colors[*_score % _colors.size() - 1];
}
