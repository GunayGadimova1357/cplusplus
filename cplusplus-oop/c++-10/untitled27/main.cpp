#include <iostream>
#include <cstring>
#include <stdexcept>

class BookNotFoundException : public std::exception {
private:
    const char* _msg;
public:
    explicit BookNotFoundException(const char* msg) : _msg(msg) {}
    inline virtual const char* what() const noexcept override {
        return _msg;
    }
};

class LibraryCapacityExceededException : public std::exception {
private:
    const char* _msg;
public:
    explicit LibraryCapacityExceededException(const char* msg) : _msg(msg) {}
    inline virtual const char* what() const noexcept override {
        return _msg;
    }
};

class Item {
protected:
    char* title;
public:
    Item(const char* itemTitle) {
        title = new char[strlen(itemTitle) + 1];
        strcpy(title, itemTitle);
    }

    virtual ~Item() {
        delete[] title;
    }

    virtual void getInfo() const = 0;

    const char* getTitle() const {
        return title;
    }
};

class Book : public Item {
private:
    char* author;
    int publicationYear;
public:
    Book(const char* title, const char* newAuthor, int year) : Item(title), publicationYear(year) {
        author = new char[strlen(newAuthor) + 1];
        strcpy(author, newAuthor);
    }

    ~Book() override {
        delete[] author;
    }

    void getInfo() const override {
        std::cout << "Title: " << title
                  << ", Author: " << author
                  << ", Year: " << publicationYear << std::endl;
    }
};

class Library {
private:
    Item** items;
    int size;
    int capacity;

public:
    Library(int capacity = 50) : capacity(capacity), size(0) {
        items = new Item*[capacity];
    }

    ~Library() {
        for (int i = 0; i < size; ++i) {
            delete items[i];
        }
        delete[] items;
    }

    void addItem(Item* item) {
        if (size >= capacity) {
            throw LibraryCapacityExceededException("Library capacity exceeded.");
        }
        items[size++] = item;
    }

    void removeItem(const char* title) {
        for (int i = 0; i < size; ++i) {
            if (strcmp(items[i]->getTitle(), title) == 0) {
                delete items[i];

                for (int j = i; j < size - 1; ++j) {
                    items[j] = items[j + 1];
                }

                --size;
                return;
            }
        }

        throw BookNotFoundException("Book not found in the library.");
    }

    void listItems() const {
        if (size == 0) {
            std::cout << "Library is empty.\n";
            return;
        }
        for (int i = 0; i < size; ++i) {
            items[i]->getInfo();
        }
    }
};

class LibraryManager {
private:
    Library library;

public:
    LibraryManager(int capacity = 50) : library(capacity) {}

    void mainMenu() {
        int choice;
        while (true) {
            std::cout << "\nLibrary Menu:\n"
                      << "1. Add Book\n"
                      << "2. Remove Book\n"
                      << "3. List Books\n"
                      << "4. Exit\n"
                      << "Choose an option: ";
            std::cin >> choice;

            std::cin.ignore();
            switch (choice) {
                case 1:
                    addBook();
                    break;
                case 2:
                    removeBook();
                    break;
                case 3:
                    library.listItems();
                    break;
                case 4:
                    std::cout << "Exiting the library system.\n";
                    return;
                default:
                    std::cout << "Invalid choice, try again.\n";
            }
        }
    }

    void addBook() {
        char title[100], author[100];
        int year;

        std::cout << "Enter book title: ";
        std::cin.getline(title, 100);
        std::cout << "Enter author name: ";
        std::cin.getline(author, 100);
        std::cout << "Enter publication year: ";
        std::cin >> year;

        try {
            library.addItem(new Book(title, author, year));
            std::cout << "Book added successfully.\n";
        } catch (const LibraryCapacityExceededException& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    void removeBook() {
        char title[100];
        std::cout << "Enter book title to remove: ";
        std::cin.ignore();
        std::cin.getline(title, 100);

        try {
            library.removeItem(title);
            std::cout << "Book removed successfully.\n";
        } catch (const BookNotFoundException& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }
};

int main() {
    LibraryManager manager;
    manager.mainMenu();
    return 0;
}
