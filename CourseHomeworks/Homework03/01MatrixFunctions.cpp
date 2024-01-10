#include <iostream>
#include <new>

using std::endl;

/*
------------------- 01 Matrix Functions -------------------
Write the following functions and create a program which
demonstrates them:

input() - Read two numbers N and M from the console and
create a NxM dynamic matrix of integers and read all
elements of that matrix.

transform() - Read an integer D from consolе and in a
given matrix, make all numbers which have D divisors 0.

clear() - Remove all columns and rows of a matrix which
consist entirely of 0's, shifting all other elements as
not to change their order.

print() - Print a matrix on the console.

------------------------ EXAMPLE: -------------------------
input:  5
output: 1 2 3 4 5
-----------------------------------------------------------
*/

int allocFail ()
{
    std::cerr << "FAIL: Could not allocate memory." << endl;
    return -1;
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

/**
 * Copy the contents of one array into another. Both arrays must be
 * the same size.
 */
void copyArray (const int* src, int* dest, const int size)
{
    for (int i = 0; i < size; i++)
    {
        dest[i] = src[i];
    }
}

void readMatrix (int** mat, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
        readArray(mat[i], cols);
    }
}

void deleteMatrix (int** mat, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] mat[i];
    }

    delete[] mat;
}

int numberOfDivisors (const int num)
{
    int count = 2;
    
    if (num == 0)
        return count;

    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
            count++;
    }

    return count;
}

/**
 * Iterate through a given array of integers, making each number zero
 * if it has a certain amount of different divisors.
 * 
 * @param D The required number of divisors to make the number zero
 */
void transformArray (int* arr, const int size, const int D)
{
    for (int i = 0; i < size; i++)
    {
        if (numberOfDivisors(arr[i]) == D)
            arr[i] = 0;
    }
}

/**
 * Checks if a row in a given matrix consists only of zeros
 * 
 * @param row The index of the row to check
 */
bool rowIsEmpty (int** mat, const int row, const int rowSize)
{
    for (int i = 0; i < rowSize; i++)
    {
        if (mat[row][i])
            return false;
    }

    return true;
}

void removeRow (int** mat, int& rows, int& cols, int row)
{
    for (int i = row; i < rows - 1; i++)
    {
        copyArray(mat[i + 1], mat[i], cols);
    }
    
    delete[] mat[rows - 1];
    rows--;
}

/**
 * Checks if a column in a given matrix consists only of zeros
 * 
 * @param col The index of the column to check
 */
bool colIsEmpty (int** mat, const int col, const int colSize)
{
    for (int i = 0; i < colSize; i++)
    {
        if (mat[i][col])
            return false;
    }

    return true;
}

void removeCol (int** mat, int& rows, int& cols, int col)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = col; j < cols - 1; j++)
        {
            mat[i][j] = mat[i][j + 1];
        }
    }
    
    cols--;
}

int** input (int& rows, int& cols)
{
    int N = 0, M = 0;
    std::cin >> N >> M ;

    int** mat = new (std::nothrow) int*[N];
    if (mat == nullptr)
        return nullptr;

    for (int i = 0; i < N; i++)
    {
        mat[i] = new (std::nothrow) int[M];
        if (mat[i] == nullptr)
        {
            deleteMatrix(mat, i, M);
            return nullptr;
        }
    }

    rows = N; cols = M;
    readMatrix(mat, rows, cols);

    return mat;
}

void transform (int** mat, const int rows, const int cols)
{
    int D = 0;
    std::cin >> D;

    for (int i = 0; i < rows; i++)
    {
        transformArray(mat[i], cols, D);
    }
}

void clear (int** mat, int& rows, int& cols)
{
    // Clear empty rows
    for (int i = 0; i < rows; i++)
    {
        if (rowIsEmpty(mat, i, cols))
        {
            removeRow(mat, rows, cols, i);
            i--;
        }
    }

    // Clear empty columns
    for (int i = 0; i < cols; i++)
    {
        if (colIsEmpty(mat, i, rows))
        {
            removeCol(mat, rows, cols, i);
            i--;
        }
    }
}

void print (int** mat, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
        printArray(mat[i], cols);
        std::cout << endl;
    }
}

int main ()
{
    int rows = 0, cols = 0;
    
    std::cout << "Enter size of matrix: ";
    int** mat = input(rows, cols);
    if (mat == nullptr)
        return allocFail();

    std::cout << "Enter number of divisors to delete number: ";
    transform(mat, rows, cols);
    clear(mat, rows, cols);

    std::cout << endl;
    print(mat, rows, cols);

    // Clear memory from matrix
    deleteMatrix(mat, rows, cols);

    return 0;
}