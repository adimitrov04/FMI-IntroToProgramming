#include <iostream>
#include <cmath>

using std::endl;

/**
 * ------------------------------ Make ZigZag ------------------------------
 * Read an array and determine whether or not it is "ZigZag" - i.e.
 * whether each element of the array is strictly larger or smaller than its
 * neighbouring elements.
 * 
 * Also determine whether or not the given array CAN be made ZigZag, and if
 * possible - make it ZigZag.
 */

const int MAX_SIZE = 5000; // Global max. array size

// ---------- FUNCTIONS ----------

void readArray (int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }
}

void printArray (const int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ' ';
    }
}

/**
 * Copy the contents of one array into another. 
 */
void copyArray (const int source[], int size, int copy[])
{
    for (int i = 0; i < size; i++)
    {
        copy[i] = source[i];
    }
}

/**
 * Check if array is ZigZag.
 */
bool isZigZag (const int arr[], int size)
{
    if (size <= 2)
        return true;

    for (int i = 1; i < (size - 1); i++)
    {
        if ((arr[i] == arr[i + 1]) || (arr[i] == arr[i - 1]))
        {
            return false;
        }
        else if ((arr[i] > arr[i - 1] && arr[i] < arr[i + 1]) ||
                 (arr[i] < arr[i - 1] && arr[i] > arr[i + 1]))
        {
            return false;
        }
    }

    return true;
}

/**
 * Attempt to make a non-ZigZag array ZigZag.
 * !! WORKS ONLY IN CASES WHERE ARRAY CONTAINS NO REPETITIONS !!
 * 
 * @return false if attempt was not successful
 */
bool makeZigZag (int arr[], int size)
{
    
}

// ---------- MAIN ----------

int main ()
{
    int arr[MAX_SIZE] = {0,};
    int size = 0;

    // Input validation
    std::cin >> size;
    while (size > MAX_SIZE)
    {
        size = 0;
        std::cerr << "Size is too big. Please enter a size <= " << MAX_SIZE << ":" << endl;
        std::cin >> size;
    }

    readArray(arr, size);

    

    return 0;
}