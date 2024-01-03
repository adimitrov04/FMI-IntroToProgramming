#include <iostream>

using std::endl;

const int MAX_SIZE = 5000; // Global max array size

/*
--------------------- 06 Find Largest ---------------------
Create a recursive function which returns the largest
member of an array of integers.

------------------------ EXAMPLE: -------------------------
input:  1 3 1 5 2 3
output: 5
-----------------------------------------------------------
*/

void readArray (int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cin >> *(arr + i);
    }
}

int findLargest (const int* arr, const int size)
{
    int max = *(arr + (size - 1));

    if (size == 0)
        return 0;

    if (max < findLargest(arr, (size - 1)))
        max = findLargest(arr, (size - 1));

    return max;
}

int main ()
{
    int arr[MAX_SIZE] = {0,};
    
    int size = 0;
    std::cin >> size;
    // Input validation
    while (size > MAX_SIZE)
    {
        size = 0;
        std::cerr << "Max size exceeded. Please enter a size <= " << MAX_SIZE << endl;
        std::cin >> size;
    }

    readArray(arr, size);
    
    std::cout << findLargest(arr, size) << endl;

    return 0;
}