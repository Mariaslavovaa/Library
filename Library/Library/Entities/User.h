#pragma once
#include <iostream>
#include "..\containers\String.cpp"
#include "User.cpp"  

class User
{
    private:
    String username;
    String password;

    String normalizeName(String other); 

    public:
    User();

    User(const String _username, const String _password);            
    User& operator=(const User& other);

    String getUsername() const;
    String getPassword() const;

    void addToFile(const char*);

    friend std::ostream& operator<<(std::ostream& out, const User& c);
};

