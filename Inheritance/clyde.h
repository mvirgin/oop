#ifndef CLYDE_H
#define CLYDE_H
#include "Ghost.h"


class Clyde: public Ghost
{
public:
    Clyde();
    void update(Graphics& g) override;
};

#endif // CLYDE_H
