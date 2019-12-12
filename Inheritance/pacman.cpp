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

void Pacman::update(Graphics &g,Maze& maze){ //check if he is allowed to move - compare it to the outside and inside vectors on the grid and check what symbol they are
    Vec2d cellcenter = cellCenter(g);
    //check requested direction first, then see if they can actually move that way. If not, don't change velocity - also check if they can go their original way - if they can't, stop. Prostrat - move in the requested direction when its open to do so
    if (direction=='s'){
        if (canMoveDown(g,maze)==false){
            checkStop(g,maze);
        }
        else{
            pos.x=cellcenter.x;
            velocity.y=-2.7;
            velocity.x=0;
        }
    }
    // -- moving up
    if (direction=='w'){
        if (canMoveUp(g,maze)==false){
            // do not change velocity
            checkStop(g,maze);
        }
        else{
            pos.x=cellcenter.x;
            velocity.y=2.7;
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
            pos.y=cellcenter.y;
            velocity.x=2.7;
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
            pos.y=cellcenter.y;
            velocity.x=-2.7;
            velocity.y=0;
        }
    }
    //eating a pellet
    eatingPellet(g,maze);
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

    // -- porting
    if (maze.RightTeleporterPresent(Row(g),column(g))==true){
        pos={50,290};
    }
    if (maze.LeftTeleporterPresent(Row(g),column(g))==true){
        pos={730,290};
    }
    //powering up
    if (eatingBigPellet(g,maze)==true){
        invincibleFrames=500;
    }
    invincibleFrames--;

    pos=pos+velocity;
    // cout << pos.x << "," << pos.y << endl;
}

void Pacman::eatingPellet(Graphics &g, Maze &maze){

    if (maze.PelletPresent(Row(g),column(g))==true){
        maze.clearPellet(Row(g),column(g));
       counter=counter+1;
    }
  //  cout <<counter<<endl;
    if (counter>=234){
      //  g."You win!!!"; // ------NEED TO GET THIS TO WORK -----------------------------------------------------------------------------
   cout << "you win" << endl;
    }
}

bool Pacman::eatingBigPellet(Graphics &g, Maze &maze){ //this is a bool and it does something - bad!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    if (maze.BigPelletPresent(Row(g),column(g))==true){
        maze.clearBigPellet(Row(g),column(g));
        // counter++;
        return true;
    }
    else{
        return false;
    }
}

void Pacman::gotCaught(){
        pos={391.5,110};
}

bool Pacman::isInvincible(){
    if (invincibleFrames>0){
        return true;
    }
    else{
        return false;
    }
}

bool Pacman::victory(){
    if (counter>=234){
        return true;
    }
    else{
        return false;
    }
}

bool Pacman::YouLose(){
    if (catchNumber>=3){
        return true;
    }
    else{
        return false;
    }
}


