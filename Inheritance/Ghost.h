#ifndef ENEMY1_H
#define ENEMY1_H
#include "gameobject.h"


class Ghost:public GameObject {
private:
    Color c;
public:
    Ghost(Color c1);
    void draw(Graphics& g) override;
};

#endif // ENEMY1_H
