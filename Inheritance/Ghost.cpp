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
    //    if(player.invincibleFrames>0){
    //        run(g,maze,player);
    //        if ()

    //    bool isRED=true;
    //    if (player.eatingBigPellet(g,maze)==true){ //          ------------ if player has eaten a big pellet, run and be destructable
    //        run(g,maze,player); //-----------------SHOULD PROBABLY  TRY  TO GET THIS TO WORK -----------------------------------------------------------
    //        c=BLUE;
    //        isRED=false;
    //        blueFrames=500;
    //    }
    //    blueFrames--;

    //    if (blueFrames==0){
    //        c=RED;
    //        isRED=true;
    //    }
    if (grow==prow&&gcol==pcol/*&&blueFrames>0*/){
        c=WHITE;
        // isRED=false;
        pos={393,300};
        deathFrames=500;
        // blueFrames=-1;                                          //blueFrames are positive when ghost can be eaten, negative when ghost can eat player
    }                   //this is problematic because blueFrames are also negative when the ghost has been "eaten" and is invisible - he can eat player
    //    else if(grow==prow&&gcol==pcol/*&&blueFrames<0*/&&isRED==true){
    //        cout << "caught p1" <<endl;
    //        player.gotCaught(); //ADD 1 TO A COUNTER EVERY TIME THIS HAPPENS, WHEN COUNTER HITS 3, GAME OVER --------------------------------------
    //        pos={393,300};
    //    }
    ////    else{
    ////        maze.lockDoor(grow,gcol);
    ////    }
    deathFrames--;
    if (deathFrames==0){
        c=origcolor; //not all ghosts are red!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        //  isRED=true;
        pos={393,300};
    }
}

void Ghost::draw(Graphics &g){
    //    vector<Vec2d>ghostpts{{0,0},{5,5},{10,0},{15,5},{20,0},{25,5},{30,0},{30,20},{27,23},{25,25},{15,26},{5,25},{3,23},{0,20}};
    //    for (int i=0;i<ghostpts.size();i++){
    //        ghostpts[i].scale(.66);
    //        ghostpts[i].translate(pos);
    //    }
    //    g.polygon(ghostpts,c);
    g.ellipseC(pos,20,15,c);
}

