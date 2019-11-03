#ifndef INKY_H
#define INKY_H
#include "Ghost.h"


class Inky: public Ghost{
public:
    Inky();
    void update(Graphics& g) override;
};

#endif // INKY_H
