#pragma once
#include <list>
#include <string>

#define size 8

namespace std {
    class Piece;

    class Board {
    public:
        Piece *s[size][size];
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
        void move(Piece *p, int x, int y);
        bool isEmpty(int x, int y);
        void place(Piece *p);
        string getFEN();
    };
    
    bool onBoard(int x, int y);
}