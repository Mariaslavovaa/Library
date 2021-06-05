#pragma once
#include "Library.h"
#include <iostream>
//#include <cstring>
//#include <cassert>
//#include <fstream>
//#include <exception>
//#include "..\Entities\User.cpp"

Library::Library() 
{
    User c("admin", "i<3c++"); // dali stava taka?? 
    loggedIn = false;
    isAmdminn = true;
}

Library::Library(const Library& other)  // Не мисля че ми трябват
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
    char name[32];
    std::cout << "Please, enter username: ";
    std::cin.getline(name, 32);  
    String name = String(name);

    char pass[32];
    std::cout << "Please, enter password: ";
    std::cin.getline(pass, 32);
    String pass = String(pass);

    if(name == "admin" && pass == "i<3c++")  
    {
        isAmdminn = true;
    }
    else isAmdminn = false;

    size_t n = users.getSize();
    for (size_t i = 0; i < n; i++)
    {
        if (users[i].getUsername() == name && users[i].getPassword() == pass)
        {
            std::cout << "Welcome, " << name << "!" << std::endl;
            loggedIn = true;
        }
        else std::cout << " You have entered an incorrect username or password! " << std::endl;
    }
        //При повторен опит за login, се изкарва съобщение “You are already logged in.”
        // КАК И КЪДЕ ТРЯБВА ДА ГО НАПИША???
    
}

void Library::logout()
{
    if(loggedIn)
    {
        loggedIn = false;
        isAmdminn = false;
        std::cout << " You logged out successfully! " << std::endl;
    }
    else 
    {
        std::cout << " There is no user logged in! " << std:: endl; 
    }
}

void Library::books_all()
{
    if(loggedIn)
    {
        size_t n = books.getSize();
        for (size_t i = 0; i < n; i++)
        {
            books[i].printAllBooks();
        }
    }
    else
    {
        std::cout << " There is no user logged in! " << std:: endl;
    }
}

void Library::books_info(size_t id)
{
    if(loggedIn)
    {
        size_t n = books.getSize();
        for (size_t i = 0; i < n; i++)
        {
            if(books[i].getId() == id)
            {
                books[i].print();
            }
        }
    }
    else
    {
        std::cout << " There is no user logged in! " << std:: endl;
    }
}

void Library::books_find(String word, String keyword)
{
    if(!loggedIn)
    {
        std::cout << " There is no user logged in! " << std:: endl;
        return;
    }

    size_t n = books.getSize();
    //validateBooksFindWord(word)!!!!!!!!
    if (word == "title")  //интервалите не знам какво да ги правя // може би ще ги валидирам трябва да измисля как и къде
    {
        for (size_t i = 0; i < n; i++)
        {
            if(books[i].getTitle() == keyword)
            {
                books[i].print();
            }
        }
    }
    else if (word == "author") //интервалите не знам какво да ги правя
    {
        for (size_t i = 0; i < n; i++)
        {
            if(books[i].getAuthor() == keyword)
            {
                books[i].print();
            }
        }
    }
    else if (word == "tag") //ключова дума
    {
        for (size_t i = 0; i < n; i++)
        {
            if(books[i].getKeyword() == keyword)
            {
                books[i].print();
            }
        }
    }
    else
    {
        std::cout << "Думата не е правилна" << std::endl; // Да измисля правилно съобщение
    }
    
}

void Library::books_sort(String word, String nachin)
{
    if (word == "title")
    {
        //сортирането!!!!
    }
    else if (word == "author")
    {

    }
    else if (word == "year")
    {

    }
    else if (word == "rating")
    {

    }
    else
    {

    }
}
// За сортирането
/*
    void sort(std::vector<Vehicle*> vehicles)
    {
        for (size_t i = 0; i < vehicles.size(); i++)
        {
            for (size_t j = 0; j < vehicles.size(); j++)
            {
                if (vehicles[i]->getPrice() < vehicles[j]->getPrice())
                {
                    Vehicle* temp = vehicles[i];
                    vehicles[i] = vehicles[j];
                    vehicles[j] = temp;
                }
            
            }
        }

        for (size_t k = 0; k < vehicles.size(); k++)
        {
            vehicles[k]->print();
        }
    
    }


int n = tempBooks.size();
	if (strcmp(option, "title") == 0)      // sortira se po title
    { 
		if (strcmp(order, "asc") == 0)     // v narastvasht red
        { 
			for (int i = 0; i < n; i++) 
            {
				String firstBookTitle = tempBooks[i].getTitle();
				for (int j = i + 1; j < n; j++) 
                {
					String secondBookTitle = tempBooks[j].getTitle();
					int k = 0;
					while (firstBookTitle[k] && secondBookTitle[k]) 
                    {
						if (firstBookTitle[k] > secondBookTitle[k]) 
                        {
							Book tempBook = tempBooks[i];
							tempBooks[i] = tempBooks[j];
							tempBooks[j] = tempBook;
							break;
						}
						else if (firstBookTitle[k] < secondBookTitle[k]) break;
						k++;
					}
				}
			}
		}
*/

