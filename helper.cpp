#include <cmath>
#include "helper.hpp"

using namespace std;

list<tuple<int, int, int>> iteratePromotion(int x, int y) {
    list<tuple<int, int, int>> m;

    m.push_back(tuple(x, y, ROOK));
    m.push_back(tuple(x, y, KNIGHT));
    m.push_back(tuple(x, y, BISHOP));
    m.push_back(tuple(x, y, QUEEN));

    return m;
}