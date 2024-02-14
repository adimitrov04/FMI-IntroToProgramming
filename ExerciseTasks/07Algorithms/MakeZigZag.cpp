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
 * Find the first instance of an element within a given range.
 * 
 * @param rStart, rEnd The start and end of the range
 * DEFAULT: [0; size - 1]
 * 
 * @return The index where the searched for element is first found
 * @return -1 if the element is not found within the given range
 */
int search (const int arr[], int size, int search, int rStart = 0, int rEnd = 0)
{
    if (rEnd == 0)
        rEnd = size - 1;

    for (int i = rStart; i <= rEnd; i++)
    {
        if (arr[i] == search)
            return i;
    }

    return -1;
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

/**
 * Quicksort algorithm.
 * 
 * @param ascending default - true
 */
void quicksort (int arr[], int size, bool ascending = true, int lowerLim = 0)
{
    if ((size - lowerLim) <= 1)
        return ;

    int pivot = (size - 1);

    if (ascending == true) // Sort ascending
    {
        for (int i = pivot - 1; i >= lowerLim; i--)
        {
            if (arr[i] > arr[pivot])
            {
                moveElement(arr, size, i, pivot);
                pivot--;
            }
        }
    }
    else
    {
        for (int i = pivot - 1; i >= lowerLim; i--)
        {
            if (arr[i] < arr[pivot])
            {
                moveElement(arr, size, i, pivot);
                pivot--;
            }
        }
    }

    quicksort(arr, size, ascending, pivot + 1);
    quicksort(arr, pivot, ascending, 0);
}

/**
 * Gather all repetitions of a given element within an array after the index of the
 * given element.
 * 
 * @param elem The index of the element; all repetitions of the element after the given
 * index will gather directly after this index
 */
void gatherAllRepetitions (int arr[], int size, int elem)
{
    while (search(arr, size, arr[elem], elem + 1, size - 1) != -1)
    {
        moveElement(arr, size, search(arr, size, arr[elem], elem + 1), elem + 1);
        elem++;
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


int countRepetitions (const int arr[], int size, int elem)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == elem)
            count++;
    }

    return count;
}

/**
 * Find the first instance *forward* of an element which is not a repetition of the current one.
 * 
 * @param current The starting index
 * 
 * @return The first index forward which is not a repetition of the current element.
 * @return -1 if there is no such index after current one
 */
int findNextUnique (const int arr[], int size, int current)
{
    int nextUnique = -1;

    for (int i = current + 1; i < size; i++)
    {
        if (arr[i] != arr[current])
        {
            nextUnique = i;
            break;
        }
    }

    return nextUnique;
}

/**
 * Find the most repeated element in a *sorted* array. If there are two or more elements
 * which have the same amount of repetitions, find the largest one.
 * 
 * @param rStart The start of the range to look in
 * DEFAULT: 0
 * 
 * @return The value of the most repeated element in the array
 */
int findMostRepeated (const int arr[], int size, int rStart = 0)
{
    int mostRepeated = 0, mostReps = 0;
    int currentIndex = rStart, currentReps = 0;

    while (currentIndex < size && currentIndex != -1)
    {
        // Find the repetitions of the current element
        currentReps = findNextUnique(arr, size, currentIndex) - currentIndex;
        if (findNextUnique(arr, size, currentIndex) == -1)
        {
            currentReps = size - currentIndex;
        }

        if (currentReps > mostReps)
        {
            mostReps = currentReps;
            mostRepeated = arr[currentIndex];
        }
        else if (currentReps == mostReps)
        {
            if (arr[currentIndex] > mostRepeated)
            {
                mostRepeated = arr[currentIndex];
            }
        }

        currentIndex = findNextUnique(arr, size, currentIndex);
    }

    return mostRepeated;
}


void sortByRepetitions (int arr[], const int size)
{
    quicksort(arr, size);
        
    // Sort array
    int currIndex = 0;
        
    while (currIndex != -1)
    {
        int currMostRepeated = findMostRepeated(arr, size, currIndex);

        moveElement(arr, size, search(arr, size, currMostRepeated), currIndex);
        gatherAllRepetitions(arr, size, currIndex);
        
        currIndex = findNextUnique(arr, size, currIndex);
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
bool makeZigZag (int arr[], const int size)
{
    sortByRepetitions(arr, size);
    printArray(arr, size); std::cout << endl;

    for (int i = 1; i < (size - 1); i += 2)
    {
        moveElement(arr, size, size - 1, i);
    }

    printArray(arr, size); std::cout << endl;
    
    if (isZigZag(arr, size))
    {
        return true;
    }
    else
    {
        return false;
    }
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