#include <iostream>

template <typename T>
T** generate_matrix(int rows, int cols);

template <typename T>
void fill_matrix(T**& matrix, int rows, int cols);

template <typename T>
void display_matrix(T** matrix, int rows, int cols);

template <typename T>
void free_matrix(T**& matrix, int rows);

template <typename T>
void add_row_at(T**& matrix, int& rows, int cols, int index, T* new_row);

template <typename T>
void add_col_at(T**& matrix, int rows, int& cols, int index, T* new_col);

template <typename T>
void remove_row_at(T**& matrix, int& rows, int cols, int index);

template <typename T>
void remove_col_at(T**& matrix, int rows, int& cols, int index);

int main() {
    int rows, cols;

    std::cout << "Enter the number of rows and columns:" << std::endl;
    std::cin >> rows >> cols;

    int** matrix = generate_matrix<int>(rows, cols);
    fill_matrix(matrix,rows,cols);
    std::cout <<"your matrix:"<< std::endl;
    display_matrix(matrix,rows,cols);

    while (true) {
        std::cout << "your new matrix:" << std::endl;
        display_matrix(matrix, rows, cols);
        int choice;
        std::cout <<"1. add to row\n"
                    "2. add to col\n"
                    "3. remove row at\n"
                    "4. remove col at\n"
                    "5. exit\n"<<std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        int index;

        if (choice == 1) {
            int* new_row = new int[cols];
            std::cout << "Enter the values for the new row:" << std::endl;
            for (int i = 0; i < cols; i++) {
                std::cin >> new_row[i];
            }
            std::cout << "Enter the index at which to insert the new row as user sees (1-" << rows << "):" << std::endl;
            std::cin >> index;
            add_row_at(matrix, rows, cols, index, new_row);
        }
        else if (choice == 2) {
            int* new_col = new int[rows];
            std::cout << "Enter the values for the new col:" << std::endl;
            for (int i = 0; i <cols; i++) {
                std::cin >> new_col[i];
            }
            std::cout << "Enter the index at which to insert the new row as user sees (1-" << rows << "):" << std::endl;
            std::cin >> index;
            add_col_at(matrix, rows, cols, index, new_col);
        }
        else if (choice == 3) {
            std::cout << "Enter the index of the row to remove as user sees (1-" << rows << "):" << std::endl;
            std::cin >> index;
            remove_row_at(matrix, rows, cols, index);
        }
        else if (choice == 4) {
            std::cout << "Enter the index if the col to remove as user sees (1-" << rows << "):" << std::endl;
            std::cin >> index;
            remove_col_at(matrix, rows, cols, index);
        }
        else if (choice == 5) {break;}
        else {std::cout << "Invalid choice!"<<std::endl;}
    }

    free_matrix(matrix,rows);
    return 0;
}

template <typename T>
T** generate_matrix(int rows, int cols) {
    T** temp_matrix = new T*[rows];
    for (unsigned short i = 0; i < rows; i++) {
        temp_matrix[i] = new T[cols];
    }
    return temp_matrix;
}

template <typename T>
void fill_matrix(T**& matrix, int rows, int cols) {
    srand(time(NULL));
    for (unsigned short  i = 0; i < rows; i++) {
        for (unsigned short  j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

template <typename T>
void display_matrix(T** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

}

template <typename T>
void free_matrix(T**& matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

template <typename T>
void add_row_at(T**& matrix, int& rows, int cols, int index, T* new_row) {
    index--;
    T** temp_matrix = new T*[rows + 1];

    for (int i = 0; i < index; i++) {
        temp_matrix[i] = matrix[i];
    }

    temp_matrix[index] = new T[cols];

    for (int j = 0; j < cols; j++) {
        temp_matrix[index][j] = new_row[j];
    }

    for (int i = index; i < rows; i++) {
        temp_matrix[i + 1] = matrix[i];
    }

    delete[] matrix;
    matrix = temp_matrix;
    rows++;
}

template <typename T>
void add_col_at(T**& matrix, int rows, int& cols, int index, T* new_col) {
    index--;

    for (int i = 0; i < rows; i++) {
        T* temp_row = new T[cols + 1];

        for (int j = 0; j < index; j++) {
            temp_row[j] = matrix[i][j];
        }

        temp_row[index] = new_col[i];

        for (int j = index; j < cols; j++) {
            temp_row[j + 1] = matrix[i][j];
        }

        delete[] matrix[i];
        matrix[i] = temp_row;
    }
    cols++;

}
template <typename T>
void remove_row_at(T**& matrix, int& rows, int cols, int index) {
    index--;
    T** temp_matrix = new T*[rows - 1];
    for (int i = 0; i < index; i++) {
        temp_matrix[i] = matrix[i];
    }

    for (int i = index + 1; i < rows; i++) {
        temp_matrix[i - 1] = matrix[i];
    }

    delete[] matrix;
    matrix = temp_matrix;
    rows--;

}

template <typename T>
void remove_col_at(T**& matrix, int rows, int& cols, int index) {
    index--;

    for (int i = 0; i < rows; i++) {
        T* temp_row = new T[cols - 1];

        for (int j = 0; j < index; j++) {
            temp_row[j] = matrix[i][j];
        }

        for (int j = index + 1; j < cols; j++) {
            temp_row[j - 1] = matrix[i][j];
        }

        delete[] matrix[i];
        matrix[i] = temp_row;
    }

    cols--;
}

