#define GL_SILENCE_DEPRECATION

#ifndef Draw_hpp
#define Draw_hpp

#include <string>

#include "RGB.hpp"

namespace draw {
    void circle(int t_x, int t_y, int t_radius, RGB t_color);
    /*
     Рисует закрашенный круг
     x, y - координаты
     r - радиус
     cr, cg, cb - цвет
     */

    void rect(int t_x, int t_y, int t_width, int t_height, RGB t_colors);
    /*
    Рисует закрашенный круг
    x, y - координаты
    w, h - ширина и высота
    cr, cg, cb - цвет
    */

    void roundRect(int t_x, int t_y, int t_width, int t_height, int t_radius, RGB t_color);
    /*
    Рисует закрашенный круг
    x, y - координаты
    w, h - ширина и высота
    r - радиус скругления
    cr, cg, cb - цвет
    */

    void text(int t_x, int t_y, std::string t_string, RGB t_colors);


}

#endif /* Draw_hpp */
