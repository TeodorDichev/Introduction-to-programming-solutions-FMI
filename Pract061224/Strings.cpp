#include <iostream>

unsigned int charToDigit(char ch) {
	if (ch >= '0' && ch <= '9')
		return ch - '0';

	return 0;
}

int myStrLen(const char* str) {
	if (!str)
		return 0;

	int length = 0;
	while (*str)
	{
		length++;
		str++;
	}

	return length;
}

int myStrCmp(const char* first, const char* second) {
	if (!first || !second)
		return 0;

	while (*first && *second && (*first == *second))
	{
		first++;
		second++;
	}

	return (*first - *second);
}

void myStrCpy(char* dest, const char* src) {
	if (!dest || !src)
		return;

	while (*src) {
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';
}

void myStrReverse(char* str) {
	if (!str)
		return;

	int length = myStrLen(str);
	for (size_t i = 0; i < length / 2; i++)
		str[i] = str[i + length - 1];
}

void myStrCat(char* first, const char* second) {
	if (!first || !second)
		return;

	while (*first) {
		first++;
	}

	while (*second) {
		*first = *second;
		first++;
		second++;
	}
}

void myStrCat1(char* first, const char* second) {
	if (!first || !second)
		return;

	int len = myStrLen(first);
	myStrCpy(first + len, second);
}


bool containsOnlyNumericalChars(const char* str) {
	if (!str)
		return false;

	while (*str) {
		if (*str > '9' || *str < '0')
			return false;

		str++;
	}

	return true;

}

unsigned int myAtoi(const char* str) {
	if (!str)
		return 0;

	unsigned int res = 0;

	if (!containsOnlyNumericalChars(str))
		return 0;

	while (*str)
	{
		res += charToDigit(*str);
		res *= 10;
		str++;
	}
	res /= 10;

	return res;
}

unsigned int getCharOccurrencesCount(const char* str, char ch) {
	if (!str)
		return 0;

	unsigned int cnt = 0;
	while (*str)
	{
		if (*str == ch)
			cnt++;

		str++;
	}

	return cnt;
}

bool isSuffix(const char* pattern, const char* text) {
	if (!pattern || !text)
		return 0;

	unsigned int lenPattern = myStrLen(pattern);
	unsigned int lenText = myStrLen(text);

	return 	(myStrCmp(pattern, text + lenText - lenPattern) == 0);
}

bool isPrefix(const char* pattern, const char* text) {
	if (!pattern || !text)
		return 0;

	while (*pattern && *text && (*pattern == *text))
	{
		pattern++;
		text++;
	}

	return !*pattern;
}

bool isInfix(const char* pattern, const char* text) {
	if (!pattern || !text)
		return 0;

	if (isPrefix(pattern, text) || isSuffix(pattern, text))
		return true;

	while (*pattern != *text) text++;
	while (*pattern == *text) { pattern++; text++; }

	return !*pattern;
}
