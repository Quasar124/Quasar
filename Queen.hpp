#pragma once
#include "Piece.hpp"

namespace std {
    class Queen : public Piece {
    public:
        Queen(Board *b, Square *s, bool colour);
        vector<Square *> moves();
        bool attack(Square *a);
    };
}