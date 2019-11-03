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

using namespace std;
using namespace mssm;

#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wnarrowing"

using namespace std;

void graphicsMain(Graphics& g){
    Blinky shadow;
    Inky bashful;


    while (g.draw()) {
        g.clear();

        shadow.draw(g);

        for (const Event& e : g.events()) {
            switch (e.evtType) {
            case EvtType::MousePress:

                break;
            case EvtType::MouseRelease:
                break;
            case EvtType::KeyPress:
                switch (e.arg) {
                case 'V':

                    break;
                case 'H':

                    break;
                case 'S':

                    break;
                case 'L':

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

