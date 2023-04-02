#pragma once
#include <list>
#include <stack>
#include <string>
#include "Board.hpp"

#define size 8

namespace std {
    class Game {
    public:
        Board b;
        stack<tuple<Piece*, int, int, Piece*, int, int, Piece*>> moves;
        string getFEN();
    };
}