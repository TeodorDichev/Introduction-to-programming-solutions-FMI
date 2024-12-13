// Online C++ compiler to run C++ program online
#include <iostream>
void Task20(char arr[]) {
    while (*arr != '\0') {
        if (*arr >= 'a' && *arr <= 'z')
            *arr -= 'a' - 'A';
        else if (*arr >= 'A' && *arr <= 'Z')
            *arr += 'a' - 'A';
        arr++;
    }
}
int main() {
    // Write C++ code here
    char str[] = "teDI e GEI nali?\0";
    Task20(str);
    std::cout << str;

    return 0;
}