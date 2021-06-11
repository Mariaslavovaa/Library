#include <iostream>

class Command
{
    public:
    void help()
    {
        std::cout << " The following commands are supported: " << std::endl;
        std::cout << " ---------------------------------------------------- " << std::endl;
        std::cout << " open <file>                             opens <file>" << std::endl;
        std::cout << " close                                   closes currently opened file " << std::endl;
        std::cout << " save                                    saves the currently open file " << std::endl;
        std::cout << " saveas <file>                           saves the currently open file in <file> " << std::endl;
        std::cout << " help                                    prints this information " << std::endl;
        std::cout << " exit                                    exists the program " << std::endl;   
        std::cout << " ---------------------------------------------------- " << std::endl;
        std::cout << " login                                   log in as an existing user" << std::endl;
        std::cout << " logout                                  logs out" << std::endl;
        std::cout << " books all                               prints short information about all books" << std::endl;
        std::cout << " books info <isbn_value>                 prints detailed information about the book with unique number <isbn_value>" << std::endl;
        std::cout << " books find <option> <option_string>     prints a book searched by <option> (title, author, tag) and <option_str>" << std::endl;
        std::cout << " books sort <option> [asc | desc]        sorts the books by <option> (title, author, year, rating)" << std::endl; 
        std::cout << " books add                               adds a new book to the library " << std::endl;
        std::cout << " books remove <title>                    removes a book from the library with name <title>" << std::endl; 
        std::cout << " users add <user> <password>             add a new user with name <user> and password <password>  " << std::endl;
        std::cout << " users remove <user>                     deletes user with name <user>  " << std::endl;
    }

    /*
    books view  == books info
    books add  //
    books remove //
    */


    //exit
    void exit()  // 
    {
        //system("cls");
    	//std::cout << "THANK YOU! BBYE" << std::endl;
    	//exit(1);
        std::cout << " Thank you! You left the program." << std::endl;
        //exit(0);
    }

};