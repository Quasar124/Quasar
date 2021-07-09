#include "Piece.hpp"
#include "Rook.hpp"

using namespace std;

Rook::Rook(Board *b, Square *s, bool colour, bool hasMoved) : Piece(b, s, colour) {
    value = 5;
    this->hasMoved = hasMoved;
}

vector<Square *> Rook::moves() {
    vector<Square *> m;
    
    for (int i = s->x + 1; i < size; i++) {
        if (isLegal(i, s->y)) m.push_back(&(b->s[i][s->y]));
        if (b->s[i][s->y].p != nullptr) break;
    }

    for (int i = s->x - 1; i >= 0; i--) {
        if (isLegal(i, s->y)) m.push_back(&(b->s[i][s->y]));
        if (b->s[i][s->y].p != nullptr) break;
    }

    for (int i = s->y + 1; i < size; i++) {
        if (isLegal(s->x, i)) m.push_back(&(b->s[s->x][i]));
        if (b->s[s->x][i].p != nullptr) break;
    }

    for (int i = s->y - 1; i >= 0; i--) {
        if (isLegal(s->x, i)) m.push_back(&(b->s[s->x][i]));
        if (b->s[s->x][i].p != nullptr) break;
    }

    return m;
}

bool Rook::attack(Square *a) {
    int x = a->x - s->x;
    int y = a->y - s->y;

    if (x != 0 && y != 0) return false;

    if (x > 0) {
        for (int i = s->x + 1; i < a->x; i++) {
            if (b->s[i][s->y].p != nullptr) return false;
        }
    } else if (x < 0) {
        for (int i = s->x - 1; i > a->x; i--) {
            if (b->s[i][s->y].p != nullptr) return false;
        }
    } else if (y > 0) {
        for (int i = s->y + 1; i < a->y; i++) {
            if (b->s[s->x][i].p != nullptr) return false;
        }
    } else {
        for (int i = s->y - 1; i > a->y; i--) {
            if (b->s[s->x][i].p != nullptr) return false;
        }
    }

    return true;
}