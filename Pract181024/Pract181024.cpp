#include <iostream>

void Problem07();
void Problem08();
void Problem09();
void Problem10();
void Problem11();
void Problem12();
void Problem13();
void Problem14();
void Problem15();
void Problem16();
void Problem17();
void ProblemBonus();

int main() {
	ProblemBonus();
}

// Напишете програма, която проверява дали дадено число е перфектно. 
// Едно число е перфектно, ако сборът от делителите му е равен на числото.
void Problem07() {
	int num, sum = 0;
	std::cin >> num;

	for (int i = 1; i <= num / 2; i++)
		if (num % i == 0)
			sum += i;

	std::cout << (num == sum) << std::endl;
}

// Да се напише програма, която приема положително цяло число. 
// Да се провери дали това число образува "Число на Армстронг". 
// "Число на Армстронг" е такова число, за което е изпълнено, 
// че сумата от неговите цифри, повдигнати на степен дължината на числото, 
// се получава началното число.
void Problem08() {
	int n, sum = 0;
	std::cin >> n;

	for (int i = 0, tempN = n; tempN > 0; tempN /= 10, i++) {
		int digit = tempN % 10;
		sum += digit * pow(10, i);
	}

	std::cout << (sum == n) << std::endl;
}

// Да се прочете от конзолата цяло число N и да се изведе как може да се представи като сума на 2 прости числа.
void Problem09() {
	int n;
	std::cin >> n;

	for (int i = 2; i <= n / 2; i++) {
		bool isPrime1 = true, isPrime2 = true;

		for (int j = 2; j <= std::sqrt(i); j++) {
			if (i % j == 0) {
				isPrime1 = false;
				break;
			}
		}

		int complement = n - i;
		for (int j = 2; j <= std::sqrt(complement); j++) {
			if (complement % j == 0) {
				isPrime2 = false;
				break;
			}
		}

		if (isPrime1 && isPrime2)
			std::cout << n << " = " << i << " + " << complement << std::endl;
	}
}

// Напишете програма, която по въведено число N отпечатва цифрите на четните позиции.
void Problem10() {
	int n, i = 1;
	std::cin >> n;

	int temp = n / 10;
	for (int j = 1; temp > 0; j++) {
		temp /= 10;
		i *= 10;
	}

	for (int pos = 1; i > 0; i /= 10, pos++) {
		int digit = (n / i) % 10;
		if (pos % 2 == 0) {
			std::cout << "Digit at even position " << pos << ": " << digit << '\n';
		}
	}
}

// Въвеждат се 5 цели числа - a,b,c,d, e. Разглеждаме полинома f(x) = a * x^4 + b * x^3 + c* x^2 + d * x + e. 
// Отпечатайте всички цели решения на f(x) >= 0 където x e в интервала [-100, 100]
void Problem11() {
	int a, b, c, d, e;
	std::cin >> a >> b >> c >> d >> e;

	for (int x = -100; x <= 100; x++) {
		int f_x = a * x * x * x * x + b * x * x * x + c * x * x + d * x + e;
		if (f_x >= 0) {
			std::cout << "x = " << x << " is a solution. f(x) = " << f_x << std::endl;
		}
	}
}

// Създайте програма, която приема естествено число N и след това чете неопределен 
// брой цели положителни числа от стандартния вход. Въвеждането се прекратява при 
// прочитане на числото -1. Да се отпечата сборът на всички числа от въведените, 
// които са взаимно прости с N.
void Problem12() {
	int n, k = 0, sum = 0;
	std::cin >> n;

	do
	{
		std::cin >> k;

		// could be made into a separate method
		int gcd = n > k ? k : n;
		while (gcd > 1) {
			if (n % gcd == 0 && k % gcd == 0)
				break;
			gcd--;
		}

		if (gcd == 1)
			sum += k;

	} while (k != -1);
	std::cout << sum << '\n';
}

// Създайте програма, която чете цяло положително число N. 
// След това, от конзолата приема 2*N цели числа, групирани в 
// последователни двойки. Ако всяка двойка има равна сума - 
// да се изведе сумата. В противен случай - да се изведе 
// максималната разлика между две съседни двойки.
void Problem13() {
	int n, sum, maxDiff = 0;
	std::cin >> n;

	int x, y;
	std::cin >> x >> y;
	sum = x + y;
	n--;

	for (; n > 0; n--) {
		std::cin >> x >> y;

		if (sum == x + y)
			continue;

		int diff = (sum - (x + y) > 0 ? sum - (x + y) : (x + y) - sum);
		sum = x + y;

		if (diff > maxDiff)
			maxDiff = diff;
	}

	(maxDiff == 0) ? std::cout << "Equal sums: " << sum << '\n' : std::cout << "Different sums. Max difference: " << maxDiff << '\n';
}

