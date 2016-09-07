//
//  king.cpp
//  Chess
//
//  Created by Qian Wu on 2016-07-12.
//  Copyright © 2016 Qian Wu. All rights reserved.
//

#include "king.h"
#include <memory>
#include "humanPlayer.h"

king::king(chessType type,int x,int y,shared_ptr<Player> enemy, bool dark,shared_ptr<Grid> board): chessUnit(type,x,y,dark,board,enemy){weight = 20;}



bool king::isValidMove(int x, int y){
    for(int i=int(possiblemoves.size()) - possibleMovesCounter;i<possiblemoves.size();++i){
        if (possiblemoves[i]->sameCoord(x,y)) {
            return true;
        }
    } return false;
}



void king::move(int x,int y){
    posx = x;
    posy = y;
    //theGrid[x][y]->chess = &this;
}

bool king::canBeCaptured() {
    if(dark){
        for (int i =0; i < theGrid->whiteChessUnits.size();++i) {
            for (int j= int(theGrid->whiteChessUnits[i]->possiblemoves.size()-theGrid->whiteChessUnits[i]->possibleMovesCounter);j < theGrid->whiteChessUnits[i]->possiblemoves.size();++j) {
                if (theGrid->whiteChessUnits[i]->possiblemoves.size() != 0 && theGrid->whiteChessUnits[i]->possiblemoves[j]->sameCoord(posx,posy)) {
                    return true;
                }
            }
        }
    }else{
        for (int i =0; i < theGrid->blackChessUnits.size();++i) {
            for (int j= int(theGrid->blackChessUnits[i]->possiblemoves.size()-theGrid->blackChessUnits[i]->possibleMovesCounter);j < theGrid->blackChessUnits[i]->possiblemoves.size();++j) {
                if (theGrid->blackChessUnits[i]->possiblemoves.size() != 0 && theGrid->blackChessUnits[i]->possiblemoves[j]->sameCoord(posx,posy)) {
                    return true;
                }
            }
        }
    }
    return false;
}


bool king::outOfRange(int x,int y){
    if(x < 0 || y< 0 || y > 7 || x >7){
        return true;
    }
    return false;
}



void king::refreshPossibleMoves(){
    inRangeMoves();
    //reverse();
    //validMoves();
    
}

void king::reverse(){
    for (int i = 0; i<possiblemoves.size(); ++i){
        shared_ptr <Move> m1(possiblemoves[i]->reverse());
        reverseOfKing.emplace_back(m1);
    }
}

bool king::canKingMove(int x, int y) {
    if (outOfRange(x, y)) {
        return false;
    } else if(theGrid->theGrid[y][x].occupiedBy != nullptr && theGrid->theGrid[y][x].occupiedBy->dark == dark) {
        return false;
    } else {
        return true;
    }
}

