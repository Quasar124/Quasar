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

    place(new King(this, 4, 0, white, false));
    place(new King(this, 4, size - 1, black, false));

    for (int i = 0; i < size; i++) {
        place(new WhitePawn(this, i, 1, white, false));
        place(new BlackPawn(this, i, size - 2, black, false));
    }

    place(new Rook(this, 0, 0, white, false));
    place(new Rook(this, 0, size - 1, black, false));
    place(new Rook(this, size - 1, 0, white, false));
    place(new Rook(this, size - 1, size - 1, black, false));

    place(new Knight(this, 1, 0, white));
    place(new Knight(this, 1, size - 1, black));
    place(new Knight(this, size - 2, 0, white));
    place(new Knight(this, size - 2, size - 1, black));

    place(new Bishop(this, 2, 0, white));
    place(new Bishop(this, 2, size - 1, black));
    place(new Bishop(this, size - 3, 0, white));
    place(new Bishop(this, size - 3, size - 1, black));

    place(new Queen(this, 3, 0, white));
    place(new Queen(this, 3, size - 1, black));

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
        return attack(whitePieces.front()->x, whitePieces.front()->y, black);      
    } else {
        return attack(blackPieces.front()->x, blackPieces.front()->y, white);
    }
}

bool Board::isEmpty(int x, int y) {
    return s[x][y] == nullptr;
}

void Board::place(Piece *p) {
    s[p->x][p->y] = p;
    p->colour == white ? whitePieces.push_back(p) : blackPieces.push_back(p);
}

string Board::getFEN() {
    return string("eqeqe");
}

bool std::onBoard(int x, int y) {
    return x > -1 && x < size && y > -1 && y < size;
}