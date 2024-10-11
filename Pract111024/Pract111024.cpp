#include <iostream>

// Problem1 - Problem3 too simple
static void Problem4();
static void Problem5();
static void Problem6();
// Problem7 - same as problem 4 from seminar
static void Problem8();
static void Problem9();
static void Problem10();
static void Problem11();
static void Problem12();
// Problem13 - same as problem 7 from seminar
static void Problem14();
static void Problem15();
static void Problem16();
static void Problem17();


int main()
{
    //Problem4();
    //Problem5();
    //Problem6();
    Problem9();
    Problem10();
    Problem11();
    Problem12();
    Problem14();
    Problem15();
    Problem16();
    Problem17();
}
// Напишете програма, която проверява дали дадено 4-цифрено число е палиндром.
static void Problem9() {
    int number;
    std::cin >> number;
    std::cout << (number % 10 == number / 1000) && (number / 10 % 10 == number / 100 % 10) << '\n';
}

// От конзолата се въвеждат целите числата a, b и c. Сортирайте ги във възходящ ред.
static void Problem10() {
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a > b) {
        a += b;
        b = a - b;
        a = a - b;
    }
    if (b > c) {
        b += c;
        c = b - c;
        b = b - c;
    }
    if (a > b) {
        a += b;
        b = a - b;
        a = a - b;
    }
    std::cout << a << " " << b << " " << c << '\n';
    std::cout << c * 100 + b * 10 + a << '\n';
}

// Напишете програма, която получава число от конзолата и отпечатва дали то е цяло или не.
static void Problem11() {
    float number;
    float epsilon = 0.0000001;
    std::cin >> number;
    std::cout << (number - (int)number > epsilon ? "Not an integer": "Integer");
}

// От конзолата се въвеждат дължините на трите страни на триъгълник (реални положителни числа). 
// Нека програмата извежда подходящо съобщение на конзолата, ако тези страни са валидни и ако не са. 
// Входът не е гарантирано коректен - да се извежда различно съобщение и за него.
static void Problem12() {
    float a, b, c;
    std::cin >> a >> b >> c;

    if (a + b > c && a + c > b && b + c > a) {
        std::cout << "This triangle exists.\n";
    }
    else {
        std::cout << "This triangle doesn't exist.\n";
    }
}

// Създайте калкулатор, поддържащ операциите +, -, *, / на две реални числа. 
// От конзолата се прочита число, операция и второ число и се извежда резултатът.
static void Problem14() {
    float num1, num2;
    char operation;
    std::cin >> num1 >> operation >> num2;

    switch (operation)
    {
    case '*':
        std::cout << num1 * num2 << std::endl;
        break;
    case '+':
        std::cout << num1 + num2 << std::endl;
        break;
    case '-':
        std::cout << num1 - num2 << std::endl;
        break;
    case '/':
        std::cout << num1 / num2 << std::endl;
        break;
    default:
        std::cout << "Invalid operation";
        break;
    }
}

// Да се състави програма, чрез която се въвежда 4-цифренo естествено число от интервала [1000.. 9999]. 
// От това число се формират 2 нови 2-цифрени числа. Първото число се формира от 1-та и 4-та цифра 
// на въведеното число. Второто число се формира от 2-рa - 3-та цифра на въведеното число. 
// На екрана да се изведе дали 1-то ново число e по-малко <, равно = или по-голямо от 2-то число.
static void Problem15() {
    int number;
    std::cin >> number;
    int num1 = (number / 1000) * 10 + number % 10;
    int num2 = (number / 100 % 10) * 10 + (number / 10) % 10;

    if (num1 < num2) {
        std::cout << "less ( " << num1 << " < " << num2 << " )\n";
    }
    else if (num1 > num2) {
        std::cout << "greater ( " << num1 << " > " << num2 << " )\n";
    }
    else {
        std::cout << "equal ( " << num1 << " = " << num2 << " )\n";
    }
}

// От конзолата се чете число в интервала [0, ..., 12]. Ако числото е четно, програмата
// принтира всички четни числа по-големи или равни на числото, намиращи се в интервала. 
// Ако е нечетно, принтираме всички по-големи или равни нечетни числа. (Опитайте се да 
// направите кода максимално четим)
static void Problem16() {
    int n;
    std::cin >> n;
    switch (n)
    {
    case 1:
        std::cout << 1 << std::endl;
    case 3:
        std::cout << 3 << std::endl;
    case 5:
        std::cout << 5 << std::endl;
    case 7:
        std::cout << 7 << std::endl;
    case 9:
        std::cout << 9 << std::endl;
    case 11:
        std::cout << 11 << std::endl;
        break;
    case 0:
        std::cout << 0 << std::endl;
    case 2:
        std::cout << 2 << std::endl;
    case 4:
        std::cout << 4 << std::endl;
    case 6:
        std::cout << 6 << std::endl;
    case 8:
        std::cout << 8 << std::endl;
    case 10:
        std::cout << 10 << std::endl;
    case 12:
        std::cout << 12 << std::endl;
        break;
    default:
        std::cout << "Incorrect input" << std::endl;
    }

}

// Да се напише програма, която получава 5 латински букви. Първите две от тях са главни и 
// образуват множеството A, където A съдържа всички букви между въпросните две букви, 
// включително самите тях. Вторите две букви са малки и образуват множеството B, където 
// B съдържа всички букви между тях, включително самите тях.
static void Problem17() {
    char a, b, c, d, e;
    std::cin >> a >> b >> c >> d >> e;

    std::cout << std::boolalpha << (a < e < b || c < e < d) << std::endl;
    std::cout << std::boolalpha << (a < e < b && c < e < d) << std::endl;
    std::cout << std::boolalpha << (a < e < b && !(c < e < d)) << std::endl;
    std::cout << std::boolalpha << (a < e < b && !(c < e < d) || !(a < e < b) && (c < e < d)) << std::endl;
}