#pragma once
#include <iostream>
#include "..\konteineri\String.cpp"
#include "User.cpp"  

class User
{
    private:
    String username;
    String password;
    bool isAdmin;
    bool login;

    String normalizeName(String other); //    String normalizeName(const String other); това пишеше преди

    public:
    User();
    User(const String _username, const String _password, bool _isAdmin);     //hmm
    User(const String _username, const String _password);            
    User& operator=(const User& other);
    //    String normalizeName(const String);

    String getUsername() const;
    String getPassword() const;

    void setAdmin(bool _isAdmin);
    bool getIsAdmin() const;
    bool getLogin() const;

    //bool isAdminn(String username, String password);  //да му измисля хубаво име!!!!
    void addToFile(const char*);

    friend std::ostream& operator<<(std::ostream& out, const User& c);

};

