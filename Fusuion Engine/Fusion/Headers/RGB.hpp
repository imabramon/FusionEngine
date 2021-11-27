#ifndef RGB_hpp
#define RGB_hpp

#include <string>

using namespace std;

/*!
 *\brief Class for working with color
 *\author imabramon
 *\version 0.1
 */
class RGB{
public:
    /*!
     *\brief Default contructor
     *\param t_red Red component
     *\param t_green Green component
     *\param t_blue Blue component
     *\author imabramon
     *\version 0.1
     */
    RGB(int t_red = 0, int t_green = 0, int t_blue = 0);
    
    /*!
     *\brief Default contructor
     *\param t_hex Hex number as string
     *\author imabramon
     *\version 0.1
     */
    RGB(string t_hex);
    
    /*!
     *\brief Default contructor
     *\return Red component
     *\author imabramon
     *\version 0.1
     */
    int getRed() const;
    
    /*!
     *\brief Default contructor
     *\return Green component
     *\author imabramon
     *\version 0.1
     */
    int getGreen() const;
    
    /*!
     *\brief Default contructor
     *\return Blue component
     *\author imabramon
     *\version 0.1
     */
    int getBlue() const;
private:
    //! Red component
    int m_red;
    
    //! Green compinent
    int m_green;
    
    //! Blue component
    int m_blue;
    
    /*!
     *\brief Covert hex char to number
     *\return Number of hex char
     *\author imabramon
     *\version 0.1
     */
    int _hexToDec(char t_hexDigit) const;
};

#endif /* RGB_hpp */
