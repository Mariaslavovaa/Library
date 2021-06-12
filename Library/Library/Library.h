#pragma once
#include <iostream>
#include "containers\Vector.cpp"
#include "containers\String.cpp"
#include "Entities\Book.cpp"
#include "Entities\User.cpp"

class Library
{
    private:
    char fileName[60] = {'\0'};
    Vector<Book> books;
    Vector<User> users;
    bool openedFile = false;
    bool loggedIn;
    bool isAmdminn;

    String normalizeName(String other);
    void swap(Book& a, Book& b);

    public:
    void open();
    void run();
    Library();
    Library(const Library& other);
    Library& operator=(const Library& other);

    void print() const; 

    void login();
    void logout();

    void books_all();
    void books_info(size_t id); 
    void books_find(String word, String keyword);
    void books_sort(const char* word, const char* type = "asc");

    void users_add(String name, String password);
    void users_remove(String name);
    void books_add(String _author, String _title, String _genre, String _description, unsi _year, String _keyword, double _rating);
    void books_remove(String name);

};
