#pragma once
#include "Library.h"
#include <iostream>
//#include <cstring>
//#include <cassert>
//#include <fstream>
//#include <exception>
#include "..\Entities\User.cpp"

Library::Library() {}

Library::Library(const Library& other)
{
    books = other.books;
    users = other.users;
}

Library& Library::operator=(const Library& other)
{
    if(this != &other)
    {
        books = other.books;
        users = other.users;
    }
    return *this;
}


void Library::login()
{
    /*
    char* arr = new char[32];
    std::cout << "Please, enter username: ";
    std::cin.getline(arr, 32);
    String name = String(arr);
    */

    char* arr = new char[32];

    std::cout << "Please, enter username: ";
    std::cin.getline(arr, 32);  
    String name = String(arr);
    //Как да го сетна???


    std::cout << "Please, enter password: ";
    std::cin.getline(arr, 32);
    String pass = String(arr);
    //Как да го сетна???

    /*if (!isAdminn(name, pass))
    {
        return;
    }
    */

/*
    //std::cout << name << '\n';
    //std::cout << password;

    String name;
    std::cout << "Please, enter username: ";
    getline(std::cin, name);
*/

}

void Library::logout()
{
    // admin = false;

    //bool a = false;
    //setAdmin(false);
    
    // login = false;
}

void Library::start()
{
    std::cout << "Hello! Please enter a command!" << std::endl;
    /*
    do
    {
        
    } while ();
    */
}