#ifndef GameObject_hpp
#define GameObject_hpp

#include <vector>

using namespace std;

/*!
  @brief Основной класс для всех объектов
*/

class GameObject{
public:
    GameObject(int t_x, int t_y, GameObject * t_parent);
    
    virtual ~GameObject();
    
    /*!
        @brief Инициализация объекта
     */
    virtual void init();
    
    /*!
        @brief Ренедер объекта
    */
    void render() const;
    
    /*!
     @brief Получить X-координату
     */
    int getX() const;
    
    /*!
        @brief Получить Y-координату
     */
    int getY() const;
    
    virtual bool isVisible() const;
    
    virtual string getGameObjectType() const;
    
    GameObject & operator +=(GameObject * t_object);
protected:
    virtual void _selfRender() const;
    
    void _delchilds();
    
    static int m_objectCount;
    static int m_log;
    
    int m_id;
    int m_x, m_y;
    bool m_visible;
    
    GameObject * m_parent;
    
    vector<GameObject *> m_child; //Дочерние объекты
};

#endif /* GameObject_hpp */
