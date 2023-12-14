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
 * Move an element of an array from one position within that array to another,
 * wihtout changing the order of the other elements.
 * 
 * @param elem The index of the element to move
 * @param moveTo The index to move 'elem' to
*/
void moveElement (int arr[], int size, int elem, int moveTo)
{
    // Validate input
    if (moveTo < 0 || moveTo >= size)
    {
        std::cerr << "Cannot move element outside of array." << endl;
        return ;
    }

    if (elem == moveTo)
        return ;

    // Shift elements between old and new position
    int moveValue = arr[elem];
    if (elem < moveTo)
    {
        for (int i = elem; i < moveTo; i++)
        {
            arr[i] = arr[i + 1];
        }
    }
    else if (elem > moveTo)
    {
        for (int i = elem; i > moveTo; i--)
        {
            arr[i] = arr[i - 1];
        }
    }

    // Place value in new position
    arr[moveTo] = moveValue;
}

void quicksort (int arr[], int size, int lowerLim = 0)
{
    if ((size - lowerLim) <= 1)
        return ;

    int pivot = size - 1;

    for (int i = pivot - 1; i >= lowerLim; i--)
    {
        if (arr[i] > arr[pivot])
        {
            moveElement(arr, size, i, pivot);
            pivot--;
        }
    }

    quicksort(arr, pivot, 0);
    quicksort(arr, size, pivot + 1);
}

/**
 * Attempt to make a non-ZigZag array ZigZag.
 * !! WORKS ONLY IN CASES WHERE ARRAY CONTAINS NO REPETITIONS !!
 * 
 * @return false if attempt was not successful
 */
bool makeZigZag (int arr[], int size)
{
    quicksort(arr, size);

    int front = 0, back = size - 1;
    while (front < back)
    {
        moveElement(arr, size, back, front + 1);
        front += 2;
    }

    if (isZigZag(arr, size))
    {
        return true;
    }

    return false;
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

    if (isZigZag(arr, size))
    {
        std::cout << "Array is ZigZag." << endl;
        return 0;
    }

    if (makeZigZag(arr, size) == true)
    {
        std::cout << "Converted to ZigZag:" << endl;
        printArray(arr, size); std::cout << endl;
    }
    else
    {
        std::cout << "Array cannot be made ZigZag." << endl;
    }

    return 0;
}