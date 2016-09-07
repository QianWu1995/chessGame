//
//  bishop.hpp
//  Chess
//
//  Created by Qian Wu on 2016-07-12.
//  Copyright © 2016 Qian Wu. All rights reserved.
//

#ifndef bishop_hpp
#define bishop_hpp

#include <stdio.h>
#include "chessUnit.h"

class bishop:public chessUnit{
public:
    
    bool isValidMove(int x,int y);
    void move(int x,int y);
    bishop(chessType type, int x, int y, bool dark, shared_ptr<Grid> board);
    void refreshPossibleMoves();
    bool outOfRange(int x,int y);
	bool canBeCaptured();
};

#endif /* bishop_hpp */