void Ghost::run(Graphics &g, Maze &maze, Pacman &player){
    int prow = player.Row(g);
    int pcol = player.column(g);

    int grow = Row(g);
    int gcol = column(g);
    //look at where the player is, try to get to him
    //probably want to split into player above and to the right, player above and to the left, player below and to the right, player below and to left
    //above and right
    if (prow>grow&&pcol>gcol){ //if player is above me, I want to go up until something is in my way -- its not hitting this, what if theyre on the same level
        //  cout << "above and right" <<endl;
        if (canMoveDown(g,maze)==true){
            pos.x=cellCenter(g).x;
            velocity.y=-1.4;
            velocity.x=0;
        }
        else if (canMoveDown(g,maze)==false){
            checkStop(g,maze);
            if (canMoveLeft(g,maze)==true){
                //cout <<"chasing"<<endl;
                velocity.y=0;
                velocity.x=-1.4;
                //       cout << "moving left" <<endl;
                pos.y=cellCenter(g).y;
            }
            else if (canMoveLeft(g,maze)==false){
                // cout << "stopping" << endl;
                checkStop(g,maze);
                //       cout << "stopping" << endl;
                //                if (canMoveLeft(g,maze)==true){
                //                    cout << "weirdthing4" <<endl;
                //                    velocity.y=0;
                //                    velocity.x=-1.4;
                //                    pos.y=cellCenter(g).y;
                //                }
                //                else if(canMoveLeft(g,maze)==false){
                //                    checkStop(g,maze);
                //                }
            }
        }
    }
    // above and left
    else if (prow>grow&&pcol<gcol){
        //    cout <<"above and left" <<endl;
        if (canMoveDown(g,maze)==true){
            pos.x=cellCenter(g).x;
            velocity.y=-1.4;
            //     cout << "moving down" <<endl;
            velocity.x=0;
        }
        else if (canMoveDown(g,maze)==false){
            checkStop(g,maze);
            if (canMoveRight(g,maze)==true){
                //cout <<"chasing"<<endl;
                velocity.y=0;
                velocity.x=1.4;
                //         cout << "moving right" <<endl;
                pos.y=cellCenter(g).y;
            }
            else if (canMoveRight(g,maze)==false){
                // cout << "stopping" << endl;
                checkStop(g,maze);
                //          cout << "stopping" << endl;
                //                if (canMoveRight(g,maze)==true){
                //                    cout << "weird thing" <<endl; // all of these parts in each if is broken
                //                    velocity.y=0;
                //                    velocity.x=1.4;
                //                    pos.y=cellCenter(g).y;
                //                }
                //                else if(canMoveRight(g,maze)==false){
                //                    checkStop(g,maze);
                //                }
            }
        }
    }
    //below and right
    else if (prow<grow&&pcol>gcol){
        //   cout << "below and right" <<endl;
        if (canMoveUp(g,maze)==true){
            pos.x=cellCenter(g).x;
            velocity.y=1.4;\
            //     cout << "moving up" <<endl;
            velocity.x=0;
        }
        else if (canMoveUp(g,maze)==false){
            checkStop(g,maze);
            if (canMoveLeft(g,maze)==true){
                //cout <<"chasing"<<endl;
                velocity.y=0;
                velocity.x=-1.4;
                //         cout << "moving left" <<endl;
                pos.y=cellCenter(g).y;
            }
            else if (canMoveLeft(g,maze)==false){
                // cout << "stopping" << endl;
                checkStop(g,maze);
                //          cout << "stopping" << endl;
                //                if (canMoveLeft(g,maze)==true){
                //                    cout<< "weirdthing3" <<endl;
                //                    velocity.y=0;
                //                    velocity.x=-1.4;
                //                    pos.y=cellCenter(g).y;
                //                }
                //                else if(canMoveLeft(g,maze)==false){
                //                    checkStop(g,maze);
                //                }
            }
        }
    }
    //below and left
    else if (prow<grow&&pcol<gcol){
        //    cout << "below and left" <<endl;
        if (canMoveUp(g,maze)==true){
            pos.x=cellCenter(g).x;
            velocity.y=1.4;
            //        cout << "moving up" <<endl;
            velocity.x=0;
        }
        else if (canMoveUp(g,maze)==false){
            checkStop(g,maze);
            if (canMoveRight(g,maze)==true){
                //cout <<"chasing"<<endl;
                velocity.y=0;
                velocity.x=1.4;
                //          cout << "moving right" <<endl;
                pos.y=cellCenter(g).y;
            }
            else if (canMoveRight(g,maze)==false){
                // cout << "stopping" << endl;
                checkStop(g,maze);
                //           cout << "stopping" << endl;
                //                if (canMoveUp(g,maze)==true){
                //                    cout << "weird thing2" << endl; //its crashing here, probably because it always wants to go towards the player
                //                    velocity.y=1.4;
                //                    velocity.x=0;
                //                    pos.y=cellCenter(g).x;
                //                }
                //                else if(canMoveUp(g,maze)==false){
                //                    checkStop(g,maze);
                //                }
            }
        }
    }
    //directly below
    else if (pcol==gcol&&prow>grow){
        //   cout << "directly below" << endl;
        if (canMoveDown(g,maze)==true){
            pos.x=cellCenter(g).x;
            velocity.y=-1.4;
            //    cout << "moving down" << endl;
            velocity.x=0;
        }
        else {
            checkStop(g,maze);
            if (canMoveRight(g,maze)==true){
                //cout <<"chasing"<<endl;
                velocity.y=0;
                velocity.x=1.4;
                //        cout << "moving right" <<endl;
                pos.y=cellCenter(g).y;
            }
            else {
                // cout << "stopping" << endl;
                checkStop(g,maze);
                //        cout << "stopping" << endl;
            }
        }
    }
    //directly above
    else if (pcol==gcol&&prow<grow){
        //   cout << "directly above" <<endl;
        if (canMoveUp(g,maze)==true){
            pos.x=cellCenter(g).x;
            velocity.y=1.4;
            //     cout << "moving up" <<endl;
            velocity.x=0;
        }
        else if (canMoveUp(g,maze)==false){
            checkStop(g,maze);
            if (canMoveRight(g,maze)==true){
                //cout <<"chasing"<<endl;
                velocity.y=0;
                velocity.x=1.4;
                //       cout << "moving right" <<endl;
                pos.y=cellCenter(g).y;
            }
            else if (canMoveRight(g,maze)==false){
                // cout << "stopping" << endl;
                checkStop(g,maze);
                //      cout << "stopping" << endl;
            }
        }
    }
    //directly on the right
    else if (prow==grow&&pcol>gcol){
        //    cout << "directright"<<endl;
        if (canMoveLeft(g,maze)==true){
            pos.y=cellCenter(g).y;
            velocity.x=-1.4;
            //  cout << "moving left" <<endl;
            velocity.y=0;
        }
        else if (canMoveLeft(g,maze)==false){
            checkStop(g,maze);
            if (canMoveDown(g,maze)==true){   //might want to change this to up/down
                //cout <<"chasing"<<endl;
                velocity.y=-1.4;
                //      cout <<"moving down" <<endl;
                velocity.x=0;
                pos.x=cellCenter(g).x;
            }
            else if (canMoveDown(g,maze)==false){
                // cout << "stopping" << endl;
                checkStop(g,maze);
                //       cout << "stopping" << endl;
            }
        }
    }
    // directly on the left
    else if (prow==grow&&pcol<gcol){
        //   cout << "directleft" << endl;
        if (canMoveRight(g,maze)==true){
            pos.y=cellCenter(g).y;
            velocity.x=1.4;
            //     cout << "moving right" <<endl;
            velocity.y=0;
        }
        else if (canMoveRight(g,maze)==false){
            checkStop(g,maze);
            //    cout << "stopping" << endl;
            //            if (canMoveRight(g,maze)==true){ //might want to change this to up/down
            //                //cout <<"chasing"<<endl;
            //                velocity.y=0;
            //                velocity.x=-1.4;
            //                pos.y=cellCenter(g).y;
            //            }
            //            else if (canMoveRight(g,maze)==false){
            //                // cout << "stopping" << endl;
            //                checkStop(g,maze);
            //            }
        }
    }
    //    else if (player.pos.y<pos.y){
    //        velocity.y=-1.4;
    //    }
    //    else{
    //        stop(g);
    //    }
    else{
        cout << "final case" <<endl;
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
            pos = {393,300};
            player.catchNumber++;
        }
    }
    if (player.catchNumber>=3){
        cout<<"you lose" << endl;
    }
}

