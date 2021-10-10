#define GL_SILENCE_DEPRECATION

#include "../Headers/Game.hpp"

#include <iostream>
#include <fstream>

#include "../Headers/Colors.h"
#include "../Headers/Draw.hpp"

Game::Game(Controler * c){
    _controler = c;
    _width = c->getWidth();
    _height = c->getHeight();
}

void Game::display(){
    Game::_game->_controler->display();
}

void Game::reshape(GLint w, GLint h){
    Game::_game->_controler->reshape(w, h);
}

void Game::mouse(int button, int state, int x, int y){
    Game::_game->_controler->mouse(button, state, x, y);
}

void Game::timer(int t){
    Game::_game->_controler->timer(t);
}

void Game::keyboard(unsigned char key, int x, int y){
    Game::_game->_controler->keyboard(key, x, y);
}

void Game::init(Game * g){
    Game::_game = g;
}

void Game::play(){
    //glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(_width, _height);
    glutCreateWindow("2048 Game");
    glutDisplayFunc(Game::display);
    glutReshapeFunc(Game::reshape);
    glutKeyboardFunc(Game::keyboard);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glutMainLoop();
}

/*
   glClear(GL_COLOR_BUFFER_BIT);
   Draw::RoundRect(200, 200, 100, 100, 10, GREEN);
   Draw::Circle(250, 250, 50, RED);
   Draw::Rect(275, 250, 50, 50, BLUE);
   
   glFlush();*/


/*
glViewport(0, 0, w, h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0, w, 0, h, -1.0, 1.0);*/
