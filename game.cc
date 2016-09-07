//
//  game.cpp
//  Chess
//
//  Created by Qian Wu on 2016-07-15.
//  Copyright © 2016 Qian Wu. All rights reserved.
//
#include "humanPlayer.h"
#include "game.h"

Game::Game(){
    whiteTurn = true;
    
    blackScore = 0;
    whiteScore = 0;
}

Game::~Game() {
}

void Game::initGrid(shared_ptr<Grid> g) {
    Board = g;
}

void Game::initWhite() {
    Board->white = whitePlayer;
    
}

void Game::initBlack() {
    Board->black = blackPlayer;
    
}

void Game::blackWin() {
    ++blackScore;
}
void Game::whiteWin() {
    ++whiteScore;
}
void Game::draw() {
    whiteScore+= 0.5;
    blackScore+= 0.5;
}
void Game::endGame() {
	cout << "Final Score:" << endl;
	cout << "White: " << whiteScore << endl;
	cout << "Black: " << blackScore << endl;
	//~Game();
}

void Game::newRound() {
    //Grid.initGrid()
    
}
void Game::startGame(shared_ptr<Grid> newBoard) {
    initGrid(newBoard);
    
}

/*bool Game::isOver() {
    if (whitePlayer->chessUnits[12].avail == false) { //need to modify so that checkmate
		endGame();
		return true;
    } 
	else if (blackPlayer->chessUnits[4].avail == false) { //need to modify so that checkmate
		endGame();
		return true;
	}
	else {
		return false;
	}
}*/
void Game::assignEnemy() {
    whitePlayer->enemy = blackPlayer;
    blackPlayer->enemy = whitePlayer;
    for(int i =0;i<Board->whiteChessUnits.size();++i) {
        Board->whiteChessUnits[i]->enemy = blackPlayer;
    }
    for(int i =0;i<Board->blackChessUnits.size();++i) {
        Board->blackChessUnits[i]->enemy = whitePlayer;
        
    }
    //cout<<"assigned enemy"<<endl;
}

