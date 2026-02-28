#include <iostream>
#include <cstring>
#include <fstream>
#include <termios.h>
#include <unistd.h>

const int MENU_SIZE = 8;

struct Book {
    char title[50];
    char author[50];
    char genre[50];
    int year;
    bool availability;
};

struct Library {
    int book_count;
    Book books[100];
};

void display_books(Library& library);
void add_book(Library& library, const Book& new_book);
bool str_casecmp(const char* s1, const char* s2);
void delete_book(Library& library, const char* title);
void update_book(Library& library, const char* title);
void to_lowercase(const char* src, char* dest);
void find_book(Library& library, const char* title, const char* author, const char* genre);
bool is_duplicate(Library& library, Book& new_book);
void remove_books_by_attributes(Library& library, const char* title, const char* author, const char* genre, int year);
void find_books_by_attributes(Library& library, const char* title, const char* author, const char* genre, int year);
void save_book(Library& library, const char* filename);
void load_book(Library& library, const char* filename);
char getch();
void print_menu(int selected);
void set_color(int color);

int main() {
    Library library;
    library.book_count = 0;

    const char* book_filename = "books_menu.txt";

    load_book(library, book_filename);
    int selected = 0;

    while (true) {
        print_menu(selected);
        char ch = getch();

        if (ch == 'w') {
            selected = (selected - 1 + MENU_SIZE) % MENU_SIZE;
        } else if (ch == 's') {
            selected = (selected + 1) % MENU_SIZE;
        } else if (ch == 10) {
            switch (selected) {
                case 0:
                    display_books(library);
                    break;
                case 1: {
                    Book new_book;

                    std::cout << "Enter book title: ";
                    std::cin.ignore();
                    std::cin.getline(new_book.title, sizeof(new_book.title));
                    std::cout << "Enter author: ";
                    std::cin.getline(new_book.author, sizeof(new_book.author));
                    std::cout << "Enter genre: ";
                    std::cin.getline(new_book.genre, sizeof(new_book.genre));
                    std::cout << "Enter year: ";
                    std::cin >> new_book.year;
                    std::cout << "Enter book availability (1 for available, 0 for not): ";
                    std::cin >> new_book.availability;

                    if (is_duplicate(library, new_book)) {
                        std::cout << "This book already exists\n";
                        break;
                    }
                    add_book(library, new_book);
                    break;
                }
                case 2: {
                    char title_to_delete[50];
                    std::cin.ignore();
                    std::cout << "Enter book title: ";
                    std::cin.getline(title_to_delete, sizeof(title_to_delete));
                    delete_book(library, title_to_delete);
                    break;
                }
                case 3: {
                    char title_to_update[50];
                    std::cin.ignore();
                    std::cout << "Enter book title: ";
                    std::cin.getline(title_to_update, sizeof(title_to_update));
                    update_book(library, title_to_update);
                    break;
                }
                case 4: {
                    char keyword[50];
                    char lowercase_keyword_title[50];
                    char lowercase_keyword_author[50];
                    char lowercase_keyword_genre[50];
                    while (true) {
                        int keyword_find;
                        std::cout << "1. Find a book (by title)\n"
                                  << "2. Find a book (by author)\n"
                                  << "3. Find a book (by genre)\n"
                                  << "4. Exit\n"
                                  << std::endl;
                        std::cout << "Enter your choice: ";
                        std::cin >> keyword_find;
                        std::cin.ignore();
                        if (keyword_find == 4) break;
                        switch (keyword_find) {
                            case 1:
                                std::cout<<"Enter book title: ";
                                std::cin.getline(keyword, sizeof(keyword));
                                to_lowercase(keyword, lowercase_keyword_title);
                                find_book(library, lowercase_keyword_title, nullptr, nullptr);
                            break;
                            case 2:
                                std::cout<<"Enter book author: ";
                                std::cin.getline(keyword, sizeof(keyword));
                                to_lowercase(keyword, lowercase_keyword_author);
                                find_book(library, nullptr, lowercase_keyword_author, nullptr);
                            break;
                            case 3:
                                std::cout<<"Enter book genre: ";
                                std::cin.getline(keyword, sizeof(keyword));
                                to_lowercase(keyword, lowercase_keyword_genre);
                                find_book(library, nullptr, nullptr, lowercase_keyword_genre);
                            break;
                            default:
                                std::cout<<"Invalid choice\n";
                            break;
                        }
                    }
                    break;
                }
                case 5: {
                    char title_find[50];
                char author_find[50];
                char genre_find[50];
                int year_find;

                while (true) {
                    int choice_find;
                    std::cout<<"1. Find a book(by title)\n"
                    <<"2. Find a book(by author)\n"
                    <<"3. Find a book(by genre)\n"
                    <<"4. Find a book(by year)\n"
                    <<"5. Exit\n"
                    <<std::endl;
                    std::cout<<"Enter your choice: ";
                    std::cin>>choice_find;
                    std::cin.ignore();
                    if(choice_find==5) break;
                    switch(choice_find) {
                        case 1:
                            std::cout<<"Enter book title: ";
                            std::cin.getline(title_find, sizeof(title_find));
                            find_books_by_attributes(library, title_find, nullptr, nullptr, 0);
                        break;
                        case 2:
                            std::cout<<"Enter book author: ";
                            std::cin.getline(author_find, sizeof(author_find));
                            find_books_by_attributes(library, nullptr, author_find, nullptr, 0);
                        break;
                        case 3:
                            std::cout<<"Enter book genre: ";
                            std::cin.getline(genre_find, sizeof(genre_find));
                            find_books_by_attributes(library, nullptr, genre_find, nullptr, 0);
                        break;
                        case 4:
                            std::cout<<"Enter book year: ";
                            std::cin>>year_find;
                            std::cin.ignore();
                            find_books_by_attributes(library, nullptr, nullptr, nullptr, year_find);
                        break;
                        default:
                            std::cout<<"Invalid choice\n";
                        break;
                    }
                }
            break;

                }
                case 6: {
                    char title_delete[50];
                    char author_delete[50];
                    char genre_delete[50];
                    int year_delete;
                    while (true) {
                        int choice_delete;
                        std::cout << "1. Delete a book (by title)\n"
                                  << "2. Delete a book (by author)\n"
                                  << "3. Delete a book (by genre)\n"
                                  << "4. Delete a book (by year)\n"
                                  << "5. Exit\n"
                                  << std::endl;
                        std::cout << "Enter your choice: ";
                        std::cin >> choice_delete;
                        std::cin.ignore();
                        if (choice_delete == 5) break;
                        switch (choice_delete) {
                            case 1:
                                std::cout << "Enter book title: ";
                                std::cin.getline(title_delete, sizeof(title_delete));
                                remove_books_by_attributes(library, title_delete, nullptr, nullptr, 0);
                                break;
                            case 2:
                                std::cout << "Enter book author: ";
                                std::cin.getline(author_delete, sizeof(author_delete));
                                remove_books_by_attributes(library, nullptr, author_delete, nullptr, 0);
                                break;
                            case 3:
                                std::cout << "Enter book genre: ";
                                std::cin.getline(genre_delete, sizeof(genre_delete));
                                remove_books_by_attributes(library, nullptr, genre_delete, nullptr, 0);
                                break;
                            case 4:
                                std::cout << "Enter book year: ";
                                std::cin >> year_delete;
                                std::cin.ignore();
                                remove_books_by_attributes(library, nullptr, nullptr, nullptr, year_delete);
                                break;
                            default:
                                std::cout << "Invalid choice\n";
                                break;
                        }
                    }
                    break;
                }
                case 7:
                    std::cout << "Exiting\n";
                    save_book(library, book_filename);
                    return 0;
                default:
                    std::cout << "Invalid choice. Try again!" << std::endl;
                    break;
            }
        }
    }
    return 0;
}

