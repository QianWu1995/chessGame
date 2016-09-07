//
//  knight.cpp
//  Chess
//
//  Created by Qian Wu on 2016-07-12.
//  Copyright © 2016 Qian Wu. All rights reserved.
//

#include "knight.h"
#include <memory>

bool knight::isValidMove(int x, int y){
    //cout<<"checking is valid or not"<<endl;
    for(int i=int(possiblemoves.size()) - possibleMovesCounter;i<possiblemoves.size();++i){
        if (possiblemoves[i]->sameCoord(x,y)) {
            return true;
        }
    } return false;
}

void knight::move(int x,int y){
    if(isValidMove(x, y)){
        this->posy = y;
        this->posx = x;
    }
    
}
bool knight::canBeCaptured() {
	return false;
}

knight::knight(chessType type,int x,int y, bool dark,shared_ptr<Grid> board): chessUnit(type,x,y,dark,board,nullptr){weight = 3;}

bool knight::outOfRange(int x,int y){
    if(x < 0 || y< 0 || y > 7 || x >7){
        return true;
    }
    return false;
}

void knight::refreshPossibleMoves(){
    possibleMovesCounter=0;
    shared_ptr<chessUnit> temp(this);
    if(!outOfRange(posx+1, posy+2)){
    possiblemoves.emplace_back((new Move(posx,posy,posx+1,posy+2,"*",temp)));
        ++possibleMovesCounter;
    }
    if(!outOfRange(posx-1, posy-2)){
    possiblemoves.emplace_back(shared_ptr<Move>(new Move(posx,posy,posx-1,posy-2,"*",temp)));
        ++possibleMovesCounter;
    }
    if(!outOfRange(posx+1, posy-2)){
    possiblemoves.emplace_back(shared_ptr<Move>(new Move(posx,posy,posx+1,posy-2,"*",temp)));
        ++possibleMovesCounter;
    }
    if(!outOfRange(posx-1, posy+2)){
    possiblemoves.emplace_back(shared_ptr<Move>(new Move(posx,posy,posx-1,posy+2,"*",temp)));
        ++possibleMovesCounter;
    }
    if(!outOfRange(posx+2, posy+1)){
    possiblemoves.emplace_back(shared_ptr<Move>(new Move(posx,posy,posx+2,posy+1,"*",temp)));
        ++possibleMovesCounter;
    }
    if(!outOfRange(posx-2, posy+1)){
    possiblemoves.emplace_back(shared_ptr<Move>(new Move(posx,posy,posx-2,posy+1,"*",temp)));
        ++possibleMovesCounter;
    }
    if(!outOfRange(posx+2, posy-1)){
    possiblemoves.emplace_back(shared_ptr<Move>(new Move(posx,posy,posx+2,posy-1,"*",temp)));
        ++possibleMovesCounter;
    }
    if(!outOfRange(posx-2, posy-1)){
     possiblemoves.emplace_back(shared_ptr<Move>(new Move(posx,posy,posx-2,posy-1,"*",temp)));
        ++possibleMovesCounter;
    }
}