#include <iostream>

class Grocery {
private:
    char* _name;
    char* _type;
    float _price;
public:
    // Constructor
    Grocery() {
        std::cout << "Grocery constructor";
    }
    Grocery(char* name, char* type, float price) :
        _name(name), _type(type), _price(price) {}

    // getters
    char* get_name() const;
    char* get_type() const;
    float get_price() const;

    //setters
    void set_name(char* other);
    void set_type(char* other);
    void set_price(float other);


};


char* Grocery::get_name() const {
    return _name;
}
char* Grocery::get_type() const {
    return _type;
}
float Grocery::get_price() const {
    return _price;
}
void Grocery::set_name(char* other) {
    if (other != nullptr)
    {
        _name = other;
    }
}
void Grocery::set_type(char* other) {
    if (other != nullptr)
    {
        _type = other;
    }
}
void Grocery::set_price(float other) {
    if (other >= 0)
    {
        _price = other;
    }
}


class Market {
private:
    char* _name;
    Grocery* _groceries;
    size_t _capacity;
    size_t _count;

public:
    Market(char* name, size_t capacity)
    {
        std::cout << "Market constructor\n";
        _capacity = capacity;
        _name = name;
        _count = 0;
        _groceries = new Grocery();
    }

    ~Market() {
        delete[] _groceries;
        std::cout << "\nMarket Destructor\n";
    }
    void add_grocery_at_index(const Grocery& grocery, size_t index) {
        if (_count >= _capacity || index > _count) {
            return;
        }

        for (size_t i = _count; i > index; --i) {
            _groceries[i] = _groceries[i - 1];
        }

        _groceries[index] = grocery;
        _count++;
    }
    void remove_grocery_by_index(size_t index) {
        if (index < _count) {
            for (size_t i = index; i < _count - 1; ++i) {
                _groceries[i] = _groceries[i + 1];
            }
            _count--;
        }
    }


    Grocery find(const char* name) const {
        for (size_t i = 0; i < _count; ++i) {
            if (strcmp(_groceries[i].get_name(), name) == 0) {
                return _groceries[i];
            }
        }
        return Grocery();
    }
};


int main() {
    char name[50] = "Aftandil";
    Market market(name, 10);
    Grocery grocery_1("banana","fruit",1.5f);
    Grocery grocery_2("apple","fruit",1.5f);
    market.add_grocery_at_index(grocery_2,0);
    market.add_grocery_at_index(grocery_1, 1);
    market.remove_grocery_by_index(0);
    char search_name[50];
    std::cout << "\nEnter grocery name to find: ";
    std::cin >> search_name;
    Grocery found_grocery = market.find(search_name);
    if (market.find(search_name).get_name() != nullptr) {
        std::cout << "Grocery found: Name: " << found_grocery.get_name()
                  << ", Type: " << found_grocery.get_type()
                  << ", Price: " << found_grocery.get_price() << "\n";
    } else {
        std::cout << search_name << " not found.\n";
    }
    return 0;
}