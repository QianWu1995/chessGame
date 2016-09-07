//
//  Grid.cpp
//  Chess
//
//  Created by Qian Wu on 2016-07-11.
//  Copyright © 2016 Qian Wu. All rights reserved.
//

#include "Grid.h"
#include"player.h"
#include <sstream>
#include <stdio.h>
//#include "textDisplay.h"
using namespace std;


Grid::Grid() {
    for (int i =0;i<8;++i) {
        vector<Cell> row;
        for(int j=0;j<8;++j) {
            row.emplace_back();
            row[j]= Cell(j,i,nullptr);
        }
        theGrid.emplace_back(row);
    }
    
        shared_ptr<Grid> temp(this);
    td.reset(new TextDisplay(temp));
    //gd.reset(new graphicDisplay(w,temp));
    whiteking=0;
    blackking=0;
    
}



//Grid::Grid(Xwindow &w):td{nullptr}, gd{new GraphicsDisplay{w}} {}


void Grid::attachChessToCell(){
    for(int i  = 0; i <= 7;++i){
        theGrid[0][i].occupiedBy = whiteChessUnits[i+8];
    }
    for(int i  = 0; i <= 7;++i){
        theGrid[1][i].occupiedBy = whiteChessUnits[i];
    }
    for(int i  = 0; i <= 7;++i){
        theGrid[7][i].occupiedBy = blackChessUnits[i];
    }
    for(int i  = 0; i <= 7;++i){
        theGrid[6][i].occupiedBy = blackChessUnits[i+8];
    }
    
}

void Grid::attachWithChar(){
    shared_ptr<Grid> board (this);
    for(int i = 0; i<8 ;++i){
        for (int j = 0; j < 8; ++j) {
            if(theGrid[i][j].name == '*'){
                theGrid[i][j].occupiedBy = nullptr;
            }
            else if (theGrid[i][j].name == 'P') {
                theGrid[i][j].occupiedBy.reset((new pawn(chessType::pawn,j,i,false,board)));
                blackChessUnits.push_back(theGrid[i][j].occupiedBy);
            }
            else if (theGrid[i][j].name == 'p') {
                theGrid[i][j].occupiedBy.reset((new pawn(chessType::pawn,j,i,true,board)));
                whiteChessUnits.push_back(theGrid[i][j].occupiedBy);
            }
            else if (theGrid[i][j].name == 'R') {
                theGrid[i][j].occupiedBy.reset((new rook(chessType::rook,j,i,false,board)));
                blackChessUnits.push_back(theGrid[i][j].occupiedBy);
            }else if (theGrid[i][j].name == 'r') {
                theGrid[i][j].occupiedBy.reset((new rook(chessType::rook,j,i,true,board)));
                whiteChessUnits.push_back(theGrid[i][j].occupiedBy);
            }else if (theGrid[i][j].name == 'Q') {
                theGrid[i][j].occupiedBy.reset((new queen(chessType::queen,j,i,false,board)));
                blackChessUnits.push_back(theGrid[i][j].occupiedBy);
            }
            else if (theGrid[i][j].name == 'q') {
                theGrid[i][j].occupiedBy.reset((new queen(chessType::queen,j,i,true,board)));
                whiteChessUnits.push_back(theGrid[i][j].occupiedBy);
            }
            else if (theGrid[i][j].name == 'B') {
                theGrid[i][j].occupiedBy.reset((new bishop(chessType::bishop,j,i,false,board)));
                blackChessUnits.push_back(theGrid[i][j].occupiedBy);
            }
            else if (theGrid[i][j].name == 'b') {
                theGrid[i][j].occupiedBy.reset((new bishop(chessType::bishop,j,i,true,board)));
                whiteChessUnits.push_back(theGrid[i][j].occupiedBy);
            }
            else if (theGrid[i][j].name == 'N') {
                theGrid[i][j].occupiedBy.reset((new knight(chessType::knight,j,i,false,board)));
                blackChessUnits.push_back(theGrid[i][j].occupiedBy);
            }else if (theGrid[i][j].name == 'n') {
                theGrid[i][j].occupiedBy.reset((new knight(chessType::knight,j,i,true,board)));
                whiteChessUnits.push_back(theGrid[i][j].occupiedBy);
            }
            else if (theGrid[i][j].name == 'K') {
                theGrid[i][j].occupiedBy.reset((new king(chessType::king,j,i,white,false,board)));
                blackChessUnits.push_back(theGrid[i][j].occupiedBy);
            }
            else if (theGrid[i][j].name == 'k') {
                theGrid[i][j].occupiedBy.reset((new king(chessType::king,j,i,black,true,board)));
                whiteChessUnits.push_back(theGrid[i][j].occupiedBy);
            }
            
            
        }
    }
}

