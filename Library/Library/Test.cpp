#pragma once
#include "Library.cpp"

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

TEST_CASE("Test Book")
{
    Book b("MIMI", "Poludqva", "drama", "Ne znae kakvo shte pravi", 2021, "neshto", 2.4);
    CHECK(b.getAuthor() == "MIMI"); //
    CHECK(b.getYear() == 2021);
    CHECK(b.getRating() == 2.4);
    CHECK(b.getId() == 0); //
}

TEST_CASE("Test User")
{
    User r("admin", "i<3c++");
    CHECK(r.getUsername() == "admin");
    CHECK(r.getPassword() == "i<3c++");   
}

TEST_CASE("Test Library")
{

}

TEST_CASE("Test String")
{
    String str;
    str = "Hello";
    CHECK(str.getSize() == 5);
    CHECK(str.getCapacity() == 8);

    String str1;
    str1 = "Hello";
    CHECK(str == str1);
    CHECK(str1[0] == 'H');
    str1.push_back("Mimi");
    CHECK(str1.getSize() == 9);
}

TEST_CASE("Test Vector")
{
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    CHECK(v.getSize() == 4);
    CHECK(v.getCapacity() == 8);
    CHECK(v[1] == 2);

    v.popByIndex(0);
    v.popByIndex(2);

    CHECK(v.getSize() == 2);
    CHECK(v[1] == 4);

    v.push_back(1);
    v.push_back(6);
    v.push_back(5);
    v.push_back(8);
    v.push_back(0);
    v.push_back(2);
    v.push_back(9);
    v.push_back(4);

    CHECK(v.getCapacity() == 8);
}