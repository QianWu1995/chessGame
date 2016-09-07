//
//  move.hpp
//  Chess
//
//  Created by Qian Wu on 2016-07-15.
//  Copyright © 2016 Qian Wu. All rights reserved.
//

#ifndef move_hpp
#define move_hpp

#include <stdio.h>
//#include "Grid.h"
#include <string>
#include <memory>
using namespace std;

class chessUnit;

class Move{
public:
    int fromX;
    int fromY;
    int toX;
    int toY;
    shared_ptr<chessUnit> obj;
    Move(int fromX, int fromY, int toX, int toY, string promoteTo, shared_ptr<chessUnit> obj);
    string promoteTo;
    ~Move();
    shared_ptr <Move> reverse();
    bool sameCoord(int x, int y);
};

#endif /* move_hpp */
