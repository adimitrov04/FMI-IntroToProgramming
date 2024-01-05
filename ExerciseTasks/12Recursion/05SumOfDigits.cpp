#include <iostream>
#include <cmath>

using std::endl;

/*
-------------------- 05 Sum of Digits ---------------------
Create a recursive function which returns the sum of the
digits of a given integer.

------------------------ EXAMPLE: -------------------------
input:  1241
output: 8
-----------------------------------------------------------
*/

int sumOfDigits (int num)
{
    num = abs(num); // We don't care if it's negative or not

    if (num == 0)
        return 0;
    
    int currentDigit = num % 10; // Get the right-most digit
    int remaining = num / 10;

    return currentDigit + sumOfDigits(remaining);
}

int main ()
{
    int num = 0;
    std::cin >> num;

    std::cout << sumOfDigits(num) << endl;

    return 0;
}