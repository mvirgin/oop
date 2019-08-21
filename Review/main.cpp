#include <iostream>
using namespace std;

class House{
//private:
   // int widthH;
   // int lengthH;
   // int sqrftH;

//public:
    int reportareaH();
    int reportsqrftofallrooms();
    House();
};

House::House(){

}

class Room{
//private:
    int widthR;
    int lengthR;
    int sqrftR;

//public:
    int reportareaR();
    Room(int width1, int length1);
};

Room::Room(int width1, int length1){
    widthR=width1;
    lengthR=length1;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
