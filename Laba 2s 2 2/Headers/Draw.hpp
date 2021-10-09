#define GL_SILENCE_DEPRECATION

#ifndef Draw_hpp
#define Draw_hpp

#include <string>

#include "RGB.hpp"

namespace draw {
    void circle(int x, int y, int r, RGB rgb);
    /*
     Рисует закрашенный круг
     x, y - координаты
     r - радиус
     cr, cg, cb - цвет
     */

    void rect(int x, int y, int w, int h, RGB rgb);
    /*
    Рисует закрашенный круг
    x, y - координаты
    w, h - ширина и высота
    cr, cg, cb - цвет
    */

    void roundRect(int x, int y, int w, int h, int r, RGB rgb);
    /*
    Рисует закрашенный круг
    x, y - координаты
    w, h - ширина и высота
    r - радиус скругления
    cr, cg, cb - цвет
    */

    void text(int x, int y, std::string str, RGB rgb);


}

#endif /* Draw_hpp */
