#ifndef TextBox_hpp
#define TextBox_hpp

#include "GameObject.hpp"
#include "RGB.hpp"

/*!
 *\brief Class which displays some text inside round rectangle
 *\author imabramon
 *\version 0.2.1
 */

class TextBox: public GameObject{
public:
    /*!
     *\brief Class which displays some text inside round rectangle
     *\author imabramon
     *\version 0.2.1
     */
    TextBox();
    
    /*!
     *\brief Setter for TextBox position
     *\author imabramon
     *\version 0.1
     */
    void setPosition(int t_x, int t_y);
    
    /*!
     *\brief Setter for TextBox size
     *\author imabramon
     *\version 0.1
     */
    void setSize(int t_width, int t_height);
    
    /*!
     *\brief Setter for TextBox radius
     *\author imabramon
     *\version 0.1
     */
    void setRadius(int t_radius);
    
    /*!
     *\brief Setter for TextBox text
     *\author imabramon
     *\version 0.1
     */
    void setText(int * t_score);
    
    /*!
     *\brief Setter for TextBox parent
     *\author imabramon
     *\version 0.1
     */
    void setParent(GameObject * t_parent);
    
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
