#pragma once
#include "Piece.hpp"

namespace std {
    class Knight : public Piece {
    public:
        Knight(Board *b, int x, int y, bool colour);
        list<pair<int, int>> moves();
        bool attack(int x, int y);
        bool isLegal(int x, int y);
    };
}