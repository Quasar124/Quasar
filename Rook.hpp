#pragma once
#include "Piece.hpp"

namespace std {
    class Rook : public Piece {
    public:
        bool hasMoved;
        Rook(Board *b, int x, int y, bool colour, bool hasMoved);
        list<tuple<int, int, int>> moves();
        bool attack(int x, int y);
    };
}