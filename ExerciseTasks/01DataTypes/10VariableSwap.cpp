#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/*
Task:
Given 2 variables a and b, switch their values without using a
third variable.
*/

int main () {
    int a, b;
    cout << "A: ";
    cin >> a;
    cout << "B: ";
    cin >> b;

    a = a - b;
    b = a + b;
    a = b - a;

    cout << endl << "Swapped A: " << a << endl;
    cout << "Swapped B: " << b << endl;

    return 0;
}