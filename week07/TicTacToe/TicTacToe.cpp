#include <iostream>

constexpr int size = 3;
constexpr char defaultChar = '.';
constexpr char circleChar = 'O';
constexpr char crossChar = 'X';

void printMatrix(const char matrix[][size]);
void initializeMatrix(char matrix[][size]);
void playerTurn(char matrix[size][size], const char playerChar);
bool isWinner(char matrix[][size], const char winnerChar);

int main()
{
    char matrix[size][size];
	initializeMatrix(matrix);
	printMatrix(matrix);
	for (int roundCounter = 0; roundCounter < size * size; roundCounter++)
	{
		if (roundCounter % 2 == 0) {
			playerTurn(matrix, circleChar);
			printMatrix(matrix);
			if (isWinner(matrix, circleChar)) {
				std::cout << "Congrats player one, you have defeated your opponent!\n";
				return 1;
			}
		}

		else {
			playerTurn(matrix, crossChar);
			printMatrix(matrix);
			if (isWinner(matrix, crossChar)) {
				std::cout << "Congrats player two, you have defeated your opponent!\n";
				return 1;
			}
		}
	}

	std::cout << "The game is a draw";
}

void initializeMatrix(char matrix[][size]) {
	std::cout << "Welcome to DicDacDoe\n";

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matrix[i][j] = defaultChar;
}

void printMatrix(const char matrix[][size]) {
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
			std::cout << " " << matrix[i][j] << " |";

		std::cout << "\n";
		std::cout << "------------";
		std::cout << "\n";
	}
}

void playerTurn(char matrix[size][size], const char playerChar) {
	std::cout << "Player " << playerChar << ", now is your turn!\n";
	int currRow, currCol;

	while (true) {
		std::cout << "Choose a tile [row, col]: ";
		std::cin >> currRow >> currCol;

		if (currRow >= 0 && currRow < size && currCol >= 0 && currCol < size && matrix[currRow][currCol] == defaultChar) {
			matrix[currRow][currCol] = playerChar;
			break;
		}

		std::cout << "Invalid tile! Please try again.\n";
	}
}

bool isWinner(char matrix[][size], const char winnerChar) {
	for (size_t i = 0; i < size; i++) {
		if (matrix[i][0] == winnerChar && matrix[i][1] == winnerChar && matrix[i][2] == winnerChar)
			return true;

		if (matrix[0][i] == winnerChar && matrix[1][i] == winnerChar && matrix[2][i] == winnerChar)
			return true;
	}

	if (matrix[0][0] == winnerChar && matrix[1][1] == winnerChar && matrix[2][2] == winnerChar)
		return true;

	if (matrix[0][2] == winnerChar && matrix[1][1] == winnerChar && matrix[2][0] == winnerChar)
		return true;

	return false;
}
