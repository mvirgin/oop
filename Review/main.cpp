#include <iostream>
#include <vector>

#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wnarrowing"

using namespace std;

class Room{                        ///////////////Room class start///////////////////
private:
    double width;
    double length;
    //int sqrftR;
public:
    Room(double width, double length) : width{width}, length{length} {}
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
    void addRoom(double width, double length);
    void printDescription();
    //House();
};

//House::House(){
//}                                  /////////////////House class end/////////////////

//double Room::reportareaR(double width, double length){
//    return width*length;
//}

double House::reportareaH(){
    for (int i=0; i<rooms.size(); i++){

    }
}

int main()
{
    Room a(200,300);
    cout << a.reportareaR() << endl;
    return 0;
}
