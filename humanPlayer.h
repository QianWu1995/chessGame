//humanPlayer


#include <stdio.h>
#include <vector>
#include "player.h"
#include "move.h"

//class Move;

class humanPlayer: public Player {
public:
    humanPlayer(bool black, shared_ptr<Grid> board);
    shared_ptr <Move> nextMove(string s);
};