#pragma once
#include <vector>
#include "Board.hpp"
#include "Square.hpp"

#define white true
#define black false

namespace std {
    class Piece {
    public:
        Board *b;
        Square *s;
        bool colour;
        int value;
        Piece(Board *b, Square *s, bool colour);
        virtual vector<Square *> moves() = 0;
        virtual bool attack(Square *a);
        bool ownPiece(int x, int y);
        bool enemyPiece(int x, int y);
        bool isLegal(int x, int y);
    };
}