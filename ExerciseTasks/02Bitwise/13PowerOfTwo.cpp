#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/*
Task:
Check if a given number is a power of two.
*/

bool isPowerOfTwo (int num, int SIZE = 32) {
    if (num <= 0)
        return false;
    
    int activeBits = 0;

    for (int i = 0; i < SIZE; i++) {
        if ((1 << i) & num) {
            activeBits++;
        }
        if (activeBits > 1) {
            return false;
            break;
        }
    }
    
    return true;
}

int main () {
    int32_t num;

    cout << "Enter number: ";
    cin >> num;

    if (isPowerOfTwo(num)) {
        cout << num << " is a power of 2." << endl;
    } else {
        cout << num << " is not a power of 2." << endl;
    }

    return 0;
}