//
//  display.hpp
//  Chess
//
//  Created by Qian Wu on 2016-07-24.
//  Copyright © 2016 Qian Wu. All rights reserved.
//

#ifndef display_hpp
#define display_hpp

#include<memory>
#include <stdio.h>
class Grid;
class display{
        const int gridSize = 8;
public:
    std::shared_ptr<Grid> theBoard;
    display(std::shared_ptr<Grid> theBoard);
    void notify();
    virtual void draw()=0;
    virtual void setupDraw()=0;
    ~display();
    


};

#endif /* display_hpp */
