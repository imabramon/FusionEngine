#include "../Headers/Model2048.hpp"

Model2048::Model2048(){
    
}

Model2048::~Model2048(){
    
}

int & Model2048::score() {
    return m_score;
}

int & Model2048::bestScore() {
    return m_best;
}

int & Model2048::emptyCount() {
    return m_emptyCount;
}

intMatrix_t & Model2048::data(){
    return m_data;
}
