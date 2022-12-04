#include <cmath>
#include "King.hpp"
#include "Rook.hpp"

using namespace std;

King::King(Board *b, int x, int y, bool colour, bool hasMoved) : Piece(b, x, y, colour) {
    type = KING;
    value = 0;
    this->hasMoved = hasMoved;
}

list<tuple<int, int, int>> King::moves() {
    list<tuple<int, int, int>> m;

    if (isLegal(x, y + 1)) m.push_back(tuple(x, y + 1, 0));
    if (isLegal(x + 1, y + 1)) m.push_back(tuple(x + 1, y + 1, 0));
    if (isLegal(x + 1, y)) m.push_back(tuple(x + 1, y, 0));
    if (isLegal(x + 1, y - 1)) m.push_back(tuple(x + 1, y - 1, 0));
    if (isLegal(x, y - 1)) m.push_back(tuple(x, y - 1, 0));
    if (isLegal(x - 1, y - 1)) m.push_back(tuple(x - 1, y - 1, 0));
    if (isLegal(x - 1, y)) m.push_back(tuple(x - 1, y, 0));
    if (isLegal(x - 1, y + 1)) m.push_back(tuple(x - 1, y + 1, 0));

    if (!hasMoved) {
        if (b->isEmpty(1, y) && b->isEmpty(2, y) && b->isEmpty(3, y) && ownPiece(0, y)) {
            Rook *r = dynamic_cast<Rook *>(b->s[0][y]);
            if (r && !(r->hasMoved) && !(b->inCheck(colour)) && !(b->attack(2, y, !colour)) && !(b->attack(3, y, !colour))) m.push_back(tuple(2, y, 0));
        }

        if (b->isEmpty(5, y) && b->isEmpty(6, y) && ownPiece(7, y)) {
            Rook *r = dynamic_cast<Rook *>(b->s[7][y]);
            if (r && !(r->hasMoved) && !(b->inCheck(colour)) && !(b->attack(5, y, !colour)) && !(b->attack(6, y, !colour))) m.push_back(tuple(6, y, 0));
        }
    }

    return m;
}

bool King::attack(int x, int y) {
    return abs(x - this->x) <= 1 && abs(y - this->y) <= 1;
}

bool King::isLegal(int x, int y) {
    return onBoard(x, y) && Piece::isLegal(x, y);
}