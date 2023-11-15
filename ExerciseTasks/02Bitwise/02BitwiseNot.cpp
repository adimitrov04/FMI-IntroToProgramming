#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

/*
Task:
Take an unsigned integer from console and invert its bits.
*/

int main () {
    unsigned int a;
    cin >> a;

    unsigned int bwNot = ~a;

    cout << bwNot;
}