#ifndef ENEMY1_H
#define ENEMY1_H
#include "gameobject.h"
#include "maze.h"

class Ghost:public GameObject {
private:
    Color c;
    Vec2d pos;
    Vec2d velocity;
    //Vec2d position -- helps determine if it touches the maze
public:
    Ghost(Color c1, Vec2d p1);
    void draw(Graphics& g) override;
//    Vec2d calculateCell(Graphics &g, int& row, int& col); //
//    Vec2d cellCenter(Graphics& g); //
//    void stop(Graphics&g); //
//    bool canMoveDown(Graphics& g,Maze &maze); //
//    bool canMoveUp(Graphics& g, Maze &maze);//
//    bool canMoveLeft(Graphics& g,Maze &maze);//
//    bool canMoveRight(Graphics&g, Maze &maze);//
//    int Row(Graphics &g); //
//    int column(Graphics &g); //
//    void checkStop(Graphics &g, Maze &maze);//
};

#endif // ENEMY1_H
