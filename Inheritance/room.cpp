#include "room.h"
#include <vector>

#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wnarrowing"

using namespace std;

Room::Room(string name1, vector <Wall*> walls1){
    name=name1;
    walls=walls1;
}

bool Room::containsWall(Wall *w){
    return find (walls.begin(),walls.end(),w) != walls.end();
}

void Room::replaceWall(Wall *oldWall,  Wall * newWall1, Wall* newWall2){

    auto pos = find (walls.begin(),walls.end(), oldWall);

    Wall* prevWall;
    if (pos == walls.begin()) {
        prevWall=walls.back();
    }
    else{
        prevWall = *(pos-1);
    }

    if (!wallsTouch(*newWall1,*prevWall)){
        swap(newWall1,newWall2); // ensure we are in clockwise order
    }

    auto insertPos = walls.erase(pos);
    insertPos = walls.insert(insertPos,newWall2);
    walls.insert(insertPos,newWall1);
}

void Room::Rdraw(mssm::Graphics &g, mssm::Color c){
    Vec2d middle{0,0};
    for (int i =0; i <walls.size(); i++){
        middle=middle+walls[i]->P1;
        if (selected==true){
            walls[i]->wallDraw(g, c);

            auto s = std::to_string(i+1);;
            Vec2d point2 = walls[i]->FindP2();
            Vec2d point1 = walls[i]->P1;
            double mdpt1 = ((point1.x+point2.x)/2);
            double mdpt2 = ((point1.y+point2.y)/2);
            Vec2d mdpt{mdpt1,mdpt2};
            g.text(mdpt.x,mdpt.y,20,s);
        }
        else{
            walls[i]->wallDraw(g, mssm::WHITE);
        }
    }
    middle=middle*(1.0/walls.size());
    g.text(middle,20,name);
}

bool Room::containsPoint(Vec2d pos){
    int counter=0;
    bool containPt=false;
    for (int i =0;i<walls.size();i++){
        if (walls[i]->doesRayIntersect(pos)==true){
            counter=counter+1;
        }
    }
    if (counter%2>0){
        containPt= true;
    }
    return containPt;
}

void Room::SetSelected(Vec2d pos){
    if (containsPoint(pos)==true){
        selected=true;
        cout << "  Setting a room to selected" << endl;
    }
    else{
        selected=false;
        cout << "  This room is not selected" << endl;
    }
}

void Room::saveToR(std::ostream& strm) const{
    strm << "There are " << walls.size() << " walls in this room" << endl;
    strm << "Here is the P1 of each wall, its length, its direction, and its P2: " << endl;
    string direction;
    for (int i=0;i<walls.size();i++){
        strm << "Wall " << i+1 << ": ";
        if (walls[i]->isVertical){
            direction = "Vertical";
        }
        else{
            direction = "Horizontal";
        }
        strm <<"("<< walls[i]->P1.x <<","<<walls[i]->P1.y<<")" <<" " <<walls[i]->length<<" "<<direction<<" "<<"("<<walls[i]->FindP2().x<<","<<walls[i]->FindP2().y<<")" << endl;
    }

}

