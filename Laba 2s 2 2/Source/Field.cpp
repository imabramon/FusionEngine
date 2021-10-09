#include "../Headers/Field.hpp"

#include <cstdlib>
#include <iostream>
#include <utility>
#include <fstream>

#include "../Headers/Cell2048.hpp"
#include "../Headers/Draw.hpp"
#include "../Headers/Colors.h"

using namespace std;

Field::Field(int tx, int ty, GameObject * p, int sp, int sz, int c_z, int c_r, string colorsPath): GameObject(tx, ty, p){
    _space = sp;
    _size = sz;
    _cellSize = c_z;
    _cellRound = c_r;
    _width = (_cellSize+_space)*_size + _space;
    _height = (_cellSize+_space)*_size + _space;
    _emptyCount = _size*_size;
    for(int i = 0; i < _size; i++) _data.push_back(vector<int>(_size));
    
    
    ifstream in(colorsPath);
    
    int size;
    string tmp;
    
    in >> size;
    
    for(int i = 0; i < size; i++){
        in >> tmp;
        _colors.push_back(tmp);
    }
    
    /*
    _colors.push_back(RGB("53DF00"));
    _colors.push_back(RGB("58A72A"));
    _colors.push_back(RGB("369100"));
    _colors.push_back(RGB("7EEF3C"));
    _colors.push_back(RGB("9CEF6C"));
    _colors.push_back(RGB("00A876"));
    _colors.push_back(RGB("207E62"));
    _colors.push_back(RGB("006D4C"));
    _colors.push_back(RGB("35D4A4"));
    _colors.push_back(RGB("5FD4B1"));
     */
    
    in.close();
}

void Field::createCell(){
    while(1 && _emptyCount){
        int sx = rand() % _size, sy = rand() % _size;
        if(_data[sy][sx] == 0){
            _data[sy][sx]++;
            _emptyCount--;
            break;
        }
    }
    
}

void Field::init(){
    for(int i = 0; i < _size; i++){
        for(int j =0; j < _size; j++){
            _data[i][j] = 0;
            *this += new Cell2048((_cellSize+_space)*j + _space, (_cellSize+_space)*i + _space, _cellSize, _cellSize, _cellRound, this, &_data[i][j], _colors);
        }
    }
}


void Field::_selfRender() const{
    draw::roundRect(getX(), getY(), _width, _height, _space, RGB(GREY));
}

pair<int, int> Field::moveUp(){
    int count = 0;
    int flag = 0;
    for(int i = 0; i < _size; i++){
        pair<int, int> temp = _colMoveUp(i);
        flag += temp.first;
        count += temp.second;
    }
    return pair<int, int>(flag, count);
}

pair<int, int> Field::moveDown(){
    int count = 0;
    int flag = 0;
    for(int i = 0; i < _size; i++){
        pair<int, int> temp = _colMoveDown(i);
        flag += temp.first;
        count += temp.second;
    }
    return pair<int, int>(flag, count);
}

pair<int, int> Field::moveLeft(){
    int count = 0;
    int flag = 0;
    for(int i = 0; i < _size; i++){
        pair<int, int> temp = _rowMoveLeft(i);
        flag += temp.first;
        count += temp.second;
    }
    return pair<int, int>(flag, count);
}

pair<int, int> Field::moveRight(){
    int count = 0;
    int flag = 0;
    for(int i = 0; i < _size; i++){
        pair<int, int> temp = _rowMoveRight(i);
        flag = temp.first;
        count += temp.second;
    }
    return pair<int, int>(flag, count);
}

pair<int, int> Field::_colMoveUp(int n){
    int suc = 0;
    int count = 0;
    for(int i = 0; i < _size; i++){
        if(_data[i][n] == 0){
            int j = i;
            for(; j < _size; j++) if(_data[j][n] != 0){
                _data[i][n] = _data[j][n];
                _data[j][n] = 0;
                suc = 1;
                break;
            }
            
            if(j == _size) break;
        }
    }
    
    for(int i = 0; i < _size-1; i++){
        if(_data[i][n] == 0) continue;
        if(_data[i][n] == _data[i+1][n]){
            _data[i][n]++;
            _data[i+1][n] = 0;
            _emptyCount++;
            suc = 1;
            count += _power(2, _data[i][n]);
        }
    }
    
    for(int i = 0; i < _size; i++){
        if(_data[i][n] == 0){
            int j = i;
            for(; j < _size; j++) if(_data[j][n] != 0){
                _data[i][n] = _data[j][n];
                _data[j][n] = 0;
                suc = 1;
                break;
            }
            
            if(j == _size) break;
        }
    }
    
    return pair<int, int>(suc, count);
}

