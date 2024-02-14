#include <iostream>
#include <cmath>
#include "arrmanip.h"

using namespace arrio;
using std::endl;

/* TASK DESCRIPTION:
--------------------------------------------
Take two arrays A and B as input and check if the B could be made
by removing elements form A.
--------------------------------------------
*/

/**
 * Take two arrays as input and determine whether
 * 
 * @param sizeMain Size of the main array (sizeMain should be >= to subSize)
 * although reversing the order wont break the function.
 * 
 * @return true when all elements within subArr are found inside mainArr and are in
 * the same order; false otherwise
 */
bool isOrderedSubset (const int* mainArr, const int mainSize, const int* subArr, const int subSize)
{
    if (subSize == 1)
    {
        if (search(mainArr, mainSize, *subArr) == -1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    if (search(mainArr, mainSize, *subArr) == -1)
        return false;

    int offset = search(mainArr, mainSize, *subArr);

    return isOrderedSubset(mainArr + (offset + 1), mainSize - (offset + 1), subArr + 1, subSize - 1);
}

int main ()
{
    int* arrA = nullptr;
    int* arrB = nullptr;
    int sizeA = 0, sizeB = 0;

    std::cin >> sizeA;
    arrA = new (std::nothrow) int[sizeA];
    if (!arrA)
        return -5;
    readArray(arrA, sizeA);

    std::cin >> sizeB;
    arrB = new (std::nothrow) int[sizeB];
    if (!arrB)
    {
        delete[] arrA;
        return -5;
    }
    readArray(arrB, sizeB);

    std::cout << isOrderedSubset(arrA, sizeA, arrB, sizeB) << endl;

    delete[] arrA;
    delete[] arrB;

    return 0;
}