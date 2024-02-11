#include <iostream>
#include <new>
#include <limits>

using std::endl;

typedef int const * const * const const_mat;

const char MARK = '#';

/*
------------------- 03 Largest Sum Path -------------------
Read an NxM matrix of integers and find the path (starting
from (1, 1)) along which the numbers have the largest sum
and output the sum.

------------------------ EXAMPLE: -------------------------
input:  1 5 2 6
        8 3 4 1
        7 0 2 4
output: 
-----------------------------------------------------------
*/

int max (const int num1, const int num2)
{
    return (num1 > num2) ? num1 : num2;
}

int allocFail ()
{
    std::cerr << "Failed to allocate memory." << endl;
    return -69;
}

void deleteMatrix (int** mat, const int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] mat[i];
    }

    delete[] mat;
}

void deleteMatrix (char** mat, const int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] mat[i];
    }

    delete[] mat;
}

bool createMatrix (int**& dest, const int rows, const int cols)
{
    dest = new (std::nothrow) int*[rows];
    if (!dest)
        return false;

    for (int i = 0; i < rows; i++)
    {
        dest[i] = new (std::nothrow) int[cols];
        if (!dest[i])
        {
            deleteMatrix(dest, rows);
            return false;
        }
    }

    return true;
}

bool createMatrix (char**& dest, const int rows, const int cols)
{
    dest = new (std::nothrow) char*[rows];
    if (!dest)
        return false;

    for (int i = 0; i < rows; i++)
    {
        dest[i] = new (std::nothrow) char[cols];
        if (!dest[i])
        {
            deleteMatrix(dest, rows);
            return false;
        }
    }

    return true;
}


static int lsp_helper (const_mat mat, const int rows, const int cols, int currSum, int curr_x, int curr_y, char** path)
{
    if (curr_x == cols || curr_y == rows)
        return currSum;

    currSum += mat[curr_y][curr_x];
    return max(lsp_helper(mat, rows, cols, currSum, curr_x + 1, curr_y, path),
               lsp_helper(mat, rows, cols, currSum, curr_x, curr_y + 1, path));
}

int findLargestSumPath (const_mat mat, const int rows, const int cols, char** path)
{
    int curr_x = 0, curr_y = 0;

    return max(lsp_helper(mat, rows, cols, mat[0][0], curr_x + 1, curr_y, path),
               lsp_helper(mat, rows, cols, mat[0][0], curr_x, curr_y + 1, path));
}

void readMatrix (int* const * const mat, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cin >> mat[i][j];
        }
    }
}

int main ()
{
    int rows = 0, cols = 0;
    std::cin >> rows >> cols;

    int** mat = nullptr;
    if (createMatrix(mat, rows, cols) == false)
        return allocFail();

    readMatrix(mat, rows, cols);

    char** pathMap = nullptr;
    if (createMatrix(pathMap, rows, cols) == false)
    {
        deleteMatrix(mat, rows);
        return allocFail();
    }

    std::cout << findLargestSumPath(mat, rows, cols, pathMap);

    deleteMatrix(mat, rows);
    deleteMatrix(pathMap, rows);

    return 0;
}