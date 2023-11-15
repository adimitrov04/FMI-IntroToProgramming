#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/*
Task:
Get a 5-digit number from console and determine whether or not it is
a palindrome.
*/

int main () {
    cout << "Enter a 5-digit number: ";
    int num;
    cin >> num;

    bool isPalindrome = 0;
    if ((num < 10000) || (num > 99999)) {
        cout << "Error: invalid number. 5-digit number required." << endl;
        return 1;
    } else {
        int dig1 = num / 10000;
        int dig2 = (num % 10000) / 1000;
        int dig3 = (num % 1000) / 100;
        int dig4 = (num % 100) / 10;
        int dig5 = num % 10;

        if (dig1 == dig5) {
            if (dig2 == dig4) {
                isPalindrome = 1;
            }
        }
    }

    cout << isPalindrome << endl;

    return 0;
}