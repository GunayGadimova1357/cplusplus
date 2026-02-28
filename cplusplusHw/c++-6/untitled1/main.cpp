#include <iostream>

int main() {

    const int ROW=3, COL=3;
    int matrix[ROW][COL];

    srand(time(NULL));

    std::cout<<"Original matrix:"<<std::endl;
    for(int i=0;i<ROW;i++) {
        for(int j=0;j<COL;j++) {
            matrix[i][j]=rand()%10;
            std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

    int user_choice;

    std::cout<<"\n1.row \n2.col \nyour choice(1-2):";
    std::cin>>user_choice;

    if(user_choice==1) {

        int row, steps, direction;

        std::cout<<"Which row?:";
        std::cin>>row;
        std::cout<<"Number of steps:";
        std::cin>>steps;
        std::cout<<"Left or right? (-1 for left, 1 for right):";
        std::cin>>direction;

        row--;

        if (direction == -1) {
            for (int step = 0; step < steps; step++) {
                int temp = matrix[row][0];
                for (int i = 0; i < COL - 1; i++) {
                    matrix[row][i] = matrix[row][i + 1];
                }
                matrix[row][COL- 1] = temp;
            }
        } else {
            for (int step = 0; step < steps; step++) {
                int temp = matrix[row][COL - 1];
                for (int i = COL - 1; i > 0; i--) {
                    matrix[row][i] = matrix[row][i - 1];
                }
                matrix[row][0] = temp;
            }
        }
    }
    else if(user_choice == 2) {

        int col, steps, direction;

        std::cout<<"Which column?:";
        std::cin>>col;
        std::cout<<"Number of steps:";
        std::cin>>steps;
        std::cout<<"Up or down? (-1 for down, 1 for up):";
        std::cin>>direction;

        col--;
        
        if (direction == -1) {
            for (int step = 0; step < steps; step++) {
                int temp = matrix[ROW-1][col];
                for (int i = ROW-1; i >0; i--) {
                    matrix[i][col] = matrix[i-1][col];
                }
                matrix[0][col] = temp;
            }

        } else {
            for (int step = 0; step < steps; step++) {
                int temp = matrix[0][col];
                for (int i = 0; i < ROW - 1; i++) {
                    matrix[i][col] = matrix[i + 1][col];
                }
                matrix[ROW - 1][col] = temp;
            }
        }
    }
    std::cout << "new matrix:" << std::endl;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
