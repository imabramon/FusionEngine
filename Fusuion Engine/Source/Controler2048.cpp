#define GL_SILENCE_DEPRECATION

#include "../Fusion/Headers/Glut.h"
#include "../Fusion/Headers/Draw.hpp"
#include "../Fusion/Headers/Colors.h"
#include "../Fusion/Headers/TextBox.hpp"
#include "../Fusion/Headers/Keys.h"

#include "../Headers/Field.hpp"
#include "../Headers/Controler2048.hpp"

#include <iostream>
#include <fstream>

using namespace std;

Controler2048::Controler2048(string t_path): m_model(4){
    ifstream in(t_path);
    string colorsPath;
    int size;
    in >> size >> m_space >> m_cellSize >> m_cellRound >> m_bestPath >> colorsPath;
    in.close();
    
    ifstream b(m_bestPath);
    b >> m_model.bestScore();
    b.close();
    
    //View Init
    
    m_scene = new GameObject(0, 0, NULL);
    
    auto m_field = new Field(m_space, m_cellSize + 2*m_space, m_scene, m_space, m_model.size(), m_cellSize, m_cellRound, colorsPath, m_model.data());
    /*
     * auto m_field = new Field();
     * auto fieldX = m_space;
     * auto fieldY = m_cellSize + 2*m_space;
     * auto fieldWidth =;
     * auto fieldHeight =;
     * m_field->setPosition(fieldX,fieldY)
              ->setSize(fieldWidth, fieldHeight)
              ->setCellProps(...);
     */
    
    *m_scene += new TextBox(m_space, m_space, (m_field->getWidth()-m_space) / 2, m_cellSize, m_cellRound, m_scene, &m_model.score());
    
    *m_scene += new TextBox((m_field->getWidth()-m_space)/ 2 + m_space*2 , m_space, (m_field->getWidth()-m_space) / 2, m_cellSize, m_cellRound, m_scene, &m_model.bestScore());
    
    *m_scene += m_field;
    
    m_width = m_field->getWidth() + m_space*2;
    m_height = m_field->getHeight() + m_cellSize + m_space*3;
    
    //Actions Init
    
    connect(m_keyboard.keyPressed(Key::W), new Model2048::Action(&m_model, &Model2048::moveUp));
    connect(m_keyboard.keyPressed(Key::A), new Model2048::Action(&m_model, &Model2048::moveLeft));
    connect(m_keyboard.keyPressed(Key::S), new Model2048::Action(&m_model, &Model2048::moveDown));
    connect(m_keyboard.keyPressed(Key::D), new Model2048::Action(&m_model, &Model2048::moveRight));
    connect(m_keyboard.notDoublePressed(), new Model2048::Action(&m_model, &Model2048::createCell));
    
    
    m_model.createCell();
    m_model.createCell();
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

/*
void Controler2048::keyboard(unsigned char t_key, int t_x, int t_y){
    //pair<int, int> suc;
    switch (t_key) {
        case 27:
        {
            delete m_scene;
            ofstream b(m_bestPath);
            b << m_model.bestScore();
            b.close();
            exit(0);
            break;
        }
    
    if(!m_gameOver){
        cout << "Not game over" << endl;
        //
        if((suc.first) || (m_lastKey != t_key)) {
            cout << "Can create cell" << endl;
            m_model.createCell();
            m_model.score() += suc.second;
            if(m_model.score() > m_model.bestScore()) m_model.bestScore() = m_model.score();
        }
         
        if(m_lastKey != t_key)
            m_model.createCell();
        m_lastKey = t_key;
        
        if(m_model.isFull()){
            m_gameOver = !m_model.check();
        }
    }
    
    glutPostRedisplay();
}
 */

int Controler2048::getWidth() const{
    return m_width;
}

int Controler2048::getHeight() const{
    return m_height;
}

void Controler2048::__destructor(){
    delete m_scene;
}

