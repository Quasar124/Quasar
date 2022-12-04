#pragma once
#include "Piece.hpp"

namespace std {
    class Bishop : public Piece {
    public:
        Bishop(Board *b, int x, int y, bool colour);
        list<tuple<int, int, int>> moves();
        bool attack(int x, int y);
    };
}