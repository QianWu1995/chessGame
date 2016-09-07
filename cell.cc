//
//  cell.cpp
//  Chess
//
//  Created by Qian Wu on 2016-07-14.
//  Copyright © 2016 Qian Wu. All rights reserved.
//
#include "cell.h"

Cell::Cell() {
}

Cell::Cell(int x, int y, shared_ptr<chessUnit> chess): x{x}, y{y}, name{'*'}{
    if ((x+y) % 2 ==0 ) {
        dark = true;
    } else {
        dark = false;
    }
    attachTochessUnit(chess);
}

shared_ptr<chessUnit> Cell::getOccupiedBy() { return occupiedBy; }
int Cell::getRow() const { return x; }
int Cell::getCol() const { return y; }

void Cell::attachTochessUnit(shared_ptr<chessUnit> chess){
    this->occupiedBy = chess;
}

