#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/*
Task:
Get a 4-digit number from the console and output the sum of its
digits.
*/

int main () {
    int num = 0;

    cout << "Enter 4-digit number: ";
    cin >> num;

    if ((num < 1000) || (num > 9999)) {
        cout << "Error: invalid number. 4-digit number required." << endl;
        return 1;
    } else {
        int dig1 = num / 1000;
        int dig2 = (num % 1000) / 100;
        int dig3 = (num % 100) / 10;
        int dig4 = num % 10;

        int sumOfDigits = dig1 + dig2 + dig3 + dig4;
        cout << dig1 << " + " << dig2 << " + " << dig3 << " + " << dig4 << " = " << sumOfDigits << endl;
    }

    return 0;
}