void display_books(Library& library) {
    if (library.book_count == 0) {
        std::cout << "No books found" << std::endl;
        return;
    }
    for (int i = 0; i < library.book_count; i++) {
        std::cout << "\nBook:" << i + 1 << std::endl;
        std::cout << "Title: " << library.books[i].title << std::endl;
        std::cout << "Author: " << library.books[i].author << std::endl;
        std::cout << "Genre: " << library.books[i].genre << std::endl;
        std::cout << "Year: " << library.books[i].year << std::endl;
        std::cout << "Availability: " << (library.books[i].availability ? "Available" : "Not Available") << std::endl;
    }
}

void add_book(Library& library, const Book& new_book ) {
    if(library.book_count >= 100) {
        std::cout<<"Library is full"<<std::endl;
    }
    library.books[library.book_count] = new_book;
    library.book_count++;
    std::cout<<"Book added"<<std::endl;
}

bool str_casecmp(const char* s1, const char* s2) {
    while (*s1 != '\0' || *s2 != '\0') {

        char c1 = (*s1 >= 'A' && *s1 <= 'Z') ? *s1 + ('a' - 'A') : *s1;
        char c2 = (*s2 >= 'A' && *s2 <= 'Z') ? *s2 + ('a' - 'A') : *s2;

        if (c1 != c2) {
            return false;
        }

        s1++;
        s2++;
    }

    return true;
}

