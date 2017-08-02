#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Book.h"
#include "Library.h"
#include "Person.h"



char menu();

int main() {
    Library lib;
    Person person;
    bool shouldExit = true;
    do {
        switch (menu()) {
            case '1': {
                std::system("clear");
                std::cout << "Max amount books in Library: ";
                unsigned int librarySize = 0;
                std::cin >> librarySize;
                lib.Reserve(librarySize);
                std::cout << '\n';
                std::cout << "library can store " << librarySize << " books\n";
                std::cout << '\n';
                break;
            }
            case '2': {
                std::cout << "How many books do you want to add? ";
                unsigned int number_of_books = 0;
                std::cin >> number_of_books;
                for (size_t i = 0; i != number_of_books; i++) {
                    std::string author, title;
                    int publication_year = 0;
                    std::cout << "ID " << i << '\n';
                    std::cout << "Title: ";
                    std::cin >> title;
                    std::cout << "Author: ";
                    std::cin >> author;
                    std::cout << "Publication year: ";
                    std::cin >> publication_year;
                    std::unique_ptr<Book> book_ptr = std::make_unique<Book>(title, author, publication_year);
                    lib.Add(std::move(book_ptr));
                    std::cout << '\n';
                }
                std::system("clear");
                break;
            }
            case '3': {
                std::cout << "Please select book to borrow: \n";
                lib.Print();
                unsigned int book_selection = 0;
                std::cin >> book_selection;
                std::system("clear");
                if (lib.avialable(book_selection))
                {
                    std::unique_ptr<Book> borrow_book_ptr = lib.Borrow(book_selection);
                    person.Borrow(std::move(borrow_book_ptr));
                    }else{
                   std::cout << "This book is already borrowed!\n";
                }
                break;
            }
            case '4': {
                std::cout << "Please select book to return: ";
                person.Print();
                unsigned int book_selection = 0;
                std::cin >> book_selection;
                std::unique_ptr<Book>return_book_ptr = person.Return(book_selection);
                lib.Return(std::move(return_book_ptr));
                std::system("clear");
                break;
            }
            case '5': {
                std::system("clear");
                std::cout << "Printing books in Library\n";
                lib.Print();
                break;
            }
            case '6': {
                std::system("clear");
                person.Print();
                break;
            }
            case '9': {
                shouldExit = false;
                break;
            }
            default:
            {
                std::system("clear");
                std::cout << "so good its Friday :)  \n";
            }
        }
    } while (shouldExit);
    return 0;
}

char menu() {
    char choice {' '};
    std::cout << "Please make your selection\n";
    std::cout << "Press number: \n";
    std::cout << "1 - Set size of the Library\n";
    std::cout << "2 - Create book\n";
    std::cout << "3 - Borrow book\n";
    std::cout << "4 - Return book\n";
    std::cout << "5 - Print out all books\n";
    std::cout << "6 - Print books borrowed by user\n";
    std::cout << "9 - to Quit\n";
    std::cin >> choice;

    return choice;
}