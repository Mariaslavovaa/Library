#pragma once
#include <iostream>
#include "User.h"
#include <fstream>

String User::normalizeName(String other)
{
    for (size_t i = 0; i < other.getSize(); i++)
    {
		if(other[i] == ' ')
        {
			other[i] = '_';
        }
    }
	return other;
}

User::User()
{
    isAdmin = false;
}

User::User(const String _username, const String _password, bool _isAdmin) //Трябва ли ми изобщо
{
    username = _username;
    password = _password;
    isAdmin = _isAdmin;
}


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
        isAdmin = other.isAdmin;
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

void User::setAdmin(bool _isAdmin)  // const bool _isAdmin??
{
    isAdmin = _isAdmin;
}

bool User::getIsAdmin() const
{
    return isAdmin;
}

bool User::getLogin() const
{
    return login;
}

/*
bool User::isAdminn(String username, String password)
{
    if(username == "admin" && password == "i<3c++")
    {
        isAdmin = true;
        return isAdmin;
        //return true;
    }
    return isAdmin;
}
*/


void User::addToFile(const char* fileName)
{
    std::ofstream output(fileName, std::ios::app);
    
    String normalizedName = normalizeName(username);
    output << normalizedName << ' ' << getPassword() << std::endl;
    //output << normalizedName << ' ' << getPassword() << ' ' << std::boolalpha << isAdmin << std::endl;  
                                      //output << username << ' ' << password << std::endl;
}                                     // не трябва ли някъде да записвам паролите??????? 

std::ostream& operator<<(std::ostream& out, const User& c)
{   

    out << c.getUsername() << ' ' << c.getPassword() << std::boolalpha << c.getIsAdmin() << std::endl;
    //out << c.getUsername() << ' ' << c.getPassword() << std::endl;
    //out << c.getUsername() << ' ' << std::boolalpha << c.getIsAdmin() << std::endl;
    return out;
}

void users_add(String username, String password)
{
    //login

    /* if(getIsAdmin() == false)
    {
        std::cout << " трябва да има влезнал потребител " << std::endl;
    }
    */
    //admin

    
}

/*
int main()
{
    //User d;
    User k("MIMI Slavova", "Poludqvaaa", 1);
    k.addToFile("users.mrs");
    //d.addToFile("users.mrs");
}
*/