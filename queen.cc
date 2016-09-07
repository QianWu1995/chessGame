//
//  queen.cpp
//  Chess
//
//  Created by Qian Wu on 2016-07-12.
//  Copyright © 2016 Qian Wu. All rights reserved.
//

#include "queen.h"
#include "memory"



queen::queen(chessType type,int x,int y, bool dark,shared_ptr<Grid> board): chessUnit(type,x,y,dark,board,nullptr){weight = 10;}

bool queen::canBeCaptured() {
	return false;
}

bool queen::isValidMove(int x, int y){
    for(int i=int(possiblemoves.size()) - possibleMovesCounter;i<possiblemoves.size();++i){
        if (possiblemoves[i]->sameCoord(x,y)) {
            return true;
        }
    } return false;
}
void queen::move(int x,int y){
    if(isValidMove(x, y)){
        posy = y;
        posx = x;
    }
}

bool queen::outOfRange(int x,int y){
    if(x < 0 || y< 0 || y > 7 || x >7){
        return true;
    }
    return false;
}

void queen::refreshPossibleMoves(){
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
    //go striaght rightwards.
    for(int i = posx+1; i < 8; ++i){
        if(outOfRange(i, posy)){
            break;
        }
        if(theGrid->theGrid[posy][i].occupiedBy != nullptr && theGrid->theGrid[posy][i].occupiedBy->dark == dark){
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
        if(theGrid->theGrid[posy][i].occupiedBy != nullptr && theGrid->theGrid[posy][i].occupiedBy->dark == dark){
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
        }
        //for friends units
        if(theGrid->theGrid[i][posx].occupiedBy != nullptr && theGrid->theGrid[i][posx].occupiedBy->dark == dark){
            possiblemoves.emplace_back(shared_ptr<Move>(new Move(posx,posy,posx,posy,"*",temp)));
            ++possibleMovesCounter;
            break;
        }
        //for enemy
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
        if(theGrid->theGrid[i][posx].occupiedBy != nullptr && theGrid->theGrid[i][posx].occupiedBy->dark == dark){
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
    
}