#include "../Headers/Field.hpp"

#include <cstdlib>
#include <iostream>
#include <utility>
#include <fstream>

#include "../Headers/Cell2048.hpp"
#include "../Fusion/Headers/Draw.hpp"
#include "../Fusion/Headers/Colors.h"

using namespace std;

Field::Field(int t_x, int t_y, GameObject * t_parent,
             int t_space, int t_size, int t_cellSize,
             int t_cellRadius, string t_colorsPath, intMatrix_t & t_matrix): GameObject(t_x, t_y, t_parent), m_data(t_matrix)
{
    
    m_space = t_space;
    m_size = t_size;
    m_cellSize = t_cellSize;
    m_cellRound = t_cellRadius;
    m_width = (m_cellSize+m_space)*m_size + m_space;
    m_height = (m_cellSize+m_space)*m_size + m_space;
    m_emptyCount = m_size*m_size;
    
    ifstream in(t_colorsPath);
    
    int size;
    string tmp;
    
    in >> size;
    
    for(int i = 0; i < size; i++){
        in >> tmp;
        m_colors.push_back(tmp);
    }
    
    in.close();
}

void Field::createCell(){
    while(1 && m_emptyCount){
        int sx = rand() % m_size, sy = rand() % m_size;
        if(m_data[sy][sx] == 0){
            m_data[sy][sx]++;
            m_emptyCount--;
            break;
        }
    }
    
}

void Field::init(){
    for(int i = 0; i < m_size; i++){
        for(int j =0; j < m_size; j++){
            //m_data[i][j] = 0;
            *this += new Cell2048((m_cellSize+m_space)*j + m_space,
                                  (m_cellSize+m_space)*i + m_space,
                                  m_cellSize, m_cellSize,
                                  m_cellRound,
                                  this,
                                  &m_data[i][j],
                                  m_colors);
        }
    }
}


void Field::_selfRender() const{
    draw::roundRect(getX(),
                    getY(),
                    m_width,
                    m_height,
                    m_space,
                    RGB(GREY));
}

pair<int, int> Field::moveUp(){
    int count = 0;
    int flag = 0;
    for(int i = 0; i < m_size; i++){
        pair<int, int> temp = _columnMoveUp(i);
        flag += temp.first;
        count += temp.second;
    }
    return pair<int, int>(flag, count);
}

pair<int, int> Field::moveDown(){
    int count = 0;
    int flag = 0;
    for(int i = 0; i < m_size; i++){
        pair<int, int> temp = _columnMoveDown(i);
        flag += temp.first;
        count += temp.second;
    }
    return pair<int, int>(flag, count);
}

pair<int, int> Field::moveLeft(){
    int count = 0;
    int flag = 0;
    for(int i = 0; i < m_size; i++){
        pair<int, int> temp = _rowMoveLeft(i);
        flag += temp.first;
        count += temp.second;
    }
    return pair<int, int>(flag, count);
}

pair<int, int> Field::moveRight(){
    int count = 0;
    int flag = 0;
    for(int i = 0; i < m_size; i++){
        pair<int, int> temp = _rowMoveRight(i);
        flag = temp.first;
        count += temp.second;
    }
    return pair<int, int>(flag, count);
}

pair<int, int> Field::_columnMoveUp(int t_column){
    int suc = 0;
    int count = 0;
    for(int i = 0; i < m_size; i++){
        if(m_data[i][t_column] == 0){
            int j = i;
            for(; j < m_size; j++) if(m_data[j][t_column] != 0){
                m_data[i][t_column] = m_data[j][t_column];
                m_data[j][t_column] = 0;
                suc = 1;
                break;
            }
            
            if(j == m_size) break;
        }
    }
    
    for(int i = 0; i < m_size-1; i++){
        if(m_data[i][t_column] == 0) continue;
        if(m_data[i][t_column] == m_data[i+1][t_column]){
            m_data[i][t_column]++;
            m_data[i+1][t_column] = 0;
            m_emptyCount++;
            suc = 1;
            count += _power(2, m_data[i][t_column]);
        }
    }
    
    for(int i = 0; i < m_size; i++){
        if(m_data[i][t_column] == 0){
            int j = i;
            for(; j < m_size; j++) if(m_data[j][t_column] != 0){
                m_data[i][t_column] = m_data[j][t_column];
                m_data[j][t_column] = 0;
                suc = 1;
                break;
            }
            
            if(j == m_size) break;
        }
    }
    
    return pair<int, int>(suc, count);
}

