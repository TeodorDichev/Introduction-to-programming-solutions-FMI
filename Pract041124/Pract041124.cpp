#include <iostream>
void swap(int& a, int& b);
void swap(double& a, double& b);
void reduce(int& a, int& b);
int gcd(int a, int b);
int lcm(int a, int b);
void sumOfFractions(int a, int b, int c, int d);
int getNumFromEvenPos(int a);
int getNumFromOddPos(int a);
void swapKDigit(int& m, int& n, int k);
bool isRowEvenOrOdd(int n);
int getNumFromItoJ(int num, int i, int j);
void getDigitsAverageEqualOrGreaterThanK(int m, int n, int k);
double sumDigitsAverage(int num);
void getNumsWithTwoAdjacentEqualDigits(int k, int l);
int getNumLength(int num);
void moveKDigitsToBeginning(int& a, int& b, int k);
int pow(int number, int power);
bool isDateValid(unsigned day, unsigned month, unsigned year);
bool isLeapYear(unsigned year);
void printDateAfterNDays(unsigned day, unsigned month, unsigned year, unsigned daysToAdd);
unsigned getDaysInMonth(unsigned month, unsigned year);
void getLastShow(int n, unsigned int& maxHours, unsigned int& maxMins);

int main() {
	char a = 65;
	std::cout << a;
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void swap(double& a, double& b) {
	double temp = a;
	a = b;
	b = temp;
}

void reduce(int& a, int& b) {
	int _gcd = gcd(a, b);
	a /= _gcd;
	b /= _gcd;
}

int gcd(int a, int b) {
	if (a < b) swap(a, b);

	while (b != 0) {
		int mod = a % b;
		a = b;
		b = mod;
	}

	return a;
}

int lcm(int a, int b) {
	return (a / gcd(a, b)) * b;
}

void sumOfFractions(int a, int b, int c, int d) {
	int denominator = lcm(b, d);
	int numerator = a * (denominator / b) + c * (denominator / d);
	reduce(numerator, denominator);
	std::cout << numerator << "/" << denominator;
}

int getNumFromEvenPos(int a) {
	int result = 0, numDigits = getNumLength(a), numCopy = a;
	if (numDigits % 2 != 0) a /= 10;
	for (int i = 1; a > 0; a /= 100, i *= 10)
		result += (a % 10) * i;
	return result;
}

int getNumFromOddPos(int a) {
	int result = 0, numCopy = a, numDigits = getNumLength(a);
	if (numDigits % 2 == 0) a /= 10;
	for (int i = 1; a > 0; a /= 100, i *= 10)
		result += (a % 10) * i;
	return result;
}

void swapKDigit(int& m, int& n, int k) {
	int cntM = getNumLength(m), cntN = getNumLength(n);

	if (k > cntM || k > cntN || k < 1) {
		std::cout << "Invalid digit position." << std::endl;
		return;
	}

	int mPower = 1, nPower = 1;
	for (int i = 0; i < cntM - k; i++) mPower *= 10;
	for (int i = 0; i < cntN - k; i++) nPower *= 10;

	int mKDigit = (m / mPower) % 10;
	int nKDigit = (n / nPower) % 10;

	m = m - mKDigit * mPower + nKDigit * mPower;
	n = n - nKDigit * nPower + mKDigit * nPower;
}

// a0 = 1
// an + 1 = (an * 3) / 2

// for main function
// int n;
// std::cin >> n;
// std::cout << (isRowEvenOrOdd(n) ? "even" : "odd");

bool isRowEvenOrOdd(int n) {
	double an = 1;
	for (int i = n; i > 0; i--)
		an = (an * 3) / 2;
	return ((int)an) % 2 == 0;
}

int getNumFromItoJ(int num, int i, int j) {
	if (i > j) swap(i, j);

	int numDigits = getNumLength(num);
	if (i >= numDigits || j >= numDigits || i < 0 || j < 0)
		return -1; // Indicate an invalid range

	int result = 0, power = 1;
	for (int pos = numDigits - 1; num > 0; num /= 10, pos--) {
		int currentDigit = num % 10;
		if (pos >= i && pos <= j) {
			result += currentDigit * power;
			power *= 10;
		}
	}

	return result;
}

void getDigitsAverageEqualOrGreaterThanK(int m, int n, int k) {
	if (m > n) swap(m, n);
	for (; m <= n; m++)
		if (sumDigitsAverage(m) - k >= 0)
			std::cout << m << " ";
}

double sumDigitsAverage(int num) {
	int result = 0;
	int numDigits = getNumLength(num);

	for (; num > 0; num /= 10)
		result += num % 10;
	return result / numDigits;
}

void getNumsWithTwoAdjacentEqualDigits(int k, int l) {
	if (k > l) swap(k, l);

	for (int num = k; num <= l; num++) {
		int current = num;
		bool hasAdjacentEqual = false;

		while (current >= 10) {
			int lastDigit = current % 10;
			int secondLastDigit = (current / 10) % 10;

			if (lastDigit == secondLastDigit) {
				hasAdjacentEqual = true;
				break;
			}
			current /= 10;
		}

		if (hasAdjacentEqual)
			std::cout << num << " ";
	}
}

int getNumLength(int num) {
	int numDigits = 0;
	for (int temp = num; temp > 0; temp /= 10)
		numDigits++;
	return numDigits;
}

void moveKDigitsToBeginning(int& a, int& b, int k) {
	int aLastDigits = 0, power = 1, bDigitCount = getNumLength(b);
	while (k > 0) {
		aLastDigits += (a % 10) * power;
		power *= 10;
		a /= 10;
		k--;
	}
	b = aLastDigits * pow(10, bDigitCount) + b;
	std::cout << a << " " << b;
}

int pow(int number, int power) {
	if (power == 0) return 1;

	for (int i = number; power > 1; power--)
		number *= i;
	return number;
}

bool isDateValid(unsigned day, unsigned month, unsigned year) {
	if (month < 1 || month > 12 || year == 0) return false;
	return day >= 1 && day <= getDaysInMonth(month, year);
}

bool isLeapYear(unsigned year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

unsigned getDaysInMonth(unsigned month, unsigned year) {
	if (month == 2)
		return isLeapYear(year) ? 29 : 28;
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	return 31;
}

void printDateAfterNDays(unsigned day, unsigned month, unsigned year, unsigned daysToAdd) {
	if (!isDateValid(day, month, year)) { 
		std::cout << "This date is invalid!";
		return;
	}

	day += daysToAdd;
	while (day > getDaysInMonth(month, year)) {
		day -= getDaysInMonth(month, year);
		month++;

		if (month > 12) {
			month = 1;
			year++;
		}
	}

	std::cout << "Date after " << daysToAdd << " days: "
		<< day << "/" << month << "/" << year << std::endl;
}

void getLastShow(int n, unsigned int& maxHours, unsigned int& maxMins) {
	maxHours = 0;
	maxMins = 0;

	for (int i = 0; i < n; ++i) {
		unsigned int startHour, startMin, duration;
		std::cin >> startHour >> startMin >> duration;

		unsigned int totalMinutes = startHour * 60 + startMin + duration;
		unsigned int endHour = (totalMinutes / 60) % 24;
		unsigned int endMin = totalMinutes % 60;

		if (endHour > maxHours || (endHour == maxHours && endMin > maxMins)) {
			maxHours = endHour;
			maxMins = endMin;
		}
	}
}
