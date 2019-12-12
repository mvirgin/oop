#include "Ghost.h"
#include <vector>
# include "iostream"
using namespace std;
using namespace mssm;

Ghost::Ghost(Color c1, Vec2d p1)
{
    c=c1;
    pos=p1;
    velocity={0,0};
    origcolor=c1; //when i need to change back to origcolor, say c=origcolor
}

void Ghost::beEatable(Graphics &g, Pacman &player)
{
    int prow = player.Row(g);
    int pcol = player.column(g);
    int grow = Row(g);
    int gcol = column(g);

    if (grow==prow&&gcol==pcol){
        c=TRANSPARENT;
        pos={393,300};
        deathFrames=500;
    }

    deathFrames--;
    if (deathFrames==0){
        c=origcolor;
        pos={393,300};
    }
}

void Ghost::draw(Graphics &g){
    g.ellipseC(pos,20,15,c);
}

void Ghost::run(Graphics &g, Maze &maze, Pacman &player){
    int prow = player.Row(g);
    int pcol = player.column(g);

    int grow = Row(g);
    int gcol = column(g);

    if (prow>grow&&pcol>gcol){

        if (canMoveDown(g,maze)==true){
            pos.x=cellCenter(g).x;
            velocity.y=-1;
            velocity.x=0;
        }
        else if (canMoveDown(g,maze)==false){
            checkStop(g,maze);
            if (canMoveLeft(g,maze)==true){

                velocity.y=0;
                velocity.x=-1;

                pos.y=cellCenter(g).y;
            }
            else if (canMoveLeft(g,maze)==false){

                checkStop(g,maze);
            }
        }
    }
    // above and left
    else if (prow>grow&&pcol<gcol){

        if (canMoveDown(g,maze)==true){
            pos.x=cellCenter(g).x;
            velocity.y=-1;

            velocity.x=0;
        }
        else if (canMoveDown(g,maze)==false){
            checkStop(g,maze);
            if (canMoveRight(g,maze)==true){

                velocity.y=0;
                velocity.x=1;

                pos.y=cellCenter(g).y;
            }
            else if (canMoveRight(g,maze)==false){

                checkStop(g,maze);

            }
        }
    }
    //below and right
    else if (prow<grow&&pcol>gcol){

        if (canMoveUp(g,maze)==true){
            pos.x=cellCenter(g).x;
            velocity.y=1;\

            velocity.x=0;
        }
        else if (canMoveUp(g,maze)==false){
            checkStop(g,maze);
            if (canMoveLeft(g,maze)==true){

                velocity.y=0;
                velocity.x=-1;

                pos.y=cellCenter(g).y;
            }
            else if (canMoveLeft(g,maze)==false){

                checkStop(g,maze);

            }
        }
    }
    //below and left
    else if (prow<grow&&pcol<gcol){

        if (canMoveUp(g,maze)==true){
            pos.x=cellCenter(g).x;
            velocity.y=1;

            velocity.x=0;
        }
        else if (canMoveUp(g,maze)==false){
            checkStop(g,maze);
            if (canMoveRight(g,maze)==true){

                velocity.y=0;
                velocity.x=1;

                pos.y=cellCenter(g).y;
            }
            else if (canMoveRight(g,maze)==false){

                checkStop(g,maze);

            }
        }
    }
    //directly below
    else if (pcol==gcol&&prow>grow){

        if (canMoveDown(g,maze)==true){
            pos.x=cellCenter(g).x;
            velocity.y=-1;

            velocity.x=0;
        }
        else {
            checkStop(g,maze);
            if (canMoveRight(g,maze)==true){
                //// cout <<"chasing"<<endl;
                velocity.y=0;
                velocity.x=1;

                pos.y=cellCenter(g).y;
            }
            else {

                checkStop(g,maze);

            }
        }
    }
    //directly above
    else if (pcol==gcol&&prow<grow){

        if (canMoveUp(g,maze)==true){
            pos.x=cellCenter(g).x;
            velocity.y=1;

            velocity.x=0;
        }
        else if (canMoveUp(g,maze)==false){
            checkStop(g,maze);
            if (canMoveRight(g,maze)==true){

                velocity.y=0;
                velocity.x=1;

                pos.y=cellCenter(g).y;
            }
            else if (canMoveRight(g,maze)==false){

                checkStop(g,maze);

            }
        }
    }
    //directly on the right
    else if (prow==grow&&pcol>gcol){

        if (canMoveLeft(g,maze)==true){
            pos.y=cellCenter(g).y;
            velocity.x=-1;

            velocity.y=0;
        }
        else if (canMoveLeft(g,maze)==false){
            checkStop(g,maze);
            if (canMoveDown(g,maze)==true){

                velocity.y=-1;

                velocity.x=0;
                pos.x=cellCenter(g).x;
            }
            else if (canMoveDown(g,maze)==false){

                checkStop(g,maze);

            }
        }
    }
    // directly on the left
    else if (prow==grow&&pcol<gcol){

        if (canMoveRight(g,maze)==true){
            pos.y=cellCenter(g).y;
            velocity.x=1;

            velocity.y=0;
        }
        else if (canMoveRight(g,maze)==false){
            checkStop(g,maze);

        }
    }
    pos=pos+velocity;
}

