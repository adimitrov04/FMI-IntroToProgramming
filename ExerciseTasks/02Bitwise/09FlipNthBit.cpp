#include <iostream>

#define uint uint32_t

using std::cout;
using std::cin;
using std::endl;

/*
Task:
Get an unsigned integer from user, as well as a bit position N and output the given
number with a flipped Nth bit.
*/

int flipBit (int number, int bitPos) {
    int bitMask = 1 << (bitPos - 1);
    number = number ^ bitMask;

    return number;
}

int main () {
    uint num, n;

    cout << "Enter number: ";
    cin >> num;
    cout << "Enter bit position to flip: ";
    cin >> n;

    cout << "Flipped " << n << "th bit: " << flipBit(num, n) << endl;

    return 0;
}