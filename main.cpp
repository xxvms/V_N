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
    // please add ID
public:
    //Book(std::experimental::string_view title, std::experimental::string_view author, int publication_year) : title(title), author(author), publication_year(publication_year)
    //{}
    Book(std::string title, std::string author, int publication_year) : title(title), author(author), publication_year(publication_year)
    {}
    /*std::ostream & operator << (std::ostream & os, const Book & b) {
        return os << b.publication_year << b.title << b.author;
    }*/

    void create()
    {

    }
    void printB() {
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
    void Reserve_space()
    {

    }
    void Add()
    {

    }
    void Borrow()
    {

    }
    void Return()
    {

    }
    void Print()
    {
        for (auto &shelf_with_book : shelf_with_books) {
            shelf_with_book->printB();
        }
    }
};
class Person
{
private:
    std::vector<std::unique_ptr<Book>> user_books;
public:
    void Borrow()
    {

    }
    void Return()
    {

    }
    void Print()
    {

    }
};

int main() {
    std::vector<std::unique_ptr<Book>> library;

    library.push_back(std::make_unique<Book>("title", "author", 1111));





    return 0;
}