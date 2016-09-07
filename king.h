//
//  king.hpp
//  Chess
//
//  Created by Qian Wu on 2016-07-12.
//  Copyright © 2016 Qian Wu. All rights reserved.
//

#ifndef king_hpp
#define king_hpp

#include <stdio.h>

#include "chessUnit.h"
#include "Grid.h"
using namespace std;
class king:public chessUnit{
public:
    
    bool isCheck;
    bool isCheckMate;
    vector<shared_ptr <Move> > reverseOfKing;
    king(chessType type,int x,int y,shared_ptr<Player> enemy,bool dark, shared_ptr<Grid> board);
    bool isValidMove(int x,int y);
    void move(int x,int y);
    bool canBeCaptured();
    void refreshPossibleMoves();
    void reverse();
    bool outOfRange(int x,int y);
	void inRangeMoves();
    bool canKingMove(int x, int y);
	void validMoves();
    
};

#endif /* king_hpp */
