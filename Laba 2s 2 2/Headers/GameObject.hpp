#ifndef GameObject_hpp
#define GameObject_hpp

#include <vector>

using namespace std;

/*!
 @brief Класс игрового объекта.
 */

class GameObject{
public:
    /*!
        @brief Конструктор
        @param tx x-координата
        @param ty y-координата
        @param p указатель на родительский объект
    */
    GameObject(int tx, int ty, GameObject * p);
    
    //! Деструктор
    /*!
        Деструктор.
    */
    virtual ~GameObject();
    
    virtual void init();
    void render() const;
    
    int getX() const;
    int getY() const;
    
    virtual bool isVisible() const;
    
    virtual string getGameObjectType() const;
    
    GameObject & operator +=(GameObject * obj);
protected:
    virtual void _selfRender() const;
    
    void _delchilds();
    
    static int _objectCount;
    static int _log;
    
    int _id;
    int _x, _y;
    bool _visible;
    
    GameObject * _parent;
    
    vector<GameObject *> _child; //Дочерние объекты
};

#endif /* GameObject_hpp */
