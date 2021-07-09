#include "Board.hpp"
#include "King.hpp"


using namespace std;

Board::Board() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            s[i][j].setXY(i, j);
        }
    }

    s[4][0].p = new King(this, &s[4][0], white, false);
    s[4][7].p = new King(this, &s[4][7], black, false);
}

bool Board::attack(Square *s, bool colour) {
    if (colour == white) {
        for (auto i : whitePieces) {
            if (i->attack(s)) return true;
        }        
    } else {
        for (auto i : blackPieces) {
            if (i->attack(s)) return true;
        } 
    }

    return false;
}

bool Board::inCheck(bool colour) {
    if (colour == white) {
        return attack(whitePieces[0]->s, black);      
    } else {
        return attack(blackPieces[0]->s, white);
    }
}