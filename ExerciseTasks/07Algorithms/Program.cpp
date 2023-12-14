#include <iostream>
#include <cstdlib>

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
        std::cerr << "Size is too big, please enter a size <= " << MAX_SIZE << endl;
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
        std::cerr << "Size is too big, please enter a size <= " << MAX_SIZE << endl;
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
void SortDescending04 ()
{
    int arr[MAX_SIZE] = {0,};
    int size;
    
    cin >> size;
    while (size > MAX_SIZE)
    {
        size = 0;
        std::cerr << "Size is too big, please enter a size <= " << MAX_SIZE << endl;
        cin >> size;
    }

    readArray(arr, size);

    quicksort(arr, size, 0, 0);
    printArray(arr, size); cout << endl;
}

/**
 * Read and array and sort it by the elements by the number of times each element
 * is repeated inside the array.
 */
void SortByRepetitions05 ()
{
    int arr[MAX_SIZE] = {0,};
    int size = 0;

    cin >> size;
    while (size > MAX_SIZE)
    {
        size = 0;
        std::cerr << "Size is too big, please enter a size <= " << MAX_SIZE << endl;
        cin >> size;
    }

    readArray(arr, size);

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

    std::cout << "Sorted: " << endl;
    printArray(arr, size); std::cout << endl;
}

/**
 * Given an interval, guess the number the user is thinking of. After each step,
 * ask the user whether the number is higher or lower than the guess. 
 */
void guessMyNumber06 ()
{
    int intervalStart, intervalEnd;
    cout << "Interval: ";

    cin >> intervalStart; cout << "to "; cin >> intervalEnd;
    
    // Input validation
    if (intervalStart == intervalEnd)
    {
        cout << "Your number is " << intervalStart << '!' << endl;
        return ;
    }

    while (intervalStart > intervalEnd)
    {
        intervalStart = 0; intervalEnd = 0;
        cout << "Invalid interval! Please try again:" << endl;
        cin >> intervalStart; cout << "to "; cin >> intervalEnd;
    }

    int guess;
    bool isCorrect = false;
    char response = 0;

    while (isCorrect == false)
    {
        cout << intervalStart << ',' << intervalEnd << endl;
        guess = intervalStart + (std::rand() % (intervalEnd - intervalStart + 1));
        // Random number within the current interval
        // TO DO: improve guessing algorithm

        cout << "Is your number " << guess << "? | [Y] or [N]" << endl;
        
        cin >> response;
        /*
        while (response != 'Y' || response != 'y' || response != 'N' || response != 'n')
        {
            response = 0;
            cout << "...what?" << endl;
            cin >> response;
        }
        */

        if (response == 'Y' || response == 'y')
        {
            cout << "I win!" << endl;
            isCorrect = true;
        }
        else
        {
            response = 0;
            cout << "Is your number higher or lower than " << guess << "? | [H] or [L]" << endl;

            cin >> response;
            /*
            while ((response != 'H' || response != 'h') || (response != 'L' || response != 'l'))
            {
                response = 0;
                cout << "...what?" << endl;
                cin >> response;
            }
            */

            if (response == 'H' || response == 'h')
            {
                if (guess == intervalEnd)
                {
                    cout << "Liar!" << endl;
                    return ;
                }

                intervalStart = guess + 1;
            }
            else if (response == 'L' || response == 'l')
            {
                if (guess == intervalStart)
                {
                    cout << "Liar!" << endl;
                    return ;
                }

                intervalEnd = guess - 1;
            }
        }
    }
}

/**
 * Given an array, output the longest streak of repetirions of the same number.
 */
void findLongestStreak07 ()
{
    int arr[MAX_SIZE] = {0,};
    int size;
    
    cin >> size;
    while (size > MAX_SIZE)
    {
        size = 0;
        std::cerr << "Size is too big, please enter a size <= " << MAX_SIZE << endl;
        cin >> size;
    }
}

int main()
{
    cout << "Homework 07: Algorithms" << endl;
    cout << "----------------------------------" << endl;
    
    cout << "Task 01: Find Last;" << endl;
    cout << "Task 02: Strong Pass;" << endl;
    cout << "Task 03: Sum of Odd After Even;" << endl;
    cout << "Task 04: Sort Descending;" << endl;
    cout << "Task 05: Sort by Repetitions;" << endl;
    cout << "Task 06: Guess my Number" << endl;
    cout << "Task 07: Find Longest Streak;" << endl;
    cout << "Task 08: Merge & Sort;" << endl;
    cout << "Task 09: Binary Search;" << endl;
    cout << "Task 10: Delete & Shift;" << endl;
    cout << "Task 11: Find Sum Pair;" << endl;
    cout << "Task 12: Convert to Decimal;" << endl;
    cout << "Task 13: Pyramid Sort;" << endl << endl;

    cout << "Please select task number to run: ";
    int task; cin >> task;

    while (task < 1 || task > 13)
    {
        task = 0;
        std::cerr << "Task number not found. Please enter valid task number: ";
        cin >> task;
    }

    std::cout << "Starting Task " << task << "..." << endl;
    switch (task)
    {
        case 1: FindLast_01(); break;
        case 2: StrongPass02(); break;
        case 3: SumOfOddAfterEven03(); break;
        case 4: SortDescending04(); break;
        case 5: SortByRepetitions05(); break;
        case 6: guessMyNumber06(); break;
        case 7: findLongestStreak07(); break;

        default: std::cout << "Task unavailable. Sorry!" << endl;
    }

    return 0;
}