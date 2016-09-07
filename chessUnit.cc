
//
//  chessUnit.cpp
//  Chess
//
//  Created by Qian Wu on 2016-07-12.
//  Copyright © 2016 Qian Wu. All rights reserved.
//

#include "chessUnit.h"


chessType chessUnit::getType(){
    return type;
}

int chessUnit::getPosx(){
    return posx;
}
int chessUnit::getPosy(){
    return posy;
}
void chessUnit::captured(){
    avail = false;    
}
bool chessUnit::sameCoord(int x, int y) {
    return x == posx && y == posy;
}

bool chessUnit::outOfRange(int x,int y){
    if(x < 0 || y< 0 || y > 7 || x >7){
        return true;
    }
    return false;
}

chessUnit::chessUnit(chessType type,int posx,int posy,bool dark,shared_ptr<Grid> connectTo,shared_ptr<Player> enemy): type{type}, posx{posx}, posy{posy}, dark{dark},enemy{enemy}, avail{true},possibleMovesCounter{0}{
    if(dark && (type == chessType::pawn)) {
        name = 'p';
    }
    if(dark && (type == chessType::rook)) {
        name = 'r';
    }
    if(dark && (type == chessType::knight)) {
        name = 'n';
    }
    if(dark && (type == chessType::bishop)) {
        name = 'b';
    }
    if(dark && (type == chessType::queen)) {
        name = 'q';
    }
    if(dark && (type == chessType::king)) {
        name = 'k';
    }
    if(!dark && (type == chessType::pawn)) {
        name = 'P';
    }
    if(!dark && (type == chessType::rook)) {
        name = 'R';
    }
    if(!dark && (type == chessType::knight)) {
        name = 'N';
    }
    if(!dark && (type == chessType::bishop)) {
        name = 'B';
    }
    if(!dark && (type == chessType::queen)) {
        name = 'Q';
    }
    if(!dark && (type == chessType::king)) {
        name = 'K';
    }
    theGrid = connectTo;
}
chessUnit::~chessUnit(){
	//theGrid = nullptr;
	//possiblemoves.clear();
}
bool chessUnit::canBeCaptured() {
	return false;
}
bool chessUnit::isValidMove(int x, int y) {
	return false;
}
void chessUnit::refreshPossibleMoves() {
	
}
void chessUnit::move(int x, int y) {
	x = x;
	y = y;
}
