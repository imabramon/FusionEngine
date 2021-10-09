#ifndef GameObject_hpp
#define GameObject_hpp

#include <vector>

using namespace std;

class GameObject{
public:
    GameObject(int tx, int ty, GameObject * p);
    /*
     tx, ty - координаты
     p - указатель на родительский объект
     */
    
    virtual ~GameObject();
    
    virtual void init(); // инициализация объекта
    void render() const; //отображение объекта
    
    int getX() const; //получение x координаты
    int getY() const; //получение y координаты
    
    virtual bool isVisible() const; //отображается ли объект?
    
    virtual string getGameObjectType() const; //возращает тип объекта
    
    GameObject & operator +=(GameObject * obj); //добавление объекта obj
protected:
    virtual void _selfRender() const; //отобржание самого объекта
    
    void _delchilds(); //Удаление дочерних объектов
    
    static int _objectCount; //Общее количество объектов
    static int _log; //Отображение лога
    
    int _id; //Номер объекта
    int _x, _y; //Координаты
    bool _visible; //Видим ли объект
    
    GameObject * _parent; //Указатель на родительский объект
    
    vector<GameObject *> _child; //Дочерние объекты
};

#endif /* GameObject_hpp */
