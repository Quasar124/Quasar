#include <cmath>
#include "Piece.hpp"
#include "Queen.hpp"

using namespace std;

Queen::Queen(Board *b, int x, int y, bool colour) : Piece(b, x, y, colour) {
    type = QUEEN;
    value = 9;
}

list<pair<int, int>> Queen::moves() {
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

    for (int i = x + 1; i < size; i++) {
        if (isLegal(i, y)) m.push_back(pair(i, y));
        if (!(b->isEmpty(i, y))) break;
    }

    for (int i = x - 1; i >= 0; i--) {
        if (isLegal(i, y)) m.push_back(pair(i, y));
        if (!(b->isEmpty(i, y))) break;
    }

    for (int i = y + 1; i < size; i++) {
        if (isLegal(x, i)) m.push_back(pair(x, i));
        if (!(b->isEmpty(x, i))) break;
    }

    for (int i = y - 1; i >= 0; i--) {
        if (isLegal(x, i)) m.push_back(pair(x, i));
        if (!(b->isEmpty(x, i))) break;
    }

    return m;
}

bool Queen::attack(int x, int y) {
    int rx = x - this->x;
    int ry = y - this->y;

    if (rx != 0 && ry != 0 && abs(rx) != abs(ry)) return false;

    int i, j;

    if (abs(rx) == abs(ry)) {
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
    } else {
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
    }

    return true;
}