#pragma once
#include "Square.hpp"

using namespace std;

Square::Square() {
    p = nullptr;
}

void Square::setXY(int x, int y) {
    this->x = x;
    this->y = y;
}

bool Square::isEmpty() {
    return p == nullptr;
}

bool onBoard(int x, int y) {
    return x > -1 && x < size && y > -1 && y < size;
}