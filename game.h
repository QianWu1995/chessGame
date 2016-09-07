//
//  game.hpp
//  Chess
//
//  Created by Qian Wu on 2016-07-15.
//  Copyright © 2016 Qian Wu. All rights reserved.
//

#ifndef game_hpp
#define game_hpp
#include "Grid.h"
#include <stdio.h>
#include <vector>
class Player;
class Game{
public:
    shared_ptr<Grid> Board;
    shared_ptr<Player> blackPlayer;
    shared_ptr<Player> whitePlayer;
    float blackScore;
    float whiteScore;
    bool whiteTurn;
        Game(); //default ctor
    ~Game();
    void startGame(shared_ptr<Grid> newBoard);
    void initGrid(shared_ptr<Grid> g);
    void initWhite();
    void initBlack();
    void whiteWin();
    void blackWin();
    void draw();
    void newRound();
    void endGame();
    void assignEnemy();
    //bool isOver();
    
};
#endif /* game_hpp */
