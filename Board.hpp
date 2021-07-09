#pragma once
#include <vector>
#include "Piece.hpp"
#include "Square.hpp"


#define size 8

namespace std {
    class Board {
    public:
        Square s[size][size];
        vector<Piece *> whitePieces;
        vector<Piece *> blackPieces;
        Board();
        bool attack(Square *s, bool colour);
        bool inCheck(bool colour);
        void move(Piece *p, Square *s);
    };
}