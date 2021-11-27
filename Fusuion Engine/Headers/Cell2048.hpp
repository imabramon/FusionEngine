#ifndef Cell2048_hpp
#define Cell2048_hpp

#include "TextBox.hpp"
#include "RGB.hpp"

/*!
 *\brief A class that displays a cell and changes its color depending on the cell data
 *\author imabramon
 *\version 0.1
*/
class Cell2048: public TextBox{
public:
    /*!
     *\brief Contructor.
     *\param t_x X coordinate
     *\param t_y Y coordinate
     *\param t_width Cell width
     *\param t_height Cell height
     *\param t_radius Cell border radius
     *\param t_parent Parent object
     *\param t_score Score pointer
     *\param t_colors Color sequence
     *\author imabramon
     *\version 0.1
    */
    Cell2048(int t_x, int t_y, int t_width, int t_height, int t_radius, GameObject * t_parent, int * t_score, vector<RGB> & t_colors);

    /*!
     *\brief Reimplementation of visible method
     *\return True if score is greater than zero else false
     *\author imabramon
     *\version 0.1
    */
    bool isVisible() const override;
    
    /*!
     *\brief Getter for score
     *\return Current score
     *\author imabramon
     *\version 0.1
    */
    int getScore() const override;
protected:
    
    /*!
     *\brief Getter for color
     *\return Current color depending on score
     *\author imabramon
     *\version 0.1
    */
    RGB _getColor() const override;
private:
    //! Color sqeuence 
    vector<RGB> & m_colors;
};

#endif /* Cell2048_hpp */
