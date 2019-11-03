#include "house.h"
#include <vector>
using namespace std;


#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wnarrowing"

//class wallTester {
//public:
//    Wall* wall;
//public:
//    wallTester(Wall* wall) : wall{wall} {}
//    bool operator() (unique_ptr<Wall>& w) { return wall == w.get(); }
//};

House::House(double width, double length){
    Wall *a = new Wall{{10,10},width,false};
    Wall *b = new Wall{{10+width,10},length,true};
    Wall *c = new Wall{{10,10+length},width,false};
    Wall *d = new Wall{{10,10},length,true};

    walls.emplace_back(d);
    walls.emplace_back(c);
    walls.emplace_back(b);
    walls.emplace_back(a);

    vector <Wall*> RWalls{d,c,b,a};
    Room One{"Initial House",RWalls};
    rooms.push_back(One);
}

Wall* House::wallFactory(Vec2d start, Vec2d end){
    for (int i=0;i<walls.size();i++){
        if (walls[i]->P1.x==start.x&&
                walls[i]->P1.y==start.y&&
                walls[i]->FindP2().x==end.x&&
                walls[i]->FindP2().y==end.y){
            return walls[i].get();
        }
    }
    walls.push_back(make_unique<Wall>(start, end));
    return walls.back().get();
}

Room* House::roomFactory(string name, vector<Wall*> walls){
    Room newRoom(name, walls);
    rooms.push_back(newRoom);
    return &rooms.back();
}

void House::draw(mssm::Graphics &g){
    for (int i =0; i <walls.size(); i++){
        walls[i]->wallDraw(g);
    }

    for (Room&r:rooms){
        if (r.selected){
            r.Rdraw(g,mssm::GREEN);
        }
    }
}

void House::setRoomsSelected(Vec2d pos){
    cout << "\nSelecting" << endl;
    for (int i=0; i<rooms.size(); i++){
        rooms[i].SetSelected(pos);
    }
}

vector  <Wall*> House::splitWall(Wall* wall, Vec2d pos){
    Wall* w1;
    Wall* w2;

    if (wall->isVertical==false){
        w1 = wallFactory(wall->P1,{pos.x,wall->FindP2().y});
        w2 = wallFactory({pos.x,wall->FindP2().y},wall->FindP2());

    }
    else{
        w1 = wallFactory(wall->P1,{wall->FindP2().x,pos.y});
        w2 = wallFactory({wall->FindP2().x,pos.y},wall->FindP2());
    }

    for (auto& r: rooms){
        if (r.containsWall(wall)) {
            cout << "Found a room with that wall" << endl;
            r.replaceWall(wall, w1, w2);
        }
    }

    // lambda / anonymous function
    auto i = find_if(walls.begin(), walls.end(), [wall](unique_ptr<Wall>& w) { return wall == w.get(); });
    walls.erase(i);

    vector <Wall*> splitwalls;

    if (w1->P1.x<w2->P1.x){
        splitwalls = vector <Wall*>{w1,w2};
    }
    else {
        splitwalls = vector <Wall*>{w2,w1};
    }
    return splitwalls;
}

Room *House::findRoom(Vec2d pos){
    for (auto& r : rooms) {
        if (r.containsPoint(pos)) {
            return &r;
        }
    }
    return nullptr;
}

void House::vSplitRoom(Vec2d pos){
    cout << "Gonna try to split the room " << endl;
    Room* r = findRoom(pos);

    if (!r) {  //i.e r is nullptr
        cout << "No room found " << endl;
        return;
    }

    vector <Wall*> room1;
    vector <Wall*> room2;

    bool onRoom1 = true;

    vector <Wall*> intersectedWalls;

    for (auto& w: r->walls){
        if (w->doesLineIntersect(pos,true)){
            intersectedWalls.push_back(w);
            onRoom1=!onRoom1;
        }
        else{
            if (onRoom1){
                room1.push_back(w);
            }
            else {
                room2.push_back(w);
            }
        }
    }

    if (intersectedWalls.size()!=2){
        cout << "now we gotta deal with this case" << endl;
        return;
    }

    if (intersectedWalls[0]->P1.y<intersectedWalls[1]->P1.y){ //ensuring intersectedWalls[0] is on top
        Wall* first = intersectedWalls[1];
        Wall* second = intersectedWalls[0];
        intersectedWalls[0]=first;
        intersectedWalls[1]=second;
    }
    else{}
    Vec2d mP1{pos.x,intersectedWalls[0]->P1.y};
    Vec2d mP2{pos.x,intersectedWalls[1]->P1.y};

    vector <Wall*> topsplitwalls = splitWall(intersectedWalls[0],pos);
    vector <Wall*> bottomsplitwalls = splitWall(intersectedWalls[1],pos);

    Wall * ul = topsplitwalls[0]; //left room
    Wall* ur = topsplitwalls[1]; //right room
    Wall* ll = bottomsplitwalls[0]; // left room
    Wall* lr = bottomsplitwalls[1]; //right room
    Wall* middleWall = wallFactory(mP2, mP1); // both rooms

    bool doestouch=false;
    for (int i=0; i<room1.size();i++){
        if (wallsTouch(*room1[i],*ul)){
            doestouch=true;
        }
    }

    if (!doestouch){
        swap(room1,room2);
    }

    for (int i=0; i<room1.size();i++){
        if (wallsTouch(*room1[i],*ul)==true){
            room1.insert(room1.begin()+i+1,ul);
            room1.insert(room1.begin()+i+2,middleWall);
            room1.insert(room1.begin()+i+3,ll);
            cout << "added walls to room1" << endl;
            break;
        }
    }

    for (int i=0; i<room2.size();i++){
        if (wallsTouch(*room2[i],*lr)==true){
            room2.insert(room2.begin()+i+1,lr);
            room2.insert(room2.begin()+i+2,middleWall);
            room2.insert(room2.begin()+i+3,ur);
            cout << "added rooms to room2" << endl;
            break;
        }
    }

    auto i = find_if(rooms.begin(), rooms.end(), [r](Room& room) { return r == &room; });
    rooms.erase(i);
    cout << "This is the size of the room1: " << room1.size() << endl;
    cout << "This is the size of the room2: " << room2.size() << endl;
    roomFactory("left", room1);
    roomFactory("right", room2);
}