pair<int, int> Field::_colMoveDown(int n){
    int suc = 0;
    int count = 0;
    for(int i = 0; i < _size; i++){
        if(_data[_size-1-i][n] == 0){
            int j = i;
            for(; j < _size; j++) if(_data[_size-1-j][n] != 0){
                _data[_size-1-i][n] = _data[_size-1-j][n];
                _data[_size-1-j][n] = 0;
                suc = 1;
                break;
            }
            
            if(j == _size) break;
        }
    }
    
    for(int i = 0; i < _size-1; i++){
        if(_data[_size-1-i][n] == 0) continue;
        if(_data[_size-1-i][n] == _data[_size-1-i-1][n]){
            _data[_size-1-i][n]++;
            _data[_size-1-i-1][n] = 0;
            _emptyCount++;
            count += _power(2, _data[_size-1-i][n]);
            suc = 1;
        }
    }
    
    for(int i = 0; i < _size; i++){
        if(_data[_size-1-i][n] == 0){
            int j = i;
            for(; j < _size; j++) if(_data[_size-1-j][n] != 0){
                _data[_size-1-i][n] = _data[_size-1-j][n];
                _data[_size-1-j][n] = 0;
                suc = 1;
                break;
            }
            
            if(j == _size) break;
        }
    }
    
    return pair<int, int>(suc, count);
}

pair<int, int> Field::_rowMoveLeft(int n){
    int suc = 0;
    int count = 0;
    for(int i = 0; i < _size; i++){
        if(_data[n][i] == 0){
            int j = i;
            for(; j < _size; j++) if(_data[n][j] != 0){
                _data[n][i] = _data[n][j];
                _data[n][j] = 0;
                suc = 1;
                break;
            }
            
            if(j == _size) break;
        }
    }
    
    for(int i = 0; i < _size-1; i++){
        if(_data[n][i] == 0) continue;
        if(_data[n][i] == _data[n][i+1]){
            _data[n][i]++;
            _data[n][i+1] = 0;
            _emptyCount++;
            suc = 1;
            count += _power(2, _data[n][i]);
        }
    }
    
    for(int i = 0; i < _size; i++){
        if(_data[n][i] == 0){
            int j = i;
            for(; j < _size; j++) if(_data[n][j] != 0){
                _data[n][i] = _data[n][j];
                _data[n][j] = 0;
                suc = 1;
                break;
            }
            
            if(j == _size) break;
        }
    }
    
    return pair<int, int>(suc, count);
}

pair<int, int> Field::_rowMoveRight(int n){
    int suc = 0;
    int count = 0;
    for(int i = 0; i < _size; i++){
        if(_data[n][_size-1-i] == 0){
            int j = i;
            for(; j < _size; j++) if(_data[n][_size-1-j] != 0){
                _data[n][_size-1-i] = _data[n][_size-1-j];
                _data[n][_size-1-j] = 0;
                suc = 1;
                break;
            }
            
            if(j == _size) break;
        }
    }
    
    for(int i = 0; i < _size-1; i++){
        if(_data[n][_size-1-i] == 0) continue;
        if(_data[n][_size-1-i] == _data[n][_size-1-i-1]){
            _data[n][_size-1-i]++;
            _data[n][_size-1-i-1] = 0;
            _emptyCount++;
            suc = 1;
            count += _power(2, _data[n][_size-1-i]);
        }
    }
    
    for(int i = 0; i < _size; i++){
        if(_data[n][_size-1-i] == 0){
            int j = i;
            for(; j < _size; j++) if(_data[n][_size-1-j] != 0){
                _data[n][_size-1-i] = _data[n][_size-1-j];
                _data[n][_size-1-j] = 0;
                suc = 1;
                break;
            }
            
            if(j == _size) break;
        }
    }
    
    return pair<int, int>(suc, count);
}

int Field::getWidth() const{
    return _width;
}

int Field::getHeight() const{
    return _height;
}

int Field::_power(int n, int q){
    int p = 1;
    for(int i = 0; i < q; i++) p *= n;
    return p;
}

int Field::check() const{
    for(int i = 0; i < _size-1; i++)
        for(int j = 0; j < _size-1; j++)
            if(_data[i][j] == _data[i][j+1] || _data[i][j] == _data[i+1][j] || _data[i+1][j+1] == _data[i][j+1] || _data[i+1][j+1] == _data[i+1][j]) return 1;
    
    return 0;
}

int Field::isFull() const{
    return _emptyCount == 0;
}


string Field::getGameObjectType() const{
    return "Field";
}
