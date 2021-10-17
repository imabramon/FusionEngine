#ifndef Controler2048_hpp
#define Controler2048_hpp

#include "Glut.h"

#include "../Fusion/Headers/AbstractControler.hpp"
#include "../Fusion/Headers/GameObject.hpp"
#include "Field.hpp"

#include <string>

using namespace std;


class Controler2048: public AbstractControler{
public:
    Controler2048(string t_path); // path - путь к файлу с настройками игры
    ~Controler2048(){ delete m_scene;}
    
    void display() override; // функция отобржанеия
    void reshape(GLint t_width, GLint t_height) override; // функция изменения размера
    void mouse(int t_button, int t_state, int t_x, int t_y) override; // функция обработки мыши
    void timer(int t_time) override; // функция таймера
    void keyboard(unsigned char t_key, int t_x, int t_y) override; // функция обработки клавиатуры
    
    int getWidth() const override; //получение ширины окна
    int getHeight() const override; //получение высоты окна
private:
    GameObject * m_scene; //Объект сцены
    
    Field * m_field; //Объект поля
    
    unsigned char m_lastKey = ' '; //Последняя нажатая клавиша
    
    int m_score = 0; //текущий счет
    int m_best = 0; //лучший счет
    int m_size; //количество ячеек
    int m_space; //растояние между объектами
    int m_cellSize, m_cellRound; //параметры ячейки
    
    bool m_gameOver = false; //Проиграна ли игра?
    
    string m_bestPath; //путь к файлу с лучшим счетом
};

#endif /* Controler2048_hpp */