pair<int, int> Field::_columnMoveDown(int t_column){
    int suc = 0;
    int count = 0;
    for(int i = 0; i < m_size; i++){
        if(m_data[m_size-1-i][t_column] == 0){
            int j = i;
            for(; j < m_size; j++) if(m_data[m_size-1-j][t_column] != 0){
                m_data[m_size-1-i][t_column] = m_data[m_size-1-j][t_column];
                m_data[m_size-1-j][t_column] = 0;
                suc = 1;
                break;
            }
            
            if(j == m_size) break;
        }
    }
    
    for(int i = 0; i < m_size-1; i++){
        if(m_data[m_size-1-i][t_column] == 0) continue;
        if(m_data[m_size-1-i][t_column] == m_data[m_size-1-i-1][t_column]){
            m_data[m_size-1-i][t_column]++;
            m_data[m_size-1-i-1][t_column] = 0;
            m_emptyCount++;
            count += _power(2, m_data[m_size-1-i][t_column]);
            suc = 1;
        }
    }
    
    for(int i = 0; i < m_size; i++){
        if(m_data[m_size-1-i][t_column] == 0){
            int j = i;
            for(; j < m_size; j++) if(m_data[m_size-1-j][t_column] != 0){
                m_data[m_size-1-i][t_column] = m_data[m_size-1-j][t_column];
                m_data[m_size-1-j][t_column] = 0;
                suc = 1;
                break;
            }
            
            if(j == m_size) break;
        }
    }
    
    return pair<int, int>(suc, count);
}

pair<int, int> Field::_rowMoveLeft(int t_row){
    int suc = 0;
    int count = 0;
    for(int i = 0; i < m_size; i++){
        if(m_data[t_row][i] == 0){
            int j = i;
            for(; j < m_size; j++) if(m_data[t_row][j] != 0){
                m_data[t_row][i] = m_data[t_row][j];
                m_data[t_row][j] = 0;
                suc = 1;
                break;
            }
            
            if(j == m_size) break;
        }
    }
    
    for(int i = 0; i < m_size-1; i++){
        if(m_data[t_row][i] == 0) continue;
        if(m_data[t_row][i] == m_data[t_row][i+1]){
            m_data[t_row][i]++;
            m_data[t_row][i+1] = 0;
            m_emptyCount++;
            suc = 1;
            count += _power(2, m_data[t_row][i]);
        }
    }
    
    for(int i = 0; i < m_size; i++){
        if(m_data[t_row][i] == 0){
            int j = i;
            for(; j < m_size; j++) if(m_data[t_row][j] != 0){
                m_data[t_row][i] = m_data[t_row][j];
                m_data[t_row][j] = 0;
                suc = 1;
                break;
            }
            
            if(j == m_size) break;
        }
    }
    
    return pair<int, int>(suc, count);
}

pair<int, int> Field::_rowMoveRight(int t_row){
    int suc = 0;
    int count = 0;
    for(int i = 0; i < m_size; i++){
        if(m_data[t_row][m_size-1-i] == 0){
            int j = i;
            for(; j < m_size; j++) if(m_data[t_row][m_size-1-j] != 0){
                m_data[t_row][m_size-1-i] = m_data[t_row][m_size-1-j];
                m_data[t_row][m_size-1-j] = 0;
                suc = 1;
                break;
            }
            
            if(j == m_size) break;
        }
    }
    
    for(int i = 0; i < m_size-1; i++){
        if(m_data[t_row][m_size-1-i] == 0) continue;
        if(m_data[t_row][m_size-1-i] == m_data[t_row][m_size-1-i-1]){
            m_data[t_row][m_size-1-i]++;
            m_data[t_row][m_size-1-i-1] = 0;
            m_emptyCount++;
            suc = 1;
            count += _power(2, m_data[t_row][m_size-1-i]);
        }
    }
    
    for(int i = 0; i < m_size; i++){
        if(m_data[t_row][m_size-1-i] == 0){
            int j = i;
            for(; j < m_size; j++) if(m_data[t_row][m_size-1-j] != 0){
                m_data[t_row][m_size-1-i] = m_data[t_row][m_size-1-j];
                m_data[t_row][m_size-1-j] = 0;
                suc = 1;
                break;
            }
            
            if(j == m_size) break;
        }
    }
    
    return pair<int, int>(suc, count);
}

int Field::getWidth() const{
    return m_width;
}

int Field::getHeight() const{
    return m_height;
}

int Field::_power(int t_number, int t_power){
    int p = 1;
    for(int i = 0; i < t_power; i++) p *= t_number;
    return p;
}

int Field::check() const{
    for(int i = 0; i < m_size-1; i++)
        for(int j = 0; j < m_size-1; j++)
            if(m_data[i][j] == m_data[i][j+1] || m_data[i][j] == m_data[i+1][j] || m_data[i+1][j+1] == m_data[i][j+1] || m_data[i+1][j+1] == m_data[i+1][j]) return 1;
    
    return 0;
}

int Field::isFull() const{
    return m_emptyCount == 0;
}


string Field::getGameObjectType() const{
    return "Field";
}
