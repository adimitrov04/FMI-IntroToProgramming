#include <iostream>

using std::endl;

/*
------------------ 04 Transponate Matrix ------------------
Read a matrix dynamically and determine whether it is a
magic square (the sum of all rows, columns and diagonals is
equal).

------------------------ EXAMPLE: -------------------------
input:  1 1 1
        1 1 1
        1 1 1

output: true
-----------------------------------------------------------
*/

int allocFail ()
{
    std::cerr << "Couldn't allocate memory. Terminating..." << endl;
    return -1;
}

int* newArray (const int size)
{
    int* arr = new (std::nothrow) int[size];

    return arr;
}

void deleteMatrix (int** mat, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] mat[i];
    }

    delete[] mat;
}

int** newMatrix (const int rows, const int cols)
{
    int** mat = new (std::nothrow) int*[rows];
    if (mat == nullptr)
    {
        std::cerr << "mat: ";
        return nullptr;
    }

    for (int i = 0; i < rows; i++)
    {
        mat[i] = newArray(cols);
        if (mat[i] == nullptr)
        {
            std::cerr << "mat row " << i + 1 << ": ";

            deleteMatrix(mat, i, cols);
            return nullptr;
        }
    }

    return mat;
}

void readArray (int* arr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }
}

void printArray (const int* arr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ' ';
    }
}

void readMatrix (int** mat, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
        readArray(mat[i], cols);
    }
}

void printMatrix (const int** mat, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
        printArray(mat[i], cols);
        std::cout << endl;
    }
}

/**
 * Sum a given row of a matrix
 */
int sumRow (int** mat, const int rows, const int cols, int row)
{
    int sum = 0;

    for (int i = 0; i < cols; i++)
    {
        sum += mat[row][i];
    }

    return sum;
}

/**
 * Sum a given column of a matrix
 */
int sumCol (int** mat, const int rows, const int cols, int col)
{
    int sum = 0;

    for (int i = 0; i < rows; i++)
    {
        sum += mat[i][col];
    }

    return sum;
}

/**
 * Sum a given diagonal of a matrix
 * 
 * @param primary The diagonal to sum (1 - primary, 0 - secondary)
 */
int sumDiagonal (int** mat, const int rows, const int cols, bool primary = 1)
{
    int sum = 0;
    int limit = std::min(rows, cols);

    if (primary)
    {
        for (int i = 0; i < limit; i++)
        {
            sum += mat[i][i];
        }
    }
    else
    {
        for (int i = limit - 1, j = 0; j < limit; i--, j++)
        {
            sum += mat[i][j];
        }
    }

    return sum;
}

bool isMagicSquare (int** mat, const int rows, const int cols)
{
    if (rows != cols)
        return false;

    // Check rows
    int sumRows = 0;
    for (int i = 1; i < rows; i++)
    {
        if (sumRow(mat, rows, cols, i) != sumRow(mat, rows, cols, i - 1))
            return false;

        sumRows = sumRow(mat, rows, cols, i);        
    }

    // Check columns
    int sumCols = 0;
    for (int i = 1; i < cols; i++)
    {
        if (sumCol(mat, rows, cols, i) != sumCol(mat, rows, cols, i - 1))
            return false;

        sumCols = sumCol(mat, rows, cols, i);
    }

    // Check diagonals
    int sumDiagonals = 0;
    if (sumDiagonal(mat, rows, cols, 1) != sumDiagonal(mat, rows, cols, 0))
        return false;
    
    sumDiagonals = sumDiagonal(mat, rows, cols);

    // Check if all are equal
    if (sumRows == sumCols && sumRows == sumDiagonals)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main ()
{
    int rows = 0, cols = 0;
    std::cin >> rows >> cols;

    int** mat = newMatrix(rows, cols);
    if (mat == nullptr)
        return allocFail();
    readMatrix(mat, rows, cols);

    std::cout << isMagicSquare(mat, rows, cols) << endl;

    deleteMatrix(mat, rows, cols);

    return 0;
}