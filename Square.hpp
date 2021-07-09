#pragma once
#include <vector>
#include "Piece.hpp"

namespace std {
    class Square {
    public:
        int x;
        int y;
        Piece *p;
        Square();
        void setXY(int x, int y);
        bool isEmpty();
    };

    bool onBoard(int x, int y);
}