void Grid::defaultChessUnits() {
        shared_ptr<Grid> board (this);
        int x1 = 0;
        int x2 = 0;
        for(int i = 0; i < 16; ++i) {
            if(i == 0 || i == 7) {
                blackChessUnits.emplace_back(new rook(chessType::rook, x1, 7, true,board));
                ++x1;
            } else if(i == 1 || i == 6) {
                blackChessUnits.emplace_back(new knight(chessType::knight, x1, 7, true,board));
                ++x1;
            } else if(i == 2 || i == 5) {
                blackChessUnits.emplace_back(new bishop(chessType::bishop, x1, 7, true,board));
                ++x1;
            } else if(i == 3) {
                blackChessUnits.emplace_back(new queen(chessType::queen, x1, 7, true,board));
                ++x1;
            } else if(i == 4) {
                blackChessUnits.emplace_back(new king(chessType::king, x1, 7,white, true,board));
                ++x1;
            } else {
                blackChessUnits.emplace_back(new pawn(chessType::pawn, x2, 6, true,board));
                ++x2;
            }
        }
          x1 = 0;
          x2 = 0;
        for(int i = 0; i < 16; ++i) {
            if(i == 8 || i == 15) {
                whiteChessUnits.emplace_back(new rook(chessType::rook, x1, 0, false,board));
                ++x1;
            } else if(i == 9 || i == 14) {
                whiteChessUnits.emplace_back(new knight(chessType::knight, x1, 0,false,board));
                ++x1;
            } else if(i == 10 || i == 13) {
                whiteChessUnits.emplace_back(new bishop(chessType::bishop, x1, 0,false,board));
                ++x1;
            } else if(i == 11) {
                whiteChessUnits.emplace_back(new queen(chessType::queen, x1, 0,false,board));
                ++x1;
            } else if(i == 12) {
                whiteChessUnits.emplace_back(new king(chessType::king, x1, 0,black,false,board));
                ++x1;
            } else {
                whiteChessUnits.emplace_back(new pawn(chessType::pawn, x2, 1, false,board));
                ++x2;
            }
        }

        }

void Grid::refresh(){
    for (int i =0;i<whiteChessUnits.size();++i) {
        whiteChessUnits[i]->refreshPossibleMoves();

    }
    
    for (int ii =0;ii<blackChessUnits.size();++ii) {

        blackChessUnits[ii]->refreshPossibleMoves();

    }}


Grid::~Grid() {

}

void Grid::promote(shared_ptr<Move> m) {
    shared_ptr<Grid> temp (this);
    theGrid[m->toY][m->toX].occupiedBy = nullptr;
    if (m->obj->dark) {
        for (int i = 0; i < blackChessUnits.size(); ++i) {
            if ((blackChessUnits[i]->posx == m->toX) && (blackChessUnits[i]->posy == m->toY)) {
                if (m->promoteTo == "q") {
                    blackChessUnits[i].reset(new queen(chessType::queen, m->toX, m->toY, true, temp));
                }
                else if (m->promoteTo == "r") {
                    blackChessUnits[i].reset( new rook(chessType::rook, m->toX, m->toY, true, temp));
                }
                else if (m->promoteTo == "b") {
                    blackChessUnits[i].reset(new bishop(chessType::bishop, m->toX, m->toY, true, temp));
                }
                else if (m->promoteTo == "n") {
                    blackChessUnits[i].reset(new knight(chessType::knight, m->toX, m->toY, true, temp));
                }
                theGrid[m->toY][m->toX].occupiedBy = (blackChessUnits[i]);
            }
        }
    }
    else if (!m->obj->dark) {
        for (int i = 0; i < whiteChessUnits.size(); ++i) {
            if ((whiteChessUnits[i]->posx == m->toX) && (whiteChessUnits[i]->posy == m->toY)) {
                if (m->promoteTo == "q") {
                    whiteChessUnits[i].reset(new queen(chessType::queen, m->toX, m->toY, false, temp));
                }
                else if (m->promoteTo == "r") {
                    whiteChessUnits[i].reset(new rook(chessType::rook, m->toX, m->toY, false, temp));
                }
                else if (m->promoteTo == "b") {
                    whiteChessUnits[i].reset(new bishop(chessType::bishop, m->toX, m->toY, false, temp));
                }
                else if (m->promoteTo == "n") {
                    whiteChessUnits[i].reset(new knight(chessType::knight, m->toX, m->toY, false, temp));
                }
                theGrid[m->toY][m->toX].occupiedBy = (whiteChessUnits[i]);
            }
        }
    }
}

