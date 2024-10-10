#include <iostream>

static void Problem1();
static void Problem2();
static void Problem3();
static void Problem4();
static void Problem5();
static void Problem6();
static void Problem7();
static void Problem8();
static void Problem9();

int main()
{
    Problem1();
    Problem2();
    Problem3();
    Problem4();
    Problem5();
    Problem6();
    Problem7();
    Problem8();
    Problem9();
}

// Въвежда се цяло число. Отпечатайте 1, ако числото е четно и 0, ако е нечетно.
static void Problem1() {
    int number;
    std::cin >> number;
    std::cout << !(number % 2) << std::endl;
}

// Въвежда се трицифрено цяло число n. Да се отпечата обърнатото число събрано с единица.
static void Problem2() {
    int num;
    std::cin >> num;
    std::cout << num % 10 << num / 10 % 10 << num / 100 + 1 << std::endl;
}

// Въвежа се символ. Да се отпечата 1, ако е английска гласна буква, и 0, ако не е.
static void Problem3() {
    char ch;
    std::cin >> ch;
    std::cout << (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        << std::endl;
}

// Въвежа се цяло число. Да се отпечата 1, ако числото е валидна оценка от училище, и 0, ако не е валидна.
static void Problem4() {
    int grade;
    std::cin >> grade;
    bool isValidGrade = grade <= 6 && grade >= 2;
    std::cout << isValidGrade << std::endl;
}

// Въвежа се цяло число. Да се отпечата без последната цифра.
static void Problem5() {
    int inputNumber;
    std::cin >> inputNumber;
    std::cout << inputNumber / 10 << std::endl;
}

// Напишете програма, която въвежда две числа - a и b и извежда като резултат (a + b)^4 - (a-b)^2
static void Problem6() {
    int a, b;
    std::cin >> a >> b;
    int sum = a + b;
    int dif = a - b;
    int res = sum * sum * sum * sum - dif * dif;
    std::cout << res << std::endl;
}

// Въвежда се цяло число n - n лева. Да се изведе на конзолата как може да се разпределят по банкноти,
// така че да имаме минимален брой банкноти.
static void Problem7() {
    int n = 0;
    std::cin >> n;
    int stot = n / 100;
    n -= stot * 100;
    int ped = n / 50;
    n -= ped * 50;
    int dvaiset = n / 20;
    n -= dvaiset * 20;
    int des = n / 10;
    n -= des * 10;
    int pet = n / 5;
    n -= pet * 5;
    int dva = n / 2;
    n -= dva * 2;
    int ed = n / 1;
    n -= ed * 1;
    std::cout << stot << "* 100lv, " << ped << "* 50lv, "
        << dvaiset << "* 20lv, " << des << "* 10lv, "
        << pet << "* 5lv, " << dva << "* 2lv, "
        << ed << "* 1lv\n";

}

// Въвеждат се две числа. Да се отпечата по-голямото от двете.
static void Problem8() {
    int a1, b1;
    std::cin >> a1 >> b1;
    bool marker = a1 < b1;
    marker && (std::cout << b1 << "\n") || (std::cout << a1 << "\n");
}

// Имате две променливи от тип int да се разменят техните стойности.
static void Problem9() {
    int a2, b2;
    std::cin >> a2 >> b2;
    a2 += b2;
    b2 = a2 - b2;
    a2 = a2 - b2;
    std::cout << a2 << ", " << b2 << "\n";
}