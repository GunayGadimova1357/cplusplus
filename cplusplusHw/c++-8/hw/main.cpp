#include <iostream>
const int ROW = 3, COL = 3;
template <typename T>
void rotate_clockwise(T matrix[ROW][COL]);

int main() {
    int matrix[ROW][COL];
    srand(time(NULL));
    std::cout << "original matrix:" << std::endl;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            matrix[i][j] = rand() % 10;
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "rotated matrix:" << std::endl;
    rotate_clockwise(matrix);

    return 0;
}
template <typename T>
void rotate_clockwise(T matrix[ROW][COL]) {
    for (int i = 0; i<COL; i++) {
        for (int j =(ROW-1); j>=0; j--) {
            std::cout << matrix[j][i] << " ";
        }
        std::cout << std::endl;
    }
}
