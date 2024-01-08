#include <iostream>

using std::endl;

/*
------------------ 04 Transponate Matrix ------------------
Read a square matrix from console and output its transponated
version.

------------------------ EXAMPLE: -------------------------
input:  1 2 3 5
        3 2 4 6
        1 2 2 1
        2 7 8 1

output: 1 3 1 2
        2 2 2 7
        3 4 2 8
        5 6 1 1
-----------------------------------------------------------
*/

int allocError ()
{
    std::cerr << "Could not allocate memory" << endl;
    return -1;
}

int* newArray(const size_t size)
{
    int* ptr = new (std::nothrow) int[size];

    return ptr;
}

void deleteMatrix (int** mat, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] mat[i];
    }

    delete[] mat;
}

void readArray (int* arr, const int size)
{
    for (int i = 0; i < size; i++)
        std::cin >> *(arr + i);
}

void readMatrix (int** mat, const int rows1, const int cols1)
{
    for (int i = 0; i < rows1; i++)
        readArray(*(mat + i), cols1);
}

void printArray (const int* arr, const int size)
{
    for (int i = 0; i < size; i++)
        std::cout << *(arr + i) << ' ';
}

void printMatrix (int** mat, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
        printArray(*(mat + i), cols);
        std::cout << endl;
    }
}

/**
 * Flip a square matrix around its primary diagonal.
 */
int** makeTranspose (int** mat, const int N, const int M)
{
    int** t_mat = new (std::nothrow) int*[M];
    if (t_mat == nullptr)
    {
        std::cerr << "t_mat: ";
        return nullptr;
    }

    for (int i = 0; i < M; i++)
    {
        t_mat[i] = newArray(N);
        
        if (t_mat[i] == nullptr)
        {
            std::cerr << "t_mat row " << i + 1 << ": ";
            deleteMatrix(t_mat, i, N);
            return nullptr;
        }
    }

    // Transpose
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            t_mat[i][j] = mat[j][i];
        }
    }

    return t_mat;
}

int main ()
{
    size_t rows = 0, cols = 0;
    std::cin >> rows >> cols;

    int** mat = new (std::nothrow) int*[rows];
    if (mat == nullptr)
    {
        std::cerr << "mat: ";
        return allocError();
    }
    
    for (int i = 0; i < rows; i++)
    {
        mat[i] = newArray(cols);
        
        if (mat[i] == nullptr)
        {
            deleteMatrix(mat, i, cols);
            std::cerr << "mat[" << i << "]: ";
            return allocError();
        }
    }
    readMatrix(mat, rows, cols);

    int** transpose = makeTranspose(mat, rows, cols);
    int t_rows = cols, t_cols = rows;
    if (transpose == nullptr)
    {
        deleteMatrix(mat, rows, cols);
        return allocError();
    }

    std::cout << endl;
    printMatrix(mat, rows, cols);
    std::cout << endl;
    printMatrix(transpose, t_rows, t_cols);

    deleteMatrix(mat, rows, cols);
    deleteMatrix(transpose, t_rows, t_cols);

    return 0;
}