void Grid::move(shared_ptr <Move> m) {
    if ((theGrid[m->fromY][m->fromX].occupiedBy != m->obj)) {
        return;
    }
    //refresh();
    else if (m->promoteTo != "*") {
        //cout<<"if3"<<endl;
        if(m->obj->isValidMove(m->toX, m->toY)) {
            promote(m);
            refresh();
        }
    }
    else if(m->obj->isValidMove(m->toX,m->toY)){
        //cout<<"if2"<<endl;
        if(theGrid[m->fromY][m->fromX].occupiedBy->name == 'p'){
            if((m->toY == m->fromY-1) && (m->toX == m->fromX-1||m->toX == m->fromX+1)){
                if(theGrid[m->toY+1][m->toX].occupiedBy->name == 'P'){
                    theGrid[m->toY+1][m->toX].occupiedBy = nullptr;
                }
            }
        }
        if(theGrid[m->fromY][m->fromX].occupiedBy->name == 'P'){
            if((m->toY == m->fromY+1) && (m->toX == m->fromX-1||m->toX == m->fromX+1)){
                if(theGrid[m->toY-1][m->toX].occupiedBy->name == 'p'){
                    theGrid[m->toY-1][m->toX].occupiedBy = nullptr;
                }
            }
        }
        theGrid[m->fromY][m->fromX].occupiedBy = nullptr;
        if (theGrid[m->toY][m->toX].occupiedBy == nullptr ) {
            theGrid[m->toY][m->toX].occupiedBy = m->obj;
            m->obj->move(m->toX, m->toY);
            moves.emplace_back(m);
            refresh();
            td->notify();
            //gd->notify();
        } else {
            theGrid[m->toY][m->toX].occupiedBy->captured();
            m->obj->move(m->toX, m->toY);
            theGrid[m->toY][m->toX].occupiedBy = m->obj;
            moves.emplace_back(m);
            refresh();
            td->notify();
            //gd->notify();
        }
    }
    
    else {
        return;
    }
}


bool Grid::checkMate() {
    if (white->isChecked && whiteChessUnits[12]->possiblemoves.size() == 0) {
        cout << "Checkmate! Black wins!" << endl;
        return true;
    }
    else if (black->isChecked && blackChessUnits[4]->possiblemoves.size() == 0) {
        cout << "Checkmate! White wins!" << endl;
        return true;
    }
    else {
        return false;
    }
}


bool Grid::staleMate() {
    if (!(white->isChecked) && whiteChessUnits[12]->possiblemoves.size() == 0) {
        cout << "Stalemate!" << endl;
        return true;
    }
    else if (!(black->isChecked) && blackChessUnits[4]->possiblemoves.size() == 0) {
        cout << "Stalemate!" << endl;
        return true;
    }
    else {
        return false;
    }
}


bool Grid::inCheck() {
    if (white->isCheckedFunc()) {
        cout << "White is in check." << endl;
        return true;
    }
    else if (black->isCheckedFunc()) {
        cout << "Black is in check." << endl;
        return true;
    } 
    return false;
}

bool Grid::isGridValid() {
    if (whiteking != 1 || blackking != 1) {
        return false;
    }
    for (int i=0; i<8;++i) {
        if(theGrid[0][i].name == 'p' || theGrid[7][i].name == 'P' || theGrid[0][i].name == 'P' || theGrid[7][i].name == 'p') {
            return false;
        }
    }
    // in check
    
    return true;
}









