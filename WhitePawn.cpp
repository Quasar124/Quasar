#include <cmath>
#include "WhitePawn.hpp"

using namespace std;

WhitePawn::WhitePawn(Board *b, int x, int y, bool colour, bool hasMoved) : Piece(b, x, y, colour) {
    type = PAWN;
    value = 1;
    this->hasMoved = hasMoved;
}

void std::WhitePawn::move(int x, int y, int pr) {
    Piece::move(x, y, pr);
    
}

list<tuple<int, int, int>> WhitePawn::moves() {
    list<tuple<int, int, int>> m;

    if (!hasMoved && b->isEmpty(x, 2) && b->isEmpty(x, 3) && isLegal(x, 3)) m.push_back(tuple(x, 3, 0));

    if (y + 1 == size - 1) {
        if (b->isEmpty(x, y + 1) && isLegal(x, y + 1)) m.splice(m.end(), iteratePromotion(x, y + 1));
        if (isLegal(x - 1, y + 1) && enemyPiece(x - 1, y + 1)) m.splice(m.end(), iteratePromotion(x - 1, y + 1));
        if (isLegal(x + 1, y + 1) && enemyPiece(x + 1, y + 1)) m.splice(m.end(), iteratePromotion(x + 1, y + 1));
    } else {
        if (b->isEmpty(x, y + 1) && isLegal(x, y + 1)) m.push_back(tuple(x, y + 1, 0));
        if (isLegal(x - 1, y + 1) && enemyPiece(x - 1, y + 1)) m.push_back(tuple(x - 1, y + 1, 0));
        if (isLegal(x + 1, y + 1) && enemyPiece(x + 1, y + 1)) m.push_back(tuple(x + 1, y + 1, 0));
    }

    return m;
}

bool WhitePawn::attack(int x, int y) {
    return this->y + 1 == y && (this->x - 1 == x || this->x + 1 == x);
}

bool WhitePawn::isLegal(int x, int y) {
    return onBoard(x, y) && Piece::isLegal(x, y);
}