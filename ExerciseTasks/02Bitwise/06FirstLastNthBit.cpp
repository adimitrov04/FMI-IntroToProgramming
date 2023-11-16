#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

/*
Task:
Output the first, last, and Nth bit of a given unsigned, 32-bit integer.
*/

int main () {
    int number, n;
    const int posZero = 1; // 2 to the power of 0
    
    cout << "Enter a number: ";
    cin >> number;
    cout << "Enter a Nth bit position: ";
    cin >> n;

    int LAST_BIT_MASK = posZero << 31;
    int NTH_BIT_MASK = posZero << (n - 1);

    bool firstBit = (number & 1);
    bool lastBit = (number & LAST_BIT_MASK) >> 31;
    bool nthBit = (number & NTH_BIT_MASK) >> (n - 1);

    cout << "First bit: " << firstBit << endl;
    cout << n << "th bit: " << nthBit << endl;
    cout << "Last bit: " << lastBit << endl;

    return 0;
}