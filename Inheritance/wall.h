#ifndef WALL_H
#define WALL_H

#include "graphics.h"



class Wall{
public:
    Vec2d P1;
    double length;
    bool isVertical; //true = up (vertical)
    //vector <Windoors> windoors;
public:
    Wall(Vec2d initP1, double initLength, bool initDirection);
    Wall(Vec2d GivenP1, Vec2d GivenP2);

    void wallDraw (mssm::Graphics& g, mssm::Color c = mssm::WHITE);
    Vec2d FindP2() const;
    bool doesRayIntersect(Vec2d point);
    bool doesLineIntersect(Vec2d p, bool isLineVertical) const;
};

//declare wallstouch
bool wallsTouch(const Wall& w1,const Wall& w2);//{
//    Vec2d w1P2 = w1.FindP2();
//    Vec2d w2P2 = w2.FindP2();

//    return w1.P1 == w2.P1 ||
//            w1P2 == w2.P1 ||
//            w1.P1 == w2P2 ||
//            w1P2 == w2P2;
//}

#endif // WALL_H