void delete_book(Library& library, const char* title ) {
    if(library.book_count == 0) {
        std::cout<<"No books found"<<std::endl;
    }
    bool found = false;
    for(int i = 0; i < library.book_count; i++) {
        if(str_casecmp(library.books[i].title, title)) {
            for(int j = i; j < library.book_count-1; j++) {
                library.books[j] = library.books[j+1];
            }
            library.book_count--;
            found = true;
            std::cout<<"Book deleted"<<std::endl;
            break;
        }
    }
    if(!found) {
        std::cout<<"No books found"<<std::endl;
    }
}

void update_book(Library& library, const char* title) {
    if(library.book_count == 0) {
        std::cout<<"No books found"<<std::endl;
    }
    bool found = false;
    for(int i = 0; i < library.book_count; i++) {
        if(str_casecmp(library.books[i].title, title)) {
            found = true;
            std::cout<<"Updating"<<std::endl;
            std::cout<<"Enter book title: ";
            std::cin.ignore();
            std::cin.getline(library.books[i].title, sizeof(library.books[i].title));
            std::cout<<"Enter author: ";
            std::cin.getline(library.books[i].author, sizeof(library.books[i].author));
            std::cout<<"Enter genre: ";
            std::cin.getline(library.books[i].genre, sizeof(library.books[i].genre));
            std::cout<<"Enter year: ";
            std::cin >> library.books[i].year;
            std::cout<<"Enter book availability(1,0): ";
            std::cin >> library.books[i].availability;
            std::cout<<"Book updated"<<std::endl;
            break;
        }
    }
}

void to_lowercase(const char* src, char* dest) {
    while (*src != '\0') {
        if (*src >= 'A' && *src <= 'Z') {
            *dest = *src + ('a' - 'A');
        } else {
            *dest = *src;
        }
        src++;
        dest++;
    }
    *dest = '\0';
}

void find_book(Library& library, const char* title, const char* author, const char* genre) {
    if (library.book_count == 0) {
        std::cout << "No books found" << std::endl;
        return;
    }

    bool found = false;

    for (int i = 0; i < library.book_count; i++) {
        bool matches = true;

        char lowercase_book_title[50];
        char lowercase_book_author[50];
        char lowercase_book_genre[50];

        to_lowercase(library.books[i].title, lowercase_book_title);
        to_lowercase(library.books[i].author, lowercase_book_author);
        to_lowercase(library.books[i].genre, lowercase_book_genre);

        if (title != nullptr && !strstr(lowercase_book_title, title)) {
            matches = false;
        }
        if (author != nullptr && !strstr(lowercase_book_author, author)) {
            matches = false;
        }
        if (genre != nullptr && !strstr(lowercase_book_genre, genre)) {
            matches = false;
        }

        if (matches) {
            found = true;
            std::cout << "\n";
            std::cout << "Found: " << i + 1 << std::endl;
            std::cout << "Title: " << library.books[i].title << std::endl;
            std::cout << "Author: " << library.books[i].author << std::endl;
            std::cout << "Genre: " << library.books[i].genre << std::endl;
            std::cout << "Year: " << library.books[i].year << std::endl;
            std::cout << "Availability: " << (library.books[i].availability ? "Available" : "Not Available") << std::endl;
        }
    }

    if (!found) {
        std::cout << "No books found" << std::endl;
    }
}

bool is_duplicate(Library& library, Book& new_book) {
    for (int i = 0; i < library.book_count; i++) {
        if (str_casecmp(library.books[i].title, new_book.title) &&
            str_casecmp(library.books[i].author, new_book.author) &&
            str_casecmp(library.books[i].genre, new_book.genre) &&
            library.books[i].year == new_book.year) {
            return true;
            }
    }
    return false;
}

