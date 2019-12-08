#include "pacman.h"
#include "iostream"

using namespace std;

Pacman::Pacman()
{
    pos={391.5,110};
}

void Pacman::draw(Graphics &g){
    g.ellipseC(pos,20,20,YELLOW);
}

//int Pacman::row(Graphics& g){
//    double tall = g.height()/29;
//    return pos.y/tall;
//}

//int Pacman::column(Graphics&g){
//    double wide = g.width()/27;
//    return pos.x/wide;
//}

//void Pacman::calculateCell(Graphics& g, int& row, int& col){ // want him to start at cell 5,13
//    double wide = g.width()/27; //just put before the loop
//    double tall = g.height()/29;
//    col = pos.x/wide;
//    row = pos.y/tall;
//    Vec2d cell={static_cast<double>(row),static_cast<double>(col)};
//    cout << cell.x << ',' << cell.y << "          " << pos.x << "," << pos.y << endl;
//    g.rect(col*wide,row*tall,wide,tall);
//    g.ellipseC({(col*wide)+(wide/2),(row*tall)+(tall/2)},5,5,GREEN); // finds center of cell
//}

//Vec2d Pacman::cellCenter(Graphics& g)
//{
//    double wide = g.width()/27; //just put before the loop
//    double tall = g.height()/29;
//    int row;
//    int col;
//    calculateCell(g, row, col);
//    return {(col*wide)+(wide/2),(row*tall)+(tall/2)};
//}

//void Pacman::stop(Graphics &g){
//    velocity.x=0;
//    velocity.y=0;
//    int row;
//    int col;
//    calculateCell(g, row, col);
//    cout <<"YOU HAVE BEEN STOPPED AT" << " " << row <<',' << col <<endl<<endl;
//}

//bool Pacman::canMoveDown(Graphics&g,Maze& maze) // i might be overcomplicating things and incorportating canmoveleft, etc into this
//{
//    int row;
//    int col;
//    calculateCell(g, row, col);

//    Vec2d cellcenter = cellCenter(g);

//    int xoffset = pos.x-cellcenter.x;
//    int yoffset = pos.y-cellcenter.y;
//    int xoffsetafter = pos.x+velocity.x-cellcenter.x;
//    int yoffsetafter = pos.y+velocity.y-cellcenter.y;

//    bool canDown=false;
//    //!!!!!!!!!! im not using the offsets - remember its when i get to the center of an intersection that i really have to worry about
//    // if (/*direction=='s'*/velocity.y<0){ // this is the problem, I dont always have a velocity!!!!!!!!
//    if (maze.canMove(row-1,col)==false){ //check if he can move down
//        //stop(g); -- do this in update
//        //   pos=cellcenter;
//        canDown=false;
//    }
//    else{
//        canDown=true;
//        //    }
//    }
//    return canDown;
//}

//bool Pacman::canMoveUp(Graphics&g,Maze&maze) //none of my canmoves are just can moves, they're more like if im already moving up, can I continue?
//{
//    int row;
//    int col;
//    calculateCell(g, row, col);

//    Vec2d cellcenter = cellCenter(g);

//    int xoffset = pos.x-cellcenter.x;
//    int yoffset = pos.y-cellcenter.y;
//    int xoffsetafter = pos.x+velocity.x-cellcenter.x;
//    int yoffsetafter = pos.y+velocity.y-cellcenter.y;

//    bool canUp=false;

//    // if (/*direction=='s'*/velocity.y>0){
//    if (maze.canMove(row+1,col)==false){ //check if he can move up
//        //stop(g); -- do this in update
//        //   pos=cellcenter;
//        canUp=false;
//    }
//    else{
//        canUp=true;
//    }
//    //   }
//    return canUp;

//}

//bool Pacman::canMoveLeft(Graphics&g,Maze&maze)
//{
//    int row;
//    int col;
//    calculateCell(g, row, col);

//    Vec2d cellcenter = cellCenter(g);

//    bool canLeft=false;

//    //  if (/*direction=='s'*/velocity.x<0){
//    if (maze.canMove(row,col-1)==false){ //check if he can move left
//        //stop(g); -- do this in update
//        //   pos=cellcenter;
//        canLeft=false;
//    }
//    else{
//        canLeft=true;
//    }
//    //  }
//    return canLeft;

