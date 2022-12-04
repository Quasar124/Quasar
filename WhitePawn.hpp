#pragma once
#include "Piece.hpp"

namespace std {
    class WhitePawn : public Piece {
    public:
        bool hasMoved;
        WhitePawn(Board *b, int x, int y, bool colour, bool hasMoved);
        list<tuple<int, int, int>> moves();
        bool attack(int x, int y);
        bool isLegal(int x, int y);
    };
}