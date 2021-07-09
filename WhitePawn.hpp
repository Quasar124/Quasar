#pragma once
#include "Piece.hpp"

namespace std {
    class WhitePawn : public Piece {
    public:
        bool hasMoved;
        WhitePawn(Board *b, Square *s, bool colour, bool hasMoved);
        vector<Square *> moves();
        bool attack(Square *a);
    };
}