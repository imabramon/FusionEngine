#ifndef Controler2048_hpp
#define Controler2048_hpp

#include "Glut.h"

#include "Controler.hpp"
#include "GameObject.hpp"
#include "Field.hpp"
#include <string>

using namespace std;


class Controler2048: public Controler{
public:
    Controler2048(string path); // path - путь к файлу с настройками игры
    ~Controler2048(){ delete _scene;}
    
    void display(); // функция отобржанеия
    void reshape(GLint w, GLint h); // функция изменения размера
    void mouse(int button, int state, int x, int y); // функция обработки мыши
    void timer(int t); // функция таймера
    void keyboard(unsigned char key, int x, int y); // функция обработки клавиатуры
    
    int getWidth() const; //получение ширины окна
    int getHeight() const; //получение высоты окна
private:
    GameObject * _scene; //Объект сцены
    
    Field * _field; //Объект поля
    
    unsigned char _lastKey = ' '; //Последняя нажатая клавиша
    
    int _score = 0; //текущий счет
    int _best = 0; //лучший счет
    int _size; //количество ячеек
    int _space; //растояние между объектами
    int _cellSize, _cellRound; //параметры ячейки
    
    bool _gameOver = false; //Проиграна ли игра?
    
    string _bestPath; //путь к файлу с лучшим счетом
};

#endif /* Controler2048_hpp */
