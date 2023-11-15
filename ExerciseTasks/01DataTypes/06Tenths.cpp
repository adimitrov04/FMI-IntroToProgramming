#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/*
Task:
Take integer from console and output the digit of its tenths.
*/

int main () {
    int num = 0;

    cout << "Enter number: ";
    cin >> num;

    int tenth = (num % 100) / 10;

    cout << tenth << endl;

    return 0;
}