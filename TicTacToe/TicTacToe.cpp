#include <iostream>

constexpr int rows = 3;
constexpr int cols = 3;
constexpr int defaultValue = -1;
constexpr int circleValue = 0;
constexpr int crossValue = 1;
constexpr char defaultChar = '.';
constexpr char circleChar = 'O';
constexpr char crossChar = 'X';

void printMatrix(const int matrix[rows][cols]);
void initializeMatrix(int matrix[rows][cols]);
void firstPlayerTurn(int matrix[rows][cols]);
void secondPlayerTurn(int matrix[rows][cols]);
bool isWinner(int matrix[rows][cols], const int winnerValue);

int main()
{
    int matrix[rows][cols]{ defaultValue };
	initializeMatrix(matrix);
	printMatrix(matrix);
	while (true)
	{
		firstPlayerTurn(matrix);
		printMatrix(matrix);
		if (isWinner(matrix, circleValue)) {
			std::cout << "Congrats player one, you have defeated your opponent!\n";
			return 1;
		}

		secondPlayerTurn(matrix);
		printMatrix(matrix);
		if (isWinner(matrix, crossValue)) {
			std::cout << "Congrats player two, you have defeated your opponent!\n";
			return 1;
		}
	}
}

void initializeMatrix(int matrix[rows][cols]) {
	std::cout << "Welcome to DicDacDoe\n";

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			matrix[i][j] = defaultValue;
}

void printMatrix(const int matrix[rows][cols]) {
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (matrix[i][j] == -1) std::cout << " " << defaultChar << " |";
			else if (matrix[i][j] == 0) std::cout << " " << circleChar << " |";
			else if (matrix[i][j] == 1) std::cout << " " << crossChar << " |";
			else std::cout << "?" << " |";
		}

		std::cout << "\n";
		std::cout << "------------";
		std::cout << "\n";
	}
}

void firstPlayerTurn(int matrix[rows][cols]) {
	std::cout << "Player one, now is your turn, your symbol is: " << circleChar << "!\n";
	int currRow, currCol;

	while (true) {
		std::cout << "Choose a tile [row, col]: ";
		std::cin >> currRow >> currCol;

		if (currRow >= 0 && currRow < rows && currCol >= 0 && currCol < cols && matrix[currRow][currCol] == defaultValue) {
			matrix[currRow][currCol] = circleValue;
			break;
		}

		std::cout << "Invalid tile! Please try again.\n";
	}
}

void secondPlayerTurn(int matrix[rows][cols]) {
	std::cout << "Player two, now is your turn, your symbol is: " << crossChar << "!\n";
	int currRow, currCol;

	while (true) {
		std::cout << "Choose a tile [row, col]: ";
		std::cin >> currRow >> currCol;

		if (currRow >= 0 && currRow < rows && currCol >= 0 && currCol < cols && matrix[currRow][currCol] == defaultValue) {
			matrix[currRow][currCol] = crossValue;
			break;
		}

		std::cout << "Invalid tile! Please try again.\n";
	}
}

bool isWinner(int matrix[rows][cols], const int winnerValue) {
	for (size_t i = 0; i < rows; i++) {
		if (matrix[i][0] == winnerValue && matrix[i][1] == winnerValue && matrix[i][2] == winnerValue)
			return true;

		if (matrix[0][i] == winnerValue && matrix[1][i] == winnerValue && matrix[2][i] == winnerValue)
			return true;
	}

	if (matrix[0][0] == winnerValue && matrix[1][1] == winnerValue && matrix[2][2] == winnerValue)
		return true;

	if (matrix[0][2] == winnerValue && matrix[1][1] == winnerValue && matrix[2][0] == winnerValue)
		return true;

	return false;
}
