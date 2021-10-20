#include "../Headers/Model2048.hpp"

Model2048::Model2048(int t_size): m_size(t_size), m_emptyCount(t_size*t_size){
    for(int i = 0; i < m_size; i++) m_data.push_back(std::vector<int>(m_size));
    
    for(int i = 0; i < m_size; i++){
        for(int j =0; j < m_size; j++){
            m_data[i][j] = 0;
        }
    }
    
    m_data[3][2] = 2;
}

Model2048::~Model2048(){}
    
int & Model2048::score() {
    return m_score;
}

int & Model2048::bestScore() {
    return m_best;
}

int & Model2048::emptyCount() {
    return m_emptyCount;
}

int & Model2048::size(){
    return m_size;
}

intMatrix_t & Model2048::data(){
    return m_data;
}

moveResult_t Model2048::moveUp(){
    int count = 0;
    int flag = 0;
    for(int i = 0; i < m_size; i++){
        moveResult_t temp = _columnMoveUp(i);
        flag += temp.first;
        count += temp.second;
    }
    return moveResult_t(flag, count);
}

moveResult_t Model2048::moveDown(){
    int count = 0;
    int flag = 0;
    for(int i = 0; i < m_size; i++){
        moveResult_t temp = _columnMoveDown(i);
        flag += temp.first;
        count += temp.second;
    }
    return moveResult_t(flag, count);
}

moveResult_t Model2048::moveLeft(){
    int count = 0;
    int flag = 0;
    for(int i = 0; i < m_size; i++){
        moveResult_t temp = _rowMoveLeft(i);
        flag += temp.first;
        count += temp.second;
    }
    return moveResult_t(flag, count);
}

moveResult_t Model2048::moveRight(){
    int count = 0;
    int flag = 0;
    for(int i = 0; i < m_size; i++){
        moveResult_t temp = _rowMoveRight(i);
        flag = temp.first;
        count += temp.second;
    }
    return moveResult_t(flag, count);
}

moveResult_t Model2048::_columnMoveUp(int t_column){
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
    
    return moveResult_t(suc, count);
}

moveResult_t Model2048::_columnMoveDown(int t_column){
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
    
    return moveResult_t(suc, count);
}

moveResult_t Model2048::_rowMoveLeft(int t_row){
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
    
    return moveResult_t(suc, count);
}

moveResult_t Model2048::_rowMoveRight(int t_row){
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
    
    return moveResult_t(suc, count);
}

int Model2048::_power(int t_number, int t_power){
    int p = 1;
    for(int i = 0; i < t_power; i++) p *= t_number;
    return p;
}

void Model2048::createCell(){
    std::cout << "Create cell" << std::endl;
    std::cout << m_emptyCount << std::endl;
    while(1 && m_emptyCount){
        int sx = rand() % m_size, sy = rand() % m_size;
        if(m_data[sy][sx] == 0){
            m_data[sy][sx]++;
            m_emptyCount--;
            break;
        }
    }
    
}

int Model2048::check() const{
    for(int i = 0; i < m_size-1; i++)
        for(int j = 0; j < m_size-1; j++)
            if(m_data[i][j] == m_data[i][j+1] || m_data[i][j] == m_data[i+1][j] || m_data[i+1][j+1] == m_data[i][j+1] || m_data[i+1][j+1] == m_data[i+1][j]) return 1;
    
    return 0;
}
