#include <iostream>

using std::endl;

const int MAX_ROWS = 100;
const int MAX_COLS = 100;

/*
--------------------- 02 Sum Diagonal ---------------------
Read a 2-dimensional matrix of integers from the console
and output the sum of all the elements across its primary
diagonal.

------------------------ EXAMPLE: -------------------------
input:  1 2 3
        3 2 4
        1 2 2
output: 5
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

int sumDiagonal (const int mat[][100], const int rows, const int cols)
{
    if (rows < 0 || cols < 0)
        return 0;

    return mat[rows][cols] + sumDiagonal(mat, rows - 1, cols - 1);
}

int main ()
{
    int mat[MAX_ROWS][MAX_COLS] = {0,};
    int rows = 0, cols = 0;

    std::cin >> rows >> cols;

    readMatrix(mat, rows, cols);
    std::cout << endl;
    printMatrix(mat, rows, cols);

    std::cout << sumDiagonal(mat, rows, cols) << endl;

    return 0;
}