#include <iostream>

constexpr unsigned	MAX_SIZE = 10;
// Read/Write methods
void readMatrix(int mtx[][MAX_SIZE], size_t rows, size_t cols);
void printMatrix(const int mtx[][MAX_SIZE], size_t rows, size_t cols);

// Matrix operations
void matrixDrive();
bool isMatrixTriangular(const int const mtx[][MAX_SIZE], size_t rows, size_t cols);
bool isMatrixSymmetrical(const int mtx[][MAX_SIZE], size_t rows, size_t cols);
bool canMatrixesBeSummed(size_t rows1, size_t cols1, size_t rows2, size_t cols2);
bool canMatrixesBeMultiplied(size_t cols1, size_t rows2);
void sumMatrixes(const int mtx1[][MAX_SIZE], size_t rows1, size_t cols1, 
					const int mtx2[][MAX_SIZE], size_t rows2, size_t cols2,
						int resultMtx[][MAX_SIZE], size_t resRows, size_t resCols);
void subtractMatrixes(const int mtx1[][MAX_SIZE], size_t rows1, size_t cols1, 
						const int mtx2[][MAX_SIZE], size_t rows2, size_t cols2,
							int resultMtx[][MAX_SIZE], size_t resRows, size_t resCols);
int rowByColumn(const int mtx1[][MAX_SIZE], size_t rows1, size_t cols1,
	const int mtx2[][MAX_SIZE], size_t rows2, size_t cols2,
	int rowIndex, int colIndex);
void multiplyMatrixes(const int mtx1[][MAX_SIZE], size_t rows1, size_t cols1,
						const int mtx2[][MAX_SIZE], size_t rows2, size_t cols2,
							int resultMtx[][MAX_SIZE], size_t resRows, size_t resCols);

int main()
{
	matrixDrive();
}

void matrixDrive() {
	int mtx1[MAX_SIZE][MAX_SIZE];
	int mtx2[MAX_SIZE][MAX_SIZE];
	int resultMtx[MAX_SIZE][MAX_SIZE];

	int rows1, cols1;
	std::cout << "Enter valid dimensions of matrix one: ";
	std::cin >> rows1 >> cols1;
	std::cout << "Enter matrix one: \n";
	readMatrix(mtx1, rows1, cols1);

	int rows2, cols2;
	std::cout << "Enter valid dimensions of matrix two: ";
	std::cin >> rows2 >> cols2;
	std::cout << "Enter matrix two: \n";
	readMatrix(mtx2, rows2, cols2);

	std::cout << "Matrix one is triangular: " << std::boolalpha << isMatrixTriangular(mtx1, rows1, cols1) << "\n";
	std::cout << "Matrix two is triangular: " << std::boolalpha << isMatrixTriangular(mtx2, rows2, cols2) << "\n";
	std::cout << "Matrix one is symmetrical: " << std::boolalpha << isMatrixSymmetrical(mtx1, rows1, cols1) << "\n";
	std::cout << "Matrix two is symmetrical: " << std::boolalpha << isMatrixSymmetrical(mtx2, rows2, cols2) << "\n";

	if (canMatrixesBeSummed(rows1, cols1, rows2, cols2)) {
		sumMatrixes(mtx1, rows1, cols1, mtx2, rows2, cols2, resultMtx, rows1, cols1);
		std::cout << "Sum of matrix one and matrix two: " << "\n";
		printMatrix(resultMtx, rows1, rows1);
		std::cout << "Sum of matrix one and matrix two triangular: " << std::boolalpha << isMatrixTriangular(resultMtx, rows1, cols1) << "\n";
		std::cout << "Sum of matrix one and matrix two symmetrical: " << std::boolalpha << isMatrixSymmetrical(resultMtx, rows1, cols1) << "\n";
	}
	else {
		std::cout << "The dimensions of two matrices must be the same!\n";
	}

	if (canMatrixesBeSummed(rows1, cols1, rows2, cols2)) {
		subtractMatrixes(mtx1, rows1, cols1, mtx2, rows2, cols2, resultMtx, rows1, cols1);
		std::cout << "Subtraction of matrix one and matrix two: " << "\n";
		printMatrix(resultMtx, rows1, rows1);
		std::cout << "Subtraction of matrix one and matrix two triangular: " << std::boolalpha << isMatrixTriangular(resultMtx, rows1, cols1) << "\n";
		std::cout << "Subtraction of matrix one and matrix two symmetrical: " << std::boolalpha << isMatrixSymmetrical(resultMtx, rows1, cols1) << "\n";
	}
	else {
		std::cout << "The dimensions of two matrices must be the same!\n";
	}

	if (canMatrixesBeMultiplied(cols1, rows2)) {
		multiplyMatrixes(mtx1, rows1, cols1, mtx2, rows2, cols2, resultMtx, rows2, cols1);
		std::cout << "Multiplication of matrix one and matrix two: " << "\n";
		printMatrix(resultMtx, rows2, cols1);
		std::cout << "Multiplication of matrix one and matrix two triangular: " << std::boolalpha << isMatrixTriangular(resultMtx, rows1, cols1) << "\n";
		std::cout << "Multiplication of matrix one and matrix two symmetrical: " << std::boolalpha << isMatrixSymmetrical(resultMtx, rows1, cols1) << "\n";
	}
	else {
		std::cout << "The number of columns of the first matrix must be the same as the number of rows as the second matrix!\n";
	}

}

