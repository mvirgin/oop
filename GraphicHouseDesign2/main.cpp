#include <iostream>
#include "graphics.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <memory>
#include <fstream>
#include <map>

#include "wall.h" //fix wall cpp
#include "room.h"
#include "house.h"

using namespace std;
using namespace mssm;

#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wnarrowing"

using namespace std;

//class Windoors{
//private:
//    double width;
//    string type;
//    Vec2d origin;
//};

//class Wall{
//public:
//    Vec2d P1;
//    double length;
//    bool isVertical; //true = up (vertical)
//    //vector <Windoors> windoors;
//public:
//    Wall(Vec2d initP1, double initLength, bool initDirection);
//    Wall(Vec2d GivenP1, Vec2d GivenP2);

//    void wallDraw (Graphics& g, Color c = WHITE);
//    Vec2d FindP2() const;
//    bool doesRayIntersect(Vec2d point);
//    bool doesLineIntersect(Vec2d p, bool isLineVertical) const;
//};

//Wall::Wall(Vec2d initP1, double initLength, bool initDirection){
//    P1=initP1;
//    length=initLength;
//    isVertical=initDirection;
//}

//Wall::Wall(Vec2d GivenP1, Vec2d GivenP2){
//    P1 = GivenP1;
//    length = (GivenP1-GivenP2).magnitude();
//    if (GivenP1.x==GivenP2.x){
//        isVertical=true;
//    }
//    else{
//        isVertical=false;
//    }
//}

//Vec2d Wall::FindP2() const{
//    double x = P1.x;
//    double y = P1.y;
//    if (isVertical == true){
//        y = P1.y+length;
//    }
//    else {
//        x = P1.x+length;
//    }
//    Vec2d P2{x,y};
//    return P2;
//}

//void Wall::wallDraw(Graphics &g, Color c){
//    Vec2d P2 = FindP2();
//    g.line(P1,P2, c);
//    //    g.ellipseC(P1,8,8,GREEN);
//    //    g.ellipseC(P2,16,16,RED);
//}

//bool Wall::doesRayIntersect(Vec2d point){
//    return ((P1.x==FindP2().x&&point.x<P1.x&&point.y>P1.y&&point.y<FindP2().y)||(P1.x==FindP2().x&&point.x<P1.x&&point.y<P1.y&&point.y>FindP2().y));
//}

//bool Wall::doesLineIntersect(Vec2d p, bool isLineVertical) const{ //checks if the line passing through p intersects a wall
//    Vec2d P2 = FindP2();

//    if (isLineVertical){
//        if (isVertical){
//            return false;
//        }

//        return p.x > min(P1.x,P2.x) && p.x < max(P1.x, P2.x);
//    }
//    else{
//        if (!isVertical){
//            return false;
//        }
//        return p.y > min(P1.y, P2.y) && p.y < max(P1.y, P2.y);
//    }
//}

//bool  operator== (Vec2d p1, Vec2d p2)
//{
//    return p1.x==p2.x&&p1.y==p2.y;
//}

//bool wallsTouch(const Wall& w1,const Wall& w2){
//    Vec2d w1P2 = w1.FindP2();
//    Vec2d w2P2 = w2.FindP2();

//    return w1.P1 == w2.P1 ||
//            w1P2 == w2.P1 ||
//            w1.P1 == w2P2 ||
//            w1P2 == w2P2;
//}

//class Room{
//private:
//    string name;
//    vector <Wall*> walls; //standard pointers
//    bool selected{false}; //determines if user has selected the room
//public:
//    Room(string name1, vector <Wall*> walls1);
//    void Rdraw (Graphics& g, Color c);
//    bool containsPoint(Vec2d pos);
//    void SetSelected(Vec2d pos);
//    bool containsWall(Wall* w);
//    void replaceWall (Wall* oldWall, Wall * newWall1, Wall* newWall2);
//    void saveToR(std::ostream& strm) const;

//    friend class House;
//};

//Room::Room(string name1, vector <Wall*> walls1){
//    name=name1;
//    walls=walls1;
//}

//bool Room::containsWall(Wall *w){
//    return find (walls.begin(),walls.end(),w) != walls.end();
//}

