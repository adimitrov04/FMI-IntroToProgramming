#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/*
Task:
Given a number between in the range [0; 31], output the Nth power of 2.
*/

int main () {
    const int indexZero = 1; // 2 to the power of zero, used as the first place
    
    int n;
    cout << "Enter exponent N (between 0 and 31): ";
    cin >> n;

    int nthPower = (indexZero << n); // Shift to the Nth bit aka the Nth power of 2

    cout << "2 ^ " << n << " = " << nthPower << endl; 

    return 0;
}