#include "blinky.h"
#include "iostream"

Blinky::Blinky()
    :Ghost{RED,{393,300}}
{

}

void Blinky::update(Graphics &g, Maze &maze){

}

void Blinky::bupdate(Graphics &g, Maze &maze, Pacman &player){
    int prow = player.Row(g);
    int pcol = player.column(g);

    int grow = Row(g);
    int gcol = column(g);

    if (player.isInvincible()){
        c=BLUE;
        run(g,maze,player);
        beEatable(g,player);
    }
    else{
        c=RED;
        ChaseMode(g,maze,player);
        if (prow==grow&&pcol==gcol){
            player.gotCaught();
            pos = {393,300};
            player.catchNumber++;
        }
    }
    if (player.catchNumber>=3){
        cout<<"you lose" << endl;
    }
}

void Blinky::ChaseMode(Graphics &g, Maze &maze, Pacman &player){   //COPY WANDER CODE AND WHERE IM MAKING A RADNOM DESCISION THERE MAKE AN INFORMED DESCISION HERE
    int prow = player.Row(g);
    int pcol = player.column(g);
    int grow = Row(g);
    int gcol = column(g);
    //above and right
    if (prow>grow&&pcol>gcol){ //if player is above me, I want to go up until something is in my way
        if (canMoveUp(g,maze)){
            pos.x=cellCenter(g).x;
            velocity.y=1.8;
            velocity.x=0;
        }
        else if (canMoveRight(g,maze)){
            velocity.y=0;
            velocity.x=1.8;
            pos.y=cellCenter(g).y;
        }
        else if (canMoveLeft(g,maze)){
            goLeft(g,maze);
        }
        else if (canMoveDown(g,maze)){
            goDown(g,maze);
        }
        else {
            checkStop(g,maze);
        }
    }
    // above and left
    else if (prow>grow&&pcol<gcol){
        if (canMoveUp(g,maze)==true){
            pos.x=cellCenter(g).x;
            velocity.y=1.8;
            velocity.x=0;
        }
        else if (canMoveUp(g,maze)==false){
            checkStop(g,maze);
            if (canMoveLeft(g,maze)==true){
                velocity.y=0;
                velocity.x=-1.8;
                pos.y=cellCenter(g).y;
            }
            else if (canMoveLeft(g,maze)==false){
                checkStop(g,maze);
            }
        }
    }
    //below and right
    else if (prow<grow&&pcol>gcol){
        if (canMoveDown(g,maze)==true){
            pos.x=cellCenter(g).x;
            velocity.y=-1.8;
            velocity.x=0;
        }
        else if (canMoveDown(g,maze)==false){
            checkStop(g,maze);
            if (canMoveRight(g,maze)==true){
                //cout <<"chasing"<<endl;
                velocity.y=0;
                velocity.x=1.8;
                pos.y=cellCenter(g).y;
            }
            else if (canMoveRight(g,maze)==false){
                // cout << "stopping" << endl;
                checkStop(g,maze);
            }
        }
    }
    //below and left
    else if (prow<grow&&pcol<gcol){
        // cout << "below and left" <<endl;
        if (canMoveDown(g,maze)==true){
            pos.x=cellCenter(g).x;
            velocity.y=-1.8;
            velocity.x=0;
        }
        else if (canMoveDown(g,maze)==false){
            checkStop(g,maze);
            if (canMoveLeft(g,maze)==true){
                //cout <<"chasing"<<endl;
                velocity.y=0;
                velocity.x=-1.8;
                pos.y=cellCenter(g).y;
            }
            else if (canMoveLeft(g,maze)==false){
                // cout << "stopping" << endl;
                checkStop(g,maze);
            }
        }
    }
    //directly below
    else if (pcol==gcol&&prow>grow){
        //   cout << "directly below" << endl;
        if (canMoveUp(g,maze)==true){
            pos.x=cellCenter(g).x;
            velocity.y=1.8;
            velocity.x=0;
        }
        else if (canMoveUp(g,maze)==false){
            checkStop(g,maze);
            if (canMoveLeft(g,maze)==true){
                //cout <<"chasing"<<endl;
                velocity.y=0;
                velocity.x=-1.8;
                pos.y=cellCenter(g).y;
            }
            else if (canMoveLeft(g,maze)==false){
                // cout << "stopping" << endl;
                checkStop(g,maze);
            }
        }
    }
    //directly above
    else if (pcol==gcol&&prow<grow){
        //   cout << "directly above" <<endl;
        if (canMoveDown(g,maze)==true){
            pos.x=cellCenter(g).x;
            velocity.y=-1.8;
            velocity.x=0;
        }
        else if (canMoveDown(g,maze)==false){
            checkStop(g,maze);
            if (canMoveLeft(g,maze)==true){
                //cout <<"chasing"<<endl;
                velocity.y=0;
                velocity.x=-1.8;
                pos.y=cellCenter(g).y;
            }
            else if (canMoveLeft(g,maze)==false){
                // cout << "stopping" << endl;
                checkStop(g,maze);
            }
        }
    }
    //directly on the right
    else if (prow==grow&&pcol>gcol){
        //   cout << "directright"<<endl;
        if (canMoveRight(g,maze)==true){
            pos.y=cellCenter(g).y;
            velocity.x=1.8;
            velocity.y=0;
        }
        else if (canMoveRight(g,maze)==false){
            checkStop(g,maze);
            if (canMoveUp(g,maze)==true){
                //cout <<"chasing"<<endl;
                velocity.y=1.8;
                velocity.x=0;
                pos.x=cellCenter(g).x;
            }
            else if (canMoveLeft(g,maze)==false){
                // cout << "stopping" << endl;
                checkStop(g,maze);
            }
        }
    }
    // directly on the left
    else if (prow==grow&&pcol<gcol){
        // cout << "directleft" << endl;
        if (canMoveLeft(g,maze)==true){
            pos.y=cellCenter(g).y;
            velocity.x=-1.8;
            velocity.y=0;
        }
        else if (canMoveLeft(g,maze)==false){
            checkStop(g,maze);
        }
    }
    pos=pos+velocity;
}

