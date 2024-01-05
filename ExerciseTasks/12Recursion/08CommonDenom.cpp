#include <iostream>
#include <cmath>

using std::endl;

/*
----------------- 08 Common Denominator -------------------
Find the biggest common denominator of two numbers using
a recursive function.

------------------------ EXAMPLE: -------------------------
input:  6 9
output: 3
-----------------------------------------------------------
*/

int max (int val1, int val2)
{
    if (val1 >= val2)
    {
        return val1;
    }
    else
    {
        return val2;
    }
}

int min (int val1, int val2)
{
    if (val1 <= val2)
    {
        return val1;
    }
    else
    {
        return val2;
    }
}

/**
 * Find the biggest common divisor of two numbers
 * ---- HELPER FUNCTION -----
 * !! DOES NOT WORK WELL FOR NEGATIVES !!
 */
static int bcd (const int val1, const int val2, int step)
{
    int bigger = max(val1, val2);
    int smaller = min(val1, val2);

    int denom = smaller / step; // The number to divide by
    std::cout << bigger << '/' << denom << endl;
    
    if (step > abs(smaller))
        return 1;

    if (bigger % denom == 0)
        return denom;
    
    return bcd(smaller, bigger, (step + 1));
}

int bcd (const int val1, const int val2)
{
    return bcd(val1, val2, 1);
}

int main ()
{
    int num1 = 0, num2 = 0;
    std::cin >> num1 >> num2;

    std::cout << bcd(num1, num2) << endl;

    return 0;
}