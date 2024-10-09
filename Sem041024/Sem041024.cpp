#include <iostream>

int main()
{
    // problem 1
    int number;
    std::cin >> number;
    std::cout << !(number % 2) << std::endl;

    // problem 2
    int num;
    std::cin >> num;
    std::cout << num % 10 << num / 10 % 10 << num / 100 + 1 << std::endl;

    // problem 3
    char ch;
    std::cin >> ch;
    std::cout << (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        << std::endl;

    // problem 4
    int grade;
    std::cin >> grade;
    bool isValidGrade = grade <= 6 && grade >= 2;
    std::cout << isValidGrade << std::endl;

    // problem 5
    int inputNumber;
    std::cin >> inputNumber;
    std::cout << inputNumber / 10 << std::endl;

    // problem 6
    int a, b;
    std::cin >> a >> b;
    int sum = a + b;
    int dif = a - b;
    int res = sum * sum * sum * sum - dif * dif;
    std::cout << res << std::endl;

    // problem 7
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


    // problem 8
    int a1, b1;
    std::cin >> a1 >> b1;
    bool marker = a1 < b1;
    marker && (std::cout << b1 << "\n") || (std::cout << a1 << "\n");

    // problem 9
    int a2, b2;
    std::cin >> a2 >> b2;
    a2 += b2;
    b2 = a2 - b2;
    a2 = a2 - b2;
    std::cout << a2 << ", " << b2 << "\n";
}