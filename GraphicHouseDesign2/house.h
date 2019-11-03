#ifndef HOUSE_H
#define HOUSE_H

#include<vector>
#include <iostream>
#include <map>
#include "graphics.h"
#include "wall.h"
#include "room.h"

class House{
private:
    std::vector <std::unique_ptr<Wall>> walls; //vector of unique pointers
    //public:
    std::vector <Room> rooms;
public:
    House(double width, double length);

    void draw (mssm::Graphics& g);
    void setRoomsSelected(Vec2d pos);
    Room *findRoom(Vec2d pos);
    void vSplitRoom(Vec2d pos);
    void hSplitRoom(Vec2d pos);
    Wall* wallFactory(Vec2d start, Vec2d end);
    Room* roomFactory(std::string name, std::vector<Wall*> walls);
    std::vector <Wall*> splitWall(Wall* wall, Vec2d pos);
    void saveTo(std::ostream& strm, House *a) const;
    void loadFrom(std::istream& strm);
};

#endif // HOUSE_H
