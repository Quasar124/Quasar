#pragma once
#include "Piece.hpp"

namespace std {
    class King : public Piece {
    public:
        bool hasMoved;
        King(Board *b, Square *s, bool colour, bool hasMoved);
        vector<Square *> moves();
        bool attack(Square *a);
        bool isLegal(int x, int y);
    };
}