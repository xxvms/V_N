//
// Created by tombr on 02/08/2017.
//

#include "Library.h"

bool Library::avialable(unsigned int book_selection) // done
{
    return shelf_with_books.size() > book_selection and shelf_with_books.at(book_selection) != nullptr;
}
void Library::Reserve(unsigned int size) // done
{
    shelf_with_books.reserve(size);
}
void Library::Add(std::unique_ptr<Book> bk) // done
{
    shelf_with_books.push_back(std::move(bk));
}

std::unique_ptr<Book>Library::Borrow(unsigned int book_selection)
{
    std::unique_ptr<Book>local_copy_book = (std::move(shelf_with_books.at(book_selection)));
    shelf_with_books.erase(shelf_with_books.begin() + book_selection);
    return std::move(local_copy_book);
}
void Library::Return(std::unique_ptr<Book> book)
{
    shelf_with_books.push_back(std::move(book));
}

void Library::Print() const// done
{
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