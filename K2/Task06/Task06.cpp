// Дадена е матрица от цели числа MxN, като 1 <= М, N <= 10.
// Център на област ще наричаме такава точка от матрицата, 
// която е по - голяма от средното аритметично на съседите си.
// Да се напише програма, която приема от стандартния вход размерите на матрицата M и N,
// и след това прочита елементите на матрицата.
// Програмата да изведе на стандартния изход координатите на всички центрове на области,
// отпечатани на нов ред. Ако няма такива, да не извежда нищо.

#include <iostream>

constexpr size_t MAX_SIZE = 10;

void readMatrix(int matrix[][MAX_SIZE], size_t rows, size_t cols);
bool is_valid_index(size_t N, size_t M, int x, int y);
bool is_center(int matrix[MAX_SIZE][MAX_SIZE], size_t N, size_t M, int x, int y);
void print_center(int matrix[][MAX_SIZE], size_t N, size_t M);

int main()
{
	int matrix[MAX_SIZE][MAX_SIZE];

	int rows, cols;
	std::cout << "Enter width and height of the matrix (greater or equal to one and less or equal to 10: )";
	std::cin >> rows >> cols;
	if (rows > 10 || rows < 1 || cols < 10 || cols < 1)
	{
		std::cout << "Invalid input!";
		return -1;
	}

	readMatrix(matrix, rows, cols);
	print_center(matrix, rows, cols);
}

void readMatrix(int matrix[][MAX_SIZE], size_t rows, size_t cols) 
{
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < cols; j++)
			std::cin >> matrix[i][j];
}

bool is_valid_index(size_t N, size_t M,	int x, int y)
{
	return x >= 0 && y >= 0 && x < N && y < M;
}

bool is_center(int matrix[MAX_SIZE][MAX_SIZE], size_t N, size_t M, int x, int y)
{
	if (!is_valid_index(N, M, x, y))
		return false;

	int sum = 0;

	int indexes[8][2] = {
		{x, y - 1},
		{x, y + 1},
		{x - 1, y},
		{x + 1, y},
		{x + 1, y - 1},
		{x + 1, y + 1},
		{x - 1, y + 1},
		{x - 1, y - 1},
	};

	unsigned count = 0;
	for (size_t i = 0; i < 8; i++)
	{
		int current_x = indexes[i][0];
		int current_y = indexes[i][1];

		if (is_valid_index(N, M, current_x, current_y))
		{
			++count;
			sum += matrix[current_x][current_y];
		}
	}

	double avg = (double)sum / count;

	return (avg < matrix[x][y]);
}

void print_center(int matrix[][MAX_SIZE], size_t N, size_t M)
{
	for (size_t i = 0; i < N; i++)
		for (size_t j = 0; j < M; j++)
			if (is_center(matrix, N, M, i, j))
				std::cout << i << " " << j << std::endl;
}
