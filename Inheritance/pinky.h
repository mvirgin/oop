#ifndef PINKY_H
#define PINKY_H
#include "Ghost.h"

class Pinky: public Ghost
{
public:
    Pinky();
    void update(Graphics& g,Maze&maze) override;
};

#endif // PINKY_H
