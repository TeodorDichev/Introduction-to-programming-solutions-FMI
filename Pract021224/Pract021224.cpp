#include <iostream>

unsigned powerOfTwo(unsigned power) {
	if (power > 31) {
		return 0;
	}

	return 1 << power;
}
bool checkBitValue(unsigned number, unsigned index) {
	unsigned int mask = 1;
	mask <<= index;
	return (mask & number) == mask;
}
unsigned setBitZero(unsigned number, unsigned index) {
	unsigned int mask = 1;
	mask <<= index;
	mask = ~mask;
	return number & mask;
}
unsigned getNumFromBits(unsigned number, unsigned startIndex, unsigned length) {
	// shift само ако има смисъл, cast защото иначе unsigned overflows
	if ((int)(startIndex - length) + 1 >= 0)
		number = number >> startIndex - length + 1;
	// намали дължината така че да вземе само останалите цифри
	else
		length = length - startIndex;

	// степен на двойката 2^k 0001 0000, k = 4
	// вадим 1 -> 0000 1111
	unsigned mask = powerOfTwo(length) - 1; // 0000 1111

	// побитово &
	// 1011 1001
	// 0000 1111
	return number & mask;
}
void bitSwap(unsigned& num1, unsigned& num2) {
	num1 ^= num2;
	num2 ^= num1;
	num1 ^= num2;
}

void task06() {
	int n, k;
	std::cin >> n >> k;
	std::cout << getNumFromBits(n, k - 1, k);
}
void task07() {
	unsigned n;
	std::cin >> n;

	int i = 0;
	while (n != 0)
	{
		if (checkBitValue(n, i)) {
			n = setBitZero(n, i);
			std::cout << n;
			return;
		}
		i++;
	}
}
void task08() {
	int x, m, n;
	std::cin >> x >> m >> n;
	std::cout << getNumFromBits(x, m, n);
}
void task09() {
	unsigned a, b;
	std::cin >> a >> b;
	bitSwap(a, b);
	std::cout << a << " " << b;
}
void task10() {
	unsigned n;
	char weekDays[7][10] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	std::cin >> n;
	for (size_t i = 0; i < 7; i++)
	{
		if (checkBitValue(n, i)) {
			for (size_t j = 0; j < 10; j++)
				std::cout << weekDays[i][j];

			std::cout << '\n';
		}
	}
}
void task11() {
	unsigned int n;
	std::cin >> n;
	for (size_t i = 32; i > 0; i-=8)
	{
		std::cout << getNumFromBits(n, i, 9) << " ";
	}
}

int main()
{
	task11();
}
