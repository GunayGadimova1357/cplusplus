#include <iostream>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int getch(void) {
    struct termios oldt, newt;
    int ch;

    // Get the current terminal attributes
    tcgetattr(STDIN_FILENO, &oldt);

    // Set the terminal to raw mode (no echo, no buffering)
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);  // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // Read a single character
    ch = getchar();

    // Restore the old terminal attributes
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

const short ROWS = 6;
const short COLS = 6;

const char ITEM_1 = '#';
const char ITEM_2 = '&';

int experience_points = 0;

template<typename T>
void generate_matrix(T matrix[ROWS][COLS], T initial_value) {
    for (unsigned short i = 0; i < ROWS; i++) {
        for (unsigned short j = 0; j < COLS; j++) {
            matrix[i][j] = initial_value;
        }
    }
}

template<typename T>
void place_items(T matrix[ROWS][COLS], T item1, T item2) {
    srand(time(0));
    int item1_row = rand() % ROWS;
    int item1_col = rand() % COLS;
    int item2_row = rand() % ROWS;
    int item2_col = rand() % COLS;

    matrix[item1_row][item1_col] = item1;
    matrix[item2_row][item2_col] = item2;
}


template<typename T>
void display_matrix(const T matrix[ROWS][COLS], int p_row, int p_col) {
    system("clear");
    for (unsigned short i = 0; i < ROWS; i++) {
        for (unsigned short j = 0; j < COLS; j++) {
            if (i == p_row && j == p_col) {
                std::cout << 'P' << ' ';
            } else {
                std::cout << matrix[i][j] << ' ';
            }
        }
        std::cout << std::endl;
    }
}


void move_player(char direction, int& p_row, int& p_col) {
    switch (direction) {
        case 'w':
            if (p_row > 0) --p_row;       break;
        case 's':
            if (p_row < ROWS - 1) ++p_row; break;
        case 'a':
            if (p_col > 0) --p_col;       break;
        case 'd':
            if (p_col < COLS - 1) ++p_col; break;
        default:
            std::cout << "Invalid move" << std::endl;
            break;
    }
}


void check_item(char matrix[ROWS][COLS], int p_row, int p_col) {
    if (matrix[p_row][p_col] == ITEM_1) {
        experience_points += 10;
        std::cout << "you gained 10 experience points\n";
    } else if (matrix[p_row][p_col] == ITEM_2) {
        experience_points += 20;
        std::cout << "you gained 20 experience points\n";
    }
    matrix[p_row][p_col] = '.';
}

int main() {
    char matrix[ROWS][COLS];
    generate_matrix(matrix, '.');

    int player_row = 4, player_col = 2;

    place_items(matrix, ITEM_1, ITEM_2);

    display_matrix(matrix, player_row, player_col);

    while (true) {
        char move = getch();
        if (move == 'q') break;

        matrix[player_row][player_col] = '.';
        move_player(move, player_row, player_col);
        check_item(matrix, player_row, player_col);
        matrix[player_row][player_col] = 'P';
        display_matrix(matrix, player_row, player_col);

        std::cout << "your score: " << experience_points << std::endl;
    }

    return 0;
}
