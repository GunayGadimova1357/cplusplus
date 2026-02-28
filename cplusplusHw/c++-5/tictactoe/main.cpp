#include <iostream>

int main() {
    char board[3][3] = { {' ', ' ', ' '},
                         {' ', ' ', ' '},
                         {' ', ' ', ' '} };
    char player = 'X';
    char computer = 'O';
    int row, col;
    int turn;

    srand(time(NULL));

    std::cout << "Welcome to Tic-Tac-Toe!\n";

    for (turn = 0; turn < 9; turn++) {

        std::cout << "-------------\n";
        for (int i = 0; i < 3; i++) {
            std::cout << "| ";
            for (int j = 0; j < 3; j++) {
                std::cout << board[i][j] << " | ";
            }
            std::cout << "\n-------------\n";
        }

        if (turn % 2 == 0) {
            while (true) {
                std::cout << "Player " << player << ", enter row (1-3) and column (1-3): ";
                std::cin >> row >> col;

                row--;
                col--;

                if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
                    std::cout << "Invalid move. Try again.\n";
                } else {
                    break;
                }
            }

            board[row][col] = player;

        } else {
            std::cout << "Computer's turn (" << computer << ").\n";

            while (true) {
                row = rand() % 3;
                col = rand() % 3;

                if (board[row][col] == ' ') {
                    board[row][col] = computer;
                    break;
                }
            }
        }


        bool hasPlayerWon = false;
        bool hasComputerWon = false;

        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
                (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
                hasPlayerWon = true;
            }
            if ((board[i][0] == computer && board[i][1] == computer && board[i][2] == computer) ||
                (board[0][i] == computer && board[1][i] == computer && board[2][i] == computer)) {
                hasComputerWon = true;
            }
        }

        if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
            (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
            hasPlayerWon = true;
        }
        if ((board[0][0] == computer && board[1][1] == computer && board[2][2] == computer) ||
            (board[0][2] == computer && board[1][1] == computer && board[2][0] == computer)) {
            hasComputerWon = true;
        }

        if (hasPlayerWon) {
            std::cout << "Player " << player << " wins!\n";
            break;
        } else if (hasComputerWon) {
            std::cout << "Computer wins!\n";
            break;
        }
    }

    if (turn == 9) {
        std::cout << "-------------\n";
        for (int i = 0; i < 3; i++) {
            std::cout << "| ";
            for (int j = 0; j < 3; j++) {
                std::cout << board[i][j] << " | ";
            }
            std::cout << "\n-------------\n";
        }
        std::cout << "It's a draw!\n";
    }

    return 0;
}
