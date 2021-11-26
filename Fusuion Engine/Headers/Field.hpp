#ifndef Field_hpp
#define Field_hpp

#include <vector>
#include <utility>

#include "GameObject.hpp"
#include "Cell2048.hpp"
#include "RGB.hpp"

#include "../Fusion/Headers/TypeAlias.h"

/*!
 *\brief The class responsible for displaying the field
 *\author imabramon
 *\version 1.0
 */

class Field: public GameObject{
public:
    /*!
     *\brief Constructor
     *\param t_x X coordinate
     *\param t_y Y coordinate
     *\param t_parent Parent object pointer
     *\param t_space Space between cells
     *\param t_size Cell count
     *\param t_cellSize Cell size
     *\param t_cellRound Cell Round
     *\param t_colorsPath Color sequence file path
     *\param t_matrix Matrix reference
     *\author imabramon
     *\version 0.1
     */
    Field(int t_x, int t_y, GameObject * t_parent,
          int t_space, int t_size, int t_cellSize,
          int t_cellRound, string t_colorsPath, intMatrix_t & t_matrix);
    
    /*!
     *\brief Getting field height
     *\return Field width
     *\author imabramon
     *\version 0.1
     */
    int getWidth() const;
    
    /*!
     *\brief Getting field height
     *\return Field height
     *\author imabramon
     *\version 0.1
     */
    int getHeight() const;
    
    /*!
     *\brief Getting object type name
     *\return Object type name
     *\author imabramon
     *\version 0.1
     */
    string getGameObjectType() const override;
protected:
    /*!
     *\brief Render implementation
     *\author imabramon
     *\version 0.1
     */
    void _selfRender() const override;
private:
    int m_emptyCount;
    int m_width, m_height;
    int m_space;
    int m_cellSize;
    int m_cellRound;
    int m_size;
    vector<vector<int>> & m_data;
    vector<RGB> m_colors;
};

#endif /* Field_hpp */
