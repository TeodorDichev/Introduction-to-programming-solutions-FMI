#include <iostream>

constexpr size_t MAX_SIZE = 1024;

void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

void toLower(char& ch) {
    ch = (ch > 'a' && ch < 'z') ? ch : ch - ('A' - 'a');
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

void myStrCpy(char* dest, const char* src) {
    if (!dest || !src)
        return;
    
    while (*src) {
        *dest = *src;
        if (*dest >= 'A' && *dest <= 'Z')
            toLower(*dest);
        dest++;
        src++;
    }

    *dest = '\0';
}

bool isValidString(const char* str) {
    if (!str)
        return false;

    while (*str) {
        if ((*str < 'a' || *str > 'z') && (*str < 'A' || *str > 'Z'))
            return false;
        str++;
    }
    return true;
}

void sortCharacters(const char* str, char* result) {
    if (!str || !result || !isValidString(str))
        return;

    myStrCpy(result, str);
    int length = myStrLen(result);

    // Selection Sort using pointers
    char* start = result;
    while (start < result + length - 1) {
        char* min = start;
        char* current = start + 1;

        while (current < result + length) {
            if (*current < *min) 
                min = current;
            current++;
        }

        if (min != start)
            swap(*start, *min);

        start++;
    }
        
    
}

void print(char* src) {
    while (*src) {
        std::cout << *src; // Print the word
        src++;
    }
}

int main() {
    char input[MAX_SIZE];
    char result[MAX_SIZE] = { '\0' }; //Initialize 'cause if input not valid print prints many unknow symbols

    std::cin.getline(input, MAX_SIZE);
    sortCharacters(input, result);
    print(result);
}
