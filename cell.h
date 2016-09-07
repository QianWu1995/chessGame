//
//  cell.hpp
//  Chess
//
//  Created by Qian Wu on 2016-07-14.
//  Copyright © 2016 Qian Wu. All rights reserved.
//

#ifndef cell_hpp
#define cell_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
//#include "textdisplay.h"
//#include "observer.h"
#include "chessUnit.h"
class Cell{
    int x, y;
    
    // Add other private members if necessary
    //friend class move;
public:
    bool dark;
    char name;
	Cell();
    std::shared_ptr<chessUnit> occupiedBy;
    Cell(int x, int y, std::shared_ptr<chessUnit> chess);
    int getRow() const; // Returns the value of r.
    int getCol() const; // Returns the value of c.
    void attachTochessUnit(std::shared_ptr<chessUnit> chess);
    std::shared_ptr<chessUnit> getOccupiedBy();
    };

#endif /* cell_hpp */
