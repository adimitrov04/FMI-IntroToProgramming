#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/*
Task:
Swap the values of two given integers using only bitwise operations.
*/
void bitwiseSwap (int& num1, int& num2) {
    // n1: 0001
    // n2: 0010
    num1 = num1 ^ num2; // n1: 0011; n2: 0010
    num2 = num2 ^ num1; // n1: 0011; n2: 0001
    num1 = num1 ^ num2; // n1: 0010; n2: 0001
}

int main () {
    int a, b;

    cout << "Enter A: ";
    cin >> a;
    cout << "Enter B: ";
    cin >> b;

    bitwiseSwap(a, b);

    cout << "A: " << a << endl;
    cout << "B: " << b << endl;

    return 0;
}