//void Room::replaceWall(Wall *oldWall,  Wall * newWall1, Wall* newWall2){

//    auto pos = find (walls.begin(),walls.end(), oldWall);

//    Wall* prevWall;
//    if (pos == walls.begin()) {
//        prevWall=walls.back();
//    }
//    else{
//        prevWall = *(pos-1);
//    }

//    if (!wallsTouch(*newWall1,*prevWall)){
//        swap(newWall1,newWall2); // ensure we are in clockwise order
//    }

//    auto insertPos = walls.erase(pos);
//    insertPos = walls.insert(insertPos,newWall2);
//    walls.insert(insertPos,newWall1);
//}

//void Room::Rdraw(Graphics &g, Color c){
//    Vec2d middle{0,0};
//    for (int i =0; i <walls.size(); i++){
//        middle=middle+walls[i]->P1;
//        if (selected==true){
//            walls[i]->wallDraw(g, c);

//            auto s = std::to_string(i+1);;
//            Vec2d point2 = walls[i]->FindP2();
//            Vec2d point1 = walls[i]->P1;
//            double mdpt1 = ((point1.x+point2.x)/2);
//            double mdpt2 = ((point1.y+point2.y)/2);
//            Vec2d mdpt{mdpt1,mdpt2};
//            g.text(mdpt.x,mdpt.y,20,s);
//        }
//        else{
//            walls[i]->wallDraw(g, WHITE);
//        }
//    }
//    middle=middle*(1.0/walls.size());
//    g.text(middle,20,name);
//}

//bool Room::containsPoint(Vec2d pos){
//    int counter=0;
//    bool containPt=false;
//    for (int i =0;i<walls.size();i++){
//        if (walls[i]->doesRayIntersect(pos)==true){
//            counter=counter+1;
//        }
//    }
//    if (counter%2>0){
//        containPt= true;
//    }
//    return containPt;
//}

//void Room::SetSelected(Vec2d pos){
//    if (containsPoint(pos)==true){
//        selected=true;
//        cout << "  Setting a room to selected" << endl;
//    }
//    else{
//        selected=false;
//        cout << "  This room is not selected" << endl;
//    }
//}

//void Room::saveToR(std::ostream& strm) const{
//    strm << "There are " << walls.size() << " walls in this room" << endl;
//    strm << "Here is the P1 of each wall, its length, its direction, and its P2: " << endl;
//    string direction;
//    for (int i=0;i<walls.size();i++){
//        strm << "Wall " << i+1 << ": ";
//        if (walls[i]->isVertical){
//            direction = "Vertical";
//        }
//        else{
//            direction = "Horizontal";
//        }
//        strm <<"("<< walls[i]->P1.x <<","<<walls[i]->P1.y<<")" <<" " <<walls[i]->length<<" "<<direction<<" "<<"("<<walls[i]->FindP2().x<<","<<walls[i]->FindP2().y<<")" << endl;
//    }

//}

//class House{
//private:
//    vector <unique_ptr<Wall>> walls; //vector of unique pointers
//    //public:
//    vector <Room> rooms;
//public:
//    House(double width, double length);

//    void draw (Graphics& g);
//    void setRoomsSelected(Vec2d pos);
//    Room *findRoom(Vec2d pos);
//    void vSplitRoom(Vec2d pos);
//    void hSplitRoom(Vec2d pos);
//    Wall* wallFactory(Vec2d start, Vec2d end);
//    Room* roomFactory(string name, vector<Wall*> walls);
//    vector <Wall*> splitWall(Wall* wall, Vec2d pos);
//    void saveTo(std::ostream& strm, House *a) const;
//    void loadFrom(std::istream& strm);
//};

//class wallTester {
//public:
//    Wall* wall;
//public:
//    wallTester(Wall* wall) : wall{wall} {}
//    bool operator() (unique_ptr<Wall>& w) { return wall == w.get(); }
//};

//House::House(double width, double length){
//    Wall *a = new Wall{{10,10},width,false};
//    Wall *b = new Wall{{10+width,10},length,true};
//    Wall *c = new Wall{{10,10+length},width,false};
//    Wall *d = new Wall{{10,10},length,true};

