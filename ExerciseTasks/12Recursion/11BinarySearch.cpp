#include <iostream>

using std::endl;

/*
-------------------- 11 Binary Search ---------------------
Read a dynamic array and create a recursive binary search
function to look for a given number. Output the position
in the array at which the element is found.

------------------------ EXAMPLE: -------------------------
input:  1 2 3 4 4 6
        4
output: 5
-----------------------------------------------------------
*/

int minElem (int* arr, const int size)
{
    int min = *arr;
    const int* pMin = arr;

    for (int i = 1; i < size; i++)
    {
        if (*(arr + i) < min)
        {
            min = *(arr + i);
            pMin = arr + i;
        }
    }

    return pMin - arr;
}

void selectionSort (int* arr, const int size)
{
    if (size == 0)
        return ;

    std::swap(*arr, *(arr + minElem(arr, size)));
    selectionSort(arr + 1, size - 1);
}

void readArray (int* arr, const int size)
{
    if (size == 0)
        return ;

    std::cin >> *arr;
    readArray(arr + 1, size - 1);
}

void printArray (const int* arr, const int size)
{
    if (size == 0)
        return ;
    
    std::cout << *arr << ' ';
    printArray(arr + 1, size - 1);
}

static int binSearch_helper (const int* arr, const int size, const int search, int start, int end)
{
    const int* mid = (arr + start) + ((end - start) / 2);

    if (size < 1)
        return -1;
    
    if (search == *mid)
    {
        if (*(mid - 1) != search || mid == arr)
        {
            return mid - arr;
        }
        else
        {
            while (*(mid - 1) == search && mid > arr)
            {
                mid--;
            }
            
            return mid - arr;
        }
    }
    
    if (search < *mid)
    {
        return binSearch_helper(arr, size, search, start, (mid - arr) - 1);
    }
    else if (search > *mid)
    {
        return binSearch_helper(arr, size, search, (mid - arr) + 1, end);
    }

    return 0;
}

int binarySearch (const int* arr, const int size, const int search)
{
    return binSearch_helper(arr, size, search, 0, size - 1);
}

int* createArray (size_t& size)
{
    int* ptr = nullptr;
    ptr = new (std::nothrow) int[size];

    if (!ptr)
        return nullptr;

    return ptr; 
}

int main ()
{
    size_t size = 0;
    std::cin >> size;

    int* arr = createArray(size);
    if (arr == nullptr)
    {
        delete[] arr;
        std::cerr << "Could not allocate memory. Terminating..." << endl;
        return -1;
    }

    readArray(arr, size);

    int search = 0;
    std::cin >> search;
    
    selectionSort(arr, size);
    printArray(arr, size); std::cout << endl;
    
    std::cout << binarySearch(arr, size, search) << endl;

    delete[] arr;

    return 0;
}