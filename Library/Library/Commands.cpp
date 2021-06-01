#include <iostream>

//open

//close 

//save

//save as

//help
void help()
{
    std::cout << " The following commands are supported: " << std::endl;
    std::cout << " ---------------------------------------------------- " << std::endl;
    std::cout << " open <file>         opens <file>" << std::endl;
    std::cout << " close               closes currently opened file " << std::endl;
    std::cout << " save                saves the currently open file " << std::endl;
    std::cout << " saveas <file>       saves the currently open file in <file> " << std::endl;
    std::cout << " help                prints this information " << std::endl;
    std::cout << " exit                exists the program " << std::endl;   
    std::cout << " ---------------------------------------------------- " << std::endl;
    std::cout << " login                                     " << std::endl;
    std::cout << " logout                                    " << std::endl;
    std::cout << " books all                                 " << std::endl;
    std::cout << " books info <isbn_value>                   " << std::endl;
    std::cout << " books find <option> <option_string>       " << std::endl;
    std::cout << " books sort <option> [asc | desc]          " << std::endl; 
    std::cout << " books add                                 " << std::endl;
    std::cout << " books remove                              " << std::endl; 
    std::cout << " users add <user> <password>               " << std::endl;
    std::cout << " users remove                              " << std::endl;
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
    exit(0);
}
