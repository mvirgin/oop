#include "gameobject.h"

GameObject::GameObject()
{

}

GameObject::~GameObject(){

}

int GameObject::column(Graphics &g){
    double wide = g.width()/27;
    return pos.x/wide;
}

int GameObject::Row(Graphics &g){
    double tall = g.height()/29;
    return pos.y/tall;
}

Vec2d GameObject::calculateCell(Graphics &g, int &row, int &col){
    col = column(g);
    row = Row(g);
    return {static_cast<double>(row),static_cast<double>(col)};
}

Vec2d GameObject::cellCenter(Graphics &g){
    double wide = g.width()/27;
    double tall = g.height()/29;
    return {(column(g)*wide)+(wide/2),(Row(g)*tall)+(tall/2)};
}

void GameObject::stop(Graphics &g){
    velocity.x=0;
    velocity.y=0;
}

bool GameObject::canMoveDown(Graphics &g, Maze &maze){
    bool canDown=false;
    if (maze.canMove(Row(g)-1,column(g))==false){
        canDown=false;
    }
    else{
        canDown=true;
    }
    return canDown;
}

bool GameObject::canMoveUp(Graphics &g, Maze &maze){
    bool canUp=false;
    if (maze.canMove(Row(g)+1,column(g))==false){
        canUp=false;
    }
    else{
        canUp=true;
    }
    return canUp;
}

bool GameObject::canMoveLeft(Graphics &g, Maze &maze){
    bool canLeft=false;
    if (maze.canMove(Row(g),column(g)-1)==false){
        canLeft=false;
    }
    else{
        canLeft=true;
    }
    return canLeft;
}

bool GameObject::canMoveRight(Graphics &g, Maze &maze){
    bool canRight=false;
    if (maze.canMove(Row(g),column(g)+1)==false){
        canRight=false;
    }
    else{
        canRight=true;
    }
    return canRight;
}

void GameObject::checkStop(Graphics & g, Maze & maze)
{
    bool shouldStop{false};

    if (velocity.x>0 && !canMoveRight(g,maze)){
        shouldStop = true;
    }
    if (velocity.x<0 && !canMoveLeft(g,maze)){
        shouldStop = true;
    }
    if (velocity.y>0 && !canMoveUp(g,maze)){
        shouldStop = true;
    }
    if (velocity.y<0 && !canMoveDown(g,maze)){
        shouldStop = true;
    }

    if (shouldStop) {
        stop(g);
        pos=cellCenter(g);
    }
}
