#include "inky.h"
#include "Ghost.h"
using namespace mssm;

constexpr Color CYAN(0,255,255);

Inky::Inky()
    :Ghost{mssm::CYAN,{393,300}}
{

}

void Inky::update(Graphics& g, Maze &maze){

}
