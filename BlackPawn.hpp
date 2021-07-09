#pragma once
#include "Piece.hpp"

namespace std {
    class BlackPawn : public Piece {
    public:
        bool hasMoved;
        BlackPawn(Board *b, Square *s, bool colour, bool hasMoved);
        vector<Square *> moves();
        bool attack(Square *a);
    };
}