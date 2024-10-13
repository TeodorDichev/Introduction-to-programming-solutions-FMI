#include <iostream>

// Problem1 - Problem3 too simple
static void Problem4();
static void Problem5();
static void Problem6();
// Problem7 - same as problem 4 from seminar
static void Problem8();
static void Problem9();
static void Problem10();
// Problem11 - same as problem 2 from seminar
static void Problem12();
static void Problem13();
static void Problem14();
static void Problem15();
static void Problem16();
static void Problem17();
// Problem18 same as problem 9 from seminar


int main()
{
    Problem4();
    Problem5();
    Problem6();
    Problem8();
    Problem9();
    Problem10();
    Problem12();
    Problem13();
    Problem14();
    Problem15();
    Problem16();
    Problem17();
}

// От конзолата се въвеждат 6 символа. Да се провери дали сумата от ASCII кодовете 
// на тези символи се дели на 3. Ако се дели на 3, да се изведе на конзолата 1, ако не - 0.
static void Problem4() {
    char aa, bb, cc, dd, ee, ff;
    std::cin >> aa >> bb >> cc >> dd >> ee >> ff;
    std::cout << ((aa + bb + cc + dd + ee + ff) % 3 == 0) << std::endl;
}

//Да се напише програма, която отпечатва третата цифра отзад напред на въведеното от конзолата число N.
static void Problem5() {
    int num;
    std::cin >> num;
    std::cout << num / 100 % 10 << std::endl;
}

// Създайте програма, която чете 5 числа. Да се изведе 1, ако числата са част от редицата на Фибоначи 
// в реда, в който са въведени, и 0 - в противен случай.
static void Problem6() {
    int a1, b2, c3, d4, e5;
    std::cin >> a1 >> b2 >> c3 >> d4 >> e5;
    bool areFibbNums = (c3 == b2 + a1) && (d4 == c3 + b2) && (e5 == d4 + c3);
    std::cout << areFibbNums << std::endl;
}

// Напишете програма, която прочита цяло число N от конзолата и извежда N/2, ако се дели на 2, 
// и 3*N, ако не се дели на 2.
static void Problem8() {
    int N;
    std::cin >> N;
    bool divisible = N % 2;
    divisible && (std::cout << N * 3 << std::endl) || (std::cout << N / 2 << std::endl);
}

// Напишете програма, която обръща подадени градуси от Целзий (C) във Фаренхайт (F). 
// Формулата за това е: F = (9 / 5) * C + 32
static void Problem9() {
    int tempC;
    std::cin >> tempC;
    float tempF = (9.0 / 5.0) * tempC + 32;
    std::cout << tempF << std::endl;
}

// Да се напише програма, която приема брой секунди и изчислява колко дни, часове, минути и секунди са.
static void Problem10() {
    int time;
    std::cin >> time;
    int days = time / 86400;
    time -= days * 86400;
    int hours = time / 3600;
    time -= hours * 3600;
    int minutes = time / 60;
    time -= minutes * 60;
    std::cout << days << " days " << hours << " hours " << minutes
        << " minutes " << time << " seconds" << std::endl;
}

// Напишете програма, която приема 3 числа a, b и x. Програмата отпечатва 1 ако x принадлежи 
// на интервала (a;b]. В противен случай отпечатва 0.
static void Problem12() {
    int border1, border2, element;
    std::cin >> border1 >> border2 >> element;
    std::cout << (element > border1 && element < border2)
        || (element > border2 && element < border1);
    std::cout << std::endl;
}

//Дадени са ви 4 на брой цели числа - a, b, c, d. Да се изведе дали интервалите [a, b] и [c, d] се пресичат.
static void Problem13() {
    int x1, x2, x3, x4;
    std::cin >> x1 >> x2 >> x3 >> x4;
    bool intersection = !(x2 < x3 || x4 < x1);
    std::cout << intersection << std::endl;
}

// Нека са дадени положителните естествени числа a, b и c. Да се напише булев израз, който има стойност истина, 
// ако квадратното уравнение ax2 + bx + c = 0 има два реални, различни корена.
static void Problem14() {
    int a, b, c;
    std::cin >> a >> b >> c;
    bool discr = (b * b - 4 * a * c) > 0;
    std::cout << discr << std::endl;
}

// Напишете програма, която приема 4-цифрено число и извежда произведението и средноаритметичното на цифрите.
static void Problem15() {
    int n;
    std::cin >> n;
    int product = (n % 10) * (n / 10 % 10) * (n / 100 % 10) * (n / 1000);
    double average = ((n % 10) + (n / 10 % 10) + (n / 100 % 10) + (n / 1000)) / 4.0;
    std::cout << "Product: " << product << "\n" << "Average: " << average << "\n";
}

// Потребителя въвежда число n. Да се изведе сумата на числата от 1 до n. (без цикъл)
static void Problem16() {
    int k;
    std::cin >> k;
    int sum = (1 + k) * k / 2; // Gaus
    std::cout << sum << "\n";
}

// От конзолата се въвежда малка или голяма латинска буква. Ако е главна отпечатайте 
// съответстващата и малка, ако не - обратното. (без if-проверки)
static void Problem17() {
    char ch;
    std::cin >> ch;
    bool marker = ch < 'a';
    marker && (std::cout << (char)(ch + 32)) || (std::cout << (char)(ch - 32));
}