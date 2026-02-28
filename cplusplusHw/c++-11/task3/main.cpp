#include <iostream>

void displayMenu();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main() {
    while (true) {
        displayMenu();
        int choice;
        std::cin >> choice;
        if (choice == 5) {
            std::cout << "Exiting the program. Goodbye!\n";
            break;
        }

        double num1, num2;

        std::cout << "Enter the first number: ";
        std::cin >> num1;
        std::cout << "Enter the second number: ";
        std::cin >> num2;

        double result = 0;

        switch (choice) {
            case 1:
                result = add(num1, num2);
                std::cout << "Result: " << result << std::endl;
            break;
            case 2:
                result = subtract(num1, num2);
                std::cout << "Result: " << result << std::endl;
            break;
            case 3:
                result = multiply(num1, num2);
                std::cout << "Result: " << result << std::endl;
            break;
            case 4:
                if (num2 == 0) {
                    std::cout << "Error: Division by zero is not allowed.\n";
                } else {
                    result = divide(num1, num2);
                    std::cout << "Result: " << result << std::endl;
                }
            break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
            break;
        }

        std::cout << std::endl;
    }

    return 0;
}

void displayMenu() {

    std::cout << "Select an operation:\n";
    std::cout << "1. Addition\n";
    std::cout << "2. Subtraction\n";
    std::cout << "3. Multiplication\n";
    std::cout << "4. Division\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice (1-5): ";

}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        std::cout << "Error: Division by zero is not allowed.\n";
        return 0;
    }
    return a / b;
}
