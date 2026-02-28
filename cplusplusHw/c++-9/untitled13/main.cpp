#include <iostream>

int main() {
    const int ARR_SIZE = 10;
    int arr[ARR_SIZE];

    srand(time(0));
    for (int* ptr = arr; ptr < arr + ARR_SIZE; ++ptr) {
        *ptr = rand() % 20 + 10;
    }

    std::cout << "Original array: " << std::endl;
    for (int* ptr = arr; ptr < arr + ARR_SIZE; ++ptr) {
        std::cout << *ptr << " ";
    }


    // bubble sort algorithm
    for (int* ptr1 = arr; ptr1 < arr + ARR_SIZE; ++ptr1) {
        for (int* ptr2 = arr; ptr2 < arr + ARR_SIZE-(ptr1-arr)-1; ++ptr2) {
            if (*ptr2 > *(ptr2+1)) {
                int temp = *ptr2;
                *ptr2 = *(ptr2+1);
                *(ptr2+1) = temp;
            }

        }
    }

    std::cout << "\nSorted array (Bubble)" << std::endl;
    for (int* ptr = arr; ptr < arr + ARR_SIZE; ++ptr) {
        std::cout << *ptr << " ";
    }




    //Insertion sort
    for (int* ptr1 = arr; ptr1 < arr + ARR_SIZE; ++ptr1) {
        int key = *ptr1;
        int* ptr2 = ptr1 - 1;

        while (ptr2 >= arr && *ptr2 > key) {
            *(ptr2+1) = *ptr2;
            ptr2--;
        }

        *(ptr2+1) = key;
    }
    std::cout << "\nSorted array (Insertion)" << std::endl;
    for (int* ptr = arr; ptr < arr + ARR_SIZE; ++ptr) {
        std::cout << *ptr << " ";
    }


    //Selection sort

    for (int* ptr1 = arr; ptr1 < arr + ARR_SIZE; ++ptr1) {
        int* min_ptr = ptr1;

        for (int* ptr2 = ptr1 + 1; ptr2 < arr + ARR_SIZE; ++ptr2) {
            if (*ptr2 < *min_ptr) {
                min_ptr = ptr2;
            }
        }
        int temp = *min_ptr;
        *min_ptr = *ptr1;
        *ptr1 = temp;
    }

    std::cout << "\nSorted array (Selection)" << std::endl;
    for (int* ptr = arr; ptr < arr + ARR_SIZE; ++ptr) {
        std::cout << *ptr << " ";
    }



    return 0;
}