//    walls.emplace_back(d);
//    walls.emplace_back(c);
//    walls.emplace_back(b);
//    walls.emplace_back(a);

//    vector <Wall*> RWalls{d,c,b,a};
//    Room One{"Initial House",RWalls};
//    rooms.push_back(One);
//}

//Wall* House::wallFactory(Vec2d start, Vec2d end){
//    for (int i=0;i<walls.size();i++){
//        if (walls[i]->P1.x==start.x&&
//                walls[i]->P1.y==start.y&&
//                walls[i]->FindP2().x==end.x&&
//                walls[i]->FindP2().y==end.y){
//            return walls[i].get();
//        }
//    }
//    walls.push_back(make_unique<Wall>(start, end));
//    return walls.back().get();
//}

//Room* House::roomFactory(string name, vector<Wall*> walls){
//    Room newRoom(name, walls);
//    rooms.push_back(newRoom);
//    return &rooms.back();
//}

//void House::draw(Graphics &g){
//    for (int i =0; i <walls.size(); i++){
//        walls[i]->wallDraw(g);
//    }

//    for (Room&r:rooms){
//        if (r.selected){
//            r.Rdraw(g,GREEN);
//        }
//    }
//}

//void House::setRoomsSelected(Vec2d pos){
//    cout << "\nSelecting" << endl;
//    for (int i=0; i<rooms.size(); i++){
//        rooms[i].SetSelected(pos);
//    }
//}

//vector  <Wall*> House::splitWall(Wall* wall, Vec2d pos){
//    Wall* w1;
//    Wall* w2;

//    if (wall->isVertical==false){
//        w1 = wallFactory(wall->P1,{pos.x,wall->FindP2().y});
//        w2 = wallFactory({pos.x,wall->FindP2().y},wall->FindP2());

//    }
//    else{
//        w1 = wallFactory(wall->P1,{wall->FindP2().x,pos.y});
//        w2 = wallFactory({wall->FindP2().x,pos.y},wall->FindP2());
//    }

//    for (auto& r: rooms){
//        if (r.containsWall(wall)) {
//            cout << "Found a room with that wall" << endl;
//            r.replaceWall(wall, w1, w2);
//        }
//    }

//    // lambda / anonymous function
//    auto i = find_if(walls.begin(), walls.end(), [wall](unique_ptr<Wall>& w) { return wall == w.get(); });
//    walls.erase(i);

//    vector <Wall*> splitwalls;

//    if (w1->P1.x<w2->P1.x){
//        splitwalls = vector <Wall*>{w1,w2};
//    }
//    else {
//        splitwalls = vector <Wall*>{w2,w1};
//    }
//    return splitwalls;
//}

//Room *House::findRoom(Vec2d pos){
//    for (auto& r : rooms) {
//        if (r.containsPoint(pos)) {
//            return &r;
//        }
//    }
//    return nullptr;
//}

//void House::vSplitRoom(Vec2d pos){
//    cout << "Gonna try to split the room " << endl;
//    Room* r = findRoom(pos);

//    if (!r) {  //i.e r is nullptr
//        cout << "No room found " << endl;
//        return;
//    }

//    vector <Wall*> room1;
//    vector <Wall*> room2;

//    bool onRoom1 = true;

//    vector <Wall*> intersectedWalls;

//    for (auto& w: r->walls){
//        if (w->doesLineIntersect(pos,true)){
//            intersectedWalls.push_back(w);
//            onRoom1=!onRoom1;
//        }
//        else{
//            if (onRoom1){
//                room1.push_back(w);
//            }
//            else {
//                room2.push_back(w);
//            }
//        }
//    }

//    if (intersectedWalls.size()!=2){
//        cout << "now we gotta deal with this case" << endl;
//        return;
//    }

//    if (intersectedWalls[0]->P1.y<intersectedWalls[1]->P1.y){ //ensuring intersectedWalls[0] is on top
//        Wall* first = intersectedWalls[1];
//        Wall* second = intersectedWalls[0];
//        intersectedWalls[0]=first;
//        intersectedWalls[1]=second;
//    }
//    else{}
//    Vec2d mP1{pos.x,intersectedWalls[0]->P1.y};
//    Vec2d mP2{pos.x,intersectedWalls[1]->P1.y};

