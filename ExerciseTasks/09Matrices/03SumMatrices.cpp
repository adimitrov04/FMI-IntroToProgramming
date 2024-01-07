#include <iostream>

using std::endl;

/*
--------------------- 03 Sum Matrices ---------------------
Read two 2D arrays from the console and print their sum
(a matrix).

------------------------ EXAMPLE: -------------------------
input:  1 2 3   2 3 1
        3 2 4   3 4 2
        1 2 2   5 6 4

output: 3 5 4
        6 6 6
        6 8 6
-----------------------------------------------------------
*/

int* createArray (size_t& size)
{
    int* ptr = new (std::nothrow) int[size];

    return ptr;
}

void deleteMatrix (int** &mat, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] *(mat + i);
    }
    delete[] mat;
    //std::clog << "Cleared " << (rows * cols) * 4 << " bytes." << endl;
}

int allocError ()
{
    std::cerr << "Could not allocate memory. Terminating..." << endl;
    return -1;
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

void sumMatrices (int** mat1, int** mat2, int** &sum, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

int main ()
{
    size_t rows = 0, cols = 0;
    std::cin >> rows >> cols;

    int** mat1 = new (std::nothrow) int*[rows];
    if (mat1 == nullptr)
        return allocError();

    for (int i = 0; i < rows; i++)
    {
        *(mat1 + i) = createArray(cols);
        
        if ((mat1 + i) == nullptr) 
        {
            deleteMatrix(mat1, rows, cols);
            return allocError();
        }
    }
    readMatrix(mat1, rows, cols); std::cout << endl;
    //rintMatrix(mat1, rows, cols);

    int** mat2 = new (std::nothrow) int*[rows];
    if (mat2 == nullptr)
    {
        deleteMatrix(mat1, rows, cols);
        std::cerr << "mat2[0]" << endl;
        return allocError();
    }
    
    for (int i = 0; i < rows; i++)
    {
        *(mat2 + i) = createArray(cols);
        
        if ((mat2 + i) == nullptr) 
        {
            deleteMatrix(mat1, rows, cols);
            deleteMatrix(mat2, rows, cols);
            std::cerr << "mat2[0][1]" << endl;
            return allocError();
        }
    }
    readMatrix(mat2, rows, cols); std::cout << endl;
    //printMatrix(mat2, rows, cols);

    int** sum = new (std::nothrow) int*[rows];
    if (sum == nullptr)
    {
        deleteMatrix(mat1, rows, cols);
        deleteMatrix(mat2, rows, cols);
        return allocError();
    }
    
    for (int i = 0; i < rows; i++)
    {
        *(sum + i) = createArray(cols);
        
        if ((mat2 + i) == nullptr) 
        {
            deleteMatrix(mat1, rows, cols);
            deleteMatrix(mat2, rows, cols);
            deleteMatrix(sum, rows, cols);
            return allocError();
        }
    }

    sumMatrices(mat1, mat2, sum, rows, cols); std::cout << endl;

    printMatrix(mat1, rows, cols);
    std::cout << " + " << endl;
    printMatrix(mat2, rows, cols);
    std::cout << " = " << endl;
    printMatrix(sum, rows, cols);

    // Clear Memory
    deleteMatrix(mat1, rows, cols);
    deleteMatrix(mat2, rows, cols);
    deleteMatrix(sum, rows, cols);

    return 0;
}