void Library::users_add(String name, String password)
{
    if(!loggedIn)
    {
        std::cout << " There is no user logged in! " << std::endl;
        return; // moje bi??
    }
    if(!isAmdminn)
    {
        std::cout << " Must have admin logged in! " << std::endl;
        return; // moje bi??
    }

    size_t n = users.getSize();
    for (size_t i = 0; i < n; i++)
    {
        if(users[i].getUsername() == name)
        {
            std::cout << " Вече има потребител с това име. Моля въведете ново име! " << std::endl;
            //break;   //return //????
        }
    }

    User newUser(name, password);
    //users.push_back(newUser);  // Koe??
    newUser.addToFile("users.mrs");
    std::cout << "User addded successfully!" << std::endl;
}

void Library::users_remove(String name)
{
    if(!loggedIn)
    {
        std::cout << " There is no user logged in! " << std::endl;
        return; // moje bi??
    }
    if(!isAmdminn)
    {
        std::cout << " Must have admin logged in! " << std::endl;
        return; // moje bi??
    }

    size_t n = users.getSize();
    for (size_t i = 0; i < n; i++)
    {
        if (users[i].getUsername() == name)
        {
            users.popByIndex(i);
            break; // moje bi
        }
    }
}


//std::cout << "Моля въведете заглавие, автор, и т.н.  ... "   Къде да го пиша това
void Library::books_add(String _author, String _title, String _genre, String _description, unsi _year, String _keyword, double _rating)
{
    if(!loggedIn)
    {
        std::cout << " There is no user logged in! " << std::endl;
        return; // moje bi??
    }
    if(!isAmdminn)
    {
        std::cout << " Must have admin logged in! " << std::endl;
        return; // moje bi??
    }

    Book newBook( _author, _title, _genre, _description, _year, _keyword, _rating);
    size_t n = books.getSize();
    for (size_t i = 0; i < n; i++)
    {
        if (books[i].getTitle() == newBook.getTitle())   
        {
            std::cout << " A book with that title already exists! " << std::endl;
            return; //trqbva li??
        }
    }
    
    books.push_back(newBook);  // Koe??
    newBook.addToFile("books.mrs");
    std::cout << "Book added successfully!" << std::endl;
}
    
void Library::books_remove(String name)
{
    if(!loggedIn)
    {
        std::cout << " There is no user logged in! " << std::endl;
        return; // moje bi??
    }
    if(!isAmdminn)
    {
        std::cout << " Must have admin logged in! " << std::endl;
        return; // moje bi??
    }

    size_t n = books.getSize();
    for (size_t i = 0; i < n; i++)
    {
        if (books[i].getTitle() == name)
        {
            books.popByIndex(i);
            break; // moje bi
        }
    }
}

int main()
{
    Book d21("Peshko", "iznaglqva", "drama", "shte bichi", 2021, "dosta neshta", 5);
    Book d11("Maria", "Izchatka", "pusna mi", "Ne znae kakvo shte pravi", 2021, "nishto", 2.1);
	Book d31("MSS", "nimibi", "drama", "Shte ima 2", 2021, "nishto nishto", 2.0);
	Book d2("Fifi", "iznasq", "film", "ailqk", 2001, "i sq kvo", 3.59);
    Book d("MIMI", "Poludqva", "drama", "Ne znae kakvo shte pravi", 2021, "neshto", 2.4);
	Book d3("MS", "Bibibi", "drama queen", "Ne znae kakvo shte pravi veche", 2021, "neshto nishto", 2.4);
/*
    Vector<Book> books;
    books.push_back(d21);
    books.push_back(d11);
    books.push_back(d31);
    books.push_back(d2);
    books.push_back(d);
*/
    Library b;
    b.books_add("MS", "Bibibi", "drama queen", "Ne znae kakvo shte pravi veche", 2021, "neshto nishto", 2.4);
    b.books_add("Peshko", "iznaglqva", "drama", "shte bichi", 2021, "dosta neshta", 5);
    //b.books_add("Maria", "Izchatka", "pusna mi", "Ne znae kakvo shte pravi", 2021, "nishto", 2.1);
    //b.books_add("Fifi", "iznasq", "film", "ailqk", 2001, "i sq kvo", 3.59);

    std::cout << b << std::endl;

    return 0;
}


/*
void Library::start()
{
    std::cout << "Hello! Please enter a command!" << std::endl;
    
    //do
    //{
        
    //} while ();
    
}
*/
