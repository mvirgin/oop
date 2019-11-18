#ifndef PACMAN_H
#define PACMAN_H
#include "gameobject.h"


class Pacman:public GameObject
{
private:
    Vec2d pos;
public:
    Vec2d velocity;
    char direction; //set direction in main but velocity in update
public:
    Pacman();
    void draw(Graphics& g) override;
    void update(Graphics& g) override; //go right
    Vec2d calculateCell(Graphics &g);
    void stop(Graphics&g);
};

#endif // PACMAN_H
