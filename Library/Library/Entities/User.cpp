#pragma once
#include <iostream>
#include "User.h"
#include <fstream>

String User::normalizeName(String other)
{
    size_t n = other.getSize();
    for (size_t i = 0; i < n; i++)
    {
		if(other[i] == ' ')
        {
			other[i] = '_';
        }
    }
	return other;
}

User::User()
{}


User::User(const String _username, const String _password)
{
    username = _username;
    password = _password;
}


User& User::operator=(const User& other)
{
    if(this != &other)
    {
        username = other.username;
        password = other.password;
    }
    return *this;
}

String User::getUsername() const
{
    return username;
}

String User::getPassword() const
{
    return password;
}


void User::addToFile(const char* fileName)
{
    std::ofstream output(fileName, std::ios::app);
    
    String normalizedName = normalizeName(username);
    output << normalizedName << ' ' << getPassword() << std::endl;
}                                     

std::ostream& operator<<(std::ostream& out, const User& c)
{   
    out << c.getUsername() << ' ' << c.getPassword() << std::endl;
    return out;
}


/*
int main()
{
    //User d;
    //User k("MIMI Slavova", "Poludqvaaa");
    //k.addToFile("..\\Files\\users.mrs");
    //d.addToFile("..\\Files\\users.mrs");
}
*/