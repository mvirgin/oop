#ifndef BLINKY_H
#define BLINKY_H
#include "Ghost.h"

class Blinky: public Ghost
{
public:
    Blinky();
    void update(Graphics& g) override;
};

#endif // BLINKY_H
