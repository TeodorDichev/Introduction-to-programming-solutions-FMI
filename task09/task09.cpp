// Да се напише програма, която приема двумерна матрица(MxN) с M редове и N колони, 
// (0 <= M, N <= 100).Да се изведат на конзолата координатите на тези стойности, 
// които са най - малки спрямо колоната и реда си.

#include <iostream>

constexpr size_t MAX_SIZE = 100;

void readMatrix(int matrix[][MAX_SIZE], size_t rows, size_t cols);
void searchMatrix(const int matrix[][MAX_SIZE], size_t rows, size_t cols);
void printMinElement(size_t rowIndex, size_t colIndex);
bool isMinElementOnRow(const int matrix[][MAX_SIZE], size_t cols, size_t rowIndex, size_t colIndex);
bool isMinElementOnCol(const int matrix[][MAX_SIZE], size_t rows, size_t rowIndex, size_t colIndex);

int main() 
{
	size_t rows, cols;
	std::cout << "Enter width and height of the matrix: ";
	std::cin >> rows >> cols;

	if (rows > MAX_SIZE || rows < 0 || cols > MAX_SIZE || cols < 0)
	{
		std::cout << "Invalud input!";
		return -1;
	}

	int matrix[MAX_SIZE][MAX_SIZE];
	std::cout << "Enter the matrix: \n";
	readMatrix(matrix, rows, cols);

	searchMatrix(matrix, rows, cols);
}

void readMatrix(int matrix[][MAX_SIZE], size_t rows, size_t cols) {
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < cols; j++)
			std::cin >> matrix[i][j];
}

void searchMatrix(const int matrix[][MAX_SIZE], size_t rows, size_t cols) {
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (isMinElementOnRow(matrix, cols, i , j) && isMinElementOnCol(matrix, rows, i, j))
			{
				printMinElement(i, j);
				break;
			}
		}
	}
}

void printMinElement(size_t rowIndex, size_t colIndex) {
	std::cout << "(" << rowIndex << ", " << colIndex << "), ";
}

bool isMinElementOnRow(const int matrix[][MAX_SIZE], size_t cols, size_t rowIndex, size_t colIndex) {
	int minValue = matrix[rowIndex][colIndex];
	for (size_t i = 0; i < cols; i++)
	{
		if (i == colIndex)
			continue;
		else if (matrix[rowIndex][i] < minValue)
			return false;
	}

	return true;
}

bool isMinElementOnCol(const int matrix[][MAX_SIZE], size_t rows, size_t rowIndex, size_t colIndex) {
	int minValue = matrix[rowIndex][colIndex];
	for (size_t i = 0; i < rows; i++)
	{
		if (i == rowIndex)
			continue;
		else if (matrix[i][colIndex] < minValue)
			return false;
	}

	return true;
}
