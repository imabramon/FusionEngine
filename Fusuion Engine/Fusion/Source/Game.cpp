#define GL_SILENCE_DEPRECATION

#include "../Headers/Game.hpp"

#include <iostream>
#include <fstream>

#include "../Headers/Colors.h"
#include "../Headers/Draw.hpp"

Game::Game(AbstractControler * t_controller){
    m_controler = t_controller;
    m_width = t_controller->getWidth();
    m_height = t_controller->getHeight();
}

void Game::display(){
    Game::m_game->m_controler->display();
}

void Game::reshape(GLint t_width, GLint t_height){
    Game::m_game->m_controler->reshape(t_width, t_height);
}

void Game::mouse(int t_button, int t_state, int t_x, int t_y){
    Game::m_game->m_controler->mouse(t_button, t_state, t_x, t_y);
}

void Game::timer(int t_time){
    Game::m_game->m_controler->timer(t_time);
}

void Game::keyboard(unsigned char t_key, int t_x, int t_y){
    Game::m_game->m_controler->keyboard(t_key, t_x, t_y);
}

void Game::init(Game * t_game){
    Game::m_game = t_game;
}

string Game::currentWindowTitle(){
    return m_controler->getCurrentWindowTitle();
}

void Game::play(){
    //glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(m_width, m_height);
    auto windowTitle = m_game->currentWindowTitle();
    glutCreateWindow(windowTitle.c_str());
    glutDisplayFunc(Game::display);
    glutReshapeFunc(Game::reshape);
    glutKeyboardFunc(Game::keyboard);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glutMainLoop();
}
