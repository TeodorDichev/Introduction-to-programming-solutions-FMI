#include <iostream>

constexpr int MAX_INPUT_SIZE = 1024;
constexpr int MAX_WORDS = 128;
constexpr int MAX_WORD_LENGTH = 64;

void toLowerCase(char* str) {
	while (*str) {
		if (*str >= 'A' && *str <= 'Z')
			*str = *str + ('a' - 'A');

		str++;
	}
}

bool isALetter(char str) {
	return (str >= 'A' && str <= 'Z') || (str >= 'a' && str <= 'z');
}

int splitIntoWords(char* str, char words[MAX_WORDS][MAX_WORD_LENGTH]) {
	int wordCount = 0;
	char* wordStart = nullptr;
	int letterCount = 0;

	while (*str) {
		// Check if the current character is a letter and we're not already in a word
		if (isALetter(*str) && !wordStart)
			wordStart = str;

		// If the current character is not a letter or it's the end of the string
		if ((!isALetter(*str) || !*(str++)) && wordStart) {
			char* wordPtr = words[wordCount];

			// Handle the end of the string case by ensuring the last character is included
			if (isALetter(*str))
				str++;

			// Copy characters from wordStart to str
			while (wordStart < str && letterCount < MAX_WORD_LENGTH - 1) {
				*wordPtr++ = *wordStart++;
				letterCount++;
			}

			*wordPtr = '\0';  // Null-terminate the word
			wordCount++;
			wordStart = nullptr;
			letterCount = 0;
		}

		str++;
	}

	return wordCount;
}

const char* findMostFrequentWord(char words[MAX_WORDS][MAX_WORD_LENGTH], int wordCount) {
	int maxCount = 0;
	const char* mostFrequentWord = nullptr;

	for (int i = 0; i < wordCount; i++) {
		int count = 1;
		for (int j = i + 1; j < wordCount; j++) {

			/* Тук може да ползваш фунцията която си написахме за сравнение на стрингове */
			bool isSame = true;
			const char* word1 = words[i];
			const char* word2 = words[j];

			while (*word1 && *word2) {
				if (*word1 != *word2) {
					isSame = false;
					break;
				}
				word1++;
				word2++;
			}
			if (isSame && !*word1 && !*word2)
				count++;

		}
		if (count > maxCount) {
			maxCount = count;
			mostFrequentWord = words[i];
		}
	}

	return mostFrequentWord;
}

int main() {
	char input[MAX_INPUT_SIZE];
	char words[MAX_WORDS][MAX_WORD_LENGTH];

	std::cin.getline(input, MAX_INPUT_SIZE);

	toLowerCase(input);
	int wordCount = splitIntoWords(input, words);

	std::cout << "The most frequent word is: " << findMostFrequentWord(words, wordCount) << '\n';
}
