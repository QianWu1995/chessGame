//
//  pawn.cpp
//  Chess
//
//  Created by Qian Wu on 2016-07-12.
//  Copyright © 2016 Qian Wu. All rights reserved.
//
#include <memory>
#include "pawn.h"
bool pawn::isValidMove(int x, int y){
   // cout<<"checking is valid or not"<<endl;
    for(int i=int(possiblemoves.size()) - possibleMovesCounter;i<possiblemoves.size();++i){
        if (possiblemoves[i]->sameCoord(x,y)) {
            return true;
        }
    } return false;
}

bool pawn::canBeCaptured() {
	return false;
}

void pawn::move(int x,int y){

        this->posy = y;
        this->posx = x;
    
}

bool pawn::outOfRange(int x,int y){
    if(x < 0 || y< 0 || y > 7 || x >7){
        return true;
    }
    return false;
}

pawn::pawn(chessType type,int x,int y, bool dark,shared_ptr<Grid> board): chessUnit(type,x,y,dark,board,nullptr){weight = 1;}

void pawn::refreshPossibleMoves(){
    //cout<<"posx is: "<<posx<<endl;
    //cout<<"posy is: "<<posy<<endl;
    //cout<<"am i dark? "<<dark<<endl;
    possibleMovesCounter = 0;
    shared_ptr<chessUnit> t(this);
    //whiite first time;
    if(posy==1 && !dark) {
        //cout<<"if111"<<endl;
        if (!outOfRange(posx, posy+2) &&  theGrid->theGrid[posy+1][posx].occupiedBy != nullptr && theGrid->theGrid[posy+2][posx].occupiedBy == nullptr) {
            possiblemoves.push_back(shared_ptr<Move>(new Move(posx,posy,posx,posy,"*",t)));
            possibleMovesCounter++;
        }
        if(!outOfRange(posx, posy+1) && theGrid->theGrid[posy+1][posx].occupiedBy != nullptr) {
            possiblemoves.push_back(shared_ptr<Move>(new Move(posx,posy,posx,posy+1,"*",t)));
            possibleMovesCounter++;
        }
        if (!outOfRange(posx, posy+2) && theGrid->theGrid[posy+1][posx].occupiedBy == nullptr && theGrid->theGrid[posy+2][posx].occupiedBy == nullptr) {
        possiblemoves.push_back(shared_ptr<Move>(new Move(posx,posy,posx,posy+2,"*",t)));
            possibleMovesCounter++;
        }
        if(!outOfRange(posx, posy+1) && theGrid->theGrid[posy+1][posx].occupiedBy == nullptr) {
        possiblemoves.push_back(shared_ptr<Move>(new Move(posx,posy,posx,posy+1,"*",t)));
            possibleMovesCounter++;
        }
        if (!outOfRange(posx+1, posy+1) && theGrid->theGrid[posy+1][posx+1].occupiedBy != nullptr && theGrid->theGrid[posy+1][posx+1].occupiedBy->dark != t->dark) {
            possiblemoves.push_back(shared_ptr<Move>(new Move(posx,posy,posx+1,posy+1,"*",t)));
            possibleMovesCounter++;
        }
        if(!outOfRange(posx-1, posy+1) && theGrid->theGrid[posy+1][posx-1].occupiedBy != nullptr && theGrid->theGrid[posy+1][posx-1].occupiedBy->dark != t->dark) {
            possiblemoves.push_back(shared_ptr<Move>(new Move(posx,posy,posx-1,posy+1,"*",t)));
            possibleMovesCounter++;
        }

        }
    //black firsst time;
     if(posy == 6 && dark){
         
         if(!outOfRange(posx, posy-1) && theGrid->theGrid[posy-1][posx].occupiedBy == nullptr) {
                //cout<<"if222"<<endl;
             possiblemoves.push_back(shared_ptr<Move>(new Move(posx,posy,posx,posy-1,"*",t)));
             possibleMovesCounter++;
         }
     
         if (!outOfRange(posx, posy-2) &&  theGrid->theGrid[posy-1][posx].occupiedBy != nullptr) {
               // cout<<"if2220000 "<<endl;
             possiblemoves.push_back(shared_ptr<Move>(new Move(posx,posy,posx,posy,"*",t)));
             possibleMovesCounter++;
         }
       //  cout<<"if2221"<<endl;
         if (!outOfRange(posx, posy-2) &&  theGrid->theGrid[posy-2][posx].occupiedBy == nullptr && theGrid->theGrid[posy-2][posx].occupiedBy == nullptr) {
             possiblemoves.push_back(shared_ptr<Move>(new Move(posx,posy,posx,posy-2,"*",t)));
             possibleMovesCounter++;
         }
        // cout<<"if22223"<<endl;
         if (!outOfRange(posx+1, posy-1) && theGrid->theGrid[posy-1][posx+1].occupiedBy != nullptr && theGrid->theGrid[posy-1][posx+1].occupiedBy->dark != t->dark) {
             possiblemoves.push_back(shared_ptr<Move>(new Move(posx,posy,posx+1,posy-1,"*",t)));
             possibleMovesCounter++;
         }
        // cout<<"if22224"<<endl;
         if(!outOfRange(posx-1, posy-1) && theGrid->theGrid[posy-1][posx-1].occupiedBy != nullptr && theGrid->theGrid[posy-1][posx-1].occupiedBy->dark != t->dark) {
             possiblemoves.push_back(shared_ptr<Move>(new Move(posx,posy,posx-1,posy-1,"*",t)));
             possibleMovesCounter++;
         }
    }
    
    //white non-first time;
    else if (posy > 1 && posy<6 && !dark){
        //nothing infront
        if(!outOfRange(posx+1, posy+1) && theGrid->theGrid[posy+1][posx+1].occupiedBy == nullptr &&theGrid->theGrid[posy][posx+1].occupiedBy&&theGrid->theGrid[posy][posx+1].occupiedBy->dark){
            possiblemoves.push_back(shared_ptr<Move>(new Move(posx,posy,posx+1,posy+1,"*",t)));
            possibleMovesCounter +=1;
        //en passant
        }
        if(!outOfRange(posx-1, posy+1) && theGrid->theGrid[posy+1][posx-1].occupiedBy == nullptr &&theGrid->theGrid[posy][posx-1].occupiedBy&&theGrid->theGrid[posy][posx-1].occupiedBy->dark){
            possiblemoves.push_back(shared_ptr<Move>(new Move(posx,posy,posx-1,posy+1,"*",t)));
            possibleMovesCounter +=1;
        //en passant
        }
        if(!outOfRange(posx, posy+1) && theGrid->theGrid[posy+1][posx].occupiedBy != nullptr ) {
            //cout<<"if333222"<<endl;
            possiblemoves.push_back(shared_ptr<Move>(new Move(posx,posy,posx,posy,"*",t)));
            possibleMovesCounter +=1;
        }
        if(theGrid->theGrid[posy+1][posx].occupiedBy == nullptr && !outOfRange(posx, posy+1)) {
           // cout<<"if333444"<<endl;
        possiblemoves.push_back(shared_ptr<Move>(new Move(posx,posy,posx,posy+1,"*",t)));
            possibleMovesCounter +=1;
        }
        //left-up ward is something and its opponents'
        if(theGrid->theGrid[posy+1][posx-1].occupiedBy != nullptr && !outOfRange(posx-1, posy+1) && theGrid->theGrid[posy+1][posx-1].occupiedBy->dark != t->dark){
            //cout<<"theGrid->theGrid[posy-1][posx+1].occupiedBy: "<<theGrid->theGrid[posy+1][posx-1].occupiedBy->name<<endl;
            //cout<<"if444"<<endl;
            possiblemoves.push_back(shared_ptr<Move>(new Move(posx,posy,posx-1,posy+1,"*",t)));
            possibleMovesCounter +=1;
        }
        //right-up ward is something and its opponents'
        if(theGrid->theGrid[posy+1][posx+1].occupiedBy != nullptr && !outOfRange(posx+1, posy+1) && theGrid->theGrid[posy+1][posx+1].occupiedBy->dark != t->dark){
            //cout<<"theGrid->theGrid[posy+1][posx+1].occupiedBy: "<<theGrid->theGrid[posy+1][posx+1].occupiedBy->name<<endl;
            //cout<<"if555"<<endl;
            possiblemoves.push_back(shared_ptr<Move>(new Move(posx,posy,posx+1,posy+1,"*",t)));
            possibleMovesCounter +=1;
        }
    }
    
    else if (posy<6 && posy>1 && dark){
        if(!outOfRange(posx+1, posy-1) && theGrid->theGrid[posy-1][posx+1].occupiedBy == nullptr &&theGrid->theGrid[posy][posx+1].occupiedBy&&!theGrid->theGrid[posy][posx+1].occupiedBy->dark){
            possiblemoves.push_back(shared_ptr<Move>(new Move(posx,posy,posx+1,posy-1,"*",t)));
            possibleMovesCounter +=1;
            //en passant
        }
        if(!outOfRange(posx-1, posy-1) && theGrid->theGrid[posy-1][posx-1].occupiedBy == nullptr &&theGrid->theGrid[posy][posx-1].occupiedBy&&!theGrid->theGrid[posy][posx-1].occupiedBy->dark){
            possiblemoves.push_back(shared_ptr<Move>(new Move(posx,posy,posx-1,posy-1,"*",t)));
            possibleMovesCounter +=1;
            //en passant
        }
        if( !outOfRange(posx, posy-1) && theGrid->theGrid[posy-1][posx].occupiedBy != nullptr ) {
           // cout<<"if333111"<<endl;
            possiblemoves.push_back(shared_ptr<Move>(new Move(posx,posy,posx,posy,"*",t)));
            possibleMovesCounter +=1;
        }
        if(theGrid->theGrid[posy-1][posx].occupiedBy == nullptr && !outOfRange(posx, posy-1)){
            //cout<<"if666"<<endl;
            possiblemoves.push_back(shared_ptr<Move>(new Move(posx,posy,posx,posy-1,"*",t)));
            possibleMovesCounter +=1;
        }
        
        if(theGrid->theGrid[posy-1][posx-1].occupiedBy != nullptr && !outOfRange(posx-1,posy-1) && theGrid->theGrid[posy-1][posx-1].occupiedBy->dark != t->dark){
            //cout<<"theGrid->theGrid[posy-1][posx-1].occupiedBy: "<<theGrid->theGrid[posy-1][posx-1].occupiedBy->name<<endl;
            //cout<<"if777"<<endl;
            possiblemoves.push_back(shared_ptr<Move>(new Move(posx,posy,posx-1,posy-1,"*",t)));
            possibleMovesCounter +=1;
        }
        if(theGrid->theGrid[posy-1][posx+1].occupiedBy != nullptr && !outOfRange(posx+1, posy-1) && theGrid->theGrid[posy-1][posx+1].occupiedBy->dark != t->dark){
            //cout<<"theGrid->theGrid[posy+1][posx-1].occupiedBy: "<<theGrid->theGrid[posy-1][posx+1].occupiedBy->name<<endl;
            //cout<<"if888"<<endl;
            possiblemoves.push_back(shared_ptr<Move>(new Move(posx,posy,posx+1,posy-1,"*",t)));
            possibleMovesCounter +=1;
        }
    }
    
    else if (posy == 6 && !dark){
       // cout<<"if999"<<endl;
        if (!outOfRange(posx, posy+1) && theGrid->theGrid[posy+1][posx].occupiedBy == nullptr) {
        possiblemoves.push_back(shared_ptr<Move>(new Move(posx,posy,posx,posy+1,"R",t)));
        shared_ptr<Move> temp2 (new Move(posx,posy,posx,posy+1,"N",t));
        possiblemoves.push_back(temp2);
        shared_ptr<Move> temp3 (new Move(posx,posy,posx,posy+1,"B",t));
        possiblemoves.push_back(temp3);
        shared_ptr<Move> temp4 (new Move(posx,posy,posx,posy+1,"Q",t));
        possiblemoves.push_back(temp4);
        possibleMovesCounter +=4;
        }
        if (!outOfRange(posx-1, posy+1) && (theGrid->theGrid[posy+1][posx-1].occupiedBy == nullptr || theGrid->theGrid[posy+1][posx-1].occupiedBy->dark != t->dark)) {
            possiblemoves.push_back(shared_ptr<Move>(new Move(posx,posy,posx-1,posy+1,"R",t)));
            shared_ptr<Move> temp2 (new Move(posx,posy,posx-1,posy+1,"N",t));
            possiblemoves.push_back(temp2);
            shared_ptr<Move> temp3 (new Move(posx,posy,posx-1,posy+1,"B",t));
            possiblemoves.push_back(temp3);
            shared_ptr<Move> temp4 (new Move(posx,posy,posx-1,posy+1,"Q",t));
            possiblemoves.push_back(temp4);
            possibleMovesCounter +=4;
        }
        if (!outOfRange(posx+1, posy+1) && (theGrid->theGrid[posy+1][posx+1].occupiedBy == nullptr || theGrid->theGrid[posy+1][posx+1].occupiedBy->dark != t->dark)) {
            possiblemoves.push_back(shared_ptr<Move>(new Move(posx,posy,posx,posy+1,"R",t)));
            shared_ptr<Move> temp2 (new Move(posx,posy,posx+1,posy+1,"N",t));
            possiblemoves.push_back(temp2);
            shared_ptr<Move> temp3 (new Move(posx,posy,posx+1,posy+1,"B",t));
            possiblemoves.push_back(temp3);
            shared_ptr<Move> temp4 (new Move(posx,posy,posx+1,posy+1,"Q",t));
            possiblemoves.push_back(temp4);
            possibleMovesCounter +=4;
        }
    }
    else if (posy == 1 && dark ){
        //cout<<"if101010"<<endl;
        if (!outOfRange(posx, posy-1) && theGrid->theGrid[posy-1][posx].occupiedBy == nullptr) {
            possiblemoves.push_back(shared_ptr<Move>(new Move(posx,posy,posx,posy-1,"R",t)));
            shared_ptr<Move> temp2 (new Move(posx,posy,posx,posy-1,"N",t));
            possiblemoves.push_back(temp2);
            shared_ptr<Move> temp3 (new Move(posx,posy,posx,posy-1,"B",t));
            possiblemoves.push_back(temp3);
            shared_ptr<Move> temp4 (new Move(posx,posy,posx,posy-1,"Q",t));
            possiblemoves.push_back(temp4);
            possibleMovesCounter +=4;
        }
        if (!outOfRange(posx+1, posy-1) && (theGrid->theGrid[posy-1][posx+1].occupiedBy == nullptr || theGrid->theGrid[posy-1][posx+1].occupiedBy->dark != t->dark)) {
            possiblemoves.push_back(shared_ptr<Move>(new Move(posx,posy,posx+1,posy-1,"R",t)));
            shared_ptr<Move> temp2 (new Move(posx,posy,posx+1,posy-1,"N",t));
            possiblemoves.push_back(temp2);
            shared_ptr<Move> temp3 (new Move(posx,posy,posx+1,posy-1,"B",t));
            possiblemoves.push_back(temp3);
            shared_ptr<Move> temp4 (new Move(posx,posy,posx+1,posy-1,"Q",t));
            possiblemoves.push_back(temp4);
            possibleMovesCounter +=4;
        }
        if (!outOfRange(posx-1, posy-1) && (theGrid->theGrid[posy-1][posx-1].occupiedBy == nullptr || theGrid->theGrid[posy-1][posx-1].occupiedBy->dark != t->dark)) {
            possiblemoves.push_back(shared_ptr<Move>(new Move(posx,posy,posx-1,posy-1,"R",t)));
            shared_ptr<Move> temp2 (new Move(posx,posy,posx-1,posy-1,"N",t));
            possiblemoves.push_back(temp2);
            shared_ptr<Move> temp3 (new Move(posx,posy,posx-1,posy-1,"B",t));
            possiblemoves.push_back(temp3);
            shared_ptr<Move> temp4 (new Move(posx,posy,posx-1,posy-1,"Q",t));
            possiblemoves.push_back(temp4);
            possibleMovesCounter +=4;
        }
    
    }
}