void king::inRangeMoves() {
    shared_ptr<chessUnit> temp11(this);
    possibleMovesCounter = 0;
    
    if(!((canKingMove(posx-1, posy)) || (canKingMove(posx-1, posy-1)) || (canKingMove(posx+1, posy)) || (canKingMove(posx, posy+1)) || (canKingMove(posx+1, posy+1)) || (canKingMove(posx-1, posy+1))|| (canKingMove(posx, posy-1)) || (canKingMove(posx+1, posy-1)))){
        possiblemoves.push_back(shared_ptr<Move>(new Move(posx, posy, posx, posy, "*",temp11)));
        possibleMovesCounter +=1;
    }
    
    //right down
    if( !outOfRange(posx+1, posy-1) && ((theGrid->theGrid[posy-1][posx+1].occupiedBy != nullptr && theGrid->theGrid[posy-1][posx+1].occupiedBy->dark != dark)|| (theGrid->theGrid[posy-1][posx+1].occupiedBy == nullptr))){
        possiblemoves.push_back(shared_ptr<Move>(new Move(posx, posy, posx + 1, posy - 1, "*",temp11)));
        possibleMovesCounter +=1;
    }//right
    
    if( !outOfRange(posx+1, posy) && ((theGrid->theGrid[posy][posx+1].occupiedBy != nullptr && theGrid->theGrid[posy][posx+1].occupiedBy->dark != dark)|| (theGrid->theGrid[posy][posx+1].occupiedBy == nullptr))){
        possiblemoves.push_back(shared_ptr<Move>(new Move(posx, posy, posx + 1, posy, "*",temp11)));
        possibleMovesCounter +=1;
    }//left
    
    if( !outOfRange(posx-1, posy) && ((theGrid->theGrid[posy][posx-1].occupiedBy != nullptr && theGrid->theGrid[posy][posx-1].occupiedBy->dark != dark)|| (theGrid->theGrid[posy][posx-1].occupiedBy == nullptr))){
        possiblemoves.push_back(shared_ptr<Move>(new Move(posx, posy, posx - 1, posy, "*",temp11)));
        possibleMovesCounter +=1;
    }//right up
    if( !outOfRange(posx+1, posy+1) && ((theGrid->theGrid[posy+1][posx+1].occupiedBy != nullptr && theGrid->theGrid[posy+1][posx+1].occupiedBy->dark != dark)|| (theGrid->theGrid[posy+1][posx+1].occupiedBy == nullptr))){
        possiblemoves.push_back(shared_ptr<Move>(new Move(posx, posy, posx + 1, posy + 1, "*",temp11)));
        possibleMovesCounter +=1;
    }//down
    if( !outOfRange(posx, posy-1) && ((theGrid->theGrid[posy-1][posx].occupiedBy != nullptr && theGrid->theGrid[posy-1][posx].occupiedBy->dark != dark)|| (theGrid->theGrid[posy-1][posx].occupiedBy == nullptr))){
        possiblemoves.push_back(shared_ptr<Move>(new Move(posx, posy, posx, posy-1, "*",temp11)));
        possibleMovesCounter +=1;
    }//keft up
    if( !outOfRange(posx-1, posy+1) && ((theGrid->theGrid[posy+1][posx-1].occupiedBy != nullptr && theGrid->theGrid[posy+1][posx-1].occupiedBy->dark != dark)|| (theGrid->theGrid[posy+1][posx-1].occupiedBy == nullptr))){
        possiblemoves.push_back(shared_ptr<Move>(new Move(posx, posy, posx -1, posy + 1, "*",temp11)));
        possibleMovesCounter +=1;
    }//left down
    if( !outOfRange(posx-1, posy-1) && ((theGrid->theGrid[posy-1][posx-1].occupiedBy != nullptr && theGrid->theGrid[posy-1][posx-1].occupiedBy->dark != dark)|| (theGrid->theGrid[posy-1][posx-1].occupiedBy == nullptr))){
        possiblemoves.push_back(shared_ptr<Move>(new Move(posx, posy, posx - 1, posy - 1, "*",temp11)));
        possibleMovesCounter +=1;
    }//up
    if( !outOfRange(posx, posy+1) && ((theGrid->theGrid[posy+1][posx].occupiedBy != nullptr && theGrid->theGrid[posy+1][posx].occupiedBy->dark != dark)|| (theGrid->theGrid[posy+1][posx].occupiedBy == nullptr))){
        possiblemoves.push_back(shared_ptr<Move>(new Move(posx, posy, posx, posy+1, "*",temp11)));
        possibleMovesCounter +=1;
    }
}

void king::validMoves() { //if moves will put King in check.
    int popped =0;
    for (int i = int(possiblemoves.size() -1); i > int(possiblemoves.size() - possibleMovesCounter) ; --i) {
        int x = possiblemoves[i]->toX;
        int y = possiblemoves[i]->toY;
        shared_ptr<chessUnit> temp (new king(chessType::king,x,y,possiblemoves[i]->obj->enemy,possiblemoves[i]->obj->dark,theGrid));
        temp->move(x, y);
        if (temp->canBeCaptured() && possiblemoves.size() > 0 ) {
            //temp->move(possiblemoves[i]->fromX, possiblemoves[i]->fromY);
            possiblemoves.erase(possiblemoves.end());
            popped++;
        } 
    }
    possibleMovesCounter -= popped;
}
