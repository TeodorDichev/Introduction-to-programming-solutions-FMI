// task08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

constexpr size_t MAX_SIZE = 100;

void readMatrix(int matrix[][MAX_SIZE], size_t rows, size_t cols);
int getMatrixSum(int matrix[][MAX_SIZE], size_t rowsIndex, size_t colsIndex, int q);
void printSubMatrixWithSumK(int matrix[][MAX_SIZE], size_t rows, size_t cols, int q);

int main()
{
    int rows, cols;
    std::cin >> rows >> cols;
    if (rows > MAX_SIZE || rows < 0 || cols > MAX_SIZE || cols < 0) {
        std::cout << "Invalid input";
        return -1;
    }

    int matrix[MAX_SIZE][MAX_SIZE];
    readMatrix(matrix, rows, cols);

    int q;
    std::cout << "Enter q: ";
    std::cin >> q;

    printSubMatrixWithSumK(matrix, rows, cols, q);
}

void readMatrix(int matrix[][MAX_SIZE], size_t rows, size_t cols) 
{
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            std::cin >> matrix[i][j];
}

int getMatrixSum(int matrix[][MAX_SIZE], size_t rowsIndex, size_t colsIndex, int q) 
{
    int sum = 0;
    for (size_t i = rowsIndex; i < rowsIndex + q; i++)
        for (size_t j = colsIndex; j < colsIndex + q; j++)
            sum += matrix[i][j];

    return sum;
}

void printSubMatrixWithSumK(int matrix[][MAX_SIZE], size_t rows, size_t cols, int q) 
{
    int minRowIndex = 0, minColIndex = 0;
    int minSubMatrixSum = getMatrixSum(matrix, 0, 0, q);

    for (size_t i = 0; i <= rows - q; i++)
    {
        for (size_t j = 0; j <= cols - q; j++)
        {
            if (i == 0 && j == 0)
                continue;

            int subMatrixSum = getMatrixSum(matrix, i, j, q);
            if (subMatrixSum < minSubMatrixSum) {
                minSubMatrixSum = subMatrixSum;
                minRowIndex = i;
                minColIndex = j;
            }
        }
    }

    std::cout << minSubMatrixSum << " (" << minRowIndex << " " << minColIndex << ")";
}
