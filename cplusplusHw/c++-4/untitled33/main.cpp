#include <iostream>

const int rows = 6;
const int cols = 7;
const int mazeSize = rows * cols;


char direction[4] = { 'D', 'L', 'R', 'U' };
int dr[4] = { cols, -1, 1, -cols };

int main() {
    char maze[mazeSize] = {
        '#', '#', '#', '#', '#', '#', '#',
        '#', ' ', '#', 'E', ' ', '#', '#',
        '#', 'S', '#', '#', ' ', '#', '#',
        '#', ' ', '#', ' ', ' ', '#', '#',
        '#', ' ', ' ', ' ', '#', '#', '#',
        '#', '#', '#', '#', '#', '#', '#'
    };

    int pathCount = 0;
    char currentPath[100];
    int step = 0;
    int start = 2 * cols + 1;
    int indexStack[100], stepStack[100], dirStack[100];
    int top = -1;

    indexStack[++top] = start;
    stepStack[top] = step;
    dirStack[top] = 0;

    while (top >= 0) {
        int index = indexStack[top];
        step = stepStack[top];
        int &dir = dirStack[top];

        if (maze[index] == 'E') {

            std::cout << "Path " << (++pathCount) << ":" << std::endl;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    int idx = i * cols + j;
                    std::cout << maze[idx];
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;

            top--;
            continue;
        }

        if (dir == 0) {
            maze[index] = '*';
        }

        if (dir < 4) {
            int nextIndex = index + dr[dir];
            currentPath[step] = direction[dir];
            dir++;

            if (nextIndex >= 0 && nextIndex < mazeSize && maze[nextIndex] != '#' && maze[nextIndex] != '*') {

                indexStack[++top] = nextIndex;
                stepStack[top] = step + 1;
                dirStack[top] = 0;
            }
        } else {

            maze[index] = (index == start) ? 'S' : ' ';
            top--;
        }
    }

    if (pathCount == 0) {
        std::cout << -1 << std::endl;
    }

    return 0;
}
