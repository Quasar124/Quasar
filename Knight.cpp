#include <cmath>
#include "Knight.hpp"
#include "Square.hpp"

using namespace std;

Knight::Knight(Board *b, Square *s, bool colour) : Piece(b, s, colour) {
    value = 3;
}

vector<Square *> Knight::moves() {
    vector<Square *> m;

    if (isLegal(s->x + 1, s->y + 2)) m.push_back(&(b->s[s->x + 1][s->y + 2]));
    if (isLegal(s->x + 2, s->y + 1)) m.push_back(&(b->s[s->x + 2][s->y + 1]));
    if (isLegal(s->x + 2, s->y - 1)) m.push_back(&(b->s[s->x + 2][s->y - 1]));
    if (isLegal(s->x + 1, s->y - 2)) m.push_back(&(b->s[s->x + 1][s->y - 2]));
    if (isLegal(s->x - 1, s->y - 2)) m.push_back(&(b->s[s->x - 1][s->y - 2]));
    if (isLegal(s->x - 2, s->y - 1)) m.push_back(&(b->s[s->x - 2][s->y - 1]));
    if (isLegal(s->x - 2, s->y + 1)) m.push_back(&(b->s[s->x - 2][s->y + 1]));
    if (isLegal(s->x - 1, s->y + 2)) m.push_back(&(b->s[s->x - 1][s->y + 2]));

    return m;
}

bool Knight::attack(Square *a) {
    return (abs(s->x - a->x) == 1 && abs(s->y - a->y) == 2) || (abs(s->x - a->x) == 2 && abs(s->y - a->y) == 1);
}

bool Knight::isLegal(int x, int y) {
    return onBoard(x, y) && Piece::isLegal(x, y);
}