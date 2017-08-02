//
// Created by tombr on 01/08/2017.
//

#ifndef V_N_BOOK_H
#define V_N_BOOK_H

#include <iostream>
#include <string>


class Book
{
private:
    std::string title;
    std::string author;
    int publication_year;
public:
    Book(std::string title, std::string author, int publication_year) : title(title), author(author), publication_year(publication_year)
    {}
    void  printB()const;
};

#endif //V_N_BOOK_H
