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

// Да се напише програма, която въвежда цяло число отпечатава с думи кой ден от седмицата е.
static void Problem1() {
	int dayNum;
	std::cin >> dayNum;
	switch (dayNum)
	{
	case 1:
		std::cout << "Monday" << '\n' << '\n';
		break;
	case 2:
		std::cout << "Tuesday" << '\n' << '\n';
		break;
	case 3:
		std::cout << "Wednesday" << '\n' << '\n';
		break;
	case 4:
		std::cout << "Thursday" << '\n' << '\n';
		break;
	case 5:
		std::cout << "Friday" << '\n' << '\n';
		break;
	case 6:
		std::cout << "Saturday" << '\n' << '\n';
		break;
	case 7:
		std::cout << "Sunday" << '\n' << '\n';
		break;
	default:
		std::cout << "Invalid day!" << '\n' << '\n';
		break;
	}
}

// (Between 100 and 200): Да се напише програма, която въвежда цяло число и проверява дали е 
// под 100, между 100 и 200 или над 200. Да се отпечатат съответно съобщения като в примерите по-долу:
static void Problem2() {
	int number;
	std::cin >> number;
	if (number > 200) {
		std::cout << "Greater than 200" << '\n' << '\n';
	}
	else if (number < 100) {
		std::cout << "Less than 100" << '\n' << '\n';
	}
	else {
		std::cout << "Between 100 and 200" << '\n' << '\n';
	}
}

// (Speed trap): Да се напише програма, която въвежда скорост (десетично число) и отпечатва 
// информация за скоростта. При скорост до 10 (включително) отпечатайте “slow”. При скорост 
// над 10 и до 50 отпечатайте “average”. При скорост над 50 и до 150 отпечатайте “fast”. 
// При скорост над 150 и до 1000 отпечатайте “ultra fast”. При по-висока скорост отпечатайте 
// “extremely fast”
static void Problem3() {
	float speed;
	std::cin >> speed;
	if (speed <= 10) {
		std::cout << "slow" << '\n' << '\n';
	}
	else if (speed > 10 && speed <= 50) {
		std::cout << "average" << '\n' << '\n';
	}
	else if (speed > 50 && speed <= 150 ){
		std::cout << "fast" << '\n' << '\n';
	}
	else if (speed > 150 && speed <= 1000) {
		std::cout << "ultra fast" << '\n' << '\n';
	}
	else {
		std::cout << "extremely fast" << '\n' << '\n';
	}
}

// (Лице на фигура): Да се напише програма, която въвежда размерите на геометрична фигура 
// и пресмята лицето й. Фигурите са четири вида: квадрат (s), правоъгълник (r), кръг (c) 
// и триъгълник (triangle). На първия ред на входа се чете вида на фигурата (square, rectangle, 
// circle или triangle). Ако фигурата е квадрат, на следващия ред се чете едно число – дължина 
// на страната му. Ако фигурата е правоъгълник, на следващите два реда четат две числа – 
// дължините на страните му. Ако фигурата е кръг, на следващия ред чете едно число – радиусът 
// на кръга. Ако фигурата е триъгълник, на следващите два реда четат две числа – дължината на 
// страната му и дължината на височината към нея.
static void Problem4() {
	char figure;
	std::cin >> figure;

	switch (figure)
	{
	case 'S':
	case 's':
		float side;
		std::cin >> side;
		std::cout << side * side << '\n' << '\n';
		break;

	case 'r':
	case 'R':
		float length, width;
		std::cin >> length >> width;
		std::cout << length * width << '\n' << '\n';
		break;

	case 'c' :
	case 'C' :
		float radius;
		std::cin >> radius;
		std::cout << radius * radius * 2 * acos(0.0) << '\n' << '\n';
		break;

	case 't':
	case 'T':
		float sideT, height;
		std::cin >> sideT >> height;
		std::cout << (sideT * height) / 2 << '\n' << '\n';
		break;

	default:
		std::cout << "Invalid figure";
		break;
	}
}

// (Време + 15 минути) : Да се напише програма, която въвежда час и минути от 24-часово 
// денонощие и изчислява колко ще е часът след 15 минути. Резултатът да се отпечата във 
// формат hh:mm. Часовете винаги са между 0 и 23, а минутите винаги са между 0 и 59. 
// Часовете и минутите се изписват винаги с по две цифри, с водеща нула когато е необходимо
static void Problem5() {
	int hours, minutes;
	std::cin >> hours >> minutes;
	minutes += 15;
	if (minutes >= 60) {
		minutes -= 60;
		hours++;
	}
	
	hours %= 24;

	std::cout << (hours < 10 ? "0" : "") << hours << ":"
		<< (minutes < 10 ? "0" : "") << minutes << '\n' << '\n';
}

//Ще казваме, че поредица от числа е трион, ако всяко число в нея е едновременно поголямо 
// или равно от двата си съседа или пък едновременно по-малко или равно от тях. За първия 
// и последния елемент имаме само по един съсед. Напишете програма, която въвежда от 
// стандартния 5 на брой цели числа. Да се изведе на стандартния изход "yes", ако въведената 
// поредица е трион, или "no", в противен случай.
static void Problem6() {
	int n1, n2, n3, n4, n5;
	std::cin >> n1 >> n2 >> n3 >> n4 >> n5;

	bool isTrion = (n2 <= n1 && n2 <= n3 && n3 >= n4 && n4 <= n5) ||
		(n2 >= n1 && n2 >= n3 && n3 <= n4 && n4 >= n5);

	std::cout << (isTrion ? "yes" : "no") << '\n' << '\n';
}

//Да се напише програма, която при подадени радиус r и двумерна точка (х, у) проверява 
// дали точката се намира вътре/извън или по контура на окръжност с център (0,0).
static void Problem7() {
	float radius, x, y;
	std::cin >> radius >> x >> y;
	float distance = std::sqrt(x * x + y * y);

	// Проверка дали точката е вътре, на контура или извън окръжността
	if (distance < radius) {
		std::cout << "In the circle\n";
	}
	else if (distance == radius) {
		std::cout << "On the circle.\n";
	}
	else {
		std::cout << "Out of the circle\n";
	}
}