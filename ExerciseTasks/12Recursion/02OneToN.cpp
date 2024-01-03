#include <iostream>

using std::endl;

/*
--------------------- 01 PrintNumbers ---------------------
Create a program which takes a number N and prints all
numbers from 1 to N using a recursive function.

------------------------ EXAMPLE: -------------------------
input:  5
output: 1 2 3 4 5
-----------------------------------------------------------
*/

void printNumbers (int n)
{
    if (n > 0)
    {
        printNumbers(n - 1);
        std::cout << n << ' ';
    }
}

int main ()
{
    int n;
    std::cin >> n;

    printNumbers(n);
}