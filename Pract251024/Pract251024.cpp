#include <iostream>
int pow(int number, int power);
double squareRoot(double number);
int myAbs(int number);
int myAbs(int number);
bool isEven(int number);
bool isDigit(char ch);
char toUpper(char ch);
char toLower(char ch);
int compareTo(double a, double b);
int toNumber(char ch);
char toCharacter(int number);
bool isPrime(int number);
int gcd(int a, int b);
int gcdRecursion(int a, int b);
int lcm(int a, int b);
int getKDigitOfN(int n, int k);
int reverse(int num);
unsigned concat(unsigned int first, unsigned int second);
double getDistance(int x1, int y1, int x2, int y2);
double getPerimeter(int x1, int y1, int x2, int y2, int x3, int y3);
double getArea(int x1, int y1, int x2, int y2, int x3, int y3);
bool isInCircleWithRadius(int x1, int y1, int x2, int y2, int x3, int y3, int r);
void gcdAndLcmOfMultipleNumbers();
int sortDigits(unsigned int number);
int getRemainder(int first, int second);
int getDivision(int first, int second);
int squareRootToLower(int number);
unsigned int log(unsigned int n, unsigned int k);

int main()
{
}

int pow(int number, int power) {
	if (power == 0) return 1;

	for (int i = number; power > 1; power--)
		number *= i;
	return number;
}

const int epsilon = 1.0E-8;
double squareRoot(double number)
{
	double x = number;
	double y = 1;
	while (x - y > epsilon)
	{
		x = (x + y) / 2;
		y = number / x;
	}
	return x;
}

int myAbs(int number) {
	return (number < 0) ? -number : number;
}

bool isEven(int number) {
	return number % 2 == 0;
}

bool isDigit(char ch) {
	return '0' <= ch && ch <= '9';
}

char toUpper(char ch) {
	return (ch > 'A' && ch < 'Z') ? ch : ch + ('A' - 'a');
}

char toLower(char ch) {
	return (ch > 'a' && ch < 'z') ? ch : ch - ('A' - 'a');
}

int compareTo(double a, double b) {
	if (a > b > epsilon) return 1;
	else if (a - b < epsilon) return -1;
	else return 0;
}

int toNumber(char ch) {
	char j = '0';
	for (int i = 0; i < 10; i++, j++)
		if (ch == j)
			return i;
}

char toCharacter(int number) {
	char j = '0';
	for (int i = 0; i < 10; i++, j++)
		if (i == number)
			return j;
}

bool isPrime(int number) {
	if (number <= 1) return false;
		
	int sqrtN = squareRoot(number);
	for (int i = 2; i <= sqrtN; i++)
		if (number % i == 0)
			return false;

	return true;
}

int gcd(int a, int b) {
	int gcd = a > b ? b : a;

	while (b != 0)
	{
		int mod = a % b;
		a = b;
		b = mod;
	}

	return a;
}

int gcdRecursion(int a, int b) {
	return b == 0 ? a : gcdRecursion(b, a % b);
}

int lcm(int a, int b) {
	return (a / gcd(a, b)) * b;
}

int getKDigitOfN(int n, int k) {
	int countOfDigits = 0;
	for (int copyOfN = n; copyOfN > 0; copyOfN /= 10, countOfDigits++);
	if (k < 1 || k > countOfDigits) return -1;
	return (n / (int)(pow(10, countOfDigits - k))) % 10;
}

int reverse(int number) {
	int reversed = 0;

	while (number != 0) {
		(reversed *= 10) += number % 10;
		number /= 10;
	}

	return reversed;
}
unsigned concat(unsigned int first, unsigned int second) {
	int countOfDigits = -1;
	unsigned res = 0;

	first = reverse(first);
	second = reverse(second);

	for (int copyOfN = first; copyOfN > 0; copyOfN /= 10, countOfDigits++);
	for (int copyOfN = second; copyOfN > 0; copyOfN /= 10, countOfDigits++);

	for (; first > 0; first /= 10, countOfDigits--)
		res += (first % 10) * pow(10, countOfDigits);
	for (; second > 0; second /= 10, countOfDigits--)
		res += (second % 10) * pow(10, countOfDigits);

	return res;
}

double getDistance(int x1, int y1, int x2, int y2) {
	return squareRoot(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

double getPerimeter(int x1, int y1, int x2, int y2, int x3, int y3) {
	double a = getDistance(x1, y1, x2, y2);
	double b = getDistance(x1, y1, x3, y3);
	double c = getDistance(x2, y2, x3, y3);

	return a + b + c;
}
double getArea(int x1, int y1, int x2, int y2, int x3, int y3) {
	double s = getPerimeter(x1, y1, x2, y2, x3, y3) / 2;
	double a = getDistance(x1, y1, x2, y2);
	double b = getDistance(x1, y1, x3, y3);
	double c = getDistance(x2, y2, x3, y3);

	return squareRoot(s * (s - a) * (s - b) * (s - c));
}

bool isInCircleWithRadius(int x1, int y1, int x2, int y2, int x3, int y3, int r) {
	double a = getDistance(x1, y1, x2, y2);
	double b = getDistance(x1, y1, x3, y3);
	double c = getDistance(x2, y2, x3, y3);

	return (a <= r && b <= r && c <= r);
}

void gcdAndLcmOfMultipleNumbers() {
	int a, n;
	std::cin >> n >> a;
	int gcdRes = a;
	int lcmRes = a;

	for (; n - 1 > 0; n--)
	{
		std::cin >> a;
		gcdRes = gcd(gcdRes, a);
		lcmRes = lcm(lcmRes, a);
	}

	std::cout << "GCD: " << gcdRes << '\n';
	std::cout << "LCM: " << lcmRes << '\n';
}

int sortDigits(unsigned int number) {
	int cnt = 0;
	unsigned int result = 0;
	for (unsigned int i = number; i > 0; i /= 10, cnt++);

	for (int i = 9; i >= 0; i--)
	{
		int digitCount = 0;
		unsigned int numberCopy = number;

		for (int digit = numberCopy % 10; numberCopy != 0; numberCopy /= 10, digit = numberCopy % 10)
			if (digit == i)
				digitCount++;

		for (int j = 0; j < digitCount; j++, cnt--)
			result += i * pow(10, cnt - 1);
	}
	return result;
}

int getRemainder(int first, int second) {
	int bigger = (first >= second ? first : second);
	int smaller = (first < second ? first : second);
	int result = 0;
	result = bigger / smaller;
	result = bigger - (smaller * result);

	return result;
}

int getDivision(int first, int second) {
	int result = 0;
	if (first >= second) {
		int remainder = (first % second);
		first -= remainder;

		while (first >= second) {
			first -= second;
			result++;
		}
	}
	return result;
}

int squareRootToLower(int number) {
	return log(number, 2);
}

unsigned int log(unsigned int n, unsigned int k) {
	unsigned int powerOfK = 1;
	unsigned int count = 0;

	while (powerOfK <= n) {
		powerOfK *= k;
		count++;
	}

	return count - 1;
}