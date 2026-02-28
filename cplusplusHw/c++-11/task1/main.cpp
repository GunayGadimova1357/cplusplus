#include <iostream>
int length(const char* str);
void to_uppercase(const char* src, char* dest);
void printUpper(const char* str);
void printLength(const char* str);
template <typename T>
void processString(const char* str, T func);
int main() {
    const char* str = "Hello World!";

    processString(str, printUpper);

    processString(str, printLength);

    return 0;
}

int length(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}
void to_uppercase(const char* src, char* dest) {
    while (*src != '\0') {
        if (*src >= 'a' && *src <= 'z') {
            *dest = *src - ('a' - 'A');
        } else {
            *dest = *src;
        }
        src++;
        dest++;
    }
     *dest = '\0';
}
void printUpper(const char* str) {
    char upperStr[100];
    to_uppercase(str, upperStr);
    std::cout << upperStr << std::endl;
}
void printLength(const char* str) {
    int len = length(str);
    std::cout << "Length of the string: " << len << std::endl;
}
template <typename T>
void processString(const char* str, T func) {
    func(str);
}