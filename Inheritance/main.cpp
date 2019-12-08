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

    int row = player.Row(g);
    int col = player.column(g);

    while (g.draw()) {
        g.clear();
        maze.draw(g,WHITE);
        shadow.draw(g);
        player.draw(g);
        player.calculateCell(g, row, col);
        player.update(g,maze); // i dont even use g in update

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

