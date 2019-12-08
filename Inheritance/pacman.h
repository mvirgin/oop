#ifndef PACMAN_H
#define PACMAN_H
#include "gameobject.h"
#include "maze.h"


class Pacman:public GameObject
{
private:
//    Vec2d pos;
//    Vec2d velocity;
public:
    char direction; //set direction in main but velocity in update
public:
    Pacman();
    void draw(Graphics& g) override;
    void update(Graphics& g, Maze &maze) override; //go right
//    void calculateCell(Graphics &g, int& row, int& col);
//    Vec2d cellCenter(Graphics& g);
//    void stop(Graphics&g);
   // void move(Graphics &g, Maze &maze);
//    bool canMoveDown(Graphics& g,Maze &maze);
//    bool canMoveUp(Graphics& g, Maze &maze);
//    bool canMoveLeft(Graphics& g,Maze &maze);
//    bool canMoveRight(Graphics&g, Maze &maze);
//    int row(Graphics &g);
//    int column(Graphics &g);
//    void checkStop(Graphics &g, Maze &maze);
    bool eatingPellet(Graphics& g, Maze &maze);
};

#endif // PACMAN_H
