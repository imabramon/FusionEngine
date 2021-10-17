#define GL_SILENCE_DEPRECATION

#include "../Headers/Controler2048.hpp"
#include "../Fusion/Headers/Glut.h"
#include "../Fusion/Headers/Draw.hpp"
#include "../Fusion/Headers/Colors.h"
#include "../Headers/Field.hpp"
#include "../Fusion/Headers/TextBox.hpp"

#include <iostream>
#include <fstream>

using namespace std;

Controler2048::Controler2048(string t_path){
    ifstream in(t_path);
    string colorsPath;
    in >> m_size >> m_space >> m_cellSize >> m_cellRound >> m_bestPath >> colorsPath;
    in.close();
    
    ifstream b(m_bestPath);
    b >> m_best;
    b.close();
    
    m_scene = new GameObject(0, 0, NULL);
    
    m_field = new Field(m_space, m_cellSize + 2*m_space, m_scene, m_space, m_size, m_cellSize, m_cellRound, colorsPath);
    m_field->init();
    
    *m_scene += new TextBox(m_space, m_space, (m_field->getWidth()-m_space) / 2, m_cellSize, m_cellRound, m_scene, &m_score);
    *m_scene += new TextBox((m_field->getWidth()-m_space)/ 2 + m_space*2 , m_space, (m_field->getWidth()-m_space) / 2, m_cellSize, m_cellRound, m_scene, &m_best);
    
    *m_scene += m_field;
    
    m_field->createCell();
    m_field->createCell();
}

void Controler2048::display() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    m_scene->render();
    if(m_gameOver){
        draw::roundRect(getWidth()/2-100, getHeight()/2-50, 200, 100, 10, RGB(RED));
        draw::text(getWidth()/2, getHeight()/2, "GAME OVER", RGB(YELLOW));
    }
    
    glFlush();
}

void Controler2048::reshape(GLint t_width, GLint t_height) {
    glViewport(0, 0, t_width, t_height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, t_width, t_height, 0, -1.0, 1.0);
}

void Controler2048::mouse(int t_button, int t_state, int t_x, int t_y){
    
}

void Controler2048::timer(int t_time){
    
}

void Controler2048::keyboard(unsigned char t_key, int t_x, int t_y){
    pair<int, int> suc;
    switch (t_key) {
        case 27:
        {
            delete m_scene;
            ofstream b(m_bestPath);
            b << m_best;
            b.close();
            exit(0);
            break;
        }
        case 'w':
            if (!m_gameOver) suc = m_field->moveUp();
            break;
        case 's':
            if (!m_gameOver) suc = m_field->moveDown();
            break;
        case 'a':
            if (!m_gameOver) suc = m_field->moveLeft();
            break;
        case 'd':
            if (!m_gameOver) suc = m_field->moveRight();
            break;
        default:
            break;
    }
    
    if(!m_gameOver){
        if((suc.first) || (m_lastKey != t_key)) {
            m_field->createCell();
            m_score += suc.second;
            if(m_score > m_best) m_best = m_score;
        }
        m_lastKey = t_key;
        
        if(m_field->isFull()){
            m_gameOver = !m_field->check();
        }
    }
    
    glutPostRedisplay();
}

int Controler2048::getWidth() const{
    return m_field->getWidth() + m_space*2;
}

int Controler2048::getHeight() const{
    return m_field->getHeight() + m_cellSize + m_space*3;
}

