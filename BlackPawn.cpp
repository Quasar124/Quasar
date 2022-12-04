#include <cmath>
#include "BlackPawn.hpp"

using namespace std;

BlackPawn::BlackPawn(Board *b, int x, int y, bool colour, bool hasMoved) : Piece(b, x, y, colour) {
    type = PAWN;
    value = 1;
    this->hasMoved = hasMoved;
}

list<tuple<int, int, int>> BlackPawn::moves() {
    list<tuple<int, int, int>> m;

    if (!hasMoved && b->isEmpty(x, size - 3) && b->isEmpty(x, size - 4) && isLegal(x, size - 4)) m.push_back(tuple(x, size - 4, 0));

    if (y - 1 == 0) {
        if (b->isEmpty(x, y - 1) && isLegal(x, y - 1)) m.splice(m.end(), iteratePromotion(x, y - 1));
        if (isLegal(x - 1, y - 1) && enemyPiece(x - 1, y - 1)) m.splice(m.end(), iteratePromotion(x - 1, y - 1));
        if (isLegal(x + 1, y - 1) && enemyPiece(x + 1, y - 1)) m.splice(m.end(), iteratePromotion(x + 1, y - 1));
    } else {
        if (b->isEmpty(x, y - 1) && isLegal(x, y - 1)) m.push_back(tuple(x, y - 1, 0));
        if (isLegal(x - 1, y - 1) && enemyPiece(x - 1, y - 1)) m.push_back(tuple(x - 1, y - 1, 0));
        if (isLegal(x + 1, y - 1) && enemyPiece(x + 1, y - 1)) m.push_back(tuple(x + 1, y - 1, 0));
    }

    return m;
}

bool BlackPawn::attack(int x, int y) {
    return this->y - 1 == y && (this->x - 1 == x || this->x + 1 == x);
}

bool BlackPawn::isLegal(int x, int y) {
    return onBoard(x, y) && Piece::isLegal(x, y);
}