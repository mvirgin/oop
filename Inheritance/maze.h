#ifndef MAZE_H
#define MAZE_H
#include <vector>
#include "graphics.h"
using namespace std;
using namespace mssm;

class Maze
{
private:
    vector<vector <char>> grid;
public:
    Maze();
    void draw(Graphics& g);
    bool canMove(int row, int column);
};

#endif // MAZE_H