void remove_books_by_attributes(Library& library, const char* title, const char* author, const char* genre, int year) {
    if (library.book_count == 0) {
        std::cout << "No books found" << std::endl;
        return;
    }

    int original_count = library.book_count;
    for (int i = 0; i < library.book_count; i++) {
        bool matches = true;

        if (title != nullptr && !str_casecmp(library.books[i].title, title)) matches = false;
        if (author != nullptr && !str_casecmp(library.books[i].author, author)) matches = false;
        if (genre != nullptr && !str_casecmp(library.books[i].genre, genre)) matches = false;
        if (year >= 0 && library.books[i].year != year) matches = false;

        if (matches) {
            for (int j = i; j < library.book_count - 1; j++) {
                library.books[j] = library.books[j + 1];
            }
            library.book_count--;
            std::cout << "Book deleted: " << library.books[i].title << std::endl; // Show deleted book title
            i--;
        }
    }

    if (library.book_count < original_count) {
        std::cout << original_count - library.book_count << " books removed." << std::endl;
    } else {
        std::cout << "No matching books found to remove." << std::endl;
    }

}

void find_books_by_attributes(Library& library, const char* title, const char* author, const char* genre, int year) {
    if (library.book_count == 0) {
        std::cout << "No books found" << std::endl;
        return;
    }

    bool found_any = false;

    for (int i = 0; i < library.book_count; i++) {
        bool matches = true;

        if (title != nullptr && !str_casecmp(library.books[i].title, title)) matches = false;
        if (author != nullptr && !str_casecmp(library.books[i].author, author)) matches = false;
        if (genre != nullptr && !str_casecmp(library.books[i].genre, genre)) matches = false;
        if (year >= 0 && library.books[i].year != year) matches = false;


        if (matches) {
            found_any = true;
            std::cout << "Found:\n" << std::endl;
            std::cout << "Title: " << library.books[i].title << std::endl;
            std::cout << "Author: " << library.books[i].author << std::endl;
            std::cout << "Genre: " << library.books[i].genre << std::endl;
            std::cout << "Year: " << library.books[i].year << std::endl;
            std::cout << "Availability: " << library.books[i].availability << std::endl;
            std::cout << "-------------------" << std::endl;
        }
    }

    if (!found_any) {
        std::cout << "No matching books found." << std::endl;
    }
}

void save_book(Library& library, const char* filename) {
    std::ofstream out_file(filename);
    if (!out_file) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return;
    }

    for (int i = 0; i < library.book_count; i++) {
        out_file << library.books[i].title << "\n"
                 << library.books[i].author << "\n"
                 << library.books[i].genre << "\n"
                 << library.books[i].year << "\n"
                 << library.books[i].availability << "\n";
    }
    out_file.close();
    std::cout << "Library data saved successfully." << std::endl;
}

void load_book(Library& library, const char* filename) {
    std::ifstream in_file(filename);
    if (!in_file) {
        std::cerr << "Error opening file for reading!" << std::endl;
        return;
    }

    while (in_file.good() && library.book_count < 100) {
        Book new_book;
        in_file.getline(new_book.title, sizeof(new_book.title));
        in_file.getline(new_book.author, sizeof(new_book.author));
        in_file.getline(new_book.genre, sizeof(new_book.genre));
        in_file >> new_book.year;
        in_file >> new_book.availability;
        in_file.ignore();
        if (in_file.good()) {
            add_book(library, new_book);
        }
    }
    in_file.close();
    std::cout << "Library data loaded successfully." << std::endl;
}

char getch() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

void print_menu(int selected) {
    const char* menu_items[MENU_SIZE] = {
        "Display Books",
        "Add Book",
        "Delete Book",
        "Update Book",
        "Find Book by Keywords",
        "Find Books by Attributes",
        "Remove Books by Attributes",
        "Exit"
    };

    for (int i = 0; i < MENU_SIZE; i++) {
        if (i == selected) {
            set_color(12);
            std::cout << "> " << menu_items[i] << " <" << std::endl;
            set_color(0);
        } else {
            std::cout << "  " << menu_items[i] << std::endl;
        }
    }
}


void set_color(int color) {
    if (color == 12) {
        std::cout << "\033[1;31m";
    } else {
        std::cout << "\033[0m";
    }
}