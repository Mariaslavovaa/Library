#pragma once
#include <iostream>
#include "..\konteineri\String.cpp"
#include "..\konteineri\Vector.cpp"
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

    void copy(const Book& other);
    String normalizeName(String other);  //    String normalizeName(const String other);  това пишеше преди

    public:

    static unsi uniqueNum;  //уникален номер за библиотеката

    Book();
    Book(const String _author, const String _title, const String _genre, const String _description, 
         const unsi _year, const String _keyword, const double _rating);
    Book(const Book& other);
    Book& operator=(const Book& other);

    String getAuthor() const;
    String getTitle() const;
    String getGenre() const;
    String getDescription() const;
    unsi getYear() const;
    String getKeyword() const;
    double getRating() const;
    unsi getUniqueNumber() const;  // май е ненужен, защото uniqueNum е public????????????//

    void print() const;
    void addToFile(const char* fileName);
    void load(const char* fileName);

    friend std::ostream& operator<<(std::ostream& out, const Book& b);
    friend std::istream& operator>>(std::istream& in, Book& book);
};

unsi Book::uniqueNum = 0;



