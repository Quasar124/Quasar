#include <cmath>
#include "Piece.hpp"
#include "Bishop.hpp"

using namespace std;

Bishop::Bishop(Board *b, Square *s, bool colour) : Piece(b, s, colour) {
    value = 3;
}

vector<Square *> Bishop::moves() {
    vector<Square *> m;
    int i, j;
    
    for (i = s->x + 1, j = s->y + 1; i < size && j < size; i++, j++) {
        if (isLegal(i, j)) m.push_back(&(b->s[i][j]));
        if (b->s[i][j].p != nullptr) break;
    }

    for (i = s->x + 1, j = s->y - 1; i < size && j >= 0; i++, j--) {
        if (isLegal(i, j)) m.push_back(&(b->s[i][j]));
        if (b->s[i][j].p != nullptr) break;
    }

    for (i = s->x - 1, j = s->y - 1; i >= 0 && j >= 0; i--, j--) {
        if (isLegal(i, j)) m.push_back(&(b->s[i][j]));
        if (b->s[i][j].p != nullptr) break;
    }

    for (i = s->x - 1, j = s->y + 1; i >= 0 && j < size; i--, j++) {
        if (isLegal(i, j)) m.push_back(&(b->s[i][j]));
        if (b->s[i][j].p != nullptr) break;
    }

    return m;
}

bool Bishop::attack(Square *a) {
    int x = a->x - s->x;
    int y = a->y - s->y;

    if (abs(x) != abs(y)) return false;

    int i, j;

    if (x > 0) {
        if (y > 0) {
            for (i = s->x + 1, j = s->y + 1; i < a->x && j < a->y; i++, j++) {
                if (b->s[i][j].p != nullptr) return false;
            }
        } else {
            for (i = s->x + 1, j = s->y - 1; i < a->x && j > a->y; i++, j--) {
                if (b->s[i][j].p != nullptr) return false;
            }
        }
    } else {
        if (y > 0) {
            for (i = s->x - 1, j = s->y + 1; i > a->x && j < a->y; i--, j++) {
                if (b->s[i][j].p != nullptr) return false;
            }
        } else {
            for (i = s->x - 1, j = s->y - 1; i > a->x && j > a->y; i--, j--) {
                if (b->s[i][j].p != nullptr) return false;
            }
        }
    }

    return true;
}