#include <iostream>;

int getNumWhichIsPresentOddTimesInTheArray(const int arr[], int size) {
	int result = 0;

	for (size_t i = 0; i < size; i++) {
		result ^= arr[i];
	}
	return result;
}

bool isEven(int number) {
	int mask = 1;
	// check if the last bit is a 1 to see if it is odd
	// !isOdd => isEven
	return !(number & mask);
}

bool isPowerOfTwo(unsigned n) {
	return (n & n - 1) == 0;
}
unsigned setBitToOne(unsigned number, unsigned index) {
	unsigned int mask = 1;
	// 0000100000
	mask <<= index; // everywhere zero apart from the index where you want to set 1

	// 0000100000
	// 1110000111
	// |
	// 1110100111
	return number | mask;
}

unsigned setBitZero(unsigned int number, unsigned int index) {
	unsigned int mask = 1;
	// 0000100000
	mask <<= index;
	// 1111011111
	mask = ~mask; // everywhere one apart from the index where you want to set 0

	// 0000100010
	// 1111011111
	// &
	// 0000000010
	return number & mask;
}

unsigned toggleBit(unsigned number, unsigned index) {
	unsigned int mask = 1;
	// 0000100000
	mask <<= index; // everywhere zero apart from the index where you want to toggle

	// 0000100000
	// 1110000111
	// ^
	// 1110100111
	// if it was zero => 0 ^ 1 => 1
	// if it was one => 1 ^ 1 => 0
	return number ^ mask;
}

bool checkBitValue(unsigned number, unsigned index) {
	unsigned int mask = 1;
	// 0000100000
	mask <<= index;

	// with equal to mask => the number is one => true
	// else it was zero
	// 0000100000
	// 1110100001
	// &
	// 0000100000
	return (mask & number) == mask;
}

unsigned powerOfTwo(unsigned power) {
	// 2^31 is the maximum power of two that can be represented as an unsigned int
	if (power > 31) {
		return 0;
	}

	// 1 << n is equivalent to 2^n
	return 1 << power;
}

unsigned setBitValue(unsigned number, unsigned index, bool value) {
	return value
		? setBitToOne(number, index)
		: setBitZero(number, index);
}

int main() {
	std::cout << isPowerOfTwo(2);
	std::cout << isPowerOfTwo(8);
	std::cout << isPowerOfTwo(16);
	std::cout << isPowerOfTwo(5);
}