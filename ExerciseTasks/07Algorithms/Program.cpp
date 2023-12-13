#include <iostream>
using std::cin;
using std::cout;
using std::endl;

const int MAX_SIZE = 1000; // Global maximum size for an array

// ------- Array IO functions -------

void readArray (int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

void printArray (const int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ' ';
    }
}

void printArray (const char arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
    }
}

// ------- Array analysis functions -------

/**
 * Check if an array is sorted
 * 
 * @param direction The direction of the sort.
 *                  1 = ascending
 *                  0 = descending
 * @return true if the array is sorted according to the given direction
 */
bool isSorted (const int arr[], int size, bool direction = 1)
{
    if (direction == 1)
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                return false;
            }
        }
    }
    else
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i] < arr[i + 1])
            {
                return false;
            }
        }
    }

    return true;
}

int sumOddElements (const int arr[], int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 != 0)
            sum += arr[i];
    }

    return sum;
}

int findLast (const int arr[], int size, int search)
{
    for (int i = size - 1; i >= 0; i--)
    {
        if (arr[i] == search)
            return i;
    }

    return -1;
}

// ------- Array modification functions -------

void insertElement (int arr[], int& inOutSize, int insert, int index)
{
    if (inOutSize == MAX_SIZE)
    {
        std::cerr << "No space left in array." << endl;
        return ;
    }
    
    inOutSize++;
    
    for (int i = inOutSize - 1; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[index] = insert;
}

void insertElement (char arr[], int& inOutSize, char insert, int index)
{
    if (inOutSize == MAX_SIZE)
    {
        std::cerr << "No space left in array." << endl;
        return ;
    }
    
    inOutSize++;
    for (int i = inOutSize - 1; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[index] = insert;
}

/**
 * Copy one the contents of one char array into another.
 * 
 * @param source The array contatining the original information
 * @param size The size of the original information
 * @param copy The array to copy information into
 */
void copyArray (const int source[], int size, int copy[], int& copySize)
{
    for (int i = 0; i < size; i++)
    {
       insertElement(copy, copySize, source[i], i); 
    }
}

void copyArray (const char source[], int size, char copy[], int& copySize)
{
    for (int i = 0; i < size; i++)
    {
       insertElement(copy, copySize, source[i], i); 
    }
}

/**
 * Take a password consisting of characters and insert a number after each letter to make it stronger.
 */
void makeStrong (char weak[], int weakSize, char strong[], int& strongSize)
{
    copyArray(weak, weakSize, strong, strongSize);

    char currNum = '0';
    for (int i = 1; i <= strongSize; i += 2)
    {
        insertElement(strong, strongSize, currNum, i);
        currNum++;
    }
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
    else
    {
        for (int i = elem; i > moveTo; i++)
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
 * @param direction 1 - ascending (default); 0 - descending
 */
void quicksort (int arr[], int size, int lowerLim = 0, bool direction = 1)
{
    if ((size - lowerLim) <= 1)
        return ;

    int pivot = (size - 1);

    if (direction == 1) // Sort ascending
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

    quicksort(arr, size, pivot + 1, direction);
    quicksort(arr, pivot, 0, direction);
}

// --------- TASKS ----------

/**
 * Read an array and an element to find and output the index of the last instance of that element
 * within the array.
 * 
 * Output -1 if the element is not found within the array.
 */
void FindLast_01 ()
{
    int arr[MAX_SIZE] = {0,};
    int size;

    cin >> size;
    while (size > MAX_SIZE)
    {
        size = 0;
        std::cerr << "Size is too big, please enter valid size." << endl;
        cin >> size;
    }

    readArray(arr, size);   
    int find; cin >> find;

    cout << findLast(arr, size, find) << endl;
}

/**
 * Read a password, consisting of *at most* 10 letters and after each letter insert the numbers from
 * 0 to 9 in order to strenghten that password.
 */
void StrongPass02 ()
{
    const int CHAR_LIMIT = 10;
    char weakPass[CHAR_LIMIT] = {0,};

    cout << "Enter password (Max. 10 letters): ";
    
    // Read Password
    int inputSize = 0;
    for (int i = 0; i < CHAR_LIMIT; i++)
    {
        cin >> weakPass[i];
        inputSize++;
        
        if (cin.get() == '\n')
        {
            break;
        }
    }

    char newPass[CHAR_LIMIT * 2] = {0,};
    int newSize = 0;

    makeStrong(weakPass, inputSize, newPass, newSize);
    printArray(newPass, newSize);
}

/**
 * Read an array of integers and in that same array, after every even number insert the sum of all the odd
 * numbers up to that point in the array.
 */
void SumOfOddAfterEven03 ()
{
    int arr[MAX_SIZE] = {0,};
    int size;

    cin >> size;
    while (size > MAX_SIZE)
    {
        size = 0;
        std::cerr << "Size is too big, please enter valid size." << endl;
        cin >> size;
    }

    readArray(arr, size);

    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            insertElement(arr, size, sumOddElements(arr, i), i + 1);
            i++; // Skip inserted element
        }
    }

    printArray(arr, size);
}

/**
 * Read an array and sort it in descending order.
 */
void sortDescending04 ()
{
    int arr[MAX_SIZE] = {0,};
    int size;
    
    cin >> size;
    while (size > MAX_SIZE)
    {
        size = 0;
        std::cerr << "Size is too big, please enter valid size." << endl;
        cin >> size;
    }

    readArray(arr, size);

    quicksort(arr, size, 0, 0);
    printArray(arr, size); cout << endl;
}

void sortByRepetitions05 ()
{

}

void guessMyNumber06 ()
{

}

int main()
{
    sortByRepetitions05();

    return 0;
}