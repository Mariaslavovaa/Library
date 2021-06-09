#pragma once
#include <cstring>
#include "Library.h"
#include <iostream>
//#include <cstring>
//#include <cassert>
//#include <fstream>
//#include <exception>


String Library::normalizeName(String other)
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

void Library::swap(Book& a, Book& b)
{
    Book temp = a;
    a = b;
    b = temp;
}

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

void Library::print()
{
    std::cout<<"Books\n";
    books.print();
    std::cout << std::endl;

    std::cout<<"Users\n";
    users.print();
    std::cout << std::endl;
}

void Library::login()
{
    char nameFF[32];
    std::cout << "Please, enter username: ";
    std::cin.getline(nameFF, 32);  
    String name(nameFF);

    char passFF[32];
    std::cout << "Please, enter password: ";
    std::cin.getline(passFF, 32);
    String pass(passFF);

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
        else std::cout << "You have entered an incorrect username or password!" << std::endl;
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
        std::cout << "You logged out successfully!" << std::endl;
    }
    else 
    {
        std::cout << "There is no user logged in!" << std:: endl; 
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
        std::cout << "There is no user logged in!" << std:: endl;
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
        std::cout << "There is no user logged in!" << std:: endl;
    }
}

void Library::books_find(String word, String keyword)
{
    if(!loggedIn)
    {
        std::cout << "There is no user logged in!" << std:: endl;
        return;
    }

    String keyW = normalizeName(keyword); //интервалите не знам какво да ги правя // може би ще ги валидирам трябва да измисля как и къде

    size_t n = books.getSize();
    if (word == "title")  
    {
        for (size_t i = 0; i < n; i++)
        {
            if(books[i].getTitle() == keyW)
            {
                books[i].print();
            }
        }
    }
    else if (word == "author") 
    {
        for (size_t i = 0; i < n; i++)
        {
            if(books[i].getAuthor() == keyW)
            {
                books[i].print();
            }
        }
    }
    else if (word == "tag") //ключова дума
    {
        for (size_t i = 0; i < n; i++)
        {
            if(books[i].getKeyword() == keyW)
            {
                books[i].print();
            }
        }
    }
    else
    {
        std::cout << "You have chosen wrong option!" << std::endl; 
        return;
    }
    
}

void Library::books_sort(const char* word, const char* type)
{
    if(!loggedIn)
    {
        std::cout << "There is no user logged in!" << std:: endl;
        return;
    }

    size_t n = books.getSize();
    if (strcmp(word, "title") == 0)
    {
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = i + 1; j < n; j++) 
            {
                if(strcmp(type, "desc") == 0)
                {
                    if(strcmp(books[i].getCharTitle(), books[j].getCharTitle()) < 0)
                    {
                        swap(books[i], books[j]);
                        /*Book temp = books[i];
                        books[i] = books[j];
                        books[j] = temp;*/
                    }
                }
                else
                {
                    if(strcmp(books[i].getCharTitle(), books[j].getCharTitle()) > 0)
                    {
                        swap(books[i], books[j]);
                    }
                }
            }
        }
    }
    else if (word == "author")
    {
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = i + 1; j < n; j++) 
            {
                if(strcmp(type, "desc") == 0)
                {
                    if(strcmp(books[i].getCharAuthor(), books[j].getCharAuthor()) < 0)
                    {
                        swap(books[i], books[j]);
                    }
                }
                else
                {
                    if(strcmp(books[i].getCharAuthor(), books[j].getCharAuthor()) > 0)
                    {
                        swap(books[i], books[j]);
                    }
                }
            }
        }
    }
    else if (word == "year")
    {
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = i + 1; j < n; j++) 
            {
                if(strcmp(type, "desc") == 0)
                {
                    if(books[i].getYear() < books[j].getYear())
                    {
                        swap(books[i], books[j]);
                    }
                }
                else
                {
                    if(books[i].getYear() > books[j].getYear())
                    {
                        swap(books[i], books[j]);
                    }
                }
            }
        }
    }
    else if (word == "rating")
    {
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = i + 1; j < n; j++)
            {
                if(strcmp(type, "desc") == 0)
                {
                    if(books[i].getRating() < books[j].getRating())
                    {
                        swap(books[i], books[j]);
                    }
                }
                else
                {
                    if(books[i].getRating() > books[j].getRating())
                    {
                        swap(books[i], books[j]);
                    }
                }
            }
        }
    }
    else
    {
        std::cout << "You have chosen wrong option!" << std::endl; //не е въведена правилно командата
    }

}

void Library::users_add(String name, String password)
{
    if(!loggedIn)
    {
        std::cout << "There is no user logged in!" << std::endl;
        return; 
    }
    if(!isAmdminn)
    {
        std::cout << "Admin access required!" << std::endl;
        return; 
    }

    size_t n = users.getSize();
    for (size_t i = 0; i < n; i++)
    {
        if(users[i].getUsername() == name)
        {
            std::cout << "There is already user using this nickname!\n" << std::endl;
            return;
        }
    }

    User newUser(name, password);
    users.push_back(newUser);  // Koe??
    newUser.addToFile("Files\\users.mrs");
    std::cout << "User addded successfully!" << std::endl;
}

