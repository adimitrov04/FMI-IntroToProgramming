#include <iostream>

using std::endl;

/*
----------------------- 03 Factorial ----------------------
Create a program which takes a number N and outputs the
factoral of N.

------------------------ EXAMPLE: -------------------------
input:  4
output: 24 (4 x 3 x 2 x 1)
-----------------------------------------------------------
*/

int factorial (int num)
{
    if (num == 0)
        return 1;
    
    return num * factorial(num - 1);
}

int main ()
{
    int num = 0;
    std::cin >> num;

    std::cout << factorial(num) << endl;

    return 0;
}