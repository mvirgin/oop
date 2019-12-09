#ifndef BLINKY_H
#define BLINKY_H
#include "Ghost.h"
#include "pacman.h"

class Blinky: public Ghost
{
public:
    Blinky();
    void update(Graphics& g,Maze& maze) override;
    void ChaseMode(Graphics& g,Maze& maze,Pacman& player);
    void bupdate(Graphics& g,Maze& maze,Pacman& player);
};

#endif // BLINKY_H
