#include <iostream>

class Item
{
public:

    virtual void use() = 0;
    virtual const char* get_name() const = 0;
    virtual const char* get_description() const = 0;
    virtual void effect() = 0;
    virtual ~Item() {}
};

class Food : public Item {
public:
    void use() override {
        std::cout << "You used a food!" << std::endl;
    }

    const char* get_name() const {
        return "Food";
    }
    const char* get_description() const override {
        return "Tasty food.";
    }
    void effect() override {
        std::cout << "Health restored." << std::endl;
    }

};

class Stick : public Item {
public:
    void use() override {
        std::cout << "You used a stick!" << std::endl;
    }

    const char* get_name() const {
        return "Stick";
    }
    const char* get_description() const override {
        return "A simple wooden stick.";
    }

    void effect() override {
        std::cout << "Used for combat." << std::endl;
    }
};
class Potion : public Item {
public:
    void use() override {
        std::cout << "You used a potion!" << std::endl;
    }

    const char* get_name() const override {
        return "Potion";
    }

    const char* get_description() const override {
        return "A potion that buffs atk.";
    }

    void effect() override {
        std::cout << "Attack buffed." << std::endl;
    }
};
class Armor : public Item {
public:
    void use() override {
        std::cout << "You equipped armor!" << std::endl;
    }

    const char* get_name() const override {
        return "Armor";
    }

    const char* get_description() const override {
        return "Armor that increases def.";
    }

    void effect() override {
        std::cout << "Defence is increased." << std::endl;
    }
};


class Inventory {
private:
    Item* _items[10];
    int _item_count;
public:
    Inventory() : _item_count(0) {}

    ~Inventory() {
        for (size_t i = 0; i < _item_count; i++)
        {
            delete _items[i];
        }
    }

    int get_items_count() const {
        return _item_count;
    }

    bool add_item(Item* item)
    {
        if (_item_count < 10)
        {
            _items[_item_count++] = item;
            return true;
        }
        return false;
    }

    bool use_item(int index) {
        if (index >= 0 && index < _item_count)
        {
            _items[index]->use();
            _items[index]->effect();
            return true;
        }
        return false;
    }

    Item* operator[](int index) {
        return _items[index];
    }

};

void show_inventory(Inventory& inventory) {
    for (size_t i = 0; i < inventory.get_items_count(); i++)
    {
        std::cout << i << ". " << inventory[i]->get_name() << std::endl;
    }
}
void use_all_items(Inventory& inventory) {
    for (size_t i = 0; i < inventory.get_items_count(); i++) {
        inventory[i]->use();
        inventory[i]->effect();
    }
}

int main()
{

    Inventory inventory;
    inventory.add_item(new Food());
    inventory.add_item(new Stick());
    inventory.add_item(new Potion());
    inventory.add_item(new Armor());
    std::cout<<">>INVENTORY<<"<<std::endl;
    show_inventory(inventory);
    std::cout<<">>USAGE<<"<<std::endl;
    use_all_items(inventory);

    Item* items[4] = { new Food(), new Stick(), new Potion(), new Armor() };
    std::cout<<">>INFO<<"<<std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << items[i]->get_name() << ": " << items[i]->get_description() << std::endl;
        delete items[i];
    }

    return 0;
}
