#include <iostream>
#include <string.h>

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
void add_book(Library& library, const Book& new_book );
void delete_book(Library& library, const char* title);
void update_book(Library& library, const char* title);
void find_book(Library& library, const char* title);
bool is_duplicate(Library& library, Book& new_book);

int main() {
    Library library;
    library.book_count = 0;

    while(true) {
        int choice;
        std::cout<<"\n";
        std::cout<<"1. Add a book\n"
                <<"2. Delete a book\n"
                <<"3. Update information about a book\n"
                <<"4. Find a book(by name)\n"
                <<"5. Display all books\n"
                <<"6. Exit\n"
        <<std::endl;
        std::cout<<"Enter your choice: ";
        std::cin >> choice;
        switch(choice) {
            case 1:
                Book new_book;

                std::cout<<"Enter book title: ";
                std::cin >> new_book.title;
                std::cout<<"Enter author: ";
                std::cin >> new_book.author;
                std::cout<<"Enter genre: ";
                std::cin >> new_book.genre;
                std::cout<<"Enter year: ";
                std::cin >> new_book.year;
                std::cout<<"Enter book availability(1,0): ";
                std::cin >> new_book.availability;
                if(is_duplicate(library, new_book)) {
                    std::cout<<"This book already exists\n";
                    break;
                }
                add_book(library, new_book);
            break;
            case 2:
                char title_to_delete[50];
                std::cout<<"Enter book title: ";
                std::cin >> title_to_delete;

                delete_book(library, title_to_delete);
            break;
            case 3:
                char title_to_update[50];
                std::cout<<"Enter book title: ";
                std::cin >> title_to_update;

                update_book(library, title_to_update);
            break;
            case 4:

                char title_to_find[50];
                std::cout<<"Enter book title: ";
                std::cin >> title_to_find;

                find_book(library, title_to_find);
            break;
            case 5:
                display_books(library);
            break;
            case 6:
                std::cout<<"Exiting\n";
            return 0;
            default:
                std::cout<<"Invalid choice. Try again!";
            break;
        }
    }

    return 0;
}
void display_books(Library& library) {
    if(library.book_count == 0) {
        std::cout<<"No books found"<<std::endl;
        return;
    }
    for(int i = 0; i < library.book_count; i++) {
        std::cout<<"\nBook:"<<i+1<<"\n";
        std::cout<<"Title: "<<library.books[i].title<<std::endl;
        std::cout<<"Author: "<<library.books[i].author<<std::endl;
        std::cout<<"Genre: "<<library.books[i].genre<<std::endl;
        std::cout<<"Year: "<<library.books[i].year<<std::endl;
        std::cout<<"Availability: "<<library.books[i].availability<<std::endl;
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

void delete_book(Library& library, const char* title ) {
    if(library.book_count == 0) {
        std::cout<<"No books found"<<std::endl;
    }
    bool found = false;
    for(int i = 0; i < library.book_count; i++) {
        if(strcmp(title, library.books[i].title) == 0) {
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
        if(strcmp(title, library.books[i].title) == 0) {
            found = true;
            std::cout<<"Updating"<<std::endl;
            std::cout<<"Enter book title: ";
            std::cin >> library.books[i].title;
            std::cout<<"Enter author: ";
            std::cin >> library.books[i].author;
            std::cout<<"Enter genre: ";
            std::cin >> library.books[i].genre;
            std::cout<<"Enter year: ";
            std::cin >> library.books[i].year;
            std::cout<<"Enter book availability(1,0): ";
            std::cin >> library.books[i].availability;
            std::cout<<"Book updated"<<std::endl;
            break;
        }
    }
}
void find_book(Library& library, const char* title) {
    if(library.book_count == 0) {
        std::cout<<"No books found"<<std::endl;
    }
    bool found = false;
    for(int i = 0; i < library.book_count; i++) {
        if(strcmp(title, library.books[i].title) == 0) {
            found = true;
            std::cout<<"Found"<<std::endl;
            std::cout<<"Title: "<<library.books[i].title<<std::endl;
            std::cout<<"Author: "<<library.books[i].author<<std::endl;
            std::cout<<"Genre: "<<library.books[i].genre<<std::endl;
            std::cout<<"Year: "<<library.books[i].year<<std::endl;
            std::cout<<"Availability: "<<library.books[i].availability<<std::endl;
            found=true;
            break;
        }
    }
}

bool is_duplicate(Library& library, Book& new_book) {
    for (int i = 0; i < library.book_count; i++) {
        if (strcmp(library.books[i].title, new_book.title) == 0 &&
            strcmp(library.books[i].author, new_book.author) == 0 &&
            strcmp(library.books[i].genre, new_book.genre) == 0 &&
            library.books[i].year == new_book.year) {
            return true;
        }
    }
    return false;
}