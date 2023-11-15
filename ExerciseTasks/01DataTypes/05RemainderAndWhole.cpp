#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Task:
Given 2 whole numbers, divide them and output the whole part of the result
and the remainder.
*/

int main () {
    int a, b;

    cout << "Enter a: ";
    cin >> a;
    
    cout << "Enter b: ";
    cin >> b;

    if (b == 0) {
        cout << "Cannot divide by 0." << endl;
        return 1;
    } else {
        cout << "Whole part: " << (a / b) << endl;
        cout << "Remainder: " << (a % b) << endl;
    }

    return 0;
}