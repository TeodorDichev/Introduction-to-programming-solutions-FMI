#include <iostream>

 void Problem15();
 void Problem16();
 void Problem17();
 void ProblemBonus();

int main() {
	Problem15();
}

// От конзолата се въвежда число k. След това се въвежда поредица от числа, 
// докато не се въведе 0. Вашата задача е да отпечатате колко от въведените 
// числа са suffix на k. Отпечатайте също и максималният suffix.
void Problem15() {
	int k, n;
	std::cin >> k;

	do
	{
		std::cin >> n;
		for (int i = 1; n > i / 10; i *= 10) {
			if (k % i == n) {
				std::cout << n << " is suffix!\n";
				continue;
			}
		}
	} while (n != 0);
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
			for (; k <= i*n; k++)
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

}