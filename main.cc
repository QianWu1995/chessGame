//
//  main.cpp
//  Chess
//
//  Created by Qian Wu on 2016-07-11.
//  Copyright © 2016 Qian Wu. All rights reserved.
//
#include<sstream>
#include <iostream>
#include <exception>
#include "humanPlayer.h"
#include "Ai.h"
//#include "textDisplay.h"
#include "game.h"

int main() {
    //Xwindow w;
    cout<<"Welcome to the Chess Game developed by Nicode and Qian!"<<endl;
    
    cin.exceptions(ios::eofbit|ios::failbit);
    string command;
    string white;
    string black;
    bool setup = false;
    Game newgame = Game();
    shared_ptr<Grid> newBoard (new Grid());
    try {
        while (1) {
            cin>>command;
            if(command == "game"){
                newgame.startGame(newBoard);
                cin>>white;
                cin>>black;
                if(white == "human"){
                    newgame.whitePlayer.reset(new humanPlayer(false,newgame.Board));
                    newgame.initWhite();
                }
                if(black == "human"){
                    newgame.blackPlayer.reset(new humanPlayer(true,newgame.Board));
                    newgame.initBlack();
                }
                if(black == "computer[1]"){
                    newgame.blackPlayer.reset(new Ai(true,newgame.Board,1));
                    newgame.initBlack();
                }
                if(black == "computer[2]"){
                    newgame.blackPlayer.reset(new Ai(true,newgame.Board,2));
                    newgame.initBlack();
                }
                if(setup) {
                    newgame.Board->attachWithChar();
                } else {
                    newgame.Board->defaultChessUnits();
                    newgame.Board->attachChessToCell();
                }
                newgame.assignEnemy();
                newgame.Board->td->notify();
                newgame.Board->refresh();
                //newgame.Board->td->notify();
                }
 
            if(!newgame.whiteTurn && command == "move" && (black == "computer[1]" || black == "computer[2]" || black == "computer[3]" || black == "computer[4]")){
                //string commadnForinglePlayer;
                //cout<<""<<endl;
                
                   // cin>>commadnForinglePlayer;
                    //if(commadnForinglePlayer == "move"){
                    string s;
                    getline(cin,s);
                    shared_ptr <Move> m (newgame.blackPlayer->nextMove(s));
                
                        newgame.Board->move(m);
                        /*//newgame.Board->td->notify();
                        string garbage;
                        cin>>garbage; 
                        shared_ptr<Move> lll (newgame.blackPlayer->nextMove("sda"));
                        newgame.Board->move(lll);*/
                    
                newgame.whiteTurn = !newgame.whiteTurn;
                
            
            
            }
            
            else if (command == "setup"){
                //cout<<"enter setup mode"<<endl;
                newBoard->td->setupDraw();
                //newBoard->gd->setupDraw();
                setup = true;
                
                while(!newBoard->isGridValid()) {
                    string cmd;
                    cin>>cmd;
                    while(cmd != "done") {
                        if (cmd == "+") {
                            char chess;
                            string pos;
                            cin>>chess; //char
                            cin>>pos;
                            if (chess == 'K') {
                                ++newBoard->whiteking;
                            } else if (chess == 'k') {
                                ++newBoard->blackking;
                            }
                            newBoard->theGrid[pos[1]-'0'-1][pos[0]-'a'].name=chess;
                            newBoard->td->setupDraw();
                            //newBoard->gd->setupDraw();
                        } else if (cmd == "-") {
                            string pos;
                            cin>>pos;
                            if (newBoard->theGrid[pos[1]-'0'-1][pos[0]-'a'].name == 'K') {
                                --newBoard->whiteking;
                            } else if (newBoard->theGrid[pos[1]-'0'-1][pos[0]-'a'].name == 'k') {
                                --newBoard->blackking;
                            }
                            newBoard->theGrid[pos[1]-'0'-1][pos[0]-'a'].name='*';
                            newBoard->td->setupDraw();
                            //newBoard->gd->setupDraw();
                        }  else if (cmd == "=") {
                            string colour;
                            cin>>colour;
                            if (colour =="black") {
                                newgame.whiteTurn = false;
                            } else if(colour =="white") {
                                newgame.whiteTurn = true;
                            }
                            
                        }
                        cin>>cmd;
                    }
                    
                }
            }
            else if(command == "showscore"){
            newgame.endGame();
            }
            else if(command == "resign"){
                if(newgame.whiteTurn == 1){
                    ++newgame.blackScore;
                    cout<<"white concede!"<<endl;
                }
                else{
                    ++newgame.whiteScore;
                    cout<<"black concede"<<endl;
                }
                for(int i = 0; i < 8; ++i){
                    for(int j = 0; j < 8;++j){
                        newgame.Board->theGrid[i][j].occupiedBy = nullptr;
                    }
                }
            }
            else if(command == "showhistory"){
                cout<<"for your convienience please use following table to track the moves:"<<endl;
                cout<<"a:1  b:2  c:3  d:4  e:5  f:6  g:7  h:8"<<endl;
                for(int i = int(newgame.Board->moves.size())-1; i >= 0; --i){
                    cout<<"move "<<newgame.Board->moves[i]->obj->name<<" from x: "<<char(newgame.Board->moves[i]->fromX+49)<<"   y: "<<newgame.Board->moves[i]->fromY+1;
                    cout<<"  to x: "<<newgame.Board->moves[i]->toX+1<<"  y: "<<newgame.Board->moves[i]->toY+1<<endl;
                }
                continue;
            
            }
            
            else if(command == "move" && newgame.whiteTurn == 1){
            
                
                while(newgame.whiteTurn == 1 && command == "move") {
                    //white turn
                    string s;
                    getline(cin,s);
                    shared_ptr <Move> m (newgame.whitePlayer->nextMove(s));
                    
                    if(!m->obj->isValidMove(m->toX, m->toY) || m->obj->dark == newgame.whiteTurn){
                        newgame.whiteTurn = 1;
                        cout<<"invalid move!!"<<endl;
                        cin>>command;
                        continue;
                    }
                    newgame.Board->inCheck();
                    
                    newgame.Board->move(m);

                    newgame.whiteTurn = 0;
                }
                continue;
            }
            
            
            else if( command == "move" && newgame.whiteTurn == 0) {
                while(newgame.whiteTurn == 0 && command == "move") {
                    //white turn
                    string s;
                    getline(cin,s);
                    shared_ptr <Move> m (newgame.blackPlayer->nextMove(s));
                    if((m->obj->isValidMove(m->toX, m->toY)!=true)|| (m->obj->dark == newgame.whiteTurn)){
                        newgame.whiteTurn = 0;
                        cout<<"invalid move!!"<<endl;
                        cin>>command;
                        continue;
                    }
                    
                    newgame.Board->move(m);
                    newgame.Board->inCheck();
                    newgame.whiteTurn = 1;
                }
                continue;
            }
        }
}
    catch (ios::failure &) {
    cout<<"game is ended"<<endl;
    
        newgame.endGame();
        return 0;
    }}
