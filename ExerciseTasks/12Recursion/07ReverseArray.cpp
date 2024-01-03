#include <iostream>

using std::endl;

const int MAX_SIZE = 5000; // Global max array size

/*
-------------------- 07 Reverse Array ---------------------
Reverse a given array using recursion without using
internal functions.

------------------------ EXAMPLE: -------------------------
input:  1 2 3 4 5
output: 5 4 3 2 1
-----------------------------------------------------------
*/

void readArray (int arr[], const int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }
}

void printArray (const int arr[], const int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ' ';
    }
}

void my_swap (int& val1, int& val2)
{
    val1 = val1 - val2;
    val2 += val1;
    val1 = val2 - val1;
}

void reverseArray (int* arr, const int size)
{
    int* front = arr;
    int* back = arr + (size - 1);
    
    if (front == back || front > back)
        return ;

    my_swap(*front, *back);
    printArray(arr, size); std::cout << endl;
    reverseArray((arr + 1), (size - 2));
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

    reverseArray(arr, size);
    printArray(arr, size);

    return 0;
}