#include <iostream>
#include <new>

using std::endl;

int allocFail ()
{
    std::cerr << "FATAL: Could not allocate memory." << endl;
    return -1;
}

void deleteMatrix (const int* const * const mat, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] mat[i];
    }

    delete[] mat;
}

void readArray (int* const arr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }
}

void readMatrix (int* const * const mat, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
        readArray(mat[i], cols);
    }
}

bool isBigger (const int num1, const int num2)
{
    return (num1 > num2);
}

bool isSmaller (const int num1, const int num2)
{
    return (num1 < num2);
}

/**
 * Finds the index of the min/max element of a given array.
 * 
 * @param cmpr The function used to compare the values. Defines whether to search
 * for min or max.
 * @return The value of the min/max element of the array
 */
int findMinMax (const int* const arr, const int size, bool cmpr(int, int))
{
    int result = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (cmpr(arr[i], result))
            result = arr[i];
    }

    return result;
}

/**
 * Finds the min/max element of a matrix.
 * 
 * @param cmpr The function used to compare the values. Defines whether to search
 * for min or max.
 * @return The value of the min/max element of the matrix
 */
int minMaxMatrix (const int* const * const mat, const int rows, const int cols, bool cmpr(int, int))
{
    int resultRow = 0;
    int result = findMinMax(mat[resultRow], cols, cmpr);
    
    for (int i = 0; i < rows; i++)
    {
        if (cmpr(findMinMax(mat[i], cols, cmpr), result))
        {
            result = findMinMax(mat[i], cols, cmpr);
            resultRow = i;
        }
    }

    return result;
}

int main ()
{
    const int rows = 10;
    const int cols = 10;

    int** mat = new (std::nothrow) int*[rows];
    if (!mat)
        return allocFail();

    for (int i = 0; i < rows; i++)
    {
        mat[i] = new (std::nothrow) int[cols];
        if (!mat[i])
        {
            deleteMatrix(mat, i, cols);
            return allocFail();
        }
    }

    readMatrix(mat, rows, cols);

    std::cout << "Max element of matrix: " << minMaxMatrix(mat, rows, cols, isBigger) << endl;
    std::cout << "Min element of matrix: " << minMaxMatrix(mat, rows, cols, isSmaller) << endl;

    deleteMatrix(mat, rows, cols);

    return 0;
}