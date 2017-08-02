//
// Created by tombr on 02/08/2017.
//

#ifndef V_N_LIBRARY_H
#define V_N_LIBRARY_H

#include "Book.h"
#include <vector>
#include <memory>

class Library
{
private:
    std::vector<std::unique_ptr<Book>> shelf_with_books;
public:
    bool avialable(unsigned int book_selection); // done

    void Reserve(unsigned int size); // done

    void Add(std::unique_ptr<Book> bk); // done

    std::unique_ptr<Book> Borrow(unsigned int book_selection); //done

    void Return(std::unique_ptr<Book> book); // done

    void Print() const;// done
};

#endif //V_N_LIBRARY_H
