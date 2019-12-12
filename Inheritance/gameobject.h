#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "graphics.h"
#include "maze.h"
using namespace mssm;

//abstract base class -- defines interfance to be implemented by derived classes
class GameObject
{
public:  //slide for each main class, and then important methods/funcs in classes, screenshots of game!!!!!!!!!!!!!!!!!!!!!!!!
    Vec2d pos;
    Vec2d velocity;
public:
    GameObject();
    virtual ~GameObject();
    virtual void draw(mssm::Graphics& g)=0;//pure virtual draw method -- each subclass must redefine this for itself - so each version of an enemy will call its own unique draw method
    virtual void update(mssm::Graphics& g,Maze &maze)=0;//pure virtual update method - moves or modifies game element at each frame

    Vec2d calculateCell(Graphics &g, int& row, int& col); //
    Vec2d cellCenter(Graphics& g); //
    void stop(Graphics&g); //
    bool canMoveDown(Graphics& g,Maze &maze); //
    bool canMoveUp(Graphics& g, Maze &maze);//
    bool canMoveLeft(Graphics& g,Maze &maze);//
    bool canMoveRight(Graphics&g, Maze &maze);//
    int Row(Graphics &g); //
    int column(Graphics &g); //
    bool checkStop(Graphics &g, Maze &maze);//
    bool isMoving();
    bool WillPassCenter(Graphics &g);
};

#endif // GAMEOBJECT_H
