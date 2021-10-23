#include "../Headers/Draw.hpp"

#include "../Headers/Glut.h"
#include <cmath>


void draw::circle(int t_x, int t_y, int t_radius, RGB t_color){
    
    int  num_segments = 100;
    glClearColor(1.0,1.0,1.0,0.0);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(t_color.getRed(), t_color.getGreen(), t_color.getBlue());
    glVertex2f(t_x, t_y);
    for(int ii = 0; ii < num_segments+1; ii++)
    {
        double theta = 2.0f * 3.1415926f * ii / num_segments;//get the current angle

        int tx = t_radius * cos(theta);//calculate the x component
        int ty = t_radius * sin(theta);//calculate the y component

        glVertex2f(t_x + tx, t_y + ty);//output vertex

    }
    glEnd();
}

void draw::rect(int t_x, int t_y, int t_width, int t_height, RGB t_color){
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3ub(t_color.getRed(), t_color.getGreen(), t_color.getBlue());
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(t_x, t_y);
        glVertex2f(t_x, t_y+t_height);
        glVertex2f(t_x+t_width, t_y+t_height);
        glVertex2f(t_x+t_width, t_y);
    glEnd();
}

void draw::roundRect(int t_x, int t_y, int t_width, int t_height, int t_radius, RGB t_color){
    draw::circle(t_x+t_radius,
                 t_y+t_radius,
                 t_radius,
                 t_color);
    draw::circle(t_x+t_width-t_radius,
                 t_y+t_radius,
                 t_radius,
                 t_color);
    draw::circle(t_x+t_width-t_radius,
                 t_y+t_height-t_radius,
                 t_radius,
                 t_color);
    draw::circle(t_x+t_radius,
                 t_y+t_height-t_radius,
                 t_radius,
                 t_color);
    draw::rect(t_x+t_radius,
               t_y,
               t_width-2*t_radius,
               t_height,
               t_color);
    draw::rect(t_x,
               t_y+t_radius,
               t_width,
               t_height-2*t_radius,
               t_color);
    
}

void draw::text(int t_x, int t_y, std::string t_string, RGB t_color){
    glColor3ub(t_color.getRed(), t_color.getGreen(), t_color.getBlue());
    //int len = (int)str.length();
    int dx = 10, dy = 5;
    int size = (int)t_string.length();
    for(int i = 0; i < size; i++)
        dx += glutBitmapWidth(GLUT_BITMAP_TIMES_ROMAN_24, t_string[i]);
    glRasterPos2f(t_x - dx/2 + 5 , t_y+dy);

    
    for (int i = 0; i < size; i++) {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, t_string[i]);;  // Updates the position
    }
}
