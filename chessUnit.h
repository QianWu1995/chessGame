//
//  chessUnit.hpp
//  Chess
//
//  Created by Qian Wu on 2016-07-12.
//  Copyright © 2016 Qian Wu. All rights reserved.
//

#ifndef chessUnit_hpp
#define chessUnit_hpp

#include <stdio.h>
#include <vector>
#include "move.h"
//#include "Grid.h"
using namespace std;
enum class chessType {pawn,knight,bishop,rook,king,queen};

class Game;
class Player;
class Grid;
class chessUnit{
    protected:
    chessType type;
    
    
    
    shared_ptr<Grid> theGrid;

public:
	vector<shared_ptr <Move>> possiblemoves;
    bool dark;
    shared_ptr<Player> enemy;
    char name;
    bool avail;
	int posx;
	int posy;
    int weight;
    int possibleMovesCounter;
    chessUnit(chessType,int ,int,bool,shared_ptr<Grid>,shared_ptr<Player>);
    chessType getType();
    int getPosx();
    int getPosy();
    virtual bool canBeCaptured();
    void captured();
    virtual bool isValidMove(int x,int y);
    virtual void refreshPossibleMoves();
	virtual void move(int x, int y);
    bool sameCoord(int x, int y);
	bool outOfRange(int x, int y);
    virtual ~chessUnit();

};

#endif /* chessUnit_hpp */
