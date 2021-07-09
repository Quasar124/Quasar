#pragma once
#include "Piece.hpp"

namespace std {
    class Bishop : public Piece {
    public:
        Bishop(Board *b, Square *s, bool colour);
        vector<Square *> moves();
        bool attack(Square *a);
    };
}