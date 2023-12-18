#include <iostream>
#include <cmath>
#include <cstdlib>

using std::endl;

const int MAX_SIZE = 1000; // Global maximum size for an array

// ---------- Array IO functions ----------

void clearArray (int arr[], int& inOutSize)
{
    for (int i = 0; i < inOutSize; i++)
    {
        arr[i] = 0;
    }

    inOutSize = 0;
}

void clearArray (bool arr[], int& inOutSize)
{
    for (int i = 0; i < inOutSize; i++)
    {
        arr[i] = 0;
    }

    inOutSize = 0;
}

void readArray (int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }
}

bool isValidBinary (const int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != 0 && arr[i] != 1)
        {
            return false;
        }
    }

    return true;
}

void printArray (const int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ' ';
    }
}

void printArray (const char arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i];
    }
}

// ---------- Array analysis functions ----------

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

int binarySearch (const int arr[], int size, int search)
{
    int lowLim = 0, upLim = size - 1;
    int mid = 0;

    while (lowLim <= upLim)
    {
        if (lowLim == upLim)
        {
            if (arr[lowLim] == search)
            {
                return lowLim;
            }
        }

        mid = lowLim + ((upLim - lowLim) / 2);
        
        if (arr[mid] == search)
        {
            return mid;
        }
        
        if (search > arr[mid])
        {
            lowLim = mid + 1;
        }
        else
        {
            upLim = mid - 1;
        }
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

// ---------- Array modification functions ----------

bool insertElement (int arr[], int& inOutSize, int insert, int index)
{
    if (inOutSize == MAX_SIZE)
    {
        std::cerr << "No space left in array." << endl;
        return false;
    }
    
    inOutSize++;
    if (index >= inOutSize || index < 0)
    {
        std::cerr << "Cannot insert outside of array." << endl;
        inOutSize--;
        return false;
    }

    for (int i = inOutSize - 1; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[index] = insert;

    return true;
}

bool insertElement (char arr[], int& inOutSize, char insert, int index)
{
    if (inOutSize == MAX_SIZE)
    {
        std::cerr << "No space left in array." << endl;
        return false;
    }
    
    inOutSize++;
    if (index >= inOutSize || index < 0)
    {
        std::cerr << "Cannot insert outside of array." << endl;
        inOutSize--;
        return false;
    }

    for (int i = inOutSize - 1; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[index] = insert;
    
    return true;
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

void mergeArrays (const int arr1[], int size1, const int arr2[], int size2,
                  int newArr[], int& inOutNewsize)
{
    inOutNewsize = size1 + size2;
    if (inOutNewsize > MAX_SIZE)
    {
        std::cerr << "Cannot merge: new array is surpasses the size limit of "
        << MAX_SIZE << endl;

        inOutNewsize = 0;
        return ;
    }

    for (int i = 0; i < size1; i++)
    {
        newArr[i] = arr1[i];
    }

    for (int i = 0; i < size2; i++)
    {
        newArr[size1 + i] = arr2[i];
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
 * Remove an element of an array without changing the order of the rest.
 */
bool removeElement(int arr[], int& inOutSize, int index) 
{
    if (index < 0 || index >= inOutSize)
    {
        std::cerr << "Cannot delete an element outside of the array." << endl;
        return false;
    }
    
    for (int i = index; i < inOutSize - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    arr[inOutSize - 1] = 0;
    inOutSize--;

    return true;
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

// ---------- Mathematical functions ----------

int binaryToOctal (const int bits[], int size)
{
    uint32_t octal = 0;
    uint32_t exponent = 1;

    if (isValidBinary(bits, size) == false)
    {
        return -1;
    }

    int digit = 0;
    for (int i = size - 1; i >= 0; i -= 3)
    {
        if (i < 2)
        {
            while (i >= 0)
            {
                digit += bits[i] * std::pow(2, 1 - i);
                i--;
            }
        }
        else
        {
            digit = (bits[i] + (2 * bits[i - 1]) + (4 * bits[i - 2]));
        }

        octal += exponent * digit;
        
        digit = 0;
        exponent *= 10;
    }

    return octal;
}

// ---------- TASKS -----------

/**
 * Read an array and an element to find and output the index of the last instance of that element
 * within the array.
 * 
 * Output -1 if the element is not found within the array.
 */
void FindLast01 ()
{
    int arr[MAX_SIZE] = {0,};
    int size;

    std::cin >> size;
    while (size > MAX_SIZE)
    {
        size = 0;
        std::cerr << "Size is too big, please enter a size <= " << MAX_SIZE << endl;
        std::cin >> size;
    }

    readArray(arr, size);   
    int find; std::cin >> find;

    std::cout << findLast(arr, size, find) << endl;
}

/**
 * Read a password, consisting of *at most* 10 letters and after each letter insert the numbers from
 * 0 to 9 in order to strenghten that password.
 */
void StrongPass02 ()
{
    const int CHAR_LIMIT = 10;
    char weakPass[CHAR_LIMIT] = {0,};

    std::cout << "Enter password (Max. 10 letters): ";
    
    // Read Password
    int inputSize = 0;
    for (int i = 0; i < CHAR_LIMIT; i++)
    {
        std::cin >> weakPass[i];
        inputSize++;
        
        if (std::cin.get() == '\n')
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

    std::cin >> size;
    while (size > MAX_SIZE)
    {
        size = 0;
        std::cerr << "Size is too big, please enter a size <= " << MAX_SIZE << endl;
        std::cin >> size;
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
    
    std::cin >> size;
    while (size > MAX_SIZE)
    {
        size = 0;
        std::cerr << "Size is too big, please enter a size <= " << MAX_SIZE << endl;
        std::cin >> size;
    }

    readArray(arr, size);

    quicksort(arr, size, false);
    printArray(arr, size); std::cout << endl;
}

/**
 * Read and array and sort it by the elements by the number of times each element
 * is repeated inside the array.
 */
void SortByRepetitions05 ()
{
    int arr[MAX_SIZE] = {0,};
    int size = 0;

    std::cin >> size;
    while (size > MAX_SIZE)
    {
        size = 0;
        std::cerr << "Size is too big, please enter a size <= " << MAX_SIZE << endl;
        std::cin >> size;
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
void GuessMyNumber06 ()
{
    int intervalStart, intervalEnd;
    std::cout << "Interval: ";

    std::cin >> intervalStart; std::cout << "to "; std::cin >> intervalEnd;
    
    // Input validation
    if (intervalStart == intervalEnd)
    {
        std::cout << "Your number is " << intervalStart << '!' << endl;
        return ;
    }

    while (intervalStart > intervalEnd)
    {
        intervalStart = 0; intervalEnd = 0;
        std::cout << "Invalid interval! Please try again:" << endl;
        std::cin >> intervalStart; std::cout << "to "; std::cin >> intervalEnd;
    }

    int guess;
    bool isCorrect = false;
    char response = 0;

    while (isCorrect == false)
    {
        std::cout << intervalStart << ',' << intervalEnd << endl;
        guess = intervalStart + (std::rand() % (intervalEnd - intervalStart + 1));
        // Random number within the current interval
        // TO DO: improve guessing algorithm

        std::cout << "Is your number " << guess << "? | [Y] or [N]" << endl;
        
        std::cin >> response;
        /*
        while (response != 'Y' || response != 'y' || response != 'N' || response != 'n')
        {
            response = 0;
            std::cout << "...what?" << endl;
            std::cin >> response;
        }
        */

        if (response == 'Y' || response == 'y')
        {
            std::cout << "I win!" << endl;
            isCorrect = true;
        }
        else
        {
            response = 0;
            std::cout << "Is your number higher or lower than " << guess << "? | [H] or [L]" << endl;

            std::cin >> response;
            /*
            while ((response != 'H' || response != 'h') || (response != 'L' || response != 'l'))
            {
                response = 0;
                std::cout << "...what?" << endl;
                std::cin >> response;
            }
            */

            if (response == 'H' || response == 'h')
            {
                if (guess == intervalEnd)
                {
                    std::cout << "Liar!" << endl;
                    return ;
                }

                intervalStart = guess + 1;
            }
            else if (response == 'L' || response == 'l')
            {
                if (guess == intervalStart)
                {
                    std::cout << "Liar!" << endl;
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
void LongestStreak07 ()
{
    int arr[MAX_SIZE] = {0,};
    int size;
    
    std::cin >> size;
    while (size > MAX_SIZE)
    {
        size = 0;
        std::cerr << "Size is too big, please enter a size <= " << MAX_SIZE << endl;
        std::cin >> size;
    }

    readArray(arr, size);

    int currIndex = 0;
    int currentStreak = 0, longestStreak = 0;

    // Initialize first streak
    if (size > 0)
    {
        currentStreak = 1;
        longestStreak = 1;
    }
    
    while (currIndex < (size - 1))
    {
        if (arr[currIndex + 1] == arr[currIndex])
        {
            currentStreak++;
        }
        else
        {
            if (currentStreak > longestStreak)
            {
                longestStreak = currentStreak;
            }
            currentStreak = 1;
        }
        
        currIndex++;
    }

    if (currentStreak > longestStreak)
    {
        longestStreak = currentStreak;
    }

    std::cout << "Longest streak: " << longestStreak << endl;
}

/**
 * Read 2 sorted arrays and merge them into one array, which is sorted descending.
 */
void MergeAndSort08 ()
{
    // Read first array
    int arr1[MAX_SIZE] = {0,};
    int size1;
    
    std::cin >> size1;
    while (size1 > MAX_SIZE)
    {
        size1 = 0;
        std::cerr << "Size is too big, please enter a size <= " << MAX_SIZE << endl;
        std::cin >> size1;
    }

    readArray(arr1, size1);

    // Read second array
    int arr2[MAX_SIZE] = {0,};
    int size2;
    
    std::cin >> size2;
    while (size2 > MAX_SIZE)
    {
        size2 = 0;
        std::cerr << "Size is too big, please enter a size <= " << MAX_SIZE << endl;
        std::cin >> size2;
    }

    readArray(arr2, size2);

    int mergedArr[MAX_SIZE] = {0,};
    int mergedSize = 0;
    mergeArrays(arr1, size1, arr2, size2, mergedArr, mergedSize);

    if (mergedSize == 0) return ;

    quicksort(mergedArr, mergedSize, false);

    printArray(mergedArr, mergedSize);
}

/**
 * Demonstrate binary search.
 */
void BinarySearchDemo09 ()
{
    int arr[MAX_SIZE] = {0,};
    int size;
    
    std::cin >> size;
    while (size > MAX_SIZE)
    {
        size = 0;
        std::cerr << "Size is too big, please enter a size <= " << MAX_SIZE << endl;
        std::cin >> size;
    }

    readArray(arr, size);

    if (isSorted(arr, size, 1))
    {
        int search; std::cin >> search;
        std::cout << binarySearch(arr, size, search) << endl;
    }
    else
    {
        std::cerr << "Array is not sorted." << endl;
    }
}

/**
 * Delete an element within a given array without changing the order of the rest.
 * In place of the empty element in the end, insert -1.
 */
void DeleteAndInsert10 ()
{
    int arr[MAX_SIZE] = {0,};
    int size;
    
    std::cin >> size;
    while (size > MAX_SIZE)
    {
        size = 0;
        std::cerr << "Size is too big, please enter a size <= " << MAX_SIZE << endl;
        std::cin >> size;
    }

    readArray(arr, size);

    int removeIndex = 0;
    std::cin >> removeIndex;

    if (removeElement(arr, size, removeIndex) == true)
    {
        insertElement(arr, size, -1, size);
        printArray(arr, size);
    }
}

void FindSumPair11 ()
{
    int arr[MAX_SIZE] = {0,};
    int size;
    
    std::cin >> size;
    while (size > MAX_SIZE)
    {
        size = 0;
        std::cerr << "Size is too big, please enter a size <= " << MAX_SIZE << endl;
        std::cin >> size;
    }

    readArray(arr, size);

    int sum; std::cin >> sum;
    int operand1 = -1, operand2 = -1;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (j == i)
                j++;

            if (arr[i] + arr[j] == sum)
            {
                operand1 = i;
                operand2 = j;

                i = size; // Break outer loop
                break;
            }
        }
    }

    if (operand1 != -1 && operand2 != -1)
    {
        std::cout << "Pair found: " << arr[operand1] << " and " << arr[operand2] << endl;
    }
    else
    {
        std::cout << "No such pair exists." << endl;
    }
}

/**
 * Read an array of 1's and 0's and convert them from binary to octal.
 */
void BinaryToOctal12 ()
{
    const int MAX_BITS = 128;
    
    int bits[MAX_BITS] = {0,};

    int size = 0;
    std::cin >> size;
    
    readArray(bits, size);

    if (binaryToOctal(bits, size) == -1) // If reading the array failed
    {
        std::cerr << "Invalid input." << endl;
        return ;
    }

    uint32_t octal;
    octal = binaryToOctal(bits, size);

    std::cout << octal << endl;
}

int main()
{
    std::cout << "Homework 07: Algorithms" << endl;
    std::cout << "----------------------------------" << endl;
    
    std::cout << "Task 01: Find Last;" << endl;
    std::cout << "Task 02: Strong Pass;" << endl;
    std::cout << "Task 03: Sum of Odd After Even;" << endl;
    std::cout << "Task 04: Sort Descending;" << endl;
    std::cout << "Task 05: Sort by Repetitions;" << endl;
    std::cout << "Task 06: Guess my Number" << endl;
    std::cout << "Task 07: Longest Streak;" << endl;
    std::cout << "Task 08: Merge & Sort;" << endl;
    std::cout << "Task 09: Binary Search;" << endl;
    std::cout << "Task 10: Delete & Insert;" << endl;
    std::cout << "Task 11: Find Sum Pair;" << endl;
    std::cout << "Task 12: Convert to Octal;" << endl;
    std::cout << "Task 13: Pyramid Sort;" << endl << endl;

    std::cout << "Please select task number to run: ";
    int task; std::cin >> task;

    while (task < 1 || task > 13)
    {
        task = 0;
        std::cerr << "Task number not found. Please enter valid task number: ";
        std::cin >> task;
    }

    std::cout << "Starting Task " << task << "..." << endl;
    switch (task)
    {
        case 1: FindLast01(); break;
        case 2: StrongPass02(); break;
        case 3: SumOfOddAfterEven03(); break;
        case 4: SortDescending04(); break;
        case 5: SortByRepetitions05(); break;
        case 6: GuessMyNumber06(); break;
        case 7: LongestStreak07(); break;
        case 8: MergeAndSort08(); break;
        case 9: BinarySearchDemo09(); break;
        case 10: DeleteAndInsert10(); break;
        case 11: FindSumPair11(); break;
        case 12: BinaryToOctal12(); break;

        default: std::cout << "Task unavailable. Sorry!" << endl;
    }

    return 0;
}