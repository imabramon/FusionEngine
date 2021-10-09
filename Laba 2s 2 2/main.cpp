#define GL_SILENCE_DEPRECATION

#include <GLUT/glut.h>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>

#include "Headers/Draw.hpp"
#include "Headers/Colors.h"
#include "Headers/Game.hpp"
#include "Headers/Controler.hpp"
#include "Headers/Controler2048.hpp"

Game * Game::_game = NULL;
int GameObject::_objectCount = 0;
int GameObject::_log = 0;

using namespace std;

/*
 Управление на WASD на англ раскладке
 
 Файл настроек:
 <Размер сетки>
 <Размер отступа>
 <Размер клетки>
 <Размер скругления клетки>
 <Путь к файлу с лучшим счетом>
 <Путь к файлу с цветами>
 */

int main(int argc, char *argv[]){
    srand((int)time(NULL));
    glutInit(&argc,argv);
    Controler2048 controler("settings.txt"); 
    Game game2048(&controler);
    Game::init(&game2048);
    game2048.play();
    return 0;
}
