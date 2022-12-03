#include "Board.hpp"
#include "King.hpp"

using namespace std;

Board::Board() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) s[i][j] = nullptr;
    }

    // TODO
}

bool Board::attack(int x, int y, bool colour) {
    if (colour == white) {
        for (auto i : whitePieces) {
            if (i->attack(x, y)) return true;
        }        
    } else {
        for (auto i : blackPieces) {
            if (i->attack(x, y)) return true;
        } 
    }

    return false;
}

bool Board::inCheck(bool colour) {
    if (colour == white) {
        return attack(whitePieces.front()->x, whitePieces.front()->y, black);      
    } else {
        return attack(blackPieces.front()->x, blackPieces.front()->y, white);
    }
}

bool Board::isEmpty(int x, int y) {
    return s[x][y] == nullptr;
}

bool onBoard(int x, int y) {
    return x > -1 && x < size && y > -1 && y < size;
}