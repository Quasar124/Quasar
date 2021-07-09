#include <cmath>
#include "Square.hpp"
#include "WhitePawn.hpp"

using namespace std;

WhitePawn::WhitePawn(Board *b, Square *s, bool colour, bool hasMoved) : Piece(b, s, colour) {
    value = 1;
    this->hasMoved = hasMoved;
}

vector<Square *> WhitePawn::moves() {
    vector<Square *> m;

    if (!hasMoved && b->s[s->x][2].isEmpty() && b->s[s->x][3].isEmpty() && isLegal(s->x, 3)) m.push_back(&(b->s[s->x][3]));
    if (b->s[s->x][s->y + 1].isEmpty() && isLegal(s->x, s->y + 1)) m.push_back(&(b->s[s->x][s->y + 1]));
    if (onBoard(s->x - 1, s->y + 1) && enemyPiece(s->x - 1, s->y + 1) && isLegal(s->x - 1, s->y + 1)) m.push_back(&(b->s[s->x - 1][s->y + 1]));
    if (onBoard(s->x + 1, s->y + 1) && enemyPiece(s->x + 1, s->y + 1) && isLegal(s->x + 1, s->y + 1)) m.push_back(&(b->s[s->x + 1][s->y + 1]));

    return m;
}

bool WhitePawn::attack(Square *a) {
    return s->y + 1 == a->y && (s->x - 1 == a->x || s->x + 1 == a->x);
}