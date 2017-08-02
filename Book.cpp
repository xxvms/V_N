//
// Created by tombr on 01/08/2017.
//

#include "Book.h"

void  Book::printB()const {
    std::cout << "Title: " << title << '\n';
    std::cout << "Author: " << author << '\n';
    std::cout << "Publication Year: " << publication_year << '\n';
}