void readMatrix(int mtx[][MAX_SIZE], size_t rows, size_t cols) {
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++)
		{
			int input;
			std::cin >> input;
			mtx[i][j] = input;
		}
	}
}

void printMatrix(const int mtx[][MAX_SIZE], size_t rows, size_t cols) {
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++)
			std::cout << mtx[i][j] << ", ";

		std::cout << "\n";
	}

}

bool isMatrixTriangular(const int mtx[][MAX_SIZE], size_t rows, size_t cols) {
	for (size_t i = 0; i < rows - 1; i++)
		if (mtx[i+1][i] != 0)
			return false;

	return true;
}

bool isMatrixSymmetrical(const int mtx[][MAX_SIZE], size_t rows, size_t cols) {
	// only square matrixes can be symmetrical
	if (rows != cols) 
		return false;

	for (size_t i = 0; i < rows; i++)
		for (size_t j = i + 1; j < cols; j++)
			if (mtx[i][j] != mtx[j][i])
				return false;

	return true;
}

bool canMatrixesBeSummed(size_t rows1, size_t cols1, size_t rows2, size_t cols2) {
	return rows1 == rows2 && cols1 == cols2;
}

bool canMatrixesBeMultiplied(size_t cols1, size_t rows2) {
	return cols1 == rows2;
}

void sumMatrixes(const int mtx1[][MAX_SIZE], size_t rows1, size_t cols1,
					const int mtx2[][MAX_SIZE], size_t rows2, size_t cols2,
						int resultMtx[][MAX_SIZE], size_t resRows, size_t resCols) {

	for (size_t i = 0; i < rows1; i++)
		for (size_t j = 0; j < cols1; j++)
			resultMtx[i][j] = mtx1[i][j] + mtx2[i][j];
}

void subtractMatrixes(const int mtx1[][MAX_SIZE], size_t rows1, size_t cols1,
						const int mtx2[][MAX_SIZE], size_t rows2, size_t cols2,
							int resultMtx[][MAX_SIZE], size_t resRows, size_t resCols) {

	for (size_t i = 0; i < rows1; i++)
		for (size_t j = 0; j < cols1; j++)
			resultMtx[i][j] = mtx1[i][j] - mtx2[i][j];
}

void multiplyMatrixes(const int mtx1[][MAX_SIZE], size_t rows1, size_t cols1,
						const int mtx2[][MAX_SIZE], size_t rows2, size_t cols2,
							int resultMtx[][MAX_SIZE], size_t resRows, size_t resCols) {

	for (size_t i = 0; i < resRows; i++)
		for (size_t j = 0; j < resCols; j++)
			resultMtx[i][j] = rowByColumn(mtx1, rows1, cols1, mtx2, rows2, cols2, i, j);
}

int rowByColumn(const int mtx1[][MAX_SIZE], size_t rows1, size_t cols1,
				const int mtx2[][MAX_SIZE], size_t rows2, size_t cols2,
				int rowIndex, int colIndex) {
	int result = 0;

	for (size_t i = 0; i < rows1; i++)
		result += mtx1[i][rowIndex] * mtx2[colIndex][i];

	return result;
}
