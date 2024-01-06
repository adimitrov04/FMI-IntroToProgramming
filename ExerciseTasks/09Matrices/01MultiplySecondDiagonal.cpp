#include <iostream>

using std::endl;

const int MAX_ROWS = 100;
const int MAX_COLS = 100;

/*
--------------- 01 Multiply Second Diagonal ---------------
Read a 2-dimensional matrix of integers from the console
and output the product of all the numbers along its second
diagonal.

------------------------ EXAMPLE: -------------------------
input:  1 2 3
        3 2 4
        1 2 2
output: 6
-----------------------------------------------------------
*/

void readArray (int* arr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cin >> *(arr + i);
    }
}

void printArray (const int* arr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ' ';
    }
}

void readMatrix (int mat[][100], const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
        readArray(mat[i], cols);
    }
}

void printMatrix (const int mat[][100], const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
        printArray(mat[i], cols);
        std::cout << endl;
    }
}

static int MSD_help (const int mat[][100], const int rows, const int cols, int currentRow)
{
    if (currentRow == rows || cols < 0)
    {
        return 1;
    }

    return mat[currentRow][cols - 1] * MSD_help(mat, rows, cols - 1, currentRow + 1);
}

/**
 * Multiply the elements of a matrix along the second diagonal
 */
int MSD (const int mat[][100], const int rows, const int cols)
{
    return MSD_help(mat, rows, cols, 0);
}

int main ()
{
    int mat[MAX_ROWS][MAX_COLS] = {0,};
    int rows = 0, cols = 0;

    std::cin >> rows >> cols;
    readMatrix(mat, rows, cols);

    std::cout << endl;
    printMatrix(mat, rows, cols);

    std::cout << MSD(mat, rows, cols) << endl;

    return 0;
}