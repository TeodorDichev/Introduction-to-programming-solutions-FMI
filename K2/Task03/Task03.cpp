// Дадена е матрица от цели числа MxN, като 1 <= М, N <= 10, и цяло число K.
// Матрицата е сортирана по сбора на числата в колоните си - например 
// в първата колона числата имат сбор 23, във втората - 38, в третата 45 и т.н.
// Да се напише функция, която проверява дали има 2 колони, 
// чиито сбор на сумите на елементите е равен на К.

#include <iostream>

constexpr size_t MAX_SIZE = 10;

void readMatrix(int matrix[][MAX_SIZE], size_t rows, size_t cols);
int sumColumn(const int matrix[][MAX_SIZE], size_t rows, size_t colIndex);
bool hasTwoColsWithSumK(const int matrix[][MAX_SIZE], size_t rows, size_t cols, int k);
bool hasTwoColsWithSumK1(const int matrix[][MAX_SIZE], size_t rows, size_t cols, int k);

int main()
{
	int matrix[MAX_SIZE][MAX_SIZE];

	size_t rows, cols;

	std::cout << "Enter rows and columns ot the matrix (>= 1 & <= 10): ";
	std::cin >> rows >> cols;
	if (rows > 10 || cols > 10 || rows < 1 || cols < 1) {
		std::cout << "Invalid input!";
		return -1;
	}

	int k;
	std::cout << "Enter the sum of the matrix you search for (K): ";
	std::cin >> k;

	readMatrix(matrix, rows, cols);

	std::cout << std::boolalpha << hasTwoColsWithSumK(matrix, rows, cols, k);
}

void readMatrix(int matrix[][MAX_SIZE], size_t rows, size_t cols) {
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < cols; j++)
			std::cin >> matrix[i][j];

}
int sumColumn(const int matrix[][MAX_SIZE], size_t rows, size_t colIndex) {
	int sum = 0;

	for (size_t i = 0; i < rows; i++)
		sum += matrix[i][colIndex];

	return sum;
}

bool hasTwoColsWithSumK(const int matrix[][MAX_SIZE], size_t rows, size_t cols, int k) {
	for (size_t i = 0; i < cols; i++)
	{
		for (size_t j = cols; j > 0; j--)
		{
			int columnSum = sumColumn(matrix, rows, i) + sumColumn(matrix, rows, j);
			if (i == j)
				continue;
			if (columnSum == k)
				return true;
			else if (columnSum > k)
				continue;
			else
				break;
		}
	}
	return false;
}
bool hasTwoColsWithSumK1(int matrix[][MAX_SIZE], size_t rows, size_t cols, int k) {
	int sums[MAX_SIZE];

	for (int i = 0; i < cols; i++)
		sums[i] = sumColumn(matrix, rows, i);

	size_t beg = 0, end = cols - 1;

	while (beg != end)
	{
		int sumOfCols = sums[beg] + sums[end];

		if (sumOfCols == k)
			return true;
		else if (sumOfCols > k)
			end--;
		else
			beg++;
	}

	return false;
}