void Ghost::Wander(Graphics &g, Maze &maze){
    if(canMoveUp(g,maze)==true&&canMoveDown(g,maze)==true&&canMoveLeft(g,maze)==true&&canMoveRight(g,maze)==true){
      //  randomly pick a direction to move in
            //    depending on what that direction is, center myself, change veloc, etc
                int random = g.randomInt(1,4);
        switch(random){
        case 1:
            goUp(g,maze);
            break;
        case 2:
            goRight(g,maze);
            break;
        case 3:
            cout << velocity.y << endl <<endl;
            goDown(g,maze);
            break;
        case 4:
            goLeft(g,maze);
            break;
        }
    }
    //        pos.x=cellCenter(g).x;
    //        velocity.y=1.4;
    //        cout << "moving up" << endl;
    //        velocity.x=0;
    //    }
    //    else if (canMoveUp(g,maze)==false){
    //        checkStop(g,maze);
    //        if (canMoveDown(g,maze)==true){
    //            pos.x=cellCenter(g).x;
    //            velocity.y=-1.4;
    //            cout << "moving down" << endl;
    //            velocity.x=0;
    //        }
    //        else if(canMoveDown(g,maze)==false){
    //            checkStop(g,maze);
    //            if (canMoveRight(g,maze)==true){
    //                pos.y=cellCenter(g).y;
    //                velocity.x=1.4;
    //                cout << "moving right" << endl;
    //                velocity.y=0;
    //            }
    //            else if(canMoveRight(g,maze)==false){
    //                checkStop(g,maze);
    //                if (canMoveLeft(g,maze)==true){
    //                    pos.y=cellCenter(g).y;
    //                    velocity.x=-1.4;
    //                    cout << "moving left" << endl;
    //                    velocity.y=0;
    //                }
    //            }
    //        }
    //    }
    //    pos=pos+velocity;
}

void Ghost::goUp(Graphics&g, Maze&maze){
    if (canMoveUp(g,maze)==true){
        pos.x=cellCenter(g).x;
        velocity.y=1.4;
        cout << "moving up" << endl;
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
        velocity.y=-1.4;
        cout << "moving down" << endl;
        velocity.x=0;
    }
    else if (canMoveDown(g,maze)==false){
        checkStop(g,maze);
        cout << "stopping" << endl;
    }
    pos=pos+velocity;
}

void Ghost::goRight(Graphics &g, Maze &maze){
    if (canMoveRight(g,maze)==true){
        pos.y=cellCenter(g).y;
        velocity.x=1.4;
        cout << "moving Right" << endl;
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
        velocity.x=-1.4;
        cout << "moving left" << endl;
        velocity.y=0;
    }
    else if (canMoveLeft(g,maze)==false){
        checkStop(g,maze);
    }
    pos=pos+velocity;
}





