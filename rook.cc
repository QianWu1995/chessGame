//
//  rock.cpp
//  Chess
//
//  Created by Qian Wu on 2016-07-12.
//  Copyright © 2016 Qian Wu. All rights reserved.
//

#include "rook.h"
#include <memory>


bool rook::isValidMove(int x, int y){
    for(int i=int(possiblemoves.size()) - possibleMovesCounter;i<possiblemoves.size();++i){
        if (possiblemoves[i]->sameCoord(x,y)) {
            return true;
        }
    } return false;
}


void rook::move(int x,int y){
    if(isValidMove(x, y)){
        this->posy = y;
        this->posx = x;
    }

}

bool rook::outOfRange(int x,int y){
    if(x < 0 || y< 0 || y > 7 || x >7){
        return true;
    }
    return false;
}

bool rook::canBeCaptured() {
	return false;
}
rook::rook(chessType type,int x,int y, bool dark, shared_ptr<Grid> board): chessUnit(type,x,y,dark,board,nullptr){weight = 3;}

void rook::refreshPossibleMoves(){
    possibleMovesCounter =0;
    shared_ptr<chessUnit> temp (this);
    
    //go striaght rightwards.
    for(int i = posx+1; i < 8; ++i){
        if(outOfRange(i, posy)){
            break;
        }
        if(theGrid->theGrid[posy][i].occupiedBy&&theGrid->theGrid[posy][i].occupiedBy->dark == temp->dark && theGrid->theGrid[posy][i].occupiedBy){
            possiblemoves.emplace_back(shared_ptr<Move>(new Move(posx,posy,posx,posy,"*",temp)));
            ++possibleMovesCounter;
            break;
        }
        if(theGrid->theGrid[posy][i].occupiedBy != nullptr && !outOfRange(i, posy) && theGrid->theGrid[posy][i].occupiedBy->dark != temp->dark){
            possiblemoves.emplace_back((new Move(posx,posy,i,posy,"*",temp)));
            ++possibleMovesCounter;
            break;
        }
        else if(theGrid->theGrid[posy][i].occupiedBy == nullptr && !outOfRange(i, posy)){
            possiblemoves.emplace_back(shared_ptr<Move>(new Move(posx,posy,i,posy,"*",temp)));
            ++possibleMovesCounter;
            
        }
    }
    
    //go straight leftwards.
    for(int i = posx-1; i >= 0; --i){
        if(outOfRange(i, posy)){
            break;
        }
        if(theGrid->theGrid[posy][i].occupiedBy&&theGrid->theGrid[posy][i].occupiedBy->dark == temp->dark && theGrid->theGrid[posy][i].occupiedBy){
            possiblemoves.emplace_back(shared_ptr<Move>(new Move(posx,posy,posx,posy,"*",temp)));
            ++possibleMovesCounter;
            break;
        }
        if(theGrid->theGrid[posy][i].occupiedBy != nullptr && !outOfRange(i, posy) && theGrid->theGrid[posy][i].occupiedBy->dark != temp->dark){
            possiblemoves.emplace_back(shared_ptr<Move>(new Move(posx,posy,i,posy,"*",temp)));
            ++possibleMovesCounter;
            break;
        }
        else if(theGrid->theGrid[posy][i].occupiedBy == nullptr && !outOfRange(i, posy) ){
            possiblemoves.emplace_back(shared_ptr<Move>(new Move(posx,posy,i,posy,"*",temp)));
            ++possibleMovesCounter;
            
        }
    }
    
    //go straight upwards.
    for(int i = posy+1; i < 8; ++i){
        if(outOfRange(posx, i)){
            break;
        }if(theGrid->theGrid[i][posx].occupiedBy&& theGrid->theGrid[i][posx].occupiedBy->dark == temp->dark && theGrid->theGrid[i][posx].occupiedBy){
            possiblemoves.emplace_back(shared_ptr<Move>(new Move(posx,posy,posx,posy,"*",temp)));
            ++possibleMovesCounter;
            break;
        }
        if(theGrid->theGrid[i][posx].occupiedBy != nullptr && !outOfRange(posx,i) && theGrid->theGrid[i][posx].occupiedBy->dark != temp->dark){
            possiblemoves.emplace_back(shared_ptr<Move>(new Move(posx,posy,posx,i,"*",temp)));
            ++possibleMovesCounter;
            break;
        }
        else if(theGrid->theGrid[i][posx].occupiedBy == nullptr && !outOfRange(posx,i)){
            possiblemoves.emplace_back(shared_ptr<Move>(new Move(posx,posy,posx,i,"*",temp)));
            ++possibleMovesCounter;
            
        }
    }
    
    //go straight downwards.
    for(int i = posy-1; i >= 0; --i){
        if(outOfRange(posx, i)){
            break;
        }
        if(theGrid->theGrid[i][posx].occupiedBy&&theGrid->theGrid[i][posx].occupiedBy->dark == temp->dark && theGrid->theGrid[i][posx].occupiedBy){
            possiblemoves.emplace_back(shared_ptr<Move>(new Move(posx,posy,posx,posy,"*",temp)));
            ++possibleMovesCounter;
            break;
        }
        if(theGrid->theGrid[i][posx].occupiedBy != nullptr && !outOfRange(posx,i) && theGrid->theGrid[i][posx].occupiedBy->dark != temp->dark){
            possiblemoves.emplace_back(shared_ptr<Move>(new Move(posx,posy,posx,i,"*",temp)));
            ++possibleMovesCounter;
            break;
        }
        else if(theGrid->theGrid[i][posx].occupiedBy == nullptr && !outOfRange(posx,i)){
            possiblemoves.emplace_back(shared_ptr<Move>(new Move(posx,posy,posx,i,"*",temp)));
            ++possibleMovesCounter;
            
        }
    }}