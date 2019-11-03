#include "Ghost.h"
#include <vector>
using namespace std;
using namespace mssm;

Ghost::Ghost(Color c1)
{
c=c1;
}

void Ghost::draw(Graphics &g){
    vector<Vec2d>ghostpts{{0,0},{5,5},{10,0},{15,5},{20,0},{25,5},{30,0},{30,20},{27,23},{25,25},{15,26},{5,25},{3,23},{0,20}};
    g.polygon(ghostpts,c);
}

