#include <iostream>
#include "graphics.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <memory>
#include <fstream>
#include <map>

#include "gameobject.h"
#include "Ghost.h"
#include "blinky.h"
#include "inky.h"
#include "pinky.h"
#include "clyde.h"
#include "maze.h"
#include "pacman.h"

using namespace std;
using namespace mssm;

#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wnarrowing"

using namespace std;

void graphicsMain(Graphics& g){
    Blinky shadow;
    Pinky speedy; //actually make him pink
    Inky bashful;
    Clyde pokey;
    Maze maze;
    Pacman player;

    while (g.draw()) {
        g.clear();
        maze.draw(g,WHITE);
        shadow.draw(g);
        pokey.draw(g);
        speedy.draw(g);
        bashful.draw(g);
        player.draw(g);
        player.update(g,maze); // i dont even use g in update
        shadow.bupdate(g,maze,player);
        pokey.gupdate(g,maze,player);
        speedy.gupdate(g,maze,player);
        bashful.gupdate(g,maze,player);

        if (player.victory()==true&&player.YouLose()==false){
            g.text(g.width()/2,g.height()/2,50,"YOU WIN",GREEN);
        }
        else if (player.YouLose()==true&&player.victory()==false){
            g.text(g.width()/2,g.height()/2,50,"YOU LOSE",RED);
        }

        for (const Event& e : g.events()) {
            switch (e.evtType) {
            case EvtType::MousePress:

                break;
            case EvtType::MouseRelease:
                break;
            case EvtType::KeyPress:
                switch (e.arg) {
                case 'W':
                    player.direction = 'w';
//                    player.velocity.y=1.0; //only  change velocity
//                    player.velocity.x=0;
                    break;
                case 'A':
                    player.direction='a';
//                    player.velocity.x=-1.0;
//                    player.velocity.y=0;
                    break;
                case 'S':
                    player.direction='s';
//                    player.velocity.y=-1.0;
//                    player.velocity.x=0;
                    break;
                case 'D':
                    player.direction='d';
//                    player.velocity.x=1.0;
//                    player.velocity.y=0;
                    break;
                }
                break;
            case EvtType::MouseMove:
                break;
            default:
                break;
            }
        }
    }
}

int main() {
    Graphics g("Drawing", 800, 600, graphicsMain);
}

