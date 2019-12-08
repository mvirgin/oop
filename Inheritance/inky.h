#ifndef INKY_H
#define INKY_H
#include "Ghost.h"


class Inky: public Ghost{
public:
    Inky();
    void update(Graphics& g,Maze&maze) override;
};

#endif // INKY_H
