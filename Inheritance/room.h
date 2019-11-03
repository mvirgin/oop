#ifndef ROOM_H
#define ROOM_H

#include<vector>
#include <iostream>
#include <map>
#include "graphics.h"
#include "wall.h"

class Room{
private:
    std::string name;
    std::vector <Wall*> walls; //standard pointers
    bool selected{false}; //determines if user has selected the room
public:
    Room(std::string name1, std::vector <Wall*> walls1);
    void Rdraw (mssm::Graphics& g, mssm::Color c);
    bool containsPoint(Vec2d pos);
    void SetSelected(Vec2d pos);
    bool containsWall(Wall* w);
    void replaceWall (Wall* oldWall, Wall * newWall1, Wall* newWall2);
    void saveToR(std::ostream& strm) const;

    friend class House;
};

#endif // ROOM_H
