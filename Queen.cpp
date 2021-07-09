#include <cmath>
#include "Piece.hpp"
#include "Queen.hpp"

using namespace std;

Queen::Queen(Board *b, Square *s, bool colour) : Piece(b, s, colour) {
    value = 9;
}

vector<Square *> Queen::moves() {
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

    for (i = s->x + 1; i < size; i++) {
        if (isLegal(i, s->y)) m.push_back(&(b->s[i][s->y]));
        if (b->s[i][s->y].p != nullptr) break;
    }

    for (i = s->x - 1; i >= 0; i--) {
        if (isLegal(i, s->y)) m.push_back(&(b->s[i][s->y]));
        if (b->s[i][s->y].p != nullptr) break;
    }

    for (i = s->y + 1; i < size; i++) {
        if (isLegal(s->x, i)) m.push_back(&(b->s[s->x][i]));
        if (b->s[s->x][i].p != nullptr) break;
    }

    for (i = s->y - 1; i >= 0; i--) {
        if (isLegal(s->x, i)) m.push_back(&(b->s[s->x][i]));
        if (b->s[s->x][i].p != nullptr) break;
    }

    return m;
}

bool Queen::attack(Square *a) {
    int x = a->x - s->x;
    int y = a->y - s->y;

    if (x != 0 && y != 0 && abs(x) != abs(y)) return false;

    int i, j;

    if (abs(x) == abs(y)) {
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
    } else {
        if (x > 0) {
            for (i = s->x + 1; i < a->x; i++) {
                if (b->s[i][s->y].p != nullptr) return false;
            }
        } else if (x < 0) {
            for (i = s->x - 1; i > a->x; i--) {
                if (b->s[i][s->y].p != nullptr) return false;
            }
        } else if (y > 0) {
            for (i = s->y + 1; i < a->y; i++) {
                if (b->s[s->x][i].p != nullptr) return false;
            }
        } else {
            for (i = s->y - 1; i > a->y; i--) {
                if (b->s[s->x][i].p != nullptr) return false;
            }
        }
    }

    return true;
}