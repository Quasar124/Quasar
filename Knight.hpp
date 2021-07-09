#pragma once
#include "Piece.hpp"

namespace std {
    class Knight : public Piece {
    public:
        Knight(Board *b, Square *s, bool colour);
        vector<Square *> moves();
        bool attack(Square *a);
        bool isLegal(int x, int y);
    };
}