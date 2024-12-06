#include <iostream>

constexpr int MAX_INPUT_SIZE = 10000;
constexpr int MAX_WORD_SIZE = 1024;
constexpr char NULL_PTR = '\0';

void separateToWords(const char* src, char** dest, char separator) {
    if (!src || !dest)
        return;

    char** currentWord = dest; // Pointer to current word pointer
    char* currentChar = nullptr; // Pointer to current character in the word

    while (*src) {
        if (*src == separator) {
            if (currentChar) { // If we are in a word
                *currentChar = NULL_PTR; // Null-terminate the word
                currentChar = nullptr; // Reset current character pointer
                currentWord++; // Move to the next word
            }
        }
        else {
            if (!currentChar) { // Allocate memory for a new word
                *currentWord = new char[MAX_WORD_SIZE]; // Allocate memory for the word
                currentChar = *currentWord; // Start filling the new word
            }
            *currentChar = *src; // Add character to the current word
            currentChar++; // Move to the next character
        }
        src++;
    }

    if (currentChar) { // Handle the last word
        *currentChar = NULL_PTR;
        currentWord++;
    }

    *currentWord = nullptr; // Mark the end of the word list
}

void print(char** src) {
    while (*src) {
        std::cout << "[" << *src << "]" << '\n'; // Print the word
        src++;
    }
}

//int main() {
//    char input[MAX_INPUT_SIZE];
//    std::cin.getline(input, MAX_INPUT_SIZE);
//
//    char* wordsMtx[MAX_WORD_SIZE] = { nullptr }; // Initialize pointers to nullptr
//
//    separateToWords(input, wordsMtx, ' ');
//    print(wordsMtx);
//}
