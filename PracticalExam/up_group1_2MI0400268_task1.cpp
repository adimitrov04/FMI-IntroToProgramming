#include <iostream>
#include <new>

using std::endl;

const int MAX_ROWS = 100;
const int MAX_COLS = 100;

int allocFail()
{
	std::cerr << "Memory allocation failed." << endl;
	return -5;
}

void swap(const unsigned int* p1, const unsigned int* p2)
{
	const unsigned int* temp = p1;
	p1 = p2;
	p2 = temp;
}

void deleteMatrix(const unsigned int* const * const mat, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] mat[i];
	}

	delete[] mat;
}

bool newMatrix(unsigned int**& dest, const int rows, const int cols)
{
	dest = new (std::nothrow) unsigned int* [rows];
	if (!dest)
		return false;

	for (int i = 0; i < rows; i++)
	{
		dest[i] = new (std::nothrow) unsigned int[cols];
		if (!dest[i])
		{
			deleteMatrix(dest, i);
			return false;
		}
	}

	return true;
}

unsigned int dist(unsigned int A, unsigned int B)
{
	const int BIT_MASK = 1;
	const int INT_BITS = sizeof(unsigned int) * 8;

	unsigned int dist = 0;
	for (int i = 0; i < INT_BITS; i++)
	{
		if (((BIT_MASK << i) & A) != ((BIT_MASK << i) & B))
		{
			dist++;
		}
	}

	return dist;
}

unsigned int totalRowDist(const unsigned int* const row, const int size)
{
	unsigned int totalDist = 0;
	for (int i = 0; i < size - 1; i++)
	{
		totalDist += dist(row[i], row[i + 1]);
	}

	return totalDist;
}


void read(unsigned int* const * const mat, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cin >> mat[i][j];
		}
	}
}

void print(const unsigned int* const * const mat, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << mat[i][j] << ' ';
		}
		std::cout << endl;
	}
}

void print(const unsigned int* const arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << ' ';
	}
}

void removeRow(unsigned int** mat, int& rows, int cols, int rowNum)
{
	delete[] mat[rowNum];
	
	for (int i = rowNum; i < rows - 1; i++)
	{
		mat[i] = mat[i + 1];
	}

	rows--;
}

void clearK(unsigned int** mat, int& rows, const int cols, const int k)
{
	for (int i = 0; i < rows; i++)
	{
		if (totalRowDist(mat[i], cols) > k)
		{
			removeRow(mat, rows, cols, i);
			i--;
		}
	}
}

int main()
{
	int rows = 0, cols = 0;
	std::cin >> rows >> cols;

	while ((rows > MAX_ROWS || cols > MAX_COLS) || (rows <= 0 || cols <= 0))
	{
		std::cerr << "Cannot create matrix of given size." << endl;
		std::cerr << "Please enter valid size (0 < rows, cols < " << MAX_ROWS << "): " << endl;

		std::cin >> rows >> cols;
	}

	unsigned int** mat = nullptr;
	if (newMatrix(mat, rows, cols) == false)
	{
		return allocFail();
	}

	read(mat, rows, cols);

	int k = 0;
	std::cin >> k;
	while (k < 0)
	{
		std::cerr << "Invalid number K. Please enter K >= 0: " << endl;
		std::cin >> k;
	}

	clearK(mat, rows, cols, k);
	print(mat, rows, cols);

	deleteMatrix(mat, rows);

	return 0;
}