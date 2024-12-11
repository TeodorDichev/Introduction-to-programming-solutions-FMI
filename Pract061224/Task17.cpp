#include <iostream>

constexpr int MAX_INPUT_SIZE = 10000;
constexpr int MAX_WORD_SIZE = 1024;
constexpr int MAX_WORDS = 100;
constexpr char NULL_PTR = '\0';

void separateToWords(const char* src, char dest[MAX_WORDS][MAX_WORD_SIZE], char separator) {
    if (!src || !dest)
        return;

    int wordIndex = 0;
    int charIndex = 0;

    while (*src) {
        if (*src == separator) {
            if (charIndex > 0) { // Ако думата не е празна
                dest[wordIndex][charIndex] = NULL_PTR;  // Завършване на думата
                wordIndex++;  // Преминаваме към следващата дума
                charIndex = 0; // Рестартираме индекса за символите в думата
            }
        }
        else
            dest[wordIndex][charIndex++] = *src; // Добавяме символа към текущата дума
        src++;
    }

    // Ако последната дума не е завършена, завършваме я
    if (charIndex > 0)
        dest[wordIndex][charIndex] = NULL_PTR;
}

void print(char dest[MAX_WORDS][MAX_WORD_SIZE]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (dest[i][0] == NULL_PTR) // Проверка за края на списъка с думи
            break;
        std::cout << "[" << dest[i] << "]" << '\n'; // Извеждаме думата
    }
}

int main() {
    char input[MAX_INPUT_SIZE];
    std::cin.getline(input, MAX_INPUT_SIZE);

    // Опитах се да направя матрицата с указатели, но единственото ми решение на едно място използваше динамична памет
    char wordsMtx[MAX_WORDS][MAX_WORD_SIZE] = { NULL_PTR };

    separateToWords(input, wordsMtx, ' ');
    print(wordsMtx);
}
