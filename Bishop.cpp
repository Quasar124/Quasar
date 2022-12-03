#include <cmath>
#include "Bishop.hpp"

using namespace std;

Bishop::Bishop(Board *b, int x, int y, bool colour) : Piece(b, x, y, colour) {
    type = BISHOP;
    value = 3;
}

list<pair<int, int>> Bishop::moves() {
    list<pair<int, int>> m;
    int i, j;
    
    for (i = x + 1, j = y + 1; i < size && j < size; i++, j++) {
        if (isLegal(i, j)) m.push_back(pair(i, j));
        if (!(b->isEmpty(i, j))) break;
    }

    for (i = x + 1, j = y - 1; i < size && j >= 0; i++, j--) {
        if (isLegal(i, j)) m.push_back(pair(i, j));
        if (!(b->isEmpty(i, j))) break;
    }

    for (i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
        if (isLegal(i, j)) m.push_back(pair(i, j));
        if (!(b->isEmpty(i, j))) break;
    }

    for (i = x - 1, j = y + 1; i >= 0 && j < size; i--, j++) {
        if (isLegal(i, j)) m.push_back(pair(i, j));
        if (!(b->isEmpty(i, j))) break;
    }

    return m;
}

bool Bishop::attack(int x, int y) {
    int rx = x - this->x;
    int ry = y - this->y;

    if (abs(rx) != abs(ry)) return false;

    int i, j;

    if (rx > 0) {
        if (ry > 0) {
            for (i = this->x + 1, j = this->y + 1; i < x && j < y; i++, j++) {
                if (!(b->isEmpty(i, j))) return false;
            }
        } else {
            for (i = this->x + 1, j = this->y - 1; i < x && j > y; i++, j--) {
                if (!(b->isEmpty(i, j))) return false;
            }
        }
    } else {
        if (y > 0) {
            for (i = this->x - 1, j = this->y + 1; i > x && j < y; i--, j++) {
                if (!(b->isEmpty(i, j))) return false;
            }
        } else {
            for (i = this->x - 1, j = this->y - 1; i > x && j > y; i--, j--) {
                if (!(b->isEmpty(i, j))) return false;
            }
        }
    }

    return true;
}