//}

//bool Pacman::canMoveRight(Graphics&g,Maze &maze)
//{
//    int row;
//    int col;
//    calculateCell(g, row, col);

//    Vec2d cellcenter = cellCenter(g);

//    bool canRight=false;

//    // if (/*direction=='s'*/velocity.x>0){
//    if (maze.canMove(row,col+1)==false){ //check if he can move left
//        //stop(g); -- do this in update
//        cout << "changing pos to cellcenter" << endl << endl;
//        //    pos=cellcenter;
//        canRight=false;
//    }
//    else{
//        canRight=true;
//    }
//    //  }
//    return canRight;
//}

//void Pacman::checkStop(Graphics & g, Maze & maze)
//{
//    if (velocity.x>0){
//        if (canMoveRight(g,maze)==false){ // should probably make this series of if statements into a look around
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

void Pacman::update(Graphics &g,Maze& maze){ //check if he is allowed to move - compare it to the outside and inside vectors on the grid and check what symbol they are
    int row;
    int col;
    calculateCell(g, row, col);

    Vec2d cellcenter = cellCenter(g);

    int xoffset = pos.x-cellcenter.x;
    int yoffset = pos.y-cellcenter.y;
    int xoffsetafter = pos.x+velocity.x-cellcenter.x;
    int yoffsetafter = pos.y+velocity.y-cellcenter.y;

    //check requested direction first, then see if they can actually move that way. If not, don't change velocity - also check if they can go their original way - if they can't, stop. Prostrat - move in the requested direction when its open to do so
    if (direction=='s'){
        if (canMoveDown(g,maze)==false){
            checkStop(g,maze);
        }
        else{
            cout<< "you can move" << endl;
            // if (velocity.y>=0){
            pos.x=cellcenter.x;
            // }
            velocity.y=-1.7;
            velocity.x=0;

            //pos=pos+velocity;
        }
    }
    // -- moving up
    if (direction=='w'){
        if (canMoveUp(g,maze)==false){
            // do not change velocity
            checkStop(g,maze);
        }
        else{
            cout<< "you can move" << endl;
            pos.x=cellcenter.x;
            velocity.y=1.7;
            velocity.x=0;
        }
    }
    // -- moving right
    if (direction=='d'){
        if (canMoveRight(g,maze)==false){
            // do not change velocity
            checkStop(g,maze);
        }
        else{
            cout<< "you can move" << endl;
            pos.y=cellcenter.y;
            velocity.x=1.7;
            velocity.y=0;
        }
    }
    // -- moving left
    if (direction=='a'){
        if (canMoveLeft(g,maze)==false){
            // do not change velocity
            checkStop(g,maze);
        }
        else{
            cout<< "you can move" << endl;
            pos.y=cellcenter.y;
            velocity.x=-1.7;
            velocity.y=0; // also set y pos so im in middle of row
        }
    }
    //eating a pellet
   // eatingPellet(g,maze);
//    vector <Vec2d> eatenPelletInfo;
//    double wide = g.width()/27;
//    double tall = g.height()/29;
//    if (eatingPellet(g,maze)==true){
//        for (int i=0;i<800;i++){
//            eatenPelletInfo.push_back(cellcenter); // am I only putting one cellcenter into the vector, does it need to be as big as the number of free spots?
//        }
//        //        double wide = g.width()/27;
//        //        double tall = g.height()/29;
//        //       // Vec2d center{cellcenter.x,cellcenter.y};
//        //        g.ellipseC(cellcenter,wide/2,tall/3,BLACK,BLACK); // only going to draw this when it is true, goes away when false
//    }
//    for (int i=0;i<eatenPelletInfo.size();i++){
//        g.ellipseC(eatenPelletInfo[i],wide/2,tall/3,BLACK,BLACK);
//    }
    //getting him moving
    pos=pos+velocity;
}

bool Pacman::eatingPellet(Graphics &g, Maze &maze){
    if (maze.PelletPresent(Row(g),column(g))){
        double wide = g.width()/27;
        double tall = g.height()/29;
        g.ellipseC(cellCenter(g),wide/2,tall/3,BLACK,BLACK);
        return true;
    }
    else{
        return false;
    }
}


