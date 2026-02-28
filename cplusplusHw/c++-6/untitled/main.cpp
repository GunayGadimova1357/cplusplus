#include <iostream>

int main() {
    const int ROW=3, COL=3;
    int matrix1[ROW][COL];
    int matrix2[ROW][COL];
    srand(time(NULL));
    std::cout<<"the first matrix: "<<std::endl;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            matrix1[i][j] = rand() % 10;
            std::cout << matrix1[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout<<"the second matrix: "<<std::endl;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            matrix2[i][j] = rand() % 10;
            std::cout << matrix2[i][j] << " ";
        }
        std::cout << std::endl;
    }
    int matrix_selection1, col1, matrix_selection2, col2;

    std::cout << "choose matrix: ";
    std::cin >> matrix_selection1;
    std::cout << "select column from the chosen matrix (1-3): ";
    std::cin >> col1;

    std::cout << "choose matrix: ";
    std::cin >> matrix_selection2;
    std::cout << "select column from the chosen matrix (1-3): ";
    std::cin >> col2;

    const int TEMP_ARR_SIZE=COL;
    int tempCol[TEMP_ARR_SIZE];

    for (int i = 0; i < TEMP_ARR_SIZE; i++) {
        if (matrix_selection1 == 1) {
            tempCol[i] = matrix1[i][col1 - 1];
        } else {
            tempCol[i] = matrix2[i][col1 - 1];
        }
    }

    for (int i = 0; i < TEMP_ARR_SIZE; i++) {
        if (matrix_selection1 == 1) {
            matrix1[i][col1 - 1] = rand() % 10;
        } else {
            matrix2[i][col1 - 1] = rand() % 10;
        }
    }

    for (int i = 0; i < TEMP_ARR_SIZE; i++) {
        if (matrix_selection2 == 1) {
            matrix1[i][col2 - 1] = tempCol[i];
        } else {
            matrix2[i][col2 - 1] = tempCol[i];
        }
    }

    std::cout << "the first matrix:" << std::endl;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            std::cout << matrix1[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "the second matrix:" << std::endl;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            std::cout << matrix2[i][j] << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}
