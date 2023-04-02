#include "Bishop.hpp"
#include "BlackPawn.hpp"
#include "Board.hpp"
#include "King.hpp"
#include "Knight.hpp"
#include "Queen.hpp"
#include "Rook.hpp"
#include "WhitePawn.hpp"

using namespace std;

Board::Board() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) s[i][j] = nullptr;
    }

    whiteKing = new King(this, 4, 0, white, false);
    blackKing = new King(this, 4, size - 1, black, false);

    for (int i = 0; i < size; i++) {
        WhitePawn(this, i, 1, white, false);
        BlackPawn(this, i, size - 2, black, false);
    }

    Rook(this, 0, 0, white, false);
    Rook(this, 0, size - 1, black, false);
    Rook(this, size - 1, 0, white, false);
    Rook(this, size - 1, size - 1, black, false);

    Knight(this, 1, 0, white);
    Knight(this, 1, size - 1, black);
    Knight(this, size - 2, 0, white);
    Knight(this, size - 2, size - 1, black);

    Bishop(this, 2, 0, white);
    Bishop(this, 2, size - 1, black);
    Bishop(this, size - 3, 0, white);
    Bishop(this, size - 3, size - 1, black);

    Queen(this, 3, 0, white);
    Queen(this, 3, size - 1, black);

    turn = white;
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
        return attack(whiteKing->x, whiteKing->y, black);      
    } else {
        return attack(blackKing->x, blackKing->y, white);
    }
}

Piece* std::Board::move(Piece *p, int x, int y, int pr)
{
    return nullptr;
}

bool Board::isEmpty(int x, int y) {
    return s[x][y] == nullptr;
}

string Board::getFEN() {
    // TODO
    return string("eqeqe");
}

bool std::onBoard(int x, int y) {
    return x > -1 && x < size && y > -1 && y < size;
}