void Library::users_remove(String name)
{
    if(!loggedIn)
    {
        std::cout << "There is no user logged in!" << std::endl;
        return; 
    }
    if(!isAmdminn)
    {
        std::cout << "Must have admin logged in!" << std::endl;
        return; 
    }

    size_t n = users.getSize();
    for (size_t i = 0; i < n; i++)
    {
        if (users[i].getUsername() == name)
        {
            users.popByIndex(i);
            return;
        }
        /*else
        {
            std::cout << "There is no user with this name!" << std::endl;
            return;
        }*/
    }
}

//std::cout << "Моля въведете заглавие, автор, и т.н.  ... "   Къде да го пиша това
void Library::books_add(String _author, String _title, String _genre, String _description, unsi _year, String _keyword, double _rating)
{
    if(!loggedIn)
    {
        std::cout << "There is no user logged in!" << std::endl;
        return; 
    }
    if(!isAmdminn)
    {
        std::cout << "Must have admin logged in!" << std::endl;
        return; 
    }

    Book newBook( _author, _title, _genre, _description, _year, _keyword, _rating);
    size_t n = books.getSize();
    for (size_t i = 0; i < n; i++)
    {
        if (books[i].getTitle() == newBook.getTitle())   
        {
            std::cout << "A book with that title already exists!" << std::endl;
            return;
        }
    }
    
    books.push_back(newBook);  // Koe??
    newBook.addToFile("Files\\books.mrs");
    std::cout << "Book added successfully!" << std::endl;
}
    
void Library::books_remove(String name)
{
    if(!loggedIn)
    {
        std::cout << "There is no user logged in!" << std::endl;
        return; 
    }
    if(!isAmdminn)
    {
        std::cout << "Must have admin logged in!" << std::endl;
        return; 
    }

    size_t n = books.getSize();
    for (size_t i = 0; i < n; i++)
    {
        if (books[i].getTitle() == name)
        {
            books.popByIndex(i);
            return;  //Изтрих някакъв странен срр файл в който имаше единствено написано popByIndex и беше оцветено в синичко
        }  //Ако няма такава книга в това заглавие какво правя???
        /*else
        {
            std::cout << "There is no book with this title!" << std::endl;
            return;
        }*/
    }
}

void Library::start()
{
    //std::cout << "Hello! Please enter a command!" << std::endl;
    
    
    loggedIn = true;
    isAmdminn = true;
    //do
    //{
        
    //} while ();
    
}


int main()
{
    /*
    Book d21("Peshko", "iznaglqva", "drama", "shte bichi", 2021, "dosta neshta", 5);
    Book d11("Maria", "Izchatka", "pusna mi", "Ne znae kakvo shte pravi", 2021, "nishto", 2.1);
	Book d31("MSS", "nimibi", "drama", "Shte ima 2", 2021, "nishto nishto", 2.0);
	Book d2("Fifi", "iznasq", "film", "ailqk", 2001, "i sq kvo", 3.59);
    Book d("MIMI", "Poludqva", "drama", "Ne znae kakvo shte pravi", 2021, "neshto", 2.4);
	Book d3("MS", "Bibibi", "drama queen", "Ne znae kakvo shte pravi veche", 2021, "neshto nishto", 2.4);
    */
/*
    Vector<Book> books;
    books.push_back(d21);
    books.push_back(d11);
    books.push_back(d31);
    books.push_back(d2);
    books.push_back(d);
*/

    Library b;
    b.start();
    b.books_add("MS", "Bibibi", "drama queen", "Ne znae kakvo shte pravi veche", 2021, "neshto nishto", 2.4);
    b.books_add("Peshko", "iznaglqva", "drama", "shte bichi", 2099, "dosta neshta", 5);
    b.books_add("Maria", "Akcentira", "pusna mi", "Ne znae kakvo shte pravi", 2021, "nishto", 2.1);
    b.books_add("Fifi", "iznasq", "film", "ailqk", 2001, "i sq kvo", 3.59);
    b.books_add("Maria", "Blago", "pusna mi", "Ne znae kakvo shte pravi", 2051, "nishto", 2.1);
    //b.books_find("author", "Peshko");
    //b.users_add("PeshkoBeibe", "neGledai be");
    //b.users_add("MimsiFancy", "qgodi");
    //b.users_add("ToniBonboni", "nemiseSpi");
    //b.books_info(2);

    b.print();
    std::cout << "+------------------------------------------" << std::endl;
    b.books_sort("title", "desc");
    b.print();
    std::cout << " ||||||||||||||||||||||||||||||||||||||||||||" << std::endl;

    b.books_sort("author");
    b.print();
    std::cout << " ||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
    
    b.books_sort("year", "desc");
    b.print();
    std::cout << " ||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
    
    b.books_sort("rating", "asc");
    b.print();
    std::cout << " ||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
    //b.books_all();

    //b.print();
    //std::cout << "------------------------------------------" << std::endl;

    //b.books_remove("Bibibi");
    //b.books_remove("iznasq"); //
    //b.users_remove("PeshkoBeibe");
    //b.users_remove("ToniBonboni"); //

    //b.print();

   return 0;
}
