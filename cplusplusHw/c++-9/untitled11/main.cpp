#include <iostream>
#include <cstdlib>
#include <ctime>


int main() {
    const int size = 10;
    int arr1[size];
    int arr2[size];

    srand(time(NULL));
    for (int *p1 = arr1; p1 < arr1 + size; p1++) {
        *p1 = rand() % 100;
    }
    for (int *p2 = arr2; p2 < arr2 + size; p2++) {
        *p2 = 0;
    }

    std::cout << "Original arr1: ";
    for (int *p1 = arr1; p1 < arr1 + size; ++p1) {
        std::cout << *p1 << " ";
    }
    std::cout << std::endl;

    std::cout << "Original arr2: ";
    for (int *p2 = arr2; p2 < arr2 + size; ++p2) {
        std::cout << *p2 << " ";
    }
    std::cout << std::endl;

    for (int *p1 = arr1, *p2 = arr2; p1 < arr1 + size; ++p1, ++p2) {
        *p2 = *p1;
        *p1 = 0;
    }

    std::cout << "New arr1: ";
    for (int *p1 = arr1; p1 < arr1 + size; ++p1) {
        std::cout << *p1 << " ";
    }
    std::cout << std::endl;

    std::cout << "New arr2: ";
    for (int *p2 = arr2; p2 < arr2 + size; ++p2) {
        std::cout << *p2 << " ";
    }
    std::cout << std::endl;

    return 0;
}
