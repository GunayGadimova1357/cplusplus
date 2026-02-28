#include <iostream>

void binary_search(int* arr, int arr_size, int element_to_find) {
    int binary_search_attempts = 0;

    int* left = arr;
    int* right = arr + arr_size - 1;

    while (left <= right) {
        int* middle = left + (right - left) / 2;
        binary_search_attempts++;

        if (*middle == element_to_find) {
            std::cout << (middle - arr) << " Index\n";
            std::cout << "The element found in " << binary_search_attempts << " attempts\n";
            return;
        }

        if (*middle > element_to_find) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }

    std::cout << "Element not found after " << binary_search_attempts << " attempts\n";
}

int main() {
    const int arr_size = 999;
    int arr[arr_size];
    srand(time(NULL));
    int* arr_pointer = arr;
    for (int* arr_pointer = arr; arr_pointer < arr + arr_size; arr_pointer++) {
        *arr_pointer = (arr_pointer - arr) + 1;
    }
    for (int i = 0; i < arr_size; i++) {
        std::cout << *(arr_pointer + i) << "\n";
    }
    std::cout << std::endl;

    int element_to_find;
    std::cout << "Enter element to find: ";
    std::cin >> element_to_find;

    binary_search(arr, arr_size, element_to_find);

    return 0;
}
