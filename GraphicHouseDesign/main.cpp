#include <iostream>
#include "graphics.h"
#include <functional>

using namespace std;
using namespace mssm;

#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wnarrowing"


void graphicsMain(Graphics& g)
{

    while (g.draw()) {
        g.clear();

        g.line({200,100}, {50,20}, YELLOW);

        for (const Event& e : g.events()) {
            switch (e.evtType) {
            case EvtType::MousePress:
                break;
            case EvtType::MouseRelease:
                break;
            case EvtType::KeyPress:
                switch (e.arg) {
                case 'C':
                    // do something?
                    break;
                case 'D':
                    // do something else?
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

int main()
{
    mssm::Graphics g("House Designer", 800, 600, graphicsMain);
    return 0;
}
