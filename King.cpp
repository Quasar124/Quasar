#include <cmath>
#include "King.hpp"
#include "Rook.hpp"
#include "Square.hpp"

using namespace std;

King::King(Board *b, Square *s, bool colour, bool hasMoved) : Piece(b, s, colour) {
    value = 0;
    this->hasMoved = hasMoved;
}

vector<Square *> King::moves() {
    vector<Square *> m;

    if (isLegal(s->x, s->y + 1)) m.push_back(&(b->s[s->x][s->y + 1]));
    if (isLegal(s->x + 1, s->y + 1)) m.push_back(&(b->s[s->x + 1][s->y + 1]));
    if (isLegal(s->x + 1, s->y)) m.push_back(&(b->s[s->x + 1][s->y]));
    if (isLegal(s->x + 1, s->y - 1)) m.push_back(&(b->s[s->x + 1][s->y - 1]));
    if (isLegal(s->x, s->y - 1)) m.push_back(&(b->s[s->x][s->y - 1]));
    if (isLegal(s->x - 1, s->y - 1)) m.push_back(&(b->s[s->x - 1][s->y - 1]));
    if (isLegal(s->x - 1, s->y)) m.push_back(&(b->s[s->x - 1][s->y]));
    if (isLegal(s->x - 1, s->y + 1)) m.push_back(&(b->s[s->x - 1][s->y + 1]));

    if (b->s[1][s->y].isEmpty() && b->s[2][s->y].isEmpty() && b->s[3][s->y].isEmpty() && !hasMoved && ownPiece(0, s->y)) {
        Rook *r = dynamic_cast<Rook *>(b->s[0][s->y].p);
        if (r && !(r->hasMoved) && !(b->inCheck(colour)) && !(b->attack(&(b->s[2][s->y]), !colour)) && !(b->attack(&(b->s[3][s->y]), !colour))) m.push_back(&(b->s[2][s->y]));
    }

    if (b->s[5][s->y].isEmpty() && b->s[6][s->y].isEmpty() && !hasMoved && ownPiece(7, s->y)) {
        Rook *r = dynamic_cast<Rook *>(b->s[7][s->y].p);
        if (r && !(r->hasMoved) && !(b->inCheck(colour)) && !(b->attack(&(b->s[5][s->y]), !colour)) && !(b->attack(&(b->s[6][s->y]), !colour))) m.push_back(&(b->s[6][s->y]));
    }

    return m;
}

bool King::attack(Square *a) {
    return abs(s->x - a->x) <= 1 && abs(s->y - a->y) <= 1;
}

bool King::isLegal(int x, int y) {
    return onBoard(x, y) && Piece::isLegal(x, y);
}