#include <iostream>

inline int plus(int a, int b);
inline int minus(int a, int b);
inline int times(int a, int b);
inline int divide(int a, int b);
inline float plus(float a, float b);
inline float minus(float a, float b);
inline float times(float a, float b);
inline float divide(float a, float b);

int main() {
    int option;
    std::cout<< "Enter option:\n";
    std::cout<< "1. int\n";
    std::cout<< "2. float\n";
    std::cin >> option;
    char operation;
    std::cout<< "Enter operation:\n";
    std::cin >> operation;
    if (option == 1) {
        int a,b;
        std::cout<< "Enter numbers:\n";
        std::cin >> a>>b;
        switch (operation) {
            case '+':
                std::cout << a << " + " << b<< " = " << plus(a, b);
            break;
            case '-':
                std::cout << a << " - " << b<< " = " << minus(a, b);
            break;
            case '*':
                std::cout << a << " * " << b<< " = " << times(a, b);
            break;
            case '/':
                if (b == 0) {
                    std::cout<<"Division by zero is undefined"<<std::endl;
                }
                else {
                    std::cout << a << " / " << b<< " = " << divide(a, b);
                }
            break;
            default:
                std::cout<<"Invalid operation"<<std::endl;
            break;
        }
    }
    else if (option == 2) {
        float a,b;
        std::cout<< "Enter numbers:\n";
        std::cin >> a>>b;
        switch (operation) {
            case '+':
                std::cout << a << " + " << b<< " = " << plus(a, b);
            break;
            case '-':
                std::cout << a << " - " << b<< " = " << minus(a, b);
            break;
            case '*':
                std::cout << a << " * " << b<< " = " << times(a, b);
            break;
            case '/':
                if (b == 0) {
                    std::cout<<"Division by zero is undefined"<<std::endl;
                }
            else {
                std::cout << a << " / " << b<< " = " << divide(a, b);
            }
            break;
            default:
                std::cout<<"Invalid operation"<<std::endl;
            break;
        }
    }

    return 0;
}
inline int plus(int a, int b) {
    return a + b;
}
inline int minus(int a, int b) {
    return a - b;
}
inline int times(int a, int b) {
    return a * b;
}
inline int divide(int a, int b) {
    return a / b;
}
inline float plus(float a, float b) {
    return a + b;
}
inline float minus(float a, float b) {
    return a - b;
}
inline float times(float a, float b) {
    return a * b;
}
inline float divide(float a, float b) {
    return a / b;
}