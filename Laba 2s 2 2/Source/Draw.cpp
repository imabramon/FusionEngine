#include "../Headers/Draw.hpp"

#include "../Headers/Glut.h"
#include <cmath>


void draw::circle(int x, int y, int r, RGB rgb)
/*
Рисует закрашенный круг
x, y - координаты
r - радиус
cr, cg, cb - цвет
*/
{
    
    int  num_segments = 100;
    glClearColor(1.0,1.0,1.0,0.0);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(rgb.getRed(), rgb.getGreen(), rgb.getBlue());
    glVertex2f(x, y);
    for(int ii = 0; ii < num_segments+1; ii++)
    {
        double theta = 2.0f * 3.1415926f * ii / num_segments;//get the current angle

        int tx = r * cos(theta);//calculate the x component
        int ty = r * sin(theta);//calculate the y component

        glVertex2f(x + tx, y + ty);//output vertex

    }
    glEnd();
}

void draw::rect(int x, int y, int w, int h, RGB rgb)
/*
Рисует закрашенный круг
x, y - координаты
w, h - ширина и высота
cr, cg, cb - цвет
*/
{
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3ub(rgb.getRed(), rgb.getGreen(), rgb.getBlue());
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y);
        glVertex2f(x, y+h);
        glVertex2f(x+w, y+h);
        glVertex2f(x+w, y);
    glEnd();
}

void draw::roundRect(int x, int y, int w, int h, int r, RGB rgb)
/*
Рисует закрашенный круг
x, y - координаты
w, h - ширина и высота
r - радиус скругления
cr, cg, cb - цвет
*/
{
    draw::circle(x+r, y+r, r, rgb);
    draw::circle(x+w-r, y+r, r, rgb);
    draw::circle(x+w-r, y+h-r, r, rgb);
    draw::circle(x+r, y+h-r, r, rgb);
    draw::rect(x+r, y, w-2*r, h, rgb);
    draw::rect(x, y+r, w, h-2*r, rgb);
    
}

void draw::text(int x, int y, std::string str, RGB rgb){
    glColor3ub(rgb.getRed(), rgb.getGreen(), rgb.getBlue());
    //int len = (int)str.length();
    int dx = 10, dy = 5;
    int size = (int)str.length();
    for(int i = 0; i < size; i++)
        dx += glutBitmapWidth(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
    glRasterPos2f(x - dx/2 + 5 , y+dy);

    
    for (int i = 0; i < size; i++) {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);;  // Updates the position
    }
}
