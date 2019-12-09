#include "maze.h"
#include "pacman.h"
#include "iostream"

Maze::Maze():  //in practice, doubly nested loop, i and j one looping over columns and the other looping over rows. Draw a rectangle wherever I find a #, a dot for ., etc
    //there are 25 dots in a row                          mid
    grid{{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
{'#','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{'#','.','#','#','#','#','.','#','#','#','#','#','.','#','.','#','#','#','#','#','.','#','#','#','#','.','#'},
{'#','O','#','#','#','#','.','#','#','#','#','#','.','#','.','#','#','#','#','#','.','#','#','#','#','O','#'},
{'#','.','#','#','#','#','.','#','#','#','#','#','.','#','.','#','#','#','#','#','.','#','#','#','#','.','#'},
{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{'#','.','#','#','#','#','.','#','.','#','#','#','#','#','#','#','#','#','.','#','.','#','#','#','#','.','#'},
{'#','.','#','#','#','#','.','#','.','#','#','#','#','#','#','#','#','#','.','#','.','#','#','#','#','.','#'},
{'#','.','.','.','.','.','.','#','.','.','.','.','.','#','.','.','.','.','.','#','.','.','.','.','.','.','#'},
{'#','#','#','#','#','#','.','#','#','#','#','#','B','#','B','#','#','#','#','#','.','#','#','#','#','#','#'},
{'#','B','B','B','B','#','.','#','#','#','#','#','B','#','B','#','#','#','#','#','.','#','B','B','B','B','#'},
{'#','B','B','B','B','#','.','#','B','B','B','B','B','B','B','B','B','B','B','#','.','#','B','B','B','B','#'},
{'#','B','B','B','B','#','.','#','B','#','#','#','#','H','#','#','#','#','B','#','.','#','B','B','B','B','#'},
{'#','#','#','#','#','#','.','#','B','#','B','B','B','B','B','B','B','#','B','#','.','#','#','#','#','#','#'},
{'L','B','B','B','B','B','.','B','B','H','B','B','B','B','B','B','B','H','B','B','.','B','B','B','B','B','T'},
{'#','#','#','#','#','#','.','#','B','#','B','B','B','B','B','B','B','#','B','#','.','#','#','#','#','#','#'},
{'#','B','B','B','B','#','.','#','B','#','B','B','B','B','B','B','B','#','B','#','.','#','B','B','B','B','#'},
{'#','B','B','B','B','#','.','#','B','#','#','#','#','H','#','#','#','#','B','#','.','#','B','B','B','B','#'},
{'#','B','B','B','B','#','.','#','B','B','B','B','B','C','B','B','B','B','B','#','.','#','B','B','B','B','#'},
{'#','#','#','#','#','#','.','#','B','#','#','#','#','#','#','#','#','#','B','#','.','#','#','#','#','#','#'},
{'#','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{'#','.','#','#','#','#','.','#','#','#','#','#','.','#','.','#','#','#','#','#','.','#','#','#','#','.','#'},
{'#','.','#','#','#','#','.','#','#','#','#','#','.','#','.','#','#','#','#','#','.','#','#','#','#','.','#'},
{'#','O','.','.','.','#','.','.','.','.','.','.','.','S','.','.','.','.','.','.','.','#','.','.','.','O','#'},
{'#','#','#','#','.','#','.','#','.','#','#','#','#','#','#','#','#','#','.','#','.','#','.','#','#','#','#'},
{'#','.','.','.','.','.','.','#','.','.','.','.','.','#','.','.','.','.','.','#','.','.','.','.','.','.','#'},
{'#','.','#','#','#','#','#','#','#','#','#','#','.','#','.','#','#','#','#','#','#','#','#','#','#','.','#'},
{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
         } //27 blocks wide //29 blocks tall
{

}

void Maze::draw(Graphics &g, Color c){ //i is the row, j is the column
    for(int i=0;i<grid.size();i++){
        for (int j=0;j<grid[i].size();j++){
            if (grid[grid.size()-1-i][j]=='#'){
                double wide = g.width()/27; //just put before the loop
                double tall = g.height()/29;
                g.rect(j*wide,i*tall,wide,tall,BLUE);
            }
            if (grid[grid.size()-1-i][j]=='.'){ //might have to make these objects so pacman can pick them up - or just have pacman accessing this loop and looking for the chars
                double wide = g.width()/27;
                double tall = g.height()/29;
//                if (PelletPresent(i,j)==true){ //!!!!!!

//                }
                g.ellipseC({j*wide+15,i*tall+10},wide/3,tall/3,c);
            }
            if (grid[grid.size()-1-i][j]=='O'){ //might have to make these objects so pacman can pick them up - or just have pacman accessing this loop and looking for the chars
                double wide = g.width()/27;
                double tall = g.height()/29;
                g.ellipseC({j*wide+15,i*tall+10},wide/2,tall/2,WHITE,WHITE);
            }
//            if (grid[grid.size()-1-i][j]=='C'){ //cherry, need a respawn/despawn timer
//                double wide = g.width()/27;
//                double tall = g.height()/29;
//                g.ellipseC({j*wide+15,i*tall+10},wide/1.5,tall/1.5,RED,RED);
//            }
        }
    }
}
//pos x times x width and pos y times y width plus offset -- his position will be in grid coordinates then converted when drawn

bool Maze::canMove(int row, int column){ // i dont think i need row and column params
    bool canMove = false; //could use multiple bools for each pickup - make this return a vector
    if (grid[grid.size()-1-row][column]=='#'/*||grid[grid.size()-1-row][column]=='H'*/){
        canMove=false;
    }
    else{
        canMove=true;
    }
    return canMove;
}

bool Maze::doorInFront(int row, int column){
//    int ro = row +1;
//    int co = column+1;
//    bool doorPresent = false;
//    if (grid[grid.size()-1-ro][co]=='H'){
//        doorPresent=true;
//    }
//    else{
//        doorPresent=false;
//    }
//    return doorPresent;
}

void Maze::lockDoor(int row, int column){
//    int ro = row +1;
//    int co = column+1;
//    if (doorInFront(ro,co)==true){
//        cout << "locking door" << endl;
//       grid[grid.size()-1-ro][co]='#';
//    }
}

bool Maze::PelletPresent(int row, int column){ // i dont think i need row and column params
    bool pellet = false; //could use multiple bools for each pickup - make this return a vector
    if (grid[grid.size()-1-row][column]=='.'){ //might have to change this up with the -1 like in the draw
        pellet=true;
    }
    else{
        pellet=false;
    }
    return pellet; // make an eatingpellent func to use in draw, if pelletpresent is true, make it invisible
}

bool Maze::BigPelletPresent(int row, int column){ // i dont think i need row and column params
    bool pellet = false; //could use multiple bools for each pickup - make this return a vector
    if (grid[grid.size()-1-row][column]=='O'){ //might have to change this up with the -1 like in the draw
        pellet=true;
    }
    else{
        pellet=false;
    }
    return pellet; // make an eatingpellent func to use in draw, if pelletpresent is true, make it invisible
}

void Maze::clearPellet(int row, int column){
    if (PelletPresent(row,column)==true){
       grid[grid.size()-1-row][column]='V';
    }
}

void Maze::clearBigPellet(int row, int column){
    if (BigPelletPresent(row,column)==true){
       grid[grid.size()-1-row][column]='V';
    }
}

bool Maze::RightTeleporterPresent(int row, int column){ // i dont think i need row and column params
    bool porter = false; //could use multiple bools for each pickup - make this return a vector
    if (grid[grid.size()-1-row][column]=='T'){ //might have to change this up with the -1 like in the draw
        porter=true;
    }
    else{
        porter=false;
    }
    return porter; // make an eatingpellent func to use in draw, if pelletpresent is true, make it invisible
}

bool Maze::LeftTeleporterPresent(int row, int column){ // i dont think i need row and column params
    bool porter = false; //could use multiple bools for each pickup - make this return a vector
    if (grid[grid.size()-1-row][column]=='L'){ //might have to change this up with the -1 like in the draw
        porter=true;
    }
    else{
        porter=false;
    }
    return porter; // make an eatingpellent func to use in draw, if pelletpresent is true, make it invisible
}
