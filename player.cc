//
//  player.cpp
//  Chess
//
//  Created by Qian Wu on 2016-07-15.
//  Copyright © 2016 Qian Wu. All rights reserved.
//

#include "player.h"
#include <memory>
Player::Player(bool black, bool human, int level,shared_ptr<Grid> board)
: black{ black }
, human{ human }
, board{board}
, score{ 0 }
, level{ level }
, isChecked{ false }
{
    
}

bool Player::isCheckedFunc()
{ //King can be captured
    if(black) {
        isChecked = board->blackChessUnits[4]->canBeCaptured();
        return isChecked;
    } else {
        isChecked = board->whiteChessUnits[12]->canBeCaptured();
        return isChecked;
    }
}


Player::~Player()
{
}
