#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

/* TASK DESCRIPTION:
--------------------------------------------
Take two arrays A and B as input and check if the B could be made
by removing elements form A.
--------------------------------------------
*/

const int MAX_SIZE = 1000;

void readArray (int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    
}

void printArray (int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ' ';
    }
    
}

int binarySearch (int arr[], int size, int search)
{
    int lowLim = 0, highLim = size - 1, middle;

    while (lowLim <= highLim)
    {
        middle = lowLim + ((highLim - lowLim) / 2);

        if (search == middle)
        {
            return middle;
        }

        if (search > middle)
        {
            lowLim = middle + 1;
        }
        else
        {
            highLim = middle - 1;
        }
    }

    return -1;
}

/**
 * Take two arrays as input and determine whether
 * 
 * @param sizeMain Size of the main array (sizeMain should be >= to subSize)
 * although reversing the order wont break the function.
 * 
 * @return true when all elements within subArr are found inside mainArr;
 * false if otherwise
 */
bool isSubset (int mainArr[], int mainSize, int subArr[], int subSize)
{
    for (int i  = 0; i < subSize; i++)
    {
        if (binarySearch(mainArr, mainSize, subArr[i]) == -1)
        {
            return false;
        }
    }

    return true;
}

int main ()
{
    int arrA[MAX_SIZE] = {0,}, sizeA;
    int arrB[MAX_SIZE] = {0,}, sizeB;

    cin >> sizeA;
    readArray(arrA, sizeA);
    readArray(arrB, sizeB);

    return 0;
}