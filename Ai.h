//
//  Ai.hpp
//  Chess
//
//  Created by Qian Wu on 2016-07-25.
//  Copyright © 2016 Qian Wu. All rights reserved.
//

#ifndef Ai_hpp
#define Ai_hpp

#include <stdio.h>
#include <vector>
#include "player.h"
#include "move.h"

class Ai: public Player {
public:
    Ai(bool black, shared_ptr<Grid> board,int level);
    shared_ptr <Move> nextMove(string s);
};


#endif /* Ai_hpp */
