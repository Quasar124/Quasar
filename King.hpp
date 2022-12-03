#pragma once
#include "Piece.hpp"

namespace std {
    class King : public Piece {
    public:
        bool hasMoved;
        King(Board *b, int x, int y, bool colour, bool hasMoved);
        list<pair<int, int>> moves();
        bool attack(int x, int y);
        bool isLegal(int x, int y);
    };
}