void Ghost::gupdate(Graphics &g, Maze &maze, Pacman &player){
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
        c=origcolor;
        Wander(g,maze);
        if (prow==grow&&pcol==gcol){
            player.gotCaught();
            pos ={393,300};
            player.catchNumber++;
        }
    }
    if (player.catchNumber>=3){
        // cout<<"you lose" << endl;
    }

    if (maze.RightTeleporterPresent(Row(g),column(g))==true){
        pos={50,290};
    }
    if (maze.LeftTeleporterPresent(Row(g),column(g))==true){
        pos={730,290};
    }
}

void Ghost::Wander(Graphics &g, Maze &maze){
    if (checkStop(g, maze)||!isMoving()) { //if I am stopped/otherwise not moving
        // cout << "new direction" <<endl;
        int random = g.randomInt(1,4);
        switch(random){                   // choose a new direction
        case 1:
            goUp(g,maze);
            break;
        case 2:
            goRight(g,maze);
            break;
        case 3:
            // cout << velocity.y << endl <<endl;
            goDown(g,maze);
            break;
        case 4:
            goLeft(g,maze);
            break;
        }
    }
    else { //otherwise, if I am moving, see which way I'm moving and if there is an intersection, chance to take it or keep going
        if (velocity.y<0&&canMoveLeft(g,maze)&&canMoveRight(g,maze)&&WillPassCenter(g)){
            if (g.randomInt(1,2)==1){
                switch(g.randomInt(1,2)){                   // take a turn at the intersection
                case 1:
                    goLeft(g,maze);
                    break;
                case 2:
                    goRight(g,maze);
                    break;
                }
            }
        }
        else if (velocity.y>0&&canMoveLeft(g,maze)&&canMoveRight(g,maze)&&WillPassCenter(g)){
            if (g.randomInt(1,2)==1){
                switch(g.randomInt(1,2)){                   // take a turn at the intersection
                case 1:
                    goLeft(g,maze);
                    break;
                case 2:
                    goRight(g,maze);
                    break;
                }
            }
        }
        else if (velocity.x>0&&canMoveUp(g,maze)&&canMoveDown(g,maze)&&WillPassCenter(g)){
            if (g.randomInt(1,2)==1){
                switch(g.randomInt(1,2)){                   // take a turn at the intersection
                case 1:
                    goUp(g,maze);
                    break;
                case 2:
                    goDown(g,maze);
                    break;
                }
            }
        }
        else if(velocity.x<0&&canMoveUp(g,maze)&&canMoveDown(g,maze)&&WillPassCenter(g)){
            if (g.randomInt(1,2)==1){
                switch(g.randomInt(1,2)){                   // take a turn at the intersection
                case 1:
                    goUp(g,maze);
                    break;
                case 2:
                    goDown(g,maze);
                    break;
                }
            }
        }
        else if(velocity.x<0&&canMoveUp(g,maze)&&canMoveDown(g,maze)&&canMoveRight(g,maze)&&WillPassCenter(g)){
            if (g.randomInt(1,2)==1){
                switch(g.randomInt(1,3)){                   // take a turn at the intersection
                case 1:
                    goUp(g,maze);
                    break;
                case 2:
                    goDown(g,maze);
                    break;
                case 3:
                    goRight(g,maze);
                    break;
                }
            }
        }
        else if(velocity.x<0&&canMoveUp(g,maze)&&canMoveDown(g,maze)&&canMoveLeft(g,maze)&&WillPassCenter(g)){
            if (g.randomInt(1,2)==1){
                switch(g.randomInt(1,3)){                   // take a turn at the intersection
                case 1:
                    goUp(g,maze);
                    break;
                case 2:
                    goDown(g,maze);
                    break;
                case 3:
                    goLeft(g,maze);
                }
            }
        }
        else if (velocity.y>0&&canMoveLeft(g,maze)&&canMoveRight(g,maze)&&canMoveDown(g,maze)&&WillPassCenter(g)){
            if (g.randomInt(1,2)==1){
                switch(g.randomInt(1,3)){                   // take a turn at the intersection
                case 1:
                    goLeft(g,maze);
                    break;
                case 2:
                    goRight(g,maze);
                    break;
                case 3:
                    goDown(g,maze);
                    break;
                }
            }
        }
        else if (velocity.y<0&&canMoveLeft(g,maze)&&canMoveRight(g,maze)&&canMoveUp(g,maze)&&WillPassCenter(g)){
            if (g.randomInt(1,2)==1){
                switch(g.randomInt(1,2)){                   // take a turn at the intersection
                case 1:
                    goLeft(g,maze);
                    break;
                case 2:
                    goRight(g,maze);
                    break;
                case 3:
                    goUp(g,maze);
                    break;
                }
            }
        }
        else if (velocity.y<0&&canMoveLeft(g,maze)&&WillPassCenter(g)){
            if (g.randomInt(1,2)==1){
                goLeft(g,maze);
            }
        }
        else if (velocity.y<0&&canMoveRight(g,maze)&&WillPassCenter(g)){
            if (g.randomInt(1,2)==1){
                goRight(g,maze);
            }
        }
        else if (velocity.y>0&&canMoveLeft(g,maze)&&WillPassCenter(g)){
            if (g.randomInt(1,2)==1){
                goLeft(g,maze);
            }
        }
        else if (velocity.y>0&&canMoveRight(g,maze)&&WillPassCenter(g)){
            if (g.randomInt(1,2)==1){
                goRight(g,maze);
            }
        }
        else if (velocity.x<0&&canMoveUp(g,maze)&&WillPassCenter(g)){
            if (g.randomInt(1,2)==1){
                goUp(g,maze);
            }
        }
        else if (velocity.x<0&&canMoveDown(g,maze)&&WillPassCenter(g)){
            if (g.randomInt(1,2)==1){
                goDown(g,maze);
            }
        }
        else if (velocity.x>0&&canMoveUp(g,maze)&&WillPassCenter(g)){
            if (g.randomInt(1,2)==1){
                goUp(g,maze);
            }
        }
        else if (velocity.x>0&&canMoveDown(g,maze)&&WillPassCenter(g)){
            if (g.randomInt(1,2)==1){
                goDown(g,maze);
            }
        }
    }
    pos = pos + velocity;
}

