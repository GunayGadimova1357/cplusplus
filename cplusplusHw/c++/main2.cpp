#include <iostream>

int main() {
    //input:12345678
    //output:56784321
    int number;
    std::cout << "Enter an 8-digit number: ";
    std::cin >> number;

    int first_half = number / 10000;
    int second_half = number % 10000;

    int rev_first_half = (first_half % 10) * 1000 + ((first_half / 10) % 10) * 100 + ((first_half / 100) % 10) * 10 + (first_half / 1000);

    int result = second_half * 10000 +rev_first_half;

    std::cout << result << std::endl;
    return 0;
}
