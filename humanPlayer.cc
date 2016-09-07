#include <stdio.h>
#include "humanPlayer.h"
using namespace std;
#include <string>
#include <sstream>
#include <exception>
//#include "move.h"

humanPlayer::humanPlayer(bool black, shared_ptr<Grid> board) : Player(black, true, 0, board) {


}

shared_ptr <Move> humanPlayer::nextMove(string s) {
    istringstream iss{s};
    string from;
    string to;
    string promotedTo="*";
    iss>>from;
    //cout<<from<<endl;
    iss>>to;
    //cout<<to<<endl;;
    iss>>promotedTo;
    //cout<<promotedTo<<endl;
    int fromX = from[0] - 'a';
    int fromY = from[1] - '0' - 1;
    int toX = to[0] - 'a';
    int toY = to[1] - '0' - 1;
    //cout<<board->theGrid[fromY][fromX].occupiedBy->name<<endl;
    shared_ptr<chessUnit> temp = board->theGrid[fromY][fromX].occupiedBy;
    shared_ptr <Move> newMove ( new Move(fromX, fromY, toX, toY, promotedTo,temp));
    //cout<<"move created"<<endl;
    //iss.clear();
    return newMove;
}