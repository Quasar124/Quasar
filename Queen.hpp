#pragma once
#include "Piece.hpp"

namespace std {
    class Queen : public Piece {
    public:
        Queen(Board *b, int x, int y, bool colour);
        list<pair<int, int>> moves();
        bool attack(int x, int y);
    };
}