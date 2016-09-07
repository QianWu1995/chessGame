//
//  bishop.cpp
//  Chess
//
//  Created by Qian Wu on 2016-07-12.
//  Copyright © 2016 Qian Wu. All rights reserved.
//

#include "bishop.h"
#include"Grid.h"
#include <memory>

bool bishop::isValidMove(int x, int y){
    //cout<<"checking is valid or not"<<endl;
    for(int i=int(possiblemoves.size()) - possibleMovesCounter;i<possiblemoves.size();++i){
        if (possiblemoves[i]->sameCoord(x,y)) {
            return true;
        }
    } return false;
}

bool bishop::canBeCaptured() {
	return false;
}
void bishop::move(int x, int y){
    if(isValidMove(x, y)){
        posy = y;
        posx = x;
    }

}

bool bishop::outOfRange(int x,int y){
    if(x < 0 || y< 0 || y > 7 || x >7){
        return true;
    }
    return false;
}

bishop::bishop(chessType type,int x,int y, bool dark,shared_ptr<Grid> board): chessUnit(type,x,y,dark,board,nullptr){
weight = 2;
}

void bishop::refreshPossibleMoves(){
    possibleMovesCounter=0;
    shared_ptr<chessUnit> temp(this);
    //right up
    //if(posx > 0 && posy > 0){
    for(int xi = posx+1,yi = posy+1;xi <= 7 && yi <= 7;++xi,++yi){
        if(outOfRange(xi, yi)){
            break;
        }
        if(theGrid->theGrid[yi][xi].occupiedBy != nullptr && theGrid->theGrid[yi][xi].occupiedBy->dark == dark){
            possiblemoves.emplace_back(shared_ptr<Move>(new Move(posx,posy,posx,posy,"*",temp)));
            ++possibleMovesCounter;
            break;
        }
        if(theGrid->theGrid[yi][xi].occupiedBy != nullptr){
            possiblemoves.emplace_back(shared_ptr<Move>(new Move(posx,posy,xi,yi,"*",temp)));
            ++possibleMovesCounter;
        break;
        }
        else if(theGrid->theGrid[yi][xi].occupiedBy == nullptr){
            possiblemoves.emplace_back(shared_ptr<Move>(new Move(posx,posy,xi,yi,"*",temp)));
            ++possibleMovesCounter;
        }
    }
    
    
    //left up
    
    for(int xi = posx-1,yi = posy+1;xi >= 0 && yi <= 7;--xi,++yi){
        if(outOfRange(xi, yi)){
            break;
        }
        if(theGrid->theGrid[yi][xi].occupiedBy != nullptr && theGrid->theGrid[yi][xi].occupiedBy->dark == dark){
            possiblemoves.emplace_back(shared_ptr<Move>(new Move(posx,posy,posx,posy,"*",temp)));
            ++possibleMovesCounter;
            break;
        }
        if(theGrid->theGrid[yi][xi].occupiedBy != nullptr){
            possiblemoves.emplace_back(shared_ptr<Move>(new Move(posx,posy,xi,yi,"*",temp)));
            ++possibleMovesCounter;
        break;
        }
        else if(theGrid->theGrid[yi][xi].occupiedBy == nullptr){
            possiblemoves.emplace_back(shared_ptr<Move>(new Move(posx,posy,xi,yi,"*",temp)));
            ++possibleMovesCounter;
            
        }
    }
    //left down
    for(int xi = posx-1,yi = posy-1;xi >= 0 && yi >= 0;--xi,--yi){
        if(outOfRange(xi, yi)){
            break;
        }
        if(theGrid->theGrid[yi][xi].occupiedBy != nullptr && theGrid->theGrid[yi][xi].occupiedBy->dark == dark){
            possiblemoves.emplace_back(shared_ptr<Move>(new Move(posx,posy,posx,posy,"*",temp)));
            ++possibleMovesCounter;
            break;
        }
        if(theGrid->theGrid[yi][xi].occupiedBy != nullptr){
            possiblemoves.emplace_back(shared_ptr<Move>(new Move(posx,posy,xi,yi,"*",temp)));
            ++possibleMovesCounter;
        break;
        }
        else if(theGrid->theGrid[yi][xi].occupiedBy == nullptr){
            possiblemoves.emplace_back(shared_ptr<Move>(new Move(posx,posy,xi,yi,"*",temp)));
            ++possibleMovesCounter;
        }
    }
    //right down
    for(int xi = posx+1,yi = posy-1;xi <= 7 && yi >= 0;++xi,--yi){
        if(outOfRange(xi, yi)){
            break;
        }
        if(theGrid->theGrid[yi][xi].occupiedBy != nullptr && theGrid->theGrid[yi][xi].occupiedBy->dark == dark){
            possiblemoves.emplace_back(shared_ptr<Move>(new Move(posx,posy,posx,posy,"*",temp)));
            ++possibleMovesCounter;
            break;
        }
        if(theGrid->theGrid[yi][xi].occupiedBy != nullptr){
            possiblemoves.emplace_back(shared_ptr<Move>(new Move(posx,posy,xi,yi,"*",temp)));
            ++possibleMovesCounter;
       break;
        }
        else if(theGrid->theGrid[yi][xi].occupiedBy == nullptr){
            possiblemoves.emplace_back(shared_ptr<Move>(new Move(posx,posy,xi,yi,"*",temp)));
            ++possibleMovesCounter;
            
        }
    }
    
}