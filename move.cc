//
//  move.cpp
//  Chess
//
//  Created by Qian Wu on 2016-07-15.
//  Copyright © 2016 Qian Wu. All rights reserved.
//

#include "move.h"


Move::Move(int fromX, int fromY, int toX, int toY, string promoteTo, shared_ptr<chessUnit> obj): fromX{fromX}, fromY{fromY}, toX{toX}, toY{toY}, promoteTo{promoteTo},obj{obj} {
}



bool Move::sameCoord(int x, int y) {
    return x == toX && y == toY;
}

shared_ptr <Move> Move::reverse(){
    shared_ptr <Move> temp (new Move(toX,toY,fromX,fromY,"*",obj));
    return temp;
}

Move::~Move(){

}