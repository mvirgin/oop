#ifndef ENEMY1_H
#define ENEMY1_H
#include "gameobject.h"
#include "maze.h"
#include "pacman.h"

class Ghost:public GameObject {
protected:
    Color c;
    Color origcolor;
    // int blueFrames=-2;
    int deathFrames;
public:
    Ghost(Color c1, Vec2d p1);
    void draw(Graphics& g) override;
    void run(Graphics& g, Maze &maze, Pacman& player);
    void beEatable(Graphics &g, Pacman &player);
    void Wander(Graphics& g, Maze &maze);
    void gupdate(Graphics& g, Maze &maze, Pacman& player);
    void goUp(Graphics&g, Maze&maze);
    void goLeft(Graphics&g, Maze&maze);
    void goRight(Graphics&g, Maze&maze);
    void goDown(Graphics&g, Maze&maze);
};

#endif // ENEMY1_H
