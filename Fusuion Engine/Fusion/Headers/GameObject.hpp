#ifndef GameObject_hpp
#define GameObject_hpp

#include <vector>

using namespace std;

/*!
 *\brief Base class for all game object. Allows you to store all objects in a tree structure. Can display objects
 *\author imabramon
 *\version 0.1
*/

class GameObject{
public:
    /*!
     *\brief Constructor
     *\param t_x X coordinate
     *\param t_y Y coordinate
     *\param t_parent Parent GameObject pointer
     *\author imabramon
     *\version 0.1
     */
    GameObject(int t_x, int t_y, GameObject * t_parent);
    
    /*!
     *\brief Destructor. Delete child objects
     *\author imabramon
     *\version 0.1
     */
    
    virtual ~GameObject();
    
    /*!
     *\brief Init interface
     *\author imabramon
     *\version 0.1
     */
    virtual void init();
    
    /*!
     *\brief Renders child objects and itself
     *\author imabramon
     *\version 0.1
    */
    void render() const;
    
    /*!
     *\brief Get x-coordinate of object
     *\author imabramon
     *\version 0.1
     */
    int getX() const;
    
    /*!
     *\brief Get y-coordinate of object
     *\author imabramon
     *\version 0.1
     */
    int getY() const;
    
    /*!
     *\brief Checks visible of object
     *\return True if if the object is displayed, else returns false
     *\author imabramon
     *\version 0.1
     */
    virtual bool isVisible() const;
    
    /*!
     *\brief Name of object type
     *\return Object type as string
     *\author imabramon
     *\version 0.1
     */
    virtual string getGameObjectType() const;
    
    /*!
     *\brief Adding new child
     *\param t_object The object you want to add
     *\return Reference to this object
     *\author imabramon
     *\version 0.1
     */
    GameObject & operator +=(GameObject * t_object);
protected:
    /*!
     *\brief Self-render
     *\author imabramon
     *\version 0.1
     */
    virtual void _selfRender() const;
    
    /*!
     *\brief Deletes all childs
     *\author imabramon
     *\version 0.1
     */
    void _delchilds();
    
    //! Number of all gameobjects
    static int m_objectCount;
    
    //! Logging flag, if 1 GameObjects will be logg self creation and destruction, else no logging
    static int m_log;
    
    //! Object ID
    int m_id;
    
    //! Object x coordinate
    int m_x;
    
    //! Object y coordinate
    int m_y;
    
    //! Object visible
    bool m_visible;
    
    //! Object parent pointer
    GameObject * m_parent;
    
    //! Object childs
    vector<GameObject *> m_child;
};

#endif /* GameObject_hpp */
