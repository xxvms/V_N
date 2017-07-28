#include <iostream>
#include <string>
#include <vector>
#include <memory>
//#include <experimental/string_view>

class Book
{
private:
    std::string title;
    std::string author;
    int publication_year;
public:
    //Book(std::experimental::string_view title, std::experimental::string_view author, int publication_year) : title(title), author(author), publication_year(publication_year)
    //{}
    Book(std::string title, std::string author, int publication_year) : title(title), author(author), publication_year(publication_year)
    {}

    void const printB() {
        std::cout << "Title: " << title << '\n';
        std::cout << "Author: " << author << '\n';
        std::cout << "Publication Year: " << publication_year << '\n';
    }
};
class Library
{
private:
    std::vector<std::unique_ptr<Book>> shelf_with_books;
public:
    void Reserve(unsigned int size) // done
    {
        shelf_with_books.reserve(size);
    }
    void Add(std::unique_ptr<Book> bk) // done
    {
        shelf_with_books.push_back(std::move(bk));
    }
   std::unique_ptr<Book> Borrow(unsigned int book_selection)
    {
        return std::move(shelf_with_books.at(book_selection));
    }
    void Return()
    {

    }
    void const Print() // done
    {
        std::cout << "Capacity: " << shelf_with_books.capacity() << " size: " << shelf_with_books.size() << '\n';
        unsigned int i = 0;
        for (auto &shelf_with_book : shelf_with_books) {
            std::cout << '\n';
            if (shelf_with_book != nullptr)
            {
                std::cout << "Book ID: " << i << '\n';
                shelf_with_book->printB();
                i++;
            } else {
                std::cout << "Book ID: " << i << '\n';
                std::cout << "Book is borrowed \n";
                i++;
            }
            std::cout << "-----------------" << '\n';
        }
    }
};
class Person
{
private:
    std::vector<std::unique_ptr<Book>> user_books;
public:
   /* void Reserve(unsigned int size, std::unique_ptr<Book> bk) // not sure if I will need this at all
    {
        user_books.reserve(size);
        user_books.push_back(std::move(bk));
    }*/
    void Borrow(std::unique_ptr<Book> book)
    {
        user_books.push_back(std::move(book));
    }
    void Return()
    {

    }
    void const Print() // done
    {
        std::cout << "Capacity: " << user_books.capacity() << " size: " << user_books.size() << '\n';
        unsigned int i = 0;
        for (auto &user_book : user_books) {
            if (user_book != nullptr)
            {
                std::cout << '\n';
                std::cout << "Book ID: " << i << '\n';
                user_book->printB();
                i++;
                std::cout << "-----------------" << '\n';
            } else{
                std::cout << "User don't have any books! \n";
                std::cout << "Go get some :) \n";
            }
        }
    }
};

char menu();

int main() {
    Library lib;
    Person person;

    do {
        switch (menu()) {
            case '1': {
                std::cout << "Max amount books in Library: ";
                unsigned int librarySize = 0;
                std::cin >> librarySize;
                lib.Reserve(librarySize);
                std::cout << '\n';
                std::system("clear");
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
                    std::cout << "Author: ";
                    std::cin >> author;
                    std::cout << "Title: ";
                    std::cin >> title;
                    std::cout << "Publication year: ";
                    std::cin >> publication_year;
                    std::unique_ptr<Book> book_ptr = std::make_unique<Book>(title, author, publication_year);
                    lib.Add(std::move(book_ptr));
                    std::cout << '\n';
                }
                break;
            }
            case '3': {
                std::cout << "Please select book to borrow: ";
                lib.Print();
                unsigned int book_selection = 0;
                std::cin >> book_selection;
                std::unique_ptr<Book> borrow_book_ptr = lib.Borrow(book_selection);
                person.Borrow(std::move(borrow_book_ptr));
                break;
            }
            case '5': {
                std::cout << "Printing books in Library\n";
                lib.Print();
                break;
            }
            case '6': {
                person.Print();
                break;
            }
            default:
            {
                std::cout << "so good its Friday :)  \n";
            }


        }
    } while (menu() != '9');


    return 0;
}

char menu() {
    char choice{' '};
    std::cout << "Please make your selection\n";
    std::cout << "Press number: \n";
    std::cout << "1 - Set size of the Library\n";
    std::cout << "2 - Create book\n";
    std::cout << "3 - Borrow book\n";
    std::cout << "4 - Return book\n";
    std::cout << "5 - Print out all books\n";
    std::cout << "6 - Print books borrowed by user\n";
   // std::cout << "7 - Print books borrowed by Librarian\n";
    std::cout << "9 - to Quit\n";
    std::cin >> choice;

    return choice;
}