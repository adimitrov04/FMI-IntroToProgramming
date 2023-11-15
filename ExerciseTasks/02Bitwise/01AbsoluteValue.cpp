#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

/*
Task:
Get a number from console and output its absolute value.
*/

int main () {
    int num;
    cout << "Enter number: ";
    cin >> num;

    num = num < 0 ? (~num) + 1 : num;

    cout << "Absolute value: " << num << endl;

    return 0;
}