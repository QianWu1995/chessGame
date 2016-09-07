//
//  textDisplay.hpp
//  Chess
//
//  Created by Qian Wu on 2016-07-14.
//  Copyright © 2016 Qian Wu. All rights reserved.
//

#ifndef textDisplay_hpp
#define textDisplay_hpp
//using namespace std;

#include <stdio.h>
#include <vector>
#include "display.h"
//#include "cell.h"
class Grid;
class chessUnit;
//class Cell;

class TextDisplay: public display{
public:
    TextDisplay(std::shared_ptr<Grid> theBoard);
    void draw() ;
    void setupDraw();
    ~TextDisplay();
};
#endif /* textDisplay_hpp */
