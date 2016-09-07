//
//  Ai.cpp
//  Chess
//
//  Created by Qian Wu on 2016-07-25.
//  Copyright © 2016 Qian Wu. All rights reserved.
//

#include "Ai.h"
#include <memory>

Ai::Ai(bool black, shared_ptr<Grid> board,int level) : Player(black, false, level, board) {
    
    
}

shared_ptr <Move> Ai::nextMove(string s) {
    //random number
    int randomChess;
    int randomMove;//which chess to select move
    // for black random
    if(level == 1){
    if (black) {
        randomChess = rand() % board->blackChessUnits.size();
        while(board->blackChessUnits[randomChess]->possibleMovesCounter == 0){
            randomChess = rand() % board->blackChessUnits.size();
        }
        
        randomMove  = rand() % board->blackChessUnits[randomChess]->possibleMovesCounter;
        while((board->blackChessUnits[randomChess]->possiblemoves[board->blackChessUnits[randomChess]->possiblemoves.size() - board->blackChessUnits[randomChess]->possibleMovesCounter + randomMove]->fromX == board->blackChessUnits[randomChess]->possiblemoves[board->blackChessUnits[randomChess]->possiblemoves.size() - board->blackChessUnits[randomChess]->possibleMovesCounter + randomMove]->toX ) && (board->blackChessUnits[randomChess]->possiblemoves[board->blackChessUnits[randomChess]->possiblemoves.size() - board->blackChessUnits[randomChess]->possibleMovesCounter + randomMove]->fromY == board->blackChessUnits[randomChess]->possiblemoves[board->blackChessUnits[randomChess]->possiblemoves.size() - board->blackChessUnits[randomChess]->possibleMovesCounter + randomMove]->toY )){
            
            randomChess = rand() % board->blackChessUnits.size();
            randomMove  = rand() % board->blackChessUnits[randomChess]->possibleMovesCounter;
        }
        
        shared_ptr<Move> randMoveptr (board->blackChessUnits[randomChess]->possiblemoves[board->blackChessUnits[randomChess]->possiblemoves.size() - board->blackChessUnits[randomChess]->possibleMovesCounter + randomMove]);
            return randMoveptr;
        }
    
    
    else{
        randomChess = rand() % board->whiteChessUnits.size();
        while(board->whiteChessUnits[randomChess]->possibleMovesCounter == 0){
            randomChess = rand() % board->whiteChessUnits.size();
        }
        
        randomMove  = rand() % board->whiteChessUnits[randomChess]->possibleMovesCounter;
        shared_ptr<Move> randMoveptr (board->whiteChessUnits[randomChess]->possiblemoves[board->whiteChessUnits[randomChess]->possiblemoves.size() - board->whiteChessUnits[randomChess]->possibleMovesCounter + randomMove]);
        return randMoveptr;
    
    }}
    
    
    if(level == 2){
        int counter = 5;
        if (black) {
            randomChess = (rand()+1) % board->blackChessUnits.size();
            while(board->blackChessUnits[randomChess]->possibleMovesCounter == 0){
                randomChess = rand() % board->blackChessUnits.size();
            }
            
            randomMove  = rand() % board->blackChessUnits[randomChess]->possibleMovesCounter;
            while((counter>=0 && board->theGrid[board->blackChessUnits[randomChess]->possiblemoves[board->blackChessUnits[randomChess]->possiblemoves.size() - board->blackChessUnits[randomChess]->possibleMovesCounter + randomMove]->toX][board->blackChessUnits[randomChess]->possiblemoves[board->blackChessUnits[randomChess]->possiblemoves.size() - board->blackChessUnits[randomChess]->possibleMovesCounter + randomMove]->toX].occupiedBy!=nullptr)||((board->blackChessUnits[randomChess]->possiblemoves[board->blackChessUnits[randomChess]->possiblemoves.size() - board->blackChessUnits[randomChess]->possibleMovesCounter + randomMove]->fromX == board->blackChessUnits[randomChess]->possiblemoves[board->blackChessUnits[randomChess]->possiblemoves.size() - board->blackChessUnits[randomChess]->possibleMovesCounter + randomMove]->toX ) && (board->blackChessUnits[randomChess]->possiblemoves[board->blackChessUnits[randomChess]->possiblemoves.size() - board->blackChessUnits[randomChess]->possibleMovesCounter + randomMove]->fromY == board->blackChessUnits[randomChess]->possiblemoves[board->blackChessUnits[randomChess]->possiblemoves.size() - board->blackChessUnits[randomChess]->possibleMovesCounter + randomMove]->toY ))){
                 --counter;
                if(counter == 0){
                    shared_ptr<Move> randMoveptr (board->blackChessUnits[randomChess]->possiblemoves[board->blackChessUnits[randomChess]->possiblemoves.size() - board->blackChessUnits[randomChess]->possibleMovesCounter + randomMove]);
                    return randMoveptr;
                }
                randomChess = (rand()+counter) % board->blackChessUnits.size();
                randomMove  = (rand()+counter) % board->blackChessUnits[randomChess]->possibleMovesCounter;
               
            }
            
            shared_ptr<Move> randMoveptr (board->blackChessUnits[randomChess]->possiblemoves[board->blackChessUnits[randomChess]->possiblemoves.size() - board->blackChessUnits[randomChess]->possibleMovesCounter + randomMove]);
            return randMoveptr;
        }
        
        
        else{
            randomChess = rand() % board->whiteChessUnits.size();
            while(board->whiteChessUnits[randomChess]->possibleMovesCounter == 0){
                randomChess = rand() % board->whiteChessUnits.size();
            }
            
            randomMove  = rand() % board->whiteChessUnits[randomChess]->possibleMovesCounter;
            shared_ptr<Move> randMoveptr (board->whiteChessUnits[randomChess]->possiblemoves[board->whiteChessUnits[randomChess]->possiblemoves.size() - board->whiteChessUnits[randomChess]->possibleMovesCounter + randomMove]);
            return randMoveptr;
            
        }}
    else{
        shared_ptr<Move> randMoveptr (board->whiteChessUnits[randomChess]->possiblemoves[board->whiteChessUnits[randomChess]->possiblemoves.size() - board->whiteChessUnits[randomChess]->possibleMovesCounter + randomMove]);
        return randMoveptr;
    }
}