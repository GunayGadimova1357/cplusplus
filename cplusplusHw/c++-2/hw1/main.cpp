#include <iostream>

int main() {
    int first_num, second_num;
    char operation;
    std::cout <<std::endl << "Enter first number: ";
    std::cin >> first_num;
    std::cout<< std::endl <<"Enter operation: ";
    std::cin >> operation;
    std::cout << std::endl << "Enter second number: ";
    std::cin >>second_num;
    switch (operation) {
        case '+':
            std::cout << first_num << " + " << second_num << " = " << first_num + second_num;
        break;
        case '-':
            std::cout << first_num << " - " << second_num << " = " << first_num - second_num;
        break;
        case '*':
            std::cout << first_num << " * " << second_num << " = " << first_num * second_num;
        break;
        case '/':
            if (second_num == 0) {
                std::cout<<"Division by zero is undefined"<<std::endl;
            }
            else {
                std::cout << first_num << " / " << second_num << " = " << first_num / second_num;
            }

        break;
        default:
            std::cout << "Invalid operation";
        break;
    }
    return 0;
}