void House::hSplitRoom(Vec2d pos){
    cout << "Gonna try to split the room " << endl;
    Room* r = findRoom(pos);

    if (!r) {  //i.e r is nullptr
        cout << "No room found " << endl;
        return;
    }

    vector <Wall*> tRoom;
    vector <Wall*> bRoom;

    bool onTopRoom = true;

    vector <Wall*> intersectedWalls;

    for (auto& w: r->walls){
        if (w->doesLineIntersect(pos,false)){
            intersectedWalls.push_back(w);
            onTopRoom=!onTopRoom;
        }
        else{
            if (onTopRoom){
                tRoom.push_back(w);
            }
            else {
                bRoom.push_back(w);
            }
        }
    }

    if (intersectedWalls.size()!=2){
        cout << "now we gotta deal with this case" << endl;
        return;
    }

    if (intersectedWalls[0]->P1.x>intersectedWalls[1]->P1.x){
        Wall* first = intersectedWalls[1];
        Wall* second = intersectedWalls[0];
        intersectedWalls[0]=first;
        intersectedWalls[1]=second;
    }
    else{}
    Vec2d mP1{intersectedWalls[0]->P1.x, pos.y};
    Vec2d mP2{intersectedWalls[1]->P1.x, pos.y};

    vector <Wall*> leftsplitwalls = splitWall(intersectedWalls[0],pos);
    vector <Wall*> rightsplitwalls = splitWall(intersectedWalls[1],pos);

    Wall * tl = leftsplitwalls[0];
    Wall* bl = leftsplitwalls[1];
    Wall* tr = rightsplitwalls[0];
    Wall* br = rightsplitwalls[1];
    Wall* middleWall = wallFactory(mP1, mP2);

    bool doestouch=false;
    for (int i=0; i<bRoom.size();i++){
        if (wallsTouch(*bRoom[i],*bl)){
            doestouch=true;
        }
    }

    if (!doestouch){
        swap(bRoom,tRoom);
    }

    for (int i=0; i<tRoom.size();i++){
        if (wallsTouch(*tRoom[i],*tr)==true){
            tRoom.insert(tRoom.begin()+i+1,tr);
            tRoom.insert(tRoom.begin()+i+2,middleWall);
            tRoom.insert(tRoom.begin()+i+3,tl);
            cout << "added walls to room1" << endl;
            break;
        }
    }

    for (int i=0; i<bRoom.size();i++){
        if (wallsTouch(*bRoom[i],*bl)==true){
            bRoom.insert(bRoom.begin()+i+1,bl);
            bRoom.insert(bRoom.begin()+i+2,middleWall);
            bRoom.insert(bRoom.begin()+i+3,br);
            cout << "added rooms to room2" << endl;
            break;
        }
    }

    auto i = find_if(rooms.begin(), rooms.end(), [r](Room& room) { return r == &room; });
    rooms.erase(i);
    cout << "This is the size of the troom: " << tRoom.size() << endl;
    cout << "This is the size of the broom: " << bRoom.size() << endl;
    roomFactory("top", tRoom);
    roomFactory("bottom", bRoom);
}

void House::saveTo (std::ostream& strm, House* a) const{
    strm << "You have 1 house with " << a->rooms.size() << " rooms in it" << endl;
    for (int i=0;i<a->rooms.size();i++){
        strm << "For room " << i+1 << ": " << endl;
        rooms[i].saveToR(strm);
    }
}

void skip (std::istream &strm, int skips){
    string dummy;
    for (int i=0;i<skips;i++){
        strm >> dummy;
    }
}

void House::loadFrom(std::istream &strm){
    walls.clear();
    rooms.clear();
    int numberOfRooms;

    skip(strm,5);

    strm >> numberOfRooms;

    skip(strm,5);

    int roomIndex;
    strm >> roomIndex;

    for (int j=0; j<numberOfRooms;j++){
        vector <Wall*> RoomWalls;

        skip(strm,3);

        int numberOfWalls;
        strm >>numberOfWalls;

        skip(strm,19);

        int wallIndex;
        strm >> wallIndex;

        for (int v=0; v<numberOfWalls;v++){
            skip(strm,1);
            strm.ignore(2);

            int p1x;
            strm >> p1x;

            strm.ignore(1);

            int p1y;
            strm >> p1y;

            strm.ignore(2);
            skip(strm,2);
            strm.ignore(2);

            int p2x;
            strm >> p2x;

            strm.ignore(1);

            int p2y;
            strm >> p2y;

            Vec2d P1{static_cast<double>(p1x),static_cast<double>(p1y)};
            Vec2d P2{static_cast<double>(p2x),static_cast<double>(p2y)};  //hmmmm

            Wall* RoomWall = wallFactory(P1,P2);
            RoomWalls.push_back(RoomWall);

            strm.ignore(1);
            skip(strm,1);
        } // end of looping over wall lines
        skip(strm,1);
        roomFactory("blah", RoomWalls);
    } // end of room looping
}

