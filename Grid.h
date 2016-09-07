//
//  Grid.hpp
//  Chess
//
//  Created by Qian Wu on 2016-07-11.
//  Copyright © 2016 Qian Wu. All rights reserved.
//

#ifndef Grid_hpp
#define Grid_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "cell.h"
#include "textDisplay.h"
//#include "graphicDisplay.hpp"

#include <memory>
//class TextDisplay;
class Player;
using namespace std;
class Move;
class Grid{
    friend class chessUnit;
    int gridSize = 8;    // Size of the grid.
public:
    int whiteking;
    int blackking;
    vector<shared_ptr<chessUnit>> whiteChessUnits;
    vector<shared_ptr<chessUnit>> blackChessUnits;
    shared_ptr<display> td;
    //shared_ptr<display> gd;
    shared_ptr<Player> white;
    shared_ptr<Player> black;
    //GUI* gd;
    vector<shared_ptr <Move> > moves;
	vector<shared_ptr <Move> > reverseMoves;
    vector< vector< Cell > > theGrid;  // The actual grid.
    Grid();
    ~Grid();
    void move(shared_ptr <Move> m);
    //friend std::ostream &operator<<(std::ostream &out, const Grid &g);
    bool checkMate();
    bool staleMate();
	bool inCheck();
    void attachChessToCell();
	void promote(shared_ptr<Move> m);
    void refresh();
    bool isGridValid();
    void attachWithChar();
    void defaultChessUnits();
};

#endif /* Grid_hpp */
