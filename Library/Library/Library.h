#pragma once
#include <iostream>
#include "konteineri\Vector.cpp"
#include "konteineri\String.cpp"
#include "Entities\Book.h"
#include "Entities\User.h"
#include "Entities\Book.cpp"
#include "Entities\User.cpp"

class Library
{
    private:
    Vector<Book> books;
    Vector<User> users;
    bool loggedIn;
    bool isAmdminn;

    public:
    Library();
    Library(const Library& other);
    Library& operator=(const Library& other);


    void login();

    void logout();

    void books_all();

    void books_info(size_t id);  //books info <isbn_value>

    void books_find(String word, String keyword);
    void books_sort(String word, String nachin);//books sort <option> [asc | desc]
    void users_add(String name, String password);
    void users_remove(String name);
    void books_add(String _author, String _title, String _genre, String _description, unsi _year, String _keyword, double _rating);
    void books_remove(String name);


    void start();
};
