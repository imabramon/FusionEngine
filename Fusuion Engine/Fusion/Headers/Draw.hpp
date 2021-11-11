#define GL_SILENCE_DEPRECATION

#ifndef Draw_hpp
#define Draw_hpp

#include <string>

#include "RGB.hpp"

namespace draw {
    /*!
     *\brief Draw a circle
     *\author imabramon
     *\version 1.0
     *\param t_x X coordinate
     *\param t_y Y coordinate
     *\param t_radius Circle radius
     *\param t_color Circle color
     */
    void circle(int t_x, int t_y, int t_radius, RGB t_color);
    
    /*!
     *\brief Draw a rectangle
     *\author imabramon
     *\version 1.0
     *\param t_x X coordinate
     *\param t_y Y coordinate
     *\param t_width Rectangle width
     *\param t_height Rectangle height
     *\param t_color Rectangle color
     */
    void rect(int t_x, int t_y, int t_width, int t_height, RGB t_color);
    
    /*!
     *\brief Draw a rounded rectangle
     *\author imabramon
     *\version 1.0
     *\param t_x X coordinate
     *\param t_y Y coordinate
     *\param t_width Rectangle width
     *\param t_height Rectangle height
     *\param t_radius Rounding radius
     *\param t_color Rectangle color
     */
    void roundRect(int t_x, int t_y, int t_width, int t_height, int t_radius, RGB t_color);
    
    /*!
     *\brief Draw a text
     *\author imabramon
     *\version 1.0
     *\param t_x X coordinate
     *\param t_y Y coordinate
     *\param t_string Text
     *\param t_color Text color
     */
    void text(int t_x, int t_y, std::string t_string, RGB t_color);
}

#endif /* Draw_hpp */