void Ghost::goUp(Graphics&g, Maze&maze){
    if (canMoveUp(g,maze)==true){
        pos.x=cellCenter(g).x;
        velocity.y=2.75;
        // cout << "moving up" << endl;
        velocity.x=0;
    }
    else if (canMoveUp(g,maze)==false){
        checkStop(g,maze);
    }
    pos=pos+velocity;
}

void Ghost::goDown(Graphics &g, Maze &maze){
    if (canMoveDown(g,maze)==true){
        pos.x=cellCenter(g).x;
        velocity.y=-2.75;
        // cout << "moving down" << endl;
        velocity.x=0;
    }
    else if (canMoveDown(g,maze)==false){
        checkStop(g,maze);
        // cout << "stopping" << endl;
    }
    pos=pos+velocity;
}

void Ghost::goRight(Graphics &g, Maze &maze){
    if (canMoveRight(g,maze)==true){
        pos.y=cellCenter(g).y;
        velocity.x=2.75;
        // cout << "moving Right" << endl;
        velocity.y=0;
    }
    else if (canMoveRight(g,maze)==false){
        checkStop(g,maze);
    }
    pos=pos+velocity;
}

void Ghost::goLeft(Graphics &g, Maze &maze){
    if (canMoveLeft(g,maze)==true){
        pos.y=cellCenter(g).y;
        velocity.x=-2.75;
        // cout << "moving left" << endl;
        velocity.y=0;
    }
    else if (canMoveLeft(g,maze)==false){
        checkStop(g,maze);
    }
    pos=pos+velocity;
}






