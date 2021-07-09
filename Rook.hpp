#pragma once
#include "Piece.hpp"

namespace std {
    class Rook : public Piece {
    public:
        bool hasMoved;
        Rook(Board *b, Square *s, bool colour, bool hasMoved);
        vector<Square *> moves();
        bool attack(Square *a);
    };
}