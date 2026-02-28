#include <iostream>

void print_properties(char locations[50][50], int buildings_count[50], double buildings_prices[50], int property_count);
void buy_house(double* price_ptr, int* count_ptr);
void sell_house(double* price_ptr, int* count_ptr);

int main() {
    char locations[50][50] = {
        {'S','a','h','i','l'},
        {'G','a','r','a','y','e','v'},
        {'E','h','m','e','d','l','i'}
    };

    int buildings_count[50] = { 20, 4, 40 };
    double buildings_prices[50] = { 55000, 78000, 89000 };

    print_properties(locations, buildings_count, buildings_prices, 3);

    int selected_property;
    std::cout << "Select a title: ";
    std::cin >> selected_property;
    selected_property--;

    char action;
    std::cout << "Sell or Buy? (S/B): ";
    std::cin >> action;

    double *price_ptr = buildings_prices + selected_property;
    int* count_ptr = buildings_count + selected_property;

    if (action == 'B' || action == 'b') {
        buy_house(price_ptr, count_ptr);
    } else if (action == 'S' || action == 's') {
        sell_house(price_ptr, count_ptr);
    } else {
        std::cout << "Invalid action.\n";
    }

    return 0;
}

void print_properties(char locations[50][50], int buildings_count[50], double buildings_prices[50], int property_count) {
    for (int i = 0; i < property_count; i++) {
        std::cout << (i + 1) << ")\nLocation: ";
        char* loc_ptr = *(locations + i);

        while (*loc_ptr != '\0') {
            std::cout << *loc_ptr;
            loc_ptr++;
        }

        std::cout << "\nNumber: " << buildings_count[i];
        std::cout << "\nPrice: ₼" << buildings_prices[i] << "\n\n";
    }
}

void buy_house(double* price_ptr, int* count_ptr) {
    int house_count;
    std::cout << "How many houses do you want to buy?: ";
    std::cin >> house_count;

    double total_price = house_count * (*price_ptr);
    std::cout << "Total price: ₼" << total_price << std::endl;

    char decision;
    std::cout << "Agree or Disagree? (A/D): ";
    std::cin >> decision;

    if (decision == 'A' || decision == 'a') {
        if (house_count > *count_ptr) {
            std::cout << "Sorry, not enough houses available.\n";
        } else {
            *count_ptr -= house_count;
            std::cout << "Purchase successful!\n";
        }
    } else if (decision == 'D' || decision == 'd') {
        std::cout << "Transaction cancelled.\n";
    }else {
        std::cout << "Invalid decision.\n";
    }
}

void sell_house(double* price_ptr, int* count_ptr) {
    int house_count;
    std::cout << "How many houses do you want to sell?: ";
    std::cin >> house_count;

    double total_price = house_count * (*price_ptr);
    std::cout << "Total price: ₼" << total_price << std::endl;

    char decision;
    std::cout << "Confirm sale? (Y/N): ";
    std::cin >> decision;

    if (decision == 'Y' || decision == 'y') {
        *count_ptr += house_count;
        std::cout << "Sale successful!\n";
    } else if(decision == 'N' || decision == 'n') {
        std::cout << "Transaction cancelled.\n";
    }else {
        std::cout << "Invalid decision.\n";
    }
}