#pragma once
#include <iostream>
#include "..\containers\String.cpp"
#include "..\containers\Vector.cpp"
#include "Book.cpp"

using unsi = unsigned short int;

class Book
{
    private:
    String author;
    String title;
    String genre;
    String description;
    unsi year;
    String keyword;
    double rating;
    unsi unique;

    void copy(const Book& other);
    String normalizeName(String other);  //    String normalizeName(const String other);  това пишеше преди

    public:

    static unsi Id;  //уникален номер за библиотеката

    Book();
    Book(const String _author, const String _title, const String _genre, const String _description, 
         const unsi _year, const String _keyword, const double _rating);
    Book(const Book& other);
    Book& operator=(const Book& other);

    String getAuthor() const;
    char* getCharAuthor() const;
    
    String getTitle() const;
    char* getCharTitle() const;

    String getGenre() const;
    String getDescription() const;
    unsi getYear() const;
    String getKeyword() const;
    double getRating() const;
    unsi getId() const;  

    void print() const;
    void printAllBooks() const;
    void addToFile(const char* fileName);
    void load(const char* fileName);

    friend std::ostream& operator<<(std::ostream& out, const Book& b);
    friend std::istream& operator>>(std::istream& in, Book& book);
};

unsi Book::Id = 0;



