#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "graphics.h"
using namespace mssm;

//abstract base class -- defines interfance to be implemented by derived classes
class GameObject
{
public:
    GameObject();
    virtual ~GameObject();
    virtual void draw(mssm::Graphics& g)=0;//pure virtual draw method -- each subclass must redefine this for itself - so each version of an enemy will call its own unique draw method
    virtual void update(mssm::Graphics& g)=0;//pure virtual update method - moves or modifies game element at each frame
    //other stuff - method to test if a bullet intersects this object
};

#endif // GAMEOBJECT_H
