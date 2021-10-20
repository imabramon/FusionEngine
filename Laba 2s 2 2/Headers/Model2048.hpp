#ifndef Model2048_hpp
#define Model2048_hpp

#include <vector>

#include "../Fusion/Headers/TypeAlias.h"

class Model2048 {
public:
    Model2048();
    ~Model2048();
    
    int & score();
    int & bestScore();
    int & emptyCount();
    
    intMatrix_t & data();
private:
    int m_score; //текущий счет
    int m_best; //лучший счет
    int m_emptyCount; //количество свобожных клеток
    
    intMatrix_t m_data; //данные о клетках
};


#endif /* Model2048_hpp */
