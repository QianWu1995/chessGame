//
//  pawn.hpp
//  Chess
//
//  Created by Qian Wu on 2016-07-12.
//  Copyright © 2016 Qian Wu. All rights reserved.
//

#ifndef pawn_hpp
#define pawn_hpp

#include <stdio.h>
#include "chessUnit.h"
#include "Grid.h"


class pawn:public chessUnit{
public:
    
	bool firstTimeMove;
    bool isValidMove(int x,int y);
    void move(int x,int y);
    pawn(chessType type, int x, int y, bool dark,shared_ptr<Grid>  board);
    void refreshPossibleMoves();
    bool outOfRange(int x,int y);
	bool canBeCaptured();
};

#endif /* pawn_hpp */