#pragma once
#include <list>
#include <string>

#define size 8

namespace std {
    class Piece;

    class Board {
    public:
        Piece *s[size][size];
        Piece *whiteKing;
        Piece *blackKing;
        list<Piece *> whitePieces;
        list<Piece *> blackPieces;
        bool turn;

        /**
         * Initialises a board
         *
         * @return eqeqe
         */
        Board();

        bool attack(int x, int y, bool colour);
        bool inCheck(bool colour);
        Piece* move(Piece *p, int x, int y, int pr);
        bool isEmpty(int x, int y);
        string getFEN();
    };
    
    bool onBoard(int x, int y);
}