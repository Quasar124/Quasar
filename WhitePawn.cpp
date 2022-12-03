#include <cmath>
#include "WhitePawn.hpp"

using namespace std;

WhitePawn::WhitePawn(Board *b, int x, int y, bool colour, bool hasMoved) : Piece(b, x, y, colour) {
    type = PAWN;
    value = 1;
    this->hasMoved = hasMoved;
}

list<pair<int, int>> WhitePawn::moves() {
    list<pair<int, int>> m;

    if (!hasMoved && b->isEmpty(x, 2) && b->isEmpty(x, 3) && isLegal(x, 3)) m.push_back(pair(x, 3));
    if (b->isEmpty(x, y + 1) && isLegal(x, y + 1)) m.push_back(pair(x, y + 1));
    if (isLegal(x - 1, y + 1) && enemyPiece(x - 1, y + 1)) m.push_back(pair(x - 1, y + 1));
    if (isLegal(x + 1, y + 1) && enemyPiece(x + 1, y + 1)) m.push_back(pair(x + 1, y + 1));

    return m;
}

bool WhitePawn::attack(int x, int y) {
    return this->y + 1 == y && (this->x - 1 == x || this->x + 1 == x);
}

bool WhitePawn::isLegal(int x, int y) {
    return onBoard(x, y) && Piece::isLegal(x, y);
}