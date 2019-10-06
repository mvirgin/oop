#include <iostream>
#include "graphics.h"
#include <functional>

using namespace std;
using namespace mssm;

#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wnarrowing"

using namespace std;

class Room{                        ///////////////Room class start///////////////////
private:
    double width;
    double length;
    string name;
    //int sqrftR;
public:
    Room(double width, double length, string name) : width{width}, length{length}, name{name} {}
    double reportareaR() {return length*width;}
};

/*Room::Room(double width, double length)
    : width{width}, length{length}
{
    // widthR=width1;
    // lengthR=length1;
}  */                               /////////////////Room class end//////////////////

class House{                        ////////////////House class start//////////////
private:
    vector <Room> rooms;
public:
    double reportareaH();
    void addRoom(double width, double length, string name);
    void printDescription(); // give the rooms a name and then list the names
    //House();
};

//House::House(){
//}                                  /////////////////House class end/////////////////

//double Room::reportareaR(double width, double length){
//    return width*length;
//}

void House::addRoom(double width, double length, string name){
    rooms.push_back(Room{width,length,name});
}

double House::reportareaH(){
    int totalarea = 0;
    for (int i=0; i<rooms.size(); i++){
        totalarea += rooms[i].reportareaR();
    }
    return totalarea;

    //OR:  double total = 0;
    //      for (Room r : rooms) {                 -- Room& r  -- edits original instead of copy -- const Room& r -- reference, but not allowed to modify room. Have to put const after the method declaration
    //          total+=r.reportareaR();             -- value types - dont worry about references - so litte data to copy - insignificant
    //      }                                       -- larger stuff w/ fields, work with references
    //      return total;

    //OR for (const auto& r: rooms)  -- auto goes where the type normally goes and automatically determines the type from context
    //auto can be used to make changing stuff later easier
    // auto i = rooms.begin(); -- iterator  -- kind of like a reference -- refers to first element of rooms vector
    //*i -- * is dereference operator -- gets at the thing that is referenced by something
    // double sf = (*i).sqFt();  -- this would give us the square feet of the first room in the rooms vector

}

//void graphicsMain(Graphics& g)
//{

//    while (g.draw()) {
//        g.clear();

//        g.line({200,100}, {50,20}, YELLOW);

//        for (const Event& e : g.events()) {
//            switch (e.evtType) {
//            case EvtType::MousePress:
//                break;
//            case EvtType::MouseRelease:
//                break;
//            case EvtType::KeyPress:
//                switch (e.arg) {
//                case 'C':
//                    // do something?
//                    break;
//                case 'D':
//                    // do something else?
//                    break;
//                }
//                break;
//            case EvtType::MouseMove:
//                break;
//            default:
//                break;
//            }
//        }
//    }
//}

int main()
{
    House a;
    a.addRoom(200,300,"Laundry");
    a.addRoom(500,2,"Office");
    cout << a.reportareaH() << endl;
  //  cout << a[1].reportareaR() << endl;

   // mssm::Graphics g("House Designer", 800, 600, graphicsMain);
    return 0;
}
