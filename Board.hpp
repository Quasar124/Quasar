#pragma once
#include <list>
#include "Piece.hpp"

#define size 8

namespace std {
    class Board {
    public:
        Piece *s[size][size];
        list<Piece *> whitePieces;
        list<Piece *> blackPieces;
        Board();
        bool attack(int x, int y, bool colour);
        bool inCheck(bool colour);
        void move(Piece *p, int x, int y);
        bool isEmpty(int x, int y);
    };
    
    bool onBoard(int x, int y);
}