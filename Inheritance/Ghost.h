#ifndef ENEMY1_H
#define ENEMY1_H
#include "gameobject.h"


class Ghost:public GameObject {
private:
    Color c;
    //Vec2d position -- helps determine if it touches the maze
public:
    Ghost(Color c1);
    void draw(Graphics& g) override;
    //bool touchesMaze -- the maze will be a vector of vectors - loop thru to see if pacman or ghosts touch any and stop them from moving
};

#endif // ENEMY1_H
