#include <iostream>

int main() {
    int number;
    std::cout << "Enter a 4-digit number: ";
    std::cin >> number;

    int digit1 = number / 1000;
    int digit2 = (number%1000)/ 100;
    int digit3 = (number%100)/ 10;
    int digit4 = number % 10;

    digit1 = digit1 + 4;
    digit2 = digit2 + 4;
    digit3 = digit3 + 4;
    digit4 = digit4 + 4;

    int new_num = digit1 * 1000 + digit2 * 100 + digit3 * 10 + digit4;

    std::cout << new_num << std::endl;
    return 0;
}
