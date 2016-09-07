//
//  queen.hpp
//  Chess
//
//  Created by Qian Wu on 2016-07-12.
//  Copyright © 2016 Qian Wu. All rights reserved.
//

#ifndef queen_hpp
#define queen_hpp

#include <stdio.h>
#include "Grid.h"
#include "chessUnit.h"


class queen:public chessUnit{
public:
    
    queen(chessType type, int x, int y, bool dark, shared_ptr<Grid> board);
    bool isValidMove(int x,int y);
    void move(int x,int y);
    bool outOfRange(int x,int y);
    void refreshPossibleMoves();
	bool canBeCaptured();
};

#endif /* queen_hpp */
