#include <iostream>

int main() {
    int option;
    std::cout<< "Enter option:\n";
    std::cout<< "1. There are 2 3x3 matrices. Multiply the elements in the 1st matrix by the elements in the 2nd matrix.(using maths formula)\n";
    std::cout<<"2. There are 3x2 and 2x3 matrices. add them.(without using maths formula)\n";
    std::cin >> option;

    srand(time(NULL));

    if (option == 1) {
        int arr1[3][3], arr2[3][3], result[3][3];
        std::cout << "Matrix 1:\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                arr1[i][j] = rand() % 10;
                std::cout << arr1[i][j] << " ";
            }
            std::cout << std::endl;
        }

        std::cout << "Matrix 2:\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                arr2[i][j] = rand() % 10;
                std::cout << arr2[i][j] << " ";
            }
            std::cout << std::endl;
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result[i][j] = 0;
                for (int k = 0; k < 3; k++) {
                    result[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }

        std::cout << "Result of multiplication:\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << result[i][j] << " ";
            }
            std::cout << std::endl;
        }

    }
    else if (option == 2) {
        int arr1[3][2], arr2[2][3], result[3][3];
        std::cout << "Matrix 1:\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                arr1[i][j] = rand() % 10;
                std::cout << arr1[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "Matrix 2:\n";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                arr2[i][j] = rand() % 10;
                std::cout << arr2[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "Result of addition:\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (j < 2) {
                    result[i][j] = arr1[i][j];
                }
                if (i < 2) {
                    result[i][j] += arr2[i][j];
                }
                std::cout << result[i][j] << " ";
            }
            std::cout << std::endl;
        }


    }
    return 0;
}
