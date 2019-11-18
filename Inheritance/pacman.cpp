#include "pacman.h"
#include "iostream"

using namespace std;

Pacman::Pacman()
{
    double wide = (800/27)+15;
    double tall = (600/29)+10;
    pos={wide,tall};
}

void Pacman::draw(Graphics &g){
    g.ellipseC(pos,20,20,YELLOW);
}

Vec2d Pacman::calculateCell(Graphics& g){
    double wide = g.width()/27; //just put before the loop
    double tall = g.height()/29;
    int column=pos.x/wide;
    int row = pos.y/tall;
    Vec2d cell={static_cast<double>(row),static_cast<double>(column)};
    cout << cell.x << ',' << cell.y << endl;
    g.rect(column*wide,row*tall,wide,tall);
    g.ellipseC({(column*wide)+(wide/2),(row*tall)+(tall/2)},5,5,GREEN); // finds center of cell
    return cell; // (row,column)
}

void Pacman::update(Graphics &g){ //check if he is allowed to move - compare it to the outside and inside vectors on the grid and check what symbol they are
//use calculateCell and canMove to determine where he can move
//    calculateCell(g);
//    if(canMove())
    pos=pos+velocity;
}

void Pacman::stop(Graphics &g){
    velocity.x=0;
    velocity.y=0;
    cout <<"YOU HAVE BEEN STOPPED AT" << " " << calculateCell(g).x <<',' << calculateCell(g).y <<endl<<endl;
}

