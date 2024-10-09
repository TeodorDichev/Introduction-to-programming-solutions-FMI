#include <iostream>

int main()
{
    // problem 4
    char aa, bb, cc, dd, ee, ff;
    std::cin >> aa >> bb >> cc >> dd >> ee >> ff;
    std::cout << ((aa + bb + cc + dd + ee + ff) % 3 == 0) << std::endl;

    // problem 5
    int num;
    std::cin >> num;
    std::cout << num / 100 % 10 << std::endl;
    
    // problem 6
    int a1, b2, c3, d4, e5;
    std::cin >> a1 >> b2 >> c3 >> d4 >> e5;
    bool areFibbNums = (c3 == b2 + a1) && (d4 == c3 + b2) && (e5 == d4 + c3);
    std::cout << areFibbNums << std::endl;
    
    // problem 7 - same as problem 4 from seminar
    
    // problem 8
    int N;
    std::cin >> N;
    bool divisible = N % 2;
    divisible && (std::cout << N * 3 << std::endl) || (std::cout << N / 2 << std::endl);
    
    // problem 9  F = (9 / 5) * C + 32
    int tempC;
    std::cin >> tempC;
    float tempF = (9.0 / 5.0) * tempC + 32;
    std::cout << tempF << std::endl;

    // problem 10
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

    // problem 11 - same as problem 2 from seminar

    // problem 12
    int border1, border2, element;
    std::cin >> border1 >> border2 >> element;
    std::cout << (element > border1 && element < border2)
        || (element > border2 && element < border1);
    std::cout << std::endl;
    
    // problem 13
    int x1, x2, x3, x4;
    std::cin >> x1 >> x2 >> x3 >> x4;
    bool intersection = !(x2 < x3 || x4 < x1);
    std::cout << intersection << std::endl;

    // problem 14
    int a, b ,c;
    std::cin >> a >> b >> c; // ax^2 + b*x + c = 0 // D = b^2 - 4ac
    bool discr = (b * b - 4 * a * c) > 0;
    std::cout << discr << std::endl;
    
    // problem 15
    int n;
    std::cin >> n;
    int product = (n % 10) * (n / 10 % 10) * (n / 100 % 10) * (n / 1000);
    double average = ((n % 10) + (n / 10 % 10) + (n / 100 % 10) + (n / 1000)) / 4.0;
    std::cout << "Product: " << product << "\n" << "Average: " << average << "\n";

    // problem 16
    int k;
    std::cin >> k;
    int sum = (1 + k) * k / 2; // Gaus
    std::cout << sum << "\n";

    // problem 17
    char ch;
    std::cin >> ch;
    bool marker = ch < 'a';
    marker && (std::cout << (char)(ch + 32)) || (std::cout << (char)(ch - 32));

    // problem 18 same as problem 9 from seminar
}