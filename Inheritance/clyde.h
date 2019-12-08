#ifndef CLYDE_H
#define CLYDE_H
#include "Ghost.h"


class Clyde: public Ghost
{
public:
    Clyde();
    void update(Graphics& g, Maze&maze) override;
};

#endif // CLYDE_H
