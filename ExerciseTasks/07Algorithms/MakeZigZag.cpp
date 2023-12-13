#include <iostream>
#include <cmath>

using std::endl;

const int MAX_SIZE = 5000;

// ---------- FUNCTIONS ----------

void readArray (int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }
}

void printArray (const int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ' ';
    }
}

int isZigZag (const int arr[], int size)
{

}

void makeZigZag ()
{

}

// ---------- MAIN ----------

int main ()
{
    int arr[MAX_SIZE] = {0,};
    int size = 0;

    // Input validation
    std::cin >> size;
    while (size > MAX_SIZE)
    {
        size = 0;
        std::cerr << "Size is too big. Please enter a size <= " << MAX_SIZE << ":" << endl;
        std::cin >> size;
    }

    readArray(arr, size);
}