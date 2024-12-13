#include <iostream>
void mergeAndSort(const int* arr1, const int size1, const int* arr2, const int size2, int* result);
int AbsoluteValue(int number);
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
int getMin(const int* arr, const int len);
int getMax(const int* arr, const int len);
void getPositiveArray(const int* arr, const int len, int* result, int& resultSize);
int findMissingElement(int* arr, const int len);
bool areLinearlyDependent(const int* arr1, const int* arr2, int size);
bool containsDigit(int num, int digit);
void nullElementsNotContainingDigitEqualToIndex(int* arr1, int size);
bool isGeometricProgression(const int* arr, int size);
int getLongestSequenceLength(const int* arr, int size);

constexpr int MAX_SIZE = 100;
int main()
{

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
			if ((arr1[i] == arr2[j]) && !contains(result, size, arr1[i])) {
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
int getMin(const int* arr, const int len) {
	int min = arr[0];
	for (int i = 1; i < len; i++)
		if (min > arr[i])
			min = arr[i];
	return min;
}
int getMax(const int* arr, const int len) {
	int max = arr[0];
	for (int i = 1; i < len; i++)
		if (max < arr[i])
			max = arr[i];
	return max;
}
void getPositiveArray(const int* arr, const int len, int* result, int& resultSize) {
	for (int i = 0; i < len; i++)
	{
		if (arr[i] > 0) {
			result[resultSize] = arr[i];
			resultSize++;
		}
	}
}
int AbsoluteValue(int number) {
	return (number < 0) ? -number : number;
}
const double EPSILON = 1e-9;
bool areLinearlyDependent(const int* arr1, const int* arr2, int size) {
	double lambda = 0;
	bool lambdaDefined = false;

	for (int i = 0; i < size; i++) {
		if (arr2[i] != 0) {
			if (!lambdaDefined) {
				lambda = double(arr1[i]) / arr2[i];
				lambdaDefined = true;
			}
			else {
				double currentLambda = double(arr1[i]) / arr2[i];
				if (AbsoluteValue(currentLambda - lambda) > EPSILON) {
					return false;
				}
			}
		}
		else if (arr1[i] != 0) {
			// arr2[i] == 0, но arr1[i] != 0 => не може да съществува коефициент
			return false;
		}
	}
	return lambdaDefined;
}
int findMissingElement(int* arr, const int len) {
	selectionSort(arr, len);
	for (int i = 0; i < len; i++)
		if (arr[i] != i)
			return i;

	return -1;
}
bool containsDigit(int num, int digit) {
	while (num != 0) {
		if (num % 10 == digit)
			return true;

		num /= 10;
	}
	return false;
}
void nullElementsNotContainingDigitEqualToIndex(int* arr1, int size) {
	for (int i = 0; i < size; i++)
		if (!containsDigit(arr1[i], i))
			arr1[i] = 0;
}
bool isGeometricProgression(const int* arr, int size) {
	double q = (double)(arr[1]) / arr[0];

	for (int i = 1; i < size - 1; i++) {
		double currentQ = (double)(arr[i + 1]) / arr[i];

		if (AbsoluteValue(currentQ - q) > EPSILON)
			return false;
	}

	return true;
}
int getLongestSequenceLength(const int* arr, int size) {
	int maxLength = 1;
	int currentLength = 1;

	for (int i = 1; i < size; i++) {

		if (arr[i] == arr[i - 1])
			currentLength++;
		else {
			if (currentLength > maxLength)
				maxLength = currentLength;

			currentLength = 1;
		}
	}

	if (currentLength > maxLength)
		maxLength = currentLength;

	return maxLength;
}