#include <iostream>
#include "Board.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
    Board x;
    
    cout << x.getFEN() << endl;

    return 0;
}