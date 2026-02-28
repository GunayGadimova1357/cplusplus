#include <iostream>

int main() {
    int height, width;
    std::cout << "Enter Height: ";
    std::cin >> height;
    std::cout << "Enter Width: ";
    std::cin >> width;

    if (height == width && height % 2 != 0 && width % 2 != 0) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (i == 0 || i == height - 1 || i==1 || j == width - 1 || j==0) {
                    std::cout << "* ";
                }
                else {
                    if (j >= width - i) {
                        std::cout << "  ";
                    }
                    else {
                        std::cout << "* ";
                    }
                }

            }
            std::cout << std::endl;
        }
    }
    else {
        std::cout << "Wrong Input! Enter an odd number for both height and width." << std::endl;
    }

    return 0;
}
