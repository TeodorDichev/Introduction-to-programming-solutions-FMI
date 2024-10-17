#include <iostream>

static void Problem1();
static void Problem2();
static void Problem3();
static void Problem4();
static void Problem5();
static void Problem6();
static void Problem7();

int main()
{
	Problem1();
	Problem2();
	Problem3();
	Problem4();
	Problem5();
	Problem6();
	Problem7();
}
// Да се напише програма, която приема поток от числа.Числата се събират, докато не срещне числото 0.
// Тогава трябва да се отпечата акумулираният резултат и програмата да приключи.
static void Problem1() {
    int n, sum = 0;
    do{
        std::cin >> n;
        sum += n;
    } while (n != 0);
    std::cout << sum << std::endl;
}

// Да се напише програма, която приема цяло положително число, обръща го и го увеличава с 1.
static void Problem2() {
    int n, revN = 0;
    std::cin >> n;
    
    while (n != 0) {
        revN *= 10;
        revN += n % 10;
        n /= 10;
    }

    std::cout << ++revN << std::endl;
}

// Напишете програма, която приема цяло число и връща най - често срещаната цифра.
// Ако има няколко най - често срещани, то да се отпечата най - малката.
static void Problem3() {
    int n = 0, mcd = 1, cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0, cnt5 = 0, cnt6 = 0, cnt7 = 0, cnt8 = 0, cnt9 = 0;
    std::cin >> n;
    while (n > 0) {
        int digit = n % 10;
        switch (digit)
        {
            case 1: cnt1++; break;
            case 2: cnt2++; break;
            case 3: cnt3++; break;
            case 4: cnt4++; break;
            case 5: cnt5++; break;
            case 6: cnt6++; break;
            case 7: cnt7++; break;
            case 8: cnt8++; break;
            case 9: cnt9++; break;
        }
        n /= 10;
    }

    int cntMax = cnt1;
    mcd = 1;
    // Compare and update the largest number
    if (cnt2 > cntMax) { cntMax = cnt2; mcd = 2; }
    if (cnt3 > cntMax) { cntMax = cnt3; mcd = 3; }
    if (cnt4 > cntMax) { cntMax = cnt4; mcd = 4; }
    if (cnt5 > cntMax) { cntMax = cnt5; mcd = 5; }
    if (cnt6 > cntMax) { cntMax = cnt6; mcd = 6; }
    if (cnt7 > cntMax) { cntMax = cnt7; mcd = 7; }
    if (cnt8 > cntMax) { cntMax = cnt8; mcd = 8; }
    if (cnt9 > cntMax) { cntMax = cnt9; mcd = 9; }

    std::cout << "The most common digit is: " << mcd << " (" << cntMax << ")" << std::endl;
}

// Напишете програма, която приема две естествени числа и връща най-големият им общ делител.
static void Problem4() {
    int a, b;
    std::cin >> a >> b;

    // getting the smaller number
    int gcd = a > b ? b : a;

    while (gcd > 1) {
        if (a % gcd == 0 && b % gcd == 0)
            break;
        gcd--;
    }

    std::cout << "Greatest Common Dividor: " << gcd << std::endl;
}

// Напишете програма, която приема две естествени числа и връща най-малкото им общо кратно.
static void Problem5() {
    int a, b;
    std::cin >> a >> b;

    // getting the smaller number
    int gcd = a > b ? b : a;

    while (gcd > 1) {
        if (a % gcd == 0 && b % gcd == 0)
            break;
        gcd--;
    }

    std::cout << "Least Common Multiple: " << (a / gcd) * b << std::endl;
}

// Напишете програма, която приема естествено число и връща дали числото е просто.
static void Problem6() {
    int n, d = 2;
    std::cin >> n;
    int cnt = 0;

    if (n <= 1)
		std::cout << n << " is not prime" << std::endl;
    else {

        for (int i = 1; i <= n; i++)
            if (n % i == 0)
                cnt++;

        if (cnt > 2)
            std::cout << n << " is not prime" << std::endl;

        else
            std::cout << n << " is prime" << std::endl;
    }
}

// Напишете програма, която приема естествено число и отпечатва разбиването му 
// на прости множители, сортирани низходящо.
static void Problem7() {
	int n, d = 2;
	std::cin >> n;

	for (int i = 2; i <= n; i++) {
		if (n % i == 0) {
			std::cout << i << ", ";
			while (n % i == 0)
				n /= i;
		}
	}
}