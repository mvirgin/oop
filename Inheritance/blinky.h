#ifndef BLINKY_H
#define BLINKY_H
#include "Ghost.h"

class Blinky: public Ghost
{
private:
    //Vec2d posb; -- dont think i need this, blinky IS a ghost, which has a position
    Vec2d velocity;
public:
    Blinky();
    void update(Graphics& g,Maze&maze) override;
};

#endif // BLINKY_H
