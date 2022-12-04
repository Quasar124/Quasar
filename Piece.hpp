#pragma once
#include <list>
#include "Board.hpp"
#include "helper.hpp"

#define white  true
#define black  false

#define PAWN   1
#define ROOK   2
#define KNIGHT 3
#define BISHOP 4
#define QUEEN  5
#define KING   6

namespace std {
    class Piece {
    public:
        Board *b;
        int x;
        int y;
        bool colour;
        int type;
        int value;
        Piece(Board *b, int x, int y, bool colour);
        virtual list<tuple<int, int, int>> moves() = 0;
        virtual bool attack(int x, int y) = 0;
        bool ownPiece(int x, int y);
        bool enemyPiece(int x, int y);
        bool isLegal(int x, int y);
    };
}