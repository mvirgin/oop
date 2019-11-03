#include "wall.h"


#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wnarrowing"

using namespace std;

// add wallstouch
bool wallsTouch(const Wall& w1,const Wall& w2){
Vec2d w1P2 = w1.FindP2();
Vec2d w2P2 = w2.FindP2();

return w1.P1 == w2.P1 ||
        w1P2 == w2.P1 ||
        w1.P1 == w2P2 ||
        w1P2 == w2P2;
}

Wall::Wall(Vec2d initP1, double initLength, bool initDirection){
    P1=initP1;
    length=initLength;
    isVertical=initDirection;
}

Wall::Wall(Vec2d GivenP1, Vec2d GivenP2){
    P1 = GivenP1;
    length = (GivenP1-GivenP2).magnitude();
    if (GivenP1.x==GivenP2.x){
        isVertical=true;
    }
    else{
        isVertical=false;
    }
}

Vec2d Wall::FindP2() const{
    double x = P1.x;
    double y = P1.y;
    if (isVertical == true){
        y = P1.y+length;
    }
    else {
        x = P1.x+length;
    }
    Vec2d P2{x,y};
    return P2;
}

void Wall::wallDraw(mssm::Graphics &g, mssm::Color c){
    Vec2d P2 = FindP2();
    g.line(P1,P2, c);
    //    g.ellipseC(P1,8,8,GREEN);
    //    g.ellipseC(P2,16,16,RED);
}

bool Wall::doesRayIntersect(Vec2d point){
    return ((P1.x==FindP2().x&&point.x<P1.x&&point.y>P1.y&&point.y<FindP2().y)||(P1.x==FindP2().x&&point.x<P1.x&&point.y<P1.y&&point.y>FindP2().y));
}

bool Wall::doesLineIntersect(Vec2d p, bool isLineVertical) const{ //checks if the line passing through p intersects a wall
    Vec2d P2 = FindP2();

    if (isLineVertical){
        if (isVertical){
            return false;
        }

        return p.x > min(P1.x,P2.x) && p.x < max(P1.x, P2.x);
    }
    else{
        if (!isVertical){
            return false;
        }
        return p.y > min(P1.y, P2.y) && p.y < max(P1.y, P2.y);
    }
}

bool  operator== (Vec2d p1, Vec2d p2)
{
    return p1.x==p2.x&&p1.y==p2.y;
}


