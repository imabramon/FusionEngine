#ifndef TextBox_hpp
#define TextBox_hpp

#include "GameObject.hpp"
#include "RGB.hpp"

/*!
 *\brief Class which displays some text inside round rectangle
 *\author imabramon
 *\version 0.1
 */

class TextBox: public GameObject{
public:
    /*!
     *\brief Class which displays some text inside round rectangle
     *\param t_x X coordinate
     *\param t_y Y coordinate
     *\param t_width Width
     *\param t_height Height
     *\param t_radius Radius
     *\param t_parent Object parent
     *\param t_score Object score
     *\author imabramon
     *\version 0.1
     */
    TextBox(int t_x, int t_y, int t_width, int t_height, int t_radius, GameObject * t_parent, int * t_score);
    
    /*!
     *\brief Getting data for displaying
     *\return Data for display
     *\author imabramon
     *\version 0.1
     */
    virtual int getScore() const;
    
    /*!
     *\brief Checks visible of object
     *\return True if if the object is displayed, else returns false
     *\author imabramon
     *\version 0.1
     */
    virtual bool isVisible() const override;
    
    /*!
     *\brief Name of object type
     *\return Object type as string
     *\author imabramon
     *\version 0.1
     */
    virtual string getGameObjectType() const override;
protected:
    /*!
     *\brief Self-render
     *\author imabramon
     *\version 0.1
     */
    void _selfRender() const override;
    
    /*!
     *\brief Getting displaying color
     *\return Data for display
     *\author imabramon
     *\version 0.1
     */
    virtual RGB _getColor() const;
    
    //! Score pointer
    int * m_score = NULL;
    
    //! Textbox width
    int m_width;
    
    //! Textbox height
    int m_height;
    
    //! Textbox corner radius
    int m_radius;
};

#endif
