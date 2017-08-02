//
// Created by tombr on 02/08/2017.
//

#include "Person.h"
//
// Created by tombr on 02/08/2017.
//

#include "Person.h"

void Person::Borrow(std::unique_ptr<Book> book)
{
    user_books.push_back(std::move(book));
}
std::unique_ptr<Book> Person::Return(unsigned int book_selection)
{
    std::unique_ptr<Book> local_copy_book = std::move(user_books.at(book_selection));
    user_books.erase(user_books.begin()+ book_selection);
    return std::move(local_copy_book);
}
void Person::Print() const// done
{
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
            i++;
        }
    }
}