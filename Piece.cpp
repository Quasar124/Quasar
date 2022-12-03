#include "Piece.hpp"

using namespace std;

Piece::Piece(Board *b, int x, int y, bool colour) {
    this->b = b;
    this->x = x;
    this->y = y;
    this->colour = colour;

    if (colour == white) {
        b->whitePieces.push_back(this);
    } else {
        b->blackPieces.push_back(this);
    }
}

bool Piece::isLegal(int x, int y) {
    if (ownPiece(x, y)) return false;

    int tx = this->x;
    int ty = this->y;
    this->x = x;
    this->y = y;
    b->s[tx][ty] = nullptr;
    Piece *t = b->s[x][y];
    b->s[x][y] = this;

    if (t) {
        if (colour == white) {
            b->blackPieces.remove(t);
        } else {
            b->whitePieces.remove(t);
        }
    }

    bool l = b->inCheck(colour);

    this->x = tx;
    this->y = ty;
    b->s[tx][ty] = this;
    b->s[x][y] = t;

    if (t) {
        if (colour == white) {
            b->blackPieces.push_back(t);
        } else {
            b->whitePieces.push_back(t);
        }
    }

    return !l;
}

bool Piece::enemyPiece(int x, int y) {
    return !(b->isEmpty(x, y)) && b->s[x][y]->colour != colour;
}

bool Piece::ownPiece(int x, int y) {
    return !(b->isEmpty(x, y)) && b->s[x][y]->colour == colour;
}