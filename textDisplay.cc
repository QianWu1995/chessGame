//
//  textDisplay.cpp
//  Chess
//
//  Created by Qian Wu on 2016-07-14.
//  Copyright © 2016 Qian Wu. All rights reserved.
//

#include "textDisplay.h"
#include <vector>
//#include "chessUnit.h"
#include<iostream>
#include"Grid.h"
using namespace std;

TextDisplay::TextDisplay(shared_ptr<Grid> theBoard): display(theBoard){}


void TextDisplay::draw(){
    for(int i = 7;i >= 0; --i){
        cout<<i+1<<" ";
        for(int j = 0; j < 8; ++j) {
            if((theBoard->theGrid)[i][j].occupiedBy == nullptr) {
                if ((theBoard->theGrid)[i][j].dark) {
                    cout<<"_";
                } else {
                    cout<<" ";
                }
            }
            else if(theBoard->theGrid[i][j].occupiedBy->avail == true){
                cout<<(theBoard->theGrid)[i][j].occupiedBy->name;
            }
        }
        cout<<endl;
    } cout<<endl;
    cout<<"  abcdefgh"<<endl;
}
void TextDisplay::setupDraw(){
    for(int i = 7;i >= 0; --i){
        cout<<i+1<<" ";
        for(int j = 0; j < 8; ++j) {
            if((theBoard->theGrid)[i][j].name == '*') {
                if ((theBoard->theGrid)[i][j].dark) {
                    cout<<"_";
                } else {
                    cout<<" ";
                }
            }
            else {
                cout<<(theBoard->theGrid)[i][j].name;
            }
        }
        cout<<endl;
    } cout<<endl;
    cout<<"  abcdefgh"<<endl;
}

TextDisplay::~TextDisplay() {

}



