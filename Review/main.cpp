#include <iostream>
#include <vector>

#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wnarrowing"

using namespace std;

class Room{                        ///////////////Room class start///////////////////
private:
    double widthR;
    double lengthR;
    //int sqrftR;
public:
    double reportareaR(int width, int length);
    Room(int width1, int length1);
};

Room::Room(int width1, int length1){
    widthR=width1;
    lengthR=length1;
}                                 /////////////////Room class end//////////////////

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

double Room::reportareaR(int width, int length){
    return width*length;
}

double House::reportareaH(){
    for (int i=0; i<rooms.size(); i++){

    }
}
int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
