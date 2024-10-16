#include <iostream>

void Problem1();
void Problem2();
 void Problem3();
 void Problem4();
// Problem5 - same as problem 1 from seminar
 void Problem6();
 void Problem7();
// Problem8(); - same as problem 6 from seminar
 void Problem9();
 void Problem10();
 void Problem11();
 void Problem12();
// Problem13 - same as problem 7 from seminar
 void Problem14();
 void Problem15();
 void Problem16();
 void Problem17();


int main()
{
    Problem1();
}

// Отпечатайте на конзолата дали едно число е четно. 
// Нека в мейна има точно един ред код, след като прочетете числото.
void Problem1() {
    int num;
    std::cin >> num;
    std::cout << !(num % 2) << std::endl;
}

// Напишете програма, която приема 2 цели числа и отпечатва по-голямото от тях. 
// Задачата да се реши както с if, така и с тернарен оператор.
 void Problem2() {
    int num1, num2;
    std::cin >> num1 >> num2;

    if (num1 < num2) {
        std::cout << "By if: " << num2 << std::endl;
    }
    else {
        std::cout << "By if: " << num1 << std::endl;
    }
    
    std::cout << "By tertiary operator: " << (num1 < num2 ? num2 : num1) << std::endl;
}

// Да се напише програма, която чете от конзолата символ, и отпечатва на екрана ASCII 
// кода на символа, ако е валиднo римскo число, и -1 - ако не е.
 void Problem3() {
    char ch;
    std::cin >> ch;
    switch (ch)
    {
        case 'I':
        case 'V':
        case 'X':
        case 'M':
        case 'L':
        case 'D':
            std::cout << (int)ch << std::endl;
            break;

    default:
        std::cout << -1 << std::endl;
        break;
    }
}

// Създайте програма, която връща дали дадена година е високосна или не.
// Високосна година е такава, деляща се на 4.
// Ако годината се дели и на 100, то тя не е високосна.
// Ако годината се дели и на 400, то тя отново е високосна.
 void Problem4() {
    int year;
    std::cin >> year;
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
        std::cout << "Leap year" << std::endl;
    }
    else {
        std::cout << "Not leap year" << std::endl;
    }
}

// На конзолата се въвежда цяло число. Проверете дали числото е положително. 
// В случай, че е положително - да се отпечата 1, ако е четно, и 0, ако е нечетно. 
// В случай, че е отрицателно - да се отпечата 1, ако числото е по-малко от -5, и 0 в противен случай.
 void Problem6() {
    int num;
    std::cin >> num;

    if (num > 0) {
        if (num % 2 == 0) {
            std::cout << 1 << std::endl;
        }
        else {
            std::cout << 0 << std::endl;
        }
    }
    else {
        if (num < -5) {
            std::cout << 1 << std::endl;
        }
        else {
            std::cout << 0 << std::endl;
        }
    }
}

// По подадени x1, y1, x2, y2, x и y, където x1, y1 са координатите на горния ляв ъгъл на правоъгълник, 
// а x2, y2 на долния десен, проверете дали точката (x,y) се намира вътре в правоъгълника.
 void Problem7() {
    int x1, y1, x2, y2, x, y;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
    std::cout << ((x1 < x && x < x2) && (y2 < y && y < y1)) << std::endl;
}

// Напишете програма, която проверява дали дадено 4-цифрено число е палиндром.
 void Problem9() {
    int number;
    std::cin >> number;
    std::cout << (number % 10 == number / 1000) && (number / 10 % 10 == number / 100 % 10) << '\n';
}

// От конзолата се въвеждат целите числата a, b и c. Сортирайте ги във възходящ ред.
 void Problem10() {
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
 void Problem11() {
    float number;
    float epsilon = 0.0000001;
    std::cin >> number;
    std::cout << (number - (int)number > epsilon ? "Not an integer": "Integer");
}

// От конзолата се въвеждат дължините на трите страни на триъгълник (реални положителни числа). 
// Нека програмата извежда подходящо съобщение на конзолата, ако тези страни са валидни и ако не са. 
// Входът не е гарантирано коректен - да се извежда различно съобщение и за него.
 void Problem12() {
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
 void Problem14() {
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
 void Problem15() {
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
 void Problem16() {
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
 void Problem17() {
    char a, b, c, d, e;
    std::cin >> a >> b >> c >> d >> e;

    //making the solution case insensitive
    a += 'a' - 'A';
    b += 'a' - 'A';

    bool isInFirst = e >= a && e <= b;
    bool isInSecond = e >= c && e <= d;

    bool isUnion = isInFirst || isInSecond;
    bool isIntersection = isInFirst && isInSecond;
    bool isDifference = isInFirst && !isInSecond;
    bool isInOnlySet = isUnion && !isIntersection;

    std::cout << "Is in intersection: " << std::boolalpha << isUnion << std::endl;
    std::cout << "Is in union: " << std::boolalpha << isIntersection << std::endl;
    std::cout << "Is in difference: " << std::boolalpha << isDifference << std::endl;
    std::cout << "Is in only one of the sets: " << std::boolalpha << isInOnlySet << std::endl;
}