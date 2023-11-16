#include <iostream>

#define BIT_POS 1

#define uint uint32_t

using std::cin;
using std::cout;
using std::endl;

/*
Task:
Get an unsigned integer from user, as well as a position of a bit N.
Then, ask user what to set the Nth bit to and return the number with the modified bit.
*/

uint setBit (int number, int position, bool bitValue) {
    int bitMask = BIT_POS << (position - 1);

    if ((number >> (position - 1)) % 2) {
        // If the Nth bit is 1
        if (bitValue) {
            return number;
        } else {
            return number ^ bitMask;
        }
    } else {
        // If the Nth bit is 0
        if (!bitValue) {
            return number;
        } else {
            return number ^ bitMask;
        }
    }
}

int main () {
    uint number, n;
    bool setTo;

    cout << "Enter integer: ";
    cin >> number;

    cout << "Enter position of bit to change: ";
    cin >> n;
    cout << "Change the " << n << "th bit to: ";
    cin >> setTo;

    uint changedBit = setBit(number, n, setTo);
    cout << "New number: " << changedBit << endl;


    return 0;
}
