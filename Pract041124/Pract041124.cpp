#include <iostream>
void swap(int& a, int& b);
void swap(double& a, double& b);
void reduce(int& a, int& b);
int gcd(int a, int b);
int lcm(int a, int b);
void sumOfFractions(int a, int b, int c, int d);
int getNumFromEvenPos(int a);
int getNumFromOddPos(int a);

int main() {
    int a;
    std::cin >> a;
    std::cout << getNumFromEvenPos(a) << " " << getNumFromOddPos(a);
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
    int result = 0, cnt = 0, numCopy = a;
    for (; numCopy > 0; numCopy /= 10)
        cnt++;
    if (cnt % 2 != 0) a /= 10;
    for (int i = 1; a > 0; a /= 100, i *= 10)
        result += (a % 10) * i;
    return result;
}

int getNumFromOddPos(int a) {
    int result = 0, cnt = 0, numCopy = a;
    for (; numCopy > 0; numCopy /= 10)
        cnt++;
    if (cnt % 2 == 0) a /= 10;
    for (int i = 1; a > 0; a /= 100, i *= 10)
        result += (a % 10) * i;
    return result;
}

