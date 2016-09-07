//
//  knight.hpp
//  Chess
//
//  Created by Qian Wu on 2016-07-12.
//  Copyright © 2016 Qian Wu. All rights reserved.
//

#ifndef knight_hpp
#define knight_hpp

#include <stdio.h>

#include "chessUnit.h"

class knight: public chessUnit{
public:
    
    bool isValidMove(int x,int y);
    void move(int x,int y);
    knight(chessType type,int x,int y,bool dark,shared_ptr<Grid> board);
    void refreshPossibleMoves();
    bool outOfRange(int x,int y);
	bool canBeCaptured();
};

#endif /* knight_hpp */
