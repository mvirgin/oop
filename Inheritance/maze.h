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
    void draw(Graphics& g, mssm::Color c);
    bool canMove(int row, int column);
    bool PelletPresent(int row, int column);
    bool RightTeleporterPresent(int row, int column);
    bool LeftTeleporterPresent(int row, int column);
    void clearPellet(int row, int column);
    bool BigPelletPresent(int row, int column);
    void clearBigPellet(int row, int column);
    bool doorInFront(int row, int column);
    void lockDoor(int row, int column);
};

#endif // MAZE_H
