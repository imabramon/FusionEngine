#ifndef Model2048_hpp
#define Model2048_hpp

#include <vector>

class Model2048 {
public:
    Model2048();
    ~Model2048();
private:
    int m_score; //текущий счет
    int m_best; //лучший счет
    int m_emptyCount; //количество свобожных клеток
    
    std::vector<std::vector<int>> m_data; //данные о клетках
};


#endif /* Model2048_hpp */
