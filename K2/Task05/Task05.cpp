// Инфикс на число наричаме такова число, което се съдържа в друго.
// Например 23 е инфикс на 1234, 123 е инфикс на 1234, 
// 34 е инфикс на 1234 и 1234 е инфикс на 1234. 
// От стандартния вход се въвжда цяло число K, 
// след което започват да се въвеждат числа.
// Въвеждането спира при прочитането на числото 0. 
// За всяко едно от числата да се изведе дали K е негов инфикс.

#include <iostream>

bool isSuffix(unsigned n, unsigned k)
{
	if (k == 0)
		return (n % 10 == 0);

	while (n >= k && k > 0)
	{
		int lastDigitN = n % 10;
		int lastDigitK = k % 10;

		if (lastDigitN != lastDigitK)
			return false;

		n /= 10;
		k /= 10;
	}

	return true;
}

bool isInfix(unsigned n, unsigned k)
{
	while (n >= k)
	{
		if (isSuffix(n, k))
			return true;

		n /= 10;
	}

	return false;
}

int main()
{
	unsigned k;
	std::cin >> k;

	int n;
	std::cin >> n;

	while (n != 0)
	{
		std::cout << isInfix(n, k) << '\n';
		std::cin >> n;
	}
}