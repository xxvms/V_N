

//
// Created by tombr on 02/08/2017.
//

#ifndef V_N_PERSON_H
#define V_N_PERSON_H

#include "Book.h"
#include <vector>
#include <memory>

class Person
{
private:
    std::vector<std::unique_ptr<Book>> user_books;
public:
    void Borrow(std::unique_ptr<Book> book); // done

    std::unique_ptr<Book> Return(unsigned int book_selection); // done

    void Print() const;// done
};


#endif //V_N_PERSON_H
