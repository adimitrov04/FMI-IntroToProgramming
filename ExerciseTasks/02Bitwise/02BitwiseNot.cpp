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
    short unsigned int a;
    cin >> a;

    short unsigned int bwNot = ~a;

    cout << bwNot;
}