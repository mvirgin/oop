#include "Ghost.h"
#include <vector>
using namespace std;
using namespace mssm;

Ghost::Ghost(Color c1, Vec2d p1)
{
    c=c1;
    pos=p1;
}

void Ghost::draw(Graphics &g){
    vector<Vec2d>ghostpts{{0,0},{5,5},{10,0},{15,5},{20,0},{25,5},{30,0},{30,20},{27,23},{25,25},{15,26},{5,25},{3,23},{0,20}};
    for (int i=0;i<ghostpts.size();i++){
        ghostpts[i].scale(.66);
        ghostpts[i].translate(pos);
    }
    g.polygon(ghostpts,c);
}

//int Ghost::column(Graphics &g){
//    double wide = g.width()/27;
//    return pos.x/wide;
//}

//int Ghost::Row(Graphics &g){
//    double tall = g.height()/29;
//    return pos.y/tall;
//}

//Vec2d Ghost::calculateCell(Graphics &g, int &row, int &col){
//    col = column(g);
//    row = Row(g);
//    return {static_cast<double>(row),static_cast<double>(col)};
//}

//Vec2d Ghost::cellCenter(Graphics &g){
//    double wide = g.width()/27;
//    double tall = g.height()/29;
//    return {(column(g)*wide)+(wide/2),(Row(g)*tall)+(tall/2)};
//}

//void Ghost::stop(Graphics &g){
//    velocity.x=0;
//    velocity.y=0;
//}

//bool Ghost::canMoveDown(Graphics &g, Maze &maze){
//    bool canDown=false;
//    if (maze.canMove(Row(g)-1,column(g))==false){
//        canDown=false;
//    }
//    else{
//        canDown=true;
//    }
//    return canDown;
//}

//bool Ghost::canMoveUp(Graphics &g, Maze &maze){
//    bool canUp=false;
//    if (maze.canMove(Row(g)+1,column(g))==false){
//        canUp=false;
//    }
//    else{
//        canUp=true;
//    }
//    return canUp;
//}

//bool Ghost::canMoveLeft(Graphics &g, Maze &maze){
//    bool canLeft=false;
//    if (maze.canMove(Row(g),column(g)-1)==false){
//        canLeft=false;
//    }
//    else{
//        canLeft=true;
//    }
//    return canLeft;
//}

//bool Ghost::canMoveRight(Graphics &g, Maze &maze){
//    bool canRight=false;
//    if (maze.canMove(Row(g),column(g)+1)==false){
//        canRight=false;
//    }
//    else{
//        canRight=true;
//    }
//    return canRight;
//}

//void Ghost::checkStop(Graphics & g, Maze & maze)
//{
//    if (velocity.x>0){
//        if (canMoveRight(g,maze)==false){
//            stop(g);
//            pos=cellCenter(g);
//        }
//        else{
//            // don't change velocity
//        }
//    }
//    if (velocity.x<0){
//        if (canMoveLeft(g,maze)==false){
//            stop(g);
//            pos=cellCenter(g);
//        }
//        else{
//            // don't change velocity
//        }
//    }
//    if (velocity.y>0){
//        if (canMoveUp(g,maze)==false){
//            stop(g);
//            pos=cellCenter(g);
//        }
//        else{
//            // don't change velocity
//        }
//    }
//    if (velocity.y<0){
//        if (canMoveDown(g,maze)==false){
//            stop(g);
//            pos=cellCenter(g);
//        }
//        else{
//            // don't change velocity
//        }
//    }
//}
