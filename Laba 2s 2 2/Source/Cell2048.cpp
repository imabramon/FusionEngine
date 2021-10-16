#include "../Headers/Cell2048.hpp"

Cell2048::Cell2048(int t_x, int t_y, int t_width, int t_height,
                   int t_radius, GameObject * t_parent,
                   int * t_score, vector<RGB> & t_colors):
TextBox(t_x, t_y, t_width, t_height, t_radius, t_parent, t_score),
m_colors(t_colors){
    
};

bool Cell2048::isVisible() const{
    if(m_score == NULL) return 0;
    return *m_score > 0;
}

int Cell2048::getScore() const{
    int p = 1;
    for(int i = 0; i < *m_score; i++) p *= 2;
    return p;
}

RGB Cell2048::_getColor() const{
    return m_colors[*m_score % m_colors.size() - 1];
}
