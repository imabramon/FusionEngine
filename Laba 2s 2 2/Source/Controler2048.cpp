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

Controler2048::Controler2048(string path){
    ifstream in(path);
    string colorsPath;
    in >> _size >> _space >> _cellSize >> _cellRound >> _bestPath >> colorsPath;
    in.close();
    
    ifstream b(_bestPath);
    b >> _best;
    b.close();
    
    _scene = new GameObject(0, 0, NULL);
    
    _field = new Field(_space, _cellSize + 2*_space, _scene, _space, _size, _cellSize, _cellRound, colorsPath);
    _field->init();
    
    *_scene += new TextBox(_space, _space, (_field->getWidth()-_space) / 2, _cellSize, _cellRound, _scene, &_score);
    *_scene += new TextBox((_field->getWidth()-_space)/ 2 + _space*2 , _space, (_field->getWidth()-_space) / 2, _cellSize, _cellRound, _scene, &_best);
    
    *_scene += _field;
    
    _field->createCell();
    _field->createCell();
}

void Controler2048::display() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    _scene->render();
    if(_gameOver){
        draw::roundRect(getWidth()/2-100, getHeight()/2-50, 200, 100, 10, RGB(RED));
        draw::text(getWidth()/2, getHeight()/2, "GAME OVER", RGB(YELLOW));
    }
    
    glFlush();
}

void Controler2048::reshape(GLint w, GLint h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, h, 0, -1.0, 1.0);
}

void Controler2048::mouse(int button, int state, int x, int y){
    
}

void Controler2048::timer(int t){
    
}

void Controler2048::keyboard(unsigned char key, int x, int y){
    pair<int, int> suc;
    switch (key) {
        case 27:
        {
            delete _scene;
            ofstream b(_bestPath);
            b << _best;
            b.close();
            exit(0);
            break;
        }
        case 'w':
            if (!_gameOver) suc = _field->moveUp();
            break;
        case 's':
            if (!_gameOver) suc = _field->moveDown();
            break;
        case 'a':
            if (!_gameOver) suc = _field->moveLeft();
            break;
        case 'd':
            if (!_gameOver) suc = _field->moveRight();
            break;
        default:
            break;
    }
    
    if(!_gameOver){
        if((suc.first) || (_lastKey != key)) {
            _field->createCell();
            _score += suc.second;
            if(_score > _best) _best = _score;
        }
        _lastKey = key;
        
        if(_field->isFull()){
            _gameOver = !_field->check();
        }
    }
    
    glutPostRedisplay();
}

int Controler2048::getWidth() const{
    return _field->getWidth() + _space*2;
}

int Controler2048::getHeight() const{
    return _field->getHeight() + _cellSize + _space*3;
}