// От конзолата се въвежда цяло положително число N. След това се подават N 
// на брой цели числа. Да се изведе дали сред тях съществува елемент, 
// равен на сумата на останалите.
void Problem14() {
	int n, k, sum = 0, numEqualToSum = 0;
	std::cin >> n;

	while (n > 0) {
		std::cin >> k;
		if (k > numEqualToSum) {
			sum += numEqualToSum;
			numEqualToSum = k;
		}
		else {
			sum += k;
		}
		n--;
	}

	numEqualToSum == sum ? (std::cout << "Yes: " << numEqualToSum << '\n') : std::cout << "No\n";
}

// От конзолата се въвежда число k. След това се въвежда поредица от числа, 
// докато не се въведе 0. Вашата задача е да отпечатате колко от въведените 
// числа са suffix на k. Отпечатайте също и максималният suffix.
void Problem15() {
	int k, n, maxsuffix = -1;
	std::cin >> k;

	do
	{
		std::cin >> n;
		for (int i = 1; n > i / 10; i *= 10) {
			if (k % i == n) {
				if (n > maxsuffix) maxsuffix = n;
				std::cout << n << " is suffix!\n";
				continue;
			}
		}
	} while (n != 0);

	std::cout << "The maximal suffix you entered is: " << maxsuffix << '\n';
}

// Да се напише програма, която приема цяло положително число n и отпечатва числата от 1 до n*n в спираловиден вид.
// 1 2 3
// 6 5 4
// 7 8 9
void Problem16() {
	int n;
	std::cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int k = (i - 1) * n + 1;
		if (i % 2 == 0) {
			for (int j = i * n; j >= k; j--)
				std::cout << j << " ";

			std::cout << '\n';
		}
		else {
			for (; k <= i * n; k++)
				std::cout << k << " ";

			std::cout << '\n';
		}
	}
}

// Да се напише програма, която прочита от конзолата цяло нечетно число n и 
// чертае вертикална стрелка с размери като в примерите по-долу:
void Problem17() {
	int n;
	std::cin >> n;
	// top row
	// left dots
	for (int i = 0; i < n / 2; i++) std::cout << ".";
	// middle part
	for (int i = 0; i < n; i++) std::cout << "#";
	// right dots
	for (int i = 0; i < n / 2; i++) std::cout << ".";
	std::cout << '\n';

	//arrow body
	for (int j = 0; j < n - 2; j++)
	{
		// left dots
		for (int i = 0; i < n / 2; i++) std::cout << ".";
		// middle part
		std::cout << "#";
		for (int i = 0; i < n - 2; i++) std::cout << ".";
		std::cout << "#";
		// right dots
		for (int i = 0; i < n / 2; i++) std::cout << ".";
		std::cout << '\n';
	}

	// arrow head first row
	// left dots
	for (int i = 0; i < n / 2 + 1; i++) std::cout << "#";
	// middle part
	for (int i = 0; i < n - 2; i++) std::cout << ".";
	// right dots
	for (int i = 0; i < n / 2 + 1; i++) std::cout << "#";
	std::cout << '\n';

	//arrow head
	for (int j = 1; j < n - 1; j++)
	{
		// left dots
		for (int i = j; i > 0; i--) std::cout << ".";
		// middle part
		std::cout << "#";
		for (int i = 0; i < (2 * n - 1) - 2 * (j + 1); i++) std::cout << ".";
		std::cout << "#";
		// right dots
		for (int i = j; i > 0; i--) std::cout << ".";
		std::cout << '\n';
	}

	//last row
	for (int i = 0; i < n - 1; i++) std::cout << ".";
	std::cout << "#";
	for (int i = 0; i < n - 1; i++) std::cout << ".";
}

// Да се напише програма, която приема цяло положително число n и 
// отпечатва числата от 1 до n*n в спираловиден вид.
// 16 15 14 13
// 5 4 3 12
// 6 1 2 11
// 7 8 9 10
void ProblemBonus() {
	int n;
	std::cin >> n;
	int num_elems = n * n;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			int side_len = n;
			int row = 0;
			int col = 0;
			int pos = 0;

			char direction = 'r';
			for (int i = num_elems; i > 0; i--) {
				if (row == y && col == x) {
					std::cout << i << ' ';
					break;
				}
				++pos;

				if (pos == side_len) {

					if (direction == 'r') direction = 'd';
					else if (direction == 'd') direction = 'l';
					else if (direction == 'l') direction = 'u';
					else direction = 'r';

					pos = 0;

					if (direction == 'd' || direction == 'u') {
						--side_len;
					}
				}

				switch (direction) {
				case 'r':
					++col;
					break;
				case 'd':
					++row;
					break;
				case 'l':
					--col;
					break;
				case 'u':
					--row;
					break;
				}
			}
			std::cout << '\n';
		}
	}
}