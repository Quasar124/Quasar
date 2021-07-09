#include <cmath>
#include "Square.hpp"
#include "BlackPawn.hpp"

using namespace std;

BlackPawn::BlackPawn(Board *b, Square *s, bool colour, bool hasMoved) : Piece(b, s, colour) {
    value = 1;
    this->hasMoved = hasMoved;
}

vector<Square *> BlackPawn::moves() {
    vector<Square *> m;

    if (!hasMoved && b->s[s->x][5].isEmpty() && b->s[s->x][4].isEmpty() && isLegal(s->x, 4)) m.push_back(&(b->s[s->x][4]));
    if (b->s[s->x][s->y - 1].isEmpty() && isLegal(s->x, s->y - 1)) m.push_back(&(b->s[s->x][s->y - 1]));
    if (onBoard(s->x - 1, s->y - 1) && enemyPiece(s->x - 1, s->y - 1) && isLegal(s->x - 1, s->y - 1)) m.push_back(&(b->s[s->x - 1][s->y - 1]));
    if (onBoard(s->x + 1, s->y - 1) && enemyPiece(s->x + 1, s->y - 1) && isLegal(s->x + 1, s->y - 1)) m.push_back(&(b->s[s->x + 1][s->y - 1]));

    return m;
}

bool BlackPawn::attack(Square *a) {
    return s->y - 1 == a->y && (s->x - 1 == a->x || s->x + 1 == a->x);
}