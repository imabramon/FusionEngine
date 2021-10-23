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
    m_cellSize = t_cellSize;
    m_cellRound = t_cellRadius;
    m_width = (m_cellSize+m_space)*t_size + m_space;
    m_height = (m_cellSize+m_space)*t_size + m_space;
    m_emptyCount = t_size*t_size;
    m_size = t_size;
    
    ifstream in(t_colorsPath);
    
    int size;
    string tmp;
    
    in >> size;
    
    for(int i = 0; i < size; i++){
        in >> tmp;
        m_colors.push_back(tmp);
    }
    
    in.close();
    
    for(int i = 0; i < m_size; i++){
        for(int j =0; j < m_size; j++){
            //m_data[i][j] = 0;
            *this += new Cell2048((m_cellSize+m_space)*j + m_space,
                                  (m_cellSize+m_space)*i + m_space,
                                  m_cellSize, m_cellSize,m_cellRound,
                                  this,
                                  &m_data[i][j],
                                  m_colors);
        }
    }
}


void Field::_selfRender() const{
    draw::roundRect(getX(), getY(),
                    m_width, m_height,
                    m_space,
                    RGB(GREY));
}

int Field::getWidth() const{
    return m_width;
}

int Field::getHeight() const{
    return m_height;
}



string Field::getGameObjectType() const{
    return "Field";
}
