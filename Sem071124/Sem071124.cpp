#include <iostream>

void swap(int& a, int& b);

// '*' return a pointer to the first element in the array
// for static memory you may not use 'int len' as a param
// you can use 'int size = sizeof(arr) / sizeof(int);

void printArray(const int* arr, int len);
bool contains(const int* arr, int len, int searchedValue);
int linearSearch(const int* arr, int len, int searchedValue);
int binarySearch(const int* arr, int len, int searchedValue);
void reverseArray(int* arr, int len);
void selectionSort(int* arr, int len);
void sieveOfEratosthenes(int limit);

int main() {
	sieveOfEratosthenes(23);
	return 0;
}

void printArray(const int* arr, int len) {
	for (int i = 0; i < len; i++)
		std::cout << arr[i] << " ";
}

bool contains(const int* arr, int len, int searchedValue) {
	for (int i = 0; i < len; i++)
		if (arr[i] == searchedValue)
			return true;
	return false;
}


int linearSearch(const int* arr, int len, int searchedValue) {
	for (int i = 0; i < len; i++)
		if (arr[i] == searchedValue)
			return i;
	return -1;
}

int binarySearch(const int* arr, int len, int searchedValue) {
	int low = 0, high = len - 1;
	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (arr[mid] == searchedValue)
			return mid;
		if (arr[mid] < searchedValue)
			low = mid + 1;
		else
			high = mid - 1;
	}

	return -1;
}

void reverseArray(int* arr, int len) {
	for (int i = 0; i < len / 2; i++)
		swap(arr[i], arr[len - i - 1]);
}

void selectionSort(int* arr, int len) {
	for (int i = 0; i < len - 1; ++i) {
		int min_idx = i;

		for (int j = i + 1; j < len; ++j)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		swap(arr[i], arr[min_idx]);
	}
}

void sieveOfEratosthenes(int limit)
{
	if (limit <= 0 && limit >= 1000) {
		std::cout << "Invalid limit";
		return;
	}

	const int MAX_SIZE = 1000;
	bool primes[MAX_SIZE];

	for (int i = 2; i < limit; i++)
		primes[i] = true;

	for (int p = 2; p * p <= limit; p++)
		if (primes[p] == true)
			for (int i = p * p; i <= limit; i += p)
				primes[i] = false;

	for (int p = 2; p <= limit; p++)
		if (primes[p])
			std::cout << p << " ";
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}