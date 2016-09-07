//
//  player.hpp
//  Chess
//
//  Created by Qian Wu on 2016-07-15.
//  Copyright © 2016 Qian Wu. All rights reserved.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include <vector>
//#include "chessUnit.h"
#include "move.h"
#include "rook.h"
#include "knight.h"
#include "queen.h"
#include "king.h"
#include "bishop.h"
#include "pawn.h"
using namespace std;

class Player{
    
public:
    bool black;
    bool human;
    int score;
    int level;
    shared_ptr<Grid>  board;
    bool isChecked;
    shared_ptr<Player>  enemy;
    Player(bool black, bool human, int level, shared_ptr<Grid> board);
    virtual shared_ptr <Move> nextMove(string s) =0;
    bool isCheckedFunc();
    virtual ~Player();
};
#endif /* player_hpp */
