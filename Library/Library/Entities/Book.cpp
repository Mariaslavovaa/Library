#pragma once
#include "Book.h"
#include <iostream>
#include <fstream>

void Book::copy(const Book& other)
{
	author = other.author;
	title = other.title;
	genre = other.genre;
	description = other.description;
	year = other.year;
	keyword = other.keyword;
	rating = other.rating;
	//uniqueNum = other.uniqueNum;   // Не съм сигурна дали трябва да го има
}

String Book::normalizeName(String other)
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

Book::Book()
{
	year = 0;
	rating = 0;
}

/*
Book::Book(const String _author, const String _title, const String _genre, const String _description, 
const unsi _year, const String _keyword, const double _rating, const unsi _uniqueNumber)
{
	author = _author;
	title = _title;
	genre = _genre;
	description = _description;
	year = _year;
	keyword = _keyword;
	rating = _rating;
	uniqueNumber = _uniqueNumber;
}
*/
//------- Не знам уникалния номер как да го направя / май нещо със статик променлива??? 

Book::Book(const String _author, const String _title, const String _genre, const String _description, 
const unsi _year, const String _keyword, const double _rating)
{
	author = _author;
	title = _title;
	genre = _genre;
	description = _description;
	year = _year;
	keyword = _keyword;
	rating = _rating;

	//uniqueNum++;
}


Book::Book(const Book& other)
{
	copy(other);
}


Book& Book::operator=(const Book& other)
{
	if (this != &other)
	{
		copy(other);
	}
	return *this;
}

String Book::getAuthor() const
{
	return author;
}
String Book::getTitle() const
{
	return title;
}
String Book::getGenre() const
{
	return genre;
}
String Book::getDescription() const
{
	return description;
}
unsi Book::getYear() const
{
	return year;
}
String Book::getKeyword() const
{
	return keyword;
}
double Book::getRating() const
{
	return rating;
}

unsi Book::getUniqueNumber() const  // ------  ??????????
{
	return uniqueNum;
}

void Book::print() const{
	std::cout << author << std::endl;
	std::cout << title << std::endl;
	std::cout << genre << std::endl;
	std::cout << description << std::endl;
	std::cout << year << std::endl;
	std::cout << keyword << std::endl;
	std::cout << rating << std::endl;
	std::cout << uniqueNum << std::endl;
	std::cout << std::endl;
}

void Book::addToFile(const char* fileName)
{
	std::ofstream output(fileName, std::ios::app);
	String normalizedName = normalizeName(author);
	String normalizedTitle = normalizeName(title);
	String normalizedGenre = normalizeName(genre);
	String normalizedDescr = normalizeName(description);
	String normalizedKw = normalizeName(keyword);

	uniqueNum++; // ------- ?????

	output << uniqueNum  << ' ' << normalizedName << ' ' << normalizedTitle << ' ' << normalizedGenre 
	<< ' ' << normalizedDescr << ' ' << year << ' ' << normalizedKw << ' ' << rating << std::endl;
	output.close();

}

std::ostream& operator<<(std::ostream& out, const Book& b)
{   
    out << b.author << ' ' << b.title << ' ' << b.genre << ' ' << b.description << ' ' 
	<< b.year << ' ' << b.keyword << ' ' << b.rating << ' ' << b.uniqueNum << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Book& book) {
	std::cout << "Author: ";
	in >> book.author;
	std::cout << "Title: ";
	in >> book.title;
	std::cout << "genre: ";
	in >> book.genre;
	std::cout << "description: ";
	in >> book.description;
	std::cout << "date of release: ";
	in >> book.year;
	std::cout << "tags: ";
	in >> book.keyword;
	std::cout << "rating: ";
	in >> book.rating;
	std::cout << "serial number: ";
	in >> book.uniqueNum;
	return in;
}

void Book::load(const char* fileName) {
	//std::ifstream input(fileName, std::ios::app);
	std::ifstream input(fileName);
	//std::ifstream& iFile
	//iFile >> *this;

	Vector<Book> books;

	while(!input.eof())
	{
	input >> uniqueNum >> author >> title >> genre >> description >> year >> keyword >> rating;
	Book b(author, title, genre, description, year, keyword, rating);
	//input >> *this;
	books.push_back(b);
	books.print();
	}
	input.close();
}
/*
void books_add()
{
	
}*/

/*
void updateFile(Book &p)
{
    std::ifstream input("books.mrs");
    char row[70];
    while(!input.eof())
    {
        input.getline(row , 70);
		input >> author;

	}
}
*/

/*
	while(!input.eof())
    {
        input >> number >> name >> title >> Genre >> price;
		book b( number, name );
		books.pushback(b);
		books.print();
	}
*/


int main()
{
	//Book d;
	Book d2("Peshko", "iznaglqva", "drama", "shte bichi", 2021, "dosta neshta", 5);
    Book d("MIMI", "Poludqva", "drama", "Ne znae kakvo shte pravi", 2021, "neshto", 2.4);
	Book d3("MS", "Bibibi", "drama queen", "Ne znae kakvo shte pravi veche", 2021, "neshto nishto", 2.4);
	//d.addToFile("books.mrs");
	//d2.addToFile("books.mrs");
	d3.addToFile("books.mrs");

	//d.load("books.mrs");
	//d2.load("books.mrs");
}

