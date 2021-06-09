#pragma once
#include <iostream>
#include "containers\Vector.cpp"
#include "containers\String.cpp"
//#include "Entities\Book.cpp"
#include "Entities\User.cpp"
#include <cstring>


class StartUp
{
    private:
    Vector<User> users;
    bool isOpened;
    public:

    //loggedIn = true;
    //isAmdminn = true;

    void start()
    {
        User b("admin", "i<3c++");
        users.push_back(b);

        std::cout << "Hello! Please enter a command!" << std::endl;
        String como;
        char* command;
        do
        {
            /*
            if (strcmp(command, "open")
            {
                
            }
            else if (strcmp(command, "close")
            {

            }
            else
            {

            }
            */
        
        } while (strcmp(command, "exit") ); // command != "exit"
    }
}; 


/*
int main()
{

    return 0;
}
*/