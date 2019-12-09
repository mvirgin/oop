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

void Blinky::ChaseMode(Graphics &g, Maze &maze, Pacman &player){
    int prow = player.Row(g);
    int pcol = player.column(g);

    int grow = Row(g);
    int gcol = column(g);
    //look at where the player is, try to get to him
    //probably want to split into player above and to the right, player above and to the left, player below and to the right, player below and to left
    //above and right
    if (prow>grow&&pcol>gcol){ //if player is above me, I want to go up until something is in my way -- its not hitting this, what if theyre on the same level
        // cout << "above and right" <<endl;
        if (canMoveUp(g,maze)==true){
            pos.x=cellCenter(g).x;
            velocity.y=1.8;
            velocity.x=0;
        }
        else if (canMoveUp(g,maze)==false){
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
                //                if (canMoveLeft(g,maze)==true){
                //                    cout << "weirdthing4" <<endl;
                //                    velocity.y=0;
                //                    velocity.x=-1.8;
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
        // cout <<"above and left" <<endl;
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
                //                if (canMoveRight(g,maze)==true){
                //                    cout << "weird thing" <<endl; // all of these parts in each if is broken
                //                    velocity.y=0;
                //                    velocity.x=1.8;
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
                //                if (canMoveLeft(g,maze)==true){
                //                    cout<< "weirdthing3" <<endl;
                //                    velocity.y=0;
                //                    velocity.x=-1.8;
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
                //                if (canMoveUp(g,maze)==true){
                //                    cout << "weird thing2" << endl; //its crashing here, probably because it always wants to go towards the player
                //                    velocity.y=1.8;
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
            if (canMoveUp(g,maze)==true){   //might want to change this to up/down
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
            //            if (canMoveRight(g,maze)==true){ //might want to change this to up/down
            //                //cout <<"chasing"<<endl;
            //                velocity.y=0;
            //                velocity.x=-1.8;
            //                pos.y=cellCenter(g).y;
            //            }
            //            else if (canMoveRight(g,maze)==false){
            //                // cout << "stopping" << endl;
            //                checkStop(g,maze);
            //            }
        }
    }
    //    else if (player.pos.y<pos.y){
    //        velocity.y=-1.8;
    //    }
    //    else{
    //        stop(g);
    //    }
    else{
        //  cout << "final case" <<endl;
    }
   // LifeAndDeath(g, player, maze, gcol, pcol, grow, prow);

    pos=pos+velocity;
}




