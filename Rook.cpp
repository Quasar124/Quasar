#include "Rook.hpp"

using namespace std;

Rook::Rook(Board *b, int x, int y, bool colour, bool hasMoved) : Piece(b, x, y, colour) {
    type = ROOK;
    value = 5;
    this->hasMoved = hasMoved;
}

list<tuple<int, int, int>> Rook::moves() {
    list<tuple<int, int, int>> m;
    
    for (int i = x + 1; i < size; i++) {
        if (isLegal(i, y)) m.push_back(tuple(i, y, 0));
        if (!(b->isEmpty(i, y))) break;
    }

    for (int i = x - 1; i >= 0; i--) {
        if (isLegal(i, y)) m.push_back(tuple(i, y, 0));
        if (!(b->isEmpty(i, y))) break;
    }

    for (int i = y + 1; i < size; i++) {
        if (isLegal(x, i)) m.push_back(tuple(x, i, 0));
        if (!(b->isEmpty(x, i))) break;
    }

    for (int i = y - 1; i >= 0; i--) {
        if (isLegal(x, i)) m.push_back(tuple(x, i, 0));
        if (!(b->isEmpty(x, i))) break;
    }

    return m;
}

bool Rook::attack(int x, int y) {
    int rx = x - this->x;
    int ry = y - this->y;

    if (rx != 0 && ry != 0) return false;

    int i, j;

    if (rx > 0) {
        for (i = this->x + 1; i < x; i++) {
            if (!(b->isEmpty(i, y))) return false;
        }
    } else if (rx < 0) {
        for (i = this->x - 1; i > x; i--) {
            if (!(b->isEmpty(i, y))) return false;
        }
    } else if (ry > 0) {
        for (i = this->y + 1; i < y; i++) {
            if (!(b->isEmpty(x, i))) return false;
        }
    } else {
        for (i = this->y - 1; i > y; i--) {
            if (!(b->isEmpty(x, i))) return false;;
        }
    }

    return true;
}