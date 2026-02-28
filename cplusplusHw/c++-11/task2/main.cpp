#include <iostream>

int compareAsc(const int arr[], int index1, int index2);
int compareDesc(const int arr[], int index1, int index2);
template <typename T>
void sortArray(int arr[], int SIZE, T func);
void printArray(const int arr[], int size);

int main() {
    const int SIZE = 9;
    int arr[SIZE] = {3, 1, 4, 1, 5, 9, 2, 6, 5};

    std::cout << "Array sorted in ascending order: ";
    sortArray(arr, SIZE, compareAsc);
    printArray(arr, SIZE);

    std::cout << "Array sorted in descending order: ";
    sortArray(arr, SIZE, compareDesc);
    printArray(arr, SIZE);

    return 0;
}

int compareAsc(const int arr[], int index1, int index2) {
    return arr[index1] - arr[index2];
}

int compareDesc(const int arr[], int index1, int index2) {
    return arr[index2] - arr[index1];
}
template <typename T>
void sortArray(int arr[], int SIZE, T func) {
    for (int i = 0; i < SIZE; i++) {
        int min_index = i;

        for (int j = i + 1; j < SIZE; j++) {
            if (func(arr, j, min_index) < 0) {
                min_index = j;
            }
        }

        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}