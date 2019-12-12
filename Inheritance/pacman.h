#ifndef PACMAN_H
#define PACMAN_H
#include "gameobject.h"
#include "maze.h"


class Pacman:public GameObject
{
private:
    int invincibleFrames=-1;
    int counter=0;
public:
    int catchNumber=0;
public:
    char direction; //set direction in main but velocity in update

    Pacman();
    void draw(Graphics& g) override;
    void update(Graphics& g, Maze &maze) override; //go right
    void eatingPellet(Graphics& g, Maze &maze);
    bool eatingBigPellet(Graphics &g, Maze &maze);
    void gotCaught();
    bool isInvincible();
    bool victory();
    bool YouLose();
};

#endif // PACMAN_H
