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
        maze.draw(g);
        pokey.draw(g);
        player.draw(g);
        player.calculateCell(g);
        player.update(g); // i dont even use g in update

       Vec2d cell = player.calculateCell(g); //bunch of if statements here checking adjacent cells with the requested direction
       if (maze.canMove(cell.x,cell.y)==false){
       player.stop(g); // i dont use g here either
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
                    player.velocity.y=1.5;
                    player.velocity.x=0;
                    break;
                case 'A':
                    player.velocity.x=-1.5;
                    player.velocity.y=0;
                    break;
                case 'S':
                    player.velocity.y=-1.5;
                    player.velocity.x=0;
                    break;
                case 'D':
                    player.velocity.x=1.5;
                    player.velocity.y=0;
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

