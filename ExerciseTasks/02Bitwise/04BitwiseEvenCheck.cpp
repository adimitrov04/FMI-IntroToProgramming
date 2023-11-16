#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/*
Task:
Read a number from console and determine whether or not it is even using bitwise operations.
*/

int main ()
{
    int num;
    cout << "Enter number: ";
    cin >> num;

    if (num & 1) {
        cout << num << " is odd" << endl;
    } else {
        cout << num << " is even" << endl;
    }

    return 0;
}