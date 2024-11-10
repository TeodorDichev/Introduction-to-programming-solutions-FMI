#include <iostream>
void mergeAndSort(const int* arr1, const int size1, const int* arr2, const int size2, int* result);
void swap(int& a, int& b);
void printArray(const int* arr, int len);
void readArray(int* arr, int& size);
int task15(const int* arr, const int len);
void increment(int* arr, const int len);
bool contains(const int* arr, const int len, int searchedValue);
bool containsArray(const int* arr1, const int size1, const int* arr2, const int size2);
bool areEqual(const int* arr1, const int* arr2, const int size);
void intersect(const int* arr1, const int size1, const int* arr2, const int size2, int* result, int& size);
void unite(const int* arr1, const int size1, const int* arr2, const int size2, int* result, int& size);
void selectionSort(int* arr, int len);
constexpr int MAX_SIZE = 100;
int main()
{
	int arr1[MAX_SIZE];
	int arrSize1 = 0;
	int arr2[MAX_SIZE];
	int arrSize2 = 0;
	readArray(arr1, arrSize1);
	readArray(arr2, arrSize2);
	std::cout << containsArray(arr1, arrSize1, arr2, arrSize2);
}

void readArray(int* arr, int& size) {
	while (size < MAX_SIZE) {
		char ch;
		std::cin.get(ch);
		if (ch == '[' || ch == ' ') {
			int num;
			std::cin >> num;
			arr[size] = num;
			size++;
		}
		else if (ch == ',') continue;
		else if (ch == ']')	return;
	}
}
void printArray(const int* arr, int len) {
	for (int i = 0; i < len; i++)
		std::cout << arr[i] << " ";
}
void mergeAndSort(const int* arr1, const int size1, const int* arr2, const int size2, int* result) {
	int i = 0, j = 0, k = 0;
	while (i < size1 && j < size2) {

		if (arr1[i] < arr2[j])
			result[k++] = arr1[i++];
		else
			result[k++] = arr2[j++];
	}

	while (i < size1)
		result[k++] = arr1[i++];

	while (j < size2)
		result[k++] = arr2[j++];
}
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
int task15(const int* arr, const int len) {
	int low = 0, high = len - 1;
	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (arr[mid] == 0)
			return mid;
		if (arr[mid] % 2 == 0)
			low = mid + 1;
		else
			high = mid - 1;
	}

	return -1;
}
void selectionSort(int* arr, int len) {
	for (int i = 0; i < len - 1; ++i) {
		int min_idx = i;

		for (int j = i + 1; j < len; ++j)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		if (i != min_idx) swap(arr[i], arr[min_idx]);
	}
}
bool contains(const int* arr, const int len, int searchedValue) {
	for (int i = 0; i < len; i++)
		if (arr[i] == searchedValue)
			return true;
	return false;
}
void intersect(const int* arr1, const int size1, const int* arr2, const int size2, int* result, int& size) {
	// more efficient way will be to order the arrays but them they will not be constants
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++)
		{
			if((arr1[i] == arr2[j]) && !contains(result, size, arr1[i])) {
				// EDGE CASE: if arr1 and arr2 contain repeating elements we do not want to add them to the result
				result[size] = arr1[i];
				size++;
			}
		}
	}
}
void unite(const int* arr1, const int size1, const int* arr2, const int size2, int* result, int& size) {
	for (int i = 0; i < size1; i++, size++)
		result[size] = arr1[i];

	for (int j = 0; j < size2; j++)
	{
		if (!contains(result, size, arr2[j])) {
			result[size] = arr2[j];
			size++;
		}
	}
}
void increment(int* arr, const int len) {
	for (int i = len - 1; i >= 0; i--)
	{
		if (arr[i] != 9) {
			arr[i] += 1;
			return;
		}

		arr[i] = 0;
	}
}
bool areEqual(const int* arr1, const int* arr2, const int size) {
	for (int i = 0; i < size; i++)
		if (arr1[i] != arr2[i])
			return false;

	return true;
}
bool containsArray(const int* arr1, const int size1, const int* arr2, const int size2) {
	// could be done by using unite
	// if union is equal to the first array than the function will return true
	int unitedArr[MAX_SIZE];
	int unitedArrSize = 0;
	unite(arr1, size1, arr2, size2, unitedArr, unitedArrSize);
	return areEqual(arr1, unitedArr, unitedArrSize);
}