//-- Experimental chaseMode
//    if (checkStop(g, maze)||!isMoving()) { //if I am stopped/otherwise not moving
//        //  cout << "new direction" <<endl;
//        if (prow>grow){
//            cout << "above me, going up" << endl;
//            goUp(g,maze);
//        }
//        else if (prow<grow){
//            cout << "below me, going down" << endl;
//            goDown(g,maze);
//        }
//        else if (pcol>gcol){
//            cout << "On right, going right" << endl;
//            goRight(g,maze);
//        }
//        else if (pcol<gcol){
//            cout << "on left, going left" << endl;
//            goLeft(g,maze);
//        }
//    }
//    else { //otherwise, if I am moving, see which way I'm moving and if there is an intersection, chance to take it or keep going
//        if (velocity.y<0&&canMoveLeft(g,maze)&&canMoveRight(g,maze)&&WillPassCenter(g)){
//            if (pcol<gcol){
//                goLeft(g,maze);
//            }
//            else{
//                goRight(g,maze);
//            }
//        }
//        else if (velocity.y>0&&canMoveLeft(g,maze)&&canMoveRight(g,maze)&&WillPassCenter(g)){
//            if (pcol<gcol){
//                goLeft(g,maze);
//            }
//            else{
//                goRight(g,maze);
//            }
//        }
//        else if (velocity.x>0&&canMoveUp(g,maze)&&canMoveDown(g,maze)&&WillPassCenter(g)){
//            if (prow>grow){
//                goUp(g,maze);
//            }
//            else{
//                goDown(g,maze);
//            }
//        }
//        else if(velocity.x<0&&canMoveUp(g,maze)&&canMoveDown(g,maze)&&WillPassCenter(g)){
//            if (prow>grow){
//                goUp(g,maze);
//            }
//            else{
//                goDown(g,maze);
//            }
//        }
//        else if(velocity.x<0&&canMoveUp(g,maze)&&canMoveDown(g,maze)&&canMoveRight(g,maze)&&WillPassCenter(g)){
//            if (prow>grow){ // might need combos, what if hes above me AND to the right?-----------------------------------
//                goUp(g,maze);
//            }
//            else if(pcol>gcol){
//                goRight(g,maze);
//            }
//            else{
//                goDown(g,maze);
//            }
//        }
//        else if(velocity.x<0&&canMoveUp(g,maze)&&canMoveDown(g,maze)&&canMoveLeft(g,maze)&&WillPassCenter(g)){
//            if (prow>grow){ // might need combos, what if hes above me AND to the right?-----------------------------------
//                goUp(g,maze);
//            }
//            else if(pcol>gcol){
//                goLeft(g,maze);
//            }
//            else{
//                goDown(g,maze);
//            }
//        }
//        else if (velocity.y>0&&canMoveLeft(g,maze)&&canMoveRight(g,maze)&&canMoveDown(g,maze)&&WillPassCenter(g)){
//            if (pcol<gcol){
//                goLeft(g,maze);
//            }
//            else if(prow<grow){
//                goDown(g,maze);
//            }
//            else{
//                goRight(g,maze);
//            }
//        }
//        else if (velocity.y<0&&canMoveLeft(g,maze)&&canMoveRight(g,maze)&&canMoveUp(g,maze)&&WillPassCenter(g)){
//            if (pcol<gcol){
//                goLeft(g,maze);
//            }
//            else if (prow>grow){
//                goUp(g,maze);
//            }
//            else{
//                goRight(g,maze);
//            }
//        }
//        else if (velocity.y<0&&canMoveLeft(g,maze)&&WillPassCenter(g)){
//            if (pcol<gcol){
//                goLeft(g,maze);
//            }
//            //            if (g.randomInt(1,2)==1){
//            //                goLeft(g,maze);
//            //            }
//        }
//        else if (velocity.y<0&&canMoveRight(g,maze)&&WillPassCenter(g)){
//            if (pcol>gcol){
//                goRight(g,maze);
//            }
//        }
//        else if (velocity.y>0&&canMoveLeft(g,maze)&&WillPassCenter(g)){
//            if (pcol<gcol){
//                goLeft(g,maze);
//            }
//        }
//        else if (velocity.y>0&&canMoveRight(g,maze)&&WillPassCenter(g)){
//            if (pcol>gcol){
//                goRight(g,maze);
//            }
//        }
//        else if (velocity.x<0&&canMoveUp(g,maze)&&WillPassCenter(g)){
//            if (prow>grow){
//                goUp(g,maze);
//            }
//        }
//        else if (velocity.x<0&&canMoveDown(g,maze)&&WillPassCenter(g)){
//            if (prow<grow){
//                goDown(g,maze);
//            }
//        }
//        else if (velocity.x>0&&canMoveUp(g,maze)&&WillPassCenter(g)){
//            if (prow>grow){
//                goUp(g,maze);
//            }
//        }
//        else if (velocity.x>0&&canMoveDown(g,maze)&&WillPassCenter(g)){
//            if (prow<grow){
//                goDown(g,maze);
//            }
//        }
//    }
//    pos = pos + velocity;
//}