//    vector <Wall*> topsplitwalls = splitWall(intersectedWalls[0],pos);
//    vector <Wall*> bottomsplitwalls = splitWall(intersectedWalls[1],pos);

//    Wall * ul = topsplitwalls[0]; //left room
//    Wall* ur = topsplitwalls[1]; //right room
//    Wall* ll = bottomsplitwalls[0]; // left room
//    Wall* lr = bottomsplitwalls[1]; //right room
//    Wall* middleWall = wallFactory(mP2, mP1); // both rooms

//    bool doestouch=false;
//    for (int i=0; i<room1.size();i++){
//        if (wallsTouch(*room1[i],*ul)){
//            doestouch=true;
//        }
//    }

//    if (!doestouch){
//        swap(room1,room2);
//    }

//    for (int i=0; i<room1.size();i++){
//        if (wallsTouch(*room1[i],*ul)==true){
//            room1.insert(room1.begin()+i+1,ul);
//            room1.insert(room1.begin()+i+2,middleWall);
//            room1.insert(room1.begin()+i+3,ll);
//            cout << "added walls to room1" << endl;
//            break;
//        }
//    }

//    for (int i=0; i<room2.size();i++){
//        if (wallsTouch(*room2[i],*lr)==true){
//            room2.insert(room2.begin()+i+1,lr);
//            room2.insert(room2.begin()+i+2,middleWall);
//            room2.insert(room2.begin()+i+3,ur);
//            cout << "added rooms to room2" << endl;
//            break;
//        }
//    }

//    auto i = find_if(rooms.begin(), rooms.end(), [r](Room& room) { return r == &room; });
//    rooms.erase(i);
//    cout << "This is the size of the room1: " << room1.size() << endl;
//    cout << "This is the size of the room2: " << room2.size() << endl;
//    roomFactory("left", room1);
//    roomFactory("right", room2);
//}

//void House::hSplitRoom(Vec2d pos){
//    cout << "Gonna try to split the room " << endl;
//    Room* r = findRoom(pos);

//    if (!r) {  //i.e r is nullptr
//        cout << "No room found " << endl;
//        return;
//    }

//    vector <Wall*> tRoom;
//    vector <Wall*> bRoom;

//    bool onTopRoom = true;

//    vector <Wall*> intersectedWalls;

//    for (auto& w: r->walls){
//        if (w->doesLineIntersect(pos,false)){
//            intersectedWalls.push_back(w);
//            onTopRoom=!onTopRoom;
//        }
//        else{
//            if (onTopRoom){
//                tRoom.push_back(w);
//            }
//            else {
//                bRoom.push_back(w);
//            }
//        }
//    }

//    if (intersectedWalls.size()!=2){
//        cout << "now we gotta deal with this case" << endl;
//        return;
//    }

//    if (intersectedWalls[0]->P1.x>intersectedWalls[1]->P1.x){
//        Wall* first = intersectedWalls[1];
//        Wall* second = intersectedWalls[0];
//        intersectedWalls[0]=first;
//        intersectedWalls[1]=second;
//    }
//    else{}
//    Vec2d mP1{intersectedWalls[0]->P1.x, pos.y};
//    Vec2d mP2{intersectedWalls[1]->P1.x, pos.y};

//    vector <Wall*> leftsplitwalls = splitWall(intersectedWalls[0],pos);
//    vector <Wall*> rightsplitwalls = splitWall(intersectedWalls[1],pos);

//    Wall * tl = leftsplitwalls[0];
//    Wall* bl = leftsplitwalls[1];
//    Wall* tr = rightsplitwalls[0];
//    Wall* br = rightsplitwalls[1];
//    Wall* middleWall = wallFactory(mP1, mP2);

//    bool doestouch=false;
//    for (int i=0; i<bRoom.size();i++){
//        if (wallsTouch(*bRoom[i],*bl)){
//            doestouch=true;
//        }
//    }

