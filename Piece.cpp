#include "Piece.hpp"

using namespace std;

Piece::Piece(Board *b, Square *s, bool colour) {
    this->b = b;
    this->s = s;
    this->colour = colour;
    s->p = this;

    if (colour == white) {
        b->whitePieces.push_back(this);
    } else {
        b->blackPieces.push_back(this);
    }
}

bool Piece::isLegal(int x, int y) {
    if (ownPiece(x, y)) return false;

    Square *prev = s;
    prev->p = nullptr;
    Piece *t = b->s[x][y].p;
    if (t != nullptr) t->s = nullptr;

    b->s[x][y].p = this;
    s = &(b->s[x][y]);
    bool l = b->inCheck(colour);
    s = prev;
    s->p = this;
    b->s[x][y].p = t;
    if (t != nullptr) t->s = &(b->s[x][y]);

    return !l;
}

bool Piece::enemyPiece(int x, int y) {
    return !(b->s[x][y].isEmpty()) && b->s[x][y].p->colour != colour;
}

bool Piece::ownPiece(int x, int y) {
    return !(b->s[x][y].isEmpty()) && b->s[x][y].p->colour == colour;
}