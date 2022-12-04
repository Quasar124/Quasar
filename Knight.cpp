#include <cmath>
#include "Knight.hpp"

using namespace std;

Knight::Knight(Board *b, int x, int y, bool colour) : Piece(b, x, y, colour) {
    type = KNIGHT;
    value = 3;
}

list<tuple<int, int, int>> Knight::moves() {
    list<tuple<int, int, int>> m;

    if (isLegal(x + 1, y + 2)) m.push_back(tuple(x + 1, y + 2, 0));
    if (isLegal(x + 2, y + 1)) m.push_back(tuple(x + 2, y + 1, 0));
    if (isLegal(x + 2, y - 1)) m.push_back(tuple(x + 2, y - 1, 0));
    if (isLegal(x + 1, y - 2)) m.push_back(tuple(x + 1, y - 2, 0));
    if (isLegal(x - 1, y - 2)) m.push_back(tuple(x - 1, y - 2, 0));
    if (isLegal(x - 2, y - 1)) m.push_back(tuple(x - 2, y - 1, 0));
    if (isLegal(x - 2, y + 1)) m.push_back(tuple(x - 2, y + 1, 0));
    if (isLegal(x - 1, y + 2)) m.push_back(tuple(x - 1, y + 2, 0));

    return m;
}

bool Knight::attack(int x, int y) {
    return (abs(this->x - x) == 1 && abs(this->y - y) == 2) || (abs(this->x - x) == 2 && abs(this->y - y) == 1);
}

bool Knight::isLegal(int x, int y) {
    return onBoard(x, y) && Piece::isLegal(x, y);
}