//    if (!doestouch){
//        swap(bRoom,tRoom);
//    }

//    for (int i=0; i<tRoom.size();i++){
//        if (wallsTouch(*tRoom[i],*tr)==true){
//            tRoom.insert(tRoom.begin()+i+1,tr);
//            tRoom.insert(tRoom.begin()+i+2,middleWall);
//            tRoom.insert(tRoom.begin()+i+3,tl);
//            cout << "added walls to room1" << endl;
//            break;
//        }
//    }

//    for (int i=0; i<bRoom.size();i++){
//        if (wallsTouch(*bRoom[i],*bl)==true){
//            bRoom.insert(bRoom.begin()+i+1,bl);
//            bRoom.insert(bRoom.begin()+i+2,middleWall);
//            bRoom.insert(bRoom.begin()+i+3,br);
//            cout << "added rooms to room2" << endl;
//            break;
//        }
//    }

//    auto i = find_if(rooms.begin(), rooms.end(), [r](Room& room) { return r == &room; });
//    rooms.erase(i);
//    cout << "This is the size of the troom: " << tRoom.size() << endl;
//    cout << "This is the size of the broom: " << bRoom.size() << endl;
//    roomFactory("top", tRoom);
//    roomFactory("bottom", bRoom);
//}

//void House::saveTo (std::ostream& strm, House* a) const{
//    strm << "You have 1 house with " << a->rooms.size() << " rooms in it" << endl;
//    for (int i=0;i<a->rooms.size();i++){
//        strm << "For room " << i+1 << ": " << endl;
//        rooms[i].saveToR(strm);
//    }
//}

//void skip (std::istream &strm, int skips){
//    string dummy;
//    for (int i=0;i<skips;i++){
//        strm >> dummy;
//    }
//}

//void House::loadFrom(std::istream &strm){
//    walls.clear();
//    rooms.clear();
//    int numberOfRooms;

//    skip(strm,5);

//    strm >> numberOfRooms;

//    skip(strm,5);

//    int roomIndex;
//    strm >> roomIndex;

//    for (int j=0; j<numberOfRooms;j++){
//        vector <Wall*> RoomWalls;

//        skip(strm,3);

//        int numberOfWalls;
//        strm >>numberOfWalls;

//        skip(strm,19);

//        int wallIndex;
//        strm >> wallIndex;

//        for (int v=0; v<numberOfWalls;v++){
//            skip(strm,1);
//            strm.ignore(2);

//            int p1x;
//            strm >> p1x;

//            strm.ignore(1);

//            int p1y;
//            strm >> p1y;

//            strm.ignore(2);
//            skip(strm,2);
//            strm.ignore(2);

//            int p2x;
//            strm >> p2x;

//            strm.ignore(1);

//            int p2y;
//            strm >> p2y;

//            Vec2d P1{p1x,p1y};
//            Vec2d P2{p2x,p2y};

//            Wall* RoomWall = wallFactory(P1,P2);
//            RoomWalls.push_back(RoomWall);

//            strm.ignore(1);
//            skip(strm,1);
//        } // end of looping over wall lines
//        skip(strm,1);
//        roomFactory("blah", RoomWalls);
//    } // end of room looping
//}

void graphicsMain(Graphics& g){
    House a {700,500};

    while (g.draw()) {
        g.clear();

        a.draw(g);

        for (const Event& e : g.events()) {
            switch (e.evtType) {
            case EvtType::MousePress:
            {Vec2d mousePos(e.x,e.y);
                a.setRoomsSelected(mousePos);}
                break;
            case EvtType::MouseRelease:
                break;
            case EvtType::KeyPress:
                switch (e.arg) {
                case 'V':
                    a.vSplitRoom(g.mousePos());
                    break;
                case 'H':
                    a.hSplitRoom(g.mousePos());
                    break;
                case 'S':
                {ofstream f {"C:\\tmp\\example.txt"};
                    a.saveTo(f,&a);
                }
                    break;
                case 'L':
                {ifstream ifile{"C:\\tmp\\example.txt"};
                    a.loadFrom(ifile);
                }
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

