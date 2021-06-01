#pragma once
#include <iostream>
#include "..\konteineri\Vector.cpp"
#include "..\Entities\Book.h"
#include "..\Entities\User.h"
#include "..\Entities\Book.cpp"
#include "..\Entities\User.cpp"

class Library
{
    private:
    Vector<Book> books;
    Vector<User> users;

    public:
    Library();
    Library(const Library& other);
    Library& operator=(const Library& other);


    void login();
    void logout();

    void start();
};
