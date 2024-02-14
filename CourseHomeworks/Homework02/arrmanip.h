#include <iostream>

#ifndef ARRAY_MANIP
#define ARRAT_MANIP

namespace arrio
{

static void readArray (int arr[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            std::cin >> arr[i];
        }
            
    }

static void printArray (int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ' ';
    }
            
}

}

/**
 * Check if a given array is sorted ascendingly or not
 */
static bool isSorted (int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }

    return true;
}

int search (const int* arr, const int size, const int search)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == search)
            return i;
    }

    return -1;
}

/**
 * Search for a value within a given [sorted] array by starting with the middle element
 * and checking whether the looked for value is larger or smaller than the value of the
 * middle element and change the range to look within. Repeat until the element is found.
 * 
 * Once an instance of the element is found, check if it is the first instance. If not,
 * find the first one.
 * 
 * @param search The value to look for.
 * @return The index, at which "search" is first found; if the value is not found in the array
 * return -1
 */
static int binarySearch (int arr[], int size, int search)
{
    int lowLim = 0, highLim = size - 1, middle;

    while (lowLim <= highLim)
    {
        middle = lowLim + ((highLim - lowLim) / 2);

        if (search == middle)
        {
            if (arr[middle - 1] == search && (middle - 1) >= 0)
            {
                if (middle - 1 == 0)
                {
                    return 0;
                } 
                else if (middle - 1 > 0)
                {
                    for (int i = middle; arr[i] == search && i >= 0; i--)
                    {
                        if (i == 0 || arr[i - 1] != search)
                        {
                            return i;
                        }
                    }
                }
            }
            else
            {
                return middle;
            }
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

static int firstInRange (int arr[], int start, int end, int search)
{
    for (int i = start + 1; i < end; i++)
    {
        if (arr[i] == search)
        {
            return i;
        }
    }

    return -1;
}

static int lastInRange (int arr[], int start, int end, int search)
{
    for (int i = end - 1; i > start; i++)
    {
        if (arr[i] == search)
        {
            return i;
        }
    }

    return -1;
}

int repetitiponsInRange (int arr[], int start, int end, int value)
{
    int count = 0;
    for (int i = start + 1; i < end - 1; i++)
    {
        if (arr[i] == value)
        {
            count++;
        }
    }

    return count;
}

static int findNext (int arr[], int size, int currIndex)
{
    for (int i = currIndex + 1; i < size; i++)
    {
        if (arr[i] == arr[currIndex])
        {
            return i;
        }
    }
    return -1;
}

#endif