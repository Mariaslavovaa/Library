#pragma once
#include "Book.h"
#include <iostream>
#include <fstream>

void Book::copy(const Book& other)
{
	this->author = other.author;
	this->title = other.title;
	this->genre = other.genre;
	this->description = other.description;
	this->year = other.year;
	this->keyword = other.keyword;
	this->rating = other.rating;
	this->unique = other.unique;
}

String Book::normalizeName(String other)
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

Book::Book()
{
	year = 0;    //Трябва ли да я занулявам???
	rating = 0;
}

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

	unique = Id++;

	//Id++;
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

char* Book::getCharAuthor() const
{
	size_t size = author.getSize();
	char *arr = new char[size + 1];
	
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = author[i];
	}
	arr[size] = '\0';
	return arr;
}

String Book::getTitle() const
{
	return title;
}

char* Book::getCharTitle() const
{
	size_t size = title.getSize();
	char *arr = new char[size + 1];
	
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = title[i];
	}
	arr[size] = '\0';
	return arr;
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

unsi Book::getId() const  
{
	return unique;
}

void Book::print() const
{
	std::cout << unique << " ";   
	std::cout << author << " ";
	std::cout << title << " ";
	std::cout << genre << " ";
	std::cout << description << " ";
	std::cout << year << " ";
	std::cout << keyword << " ";
	std::cout << rating << std::endl;
}

void Book::printAllBooks() const  
{
	std::cout << title << " ";
	std::cout << author << " ";
	std::cout << genre << " ";
	std::cout << unique << std::endl;
}

void Book::addToFile(const char* fileName)
{
	std::ofstream output(fileName, std::ios::app);
	String normalizedName = normalizeName(author);
	String normalizedTitle = normalizeName(title);
	String normalizedGenre = normalizeName(genre);
	String normalizedDescr = normalizeName(description);
	String normalizedKw = normalizeName(keyword);

	//Id++; // ------- ?????

	output << unique  << ' ' << normalizedName << ' ' << normalizedTitle << ' ' << normalizedGenre 
	<< ' ' << normalizedDescr << ' ' << year << ' ' << normalizedKw << ' ' << rating << std::endl;
	output.close();

}

std::ostream& operator<<(std::ostream& out, const Book& b)
{   
    out << b.unique << ' ' << b.author << ' ' << b.title << ' ' << b.genre << ' ' << b.description 
	<< ' ' << b.year << ' ' << b.keyword << ' ' << b.rating << std::endl;
    return out;
}
/*
std::istream& operator>>(std::istream& in, Book& b) {
	std::cout << "Unique number: ";
	in >> b.Id;
	std::cout << "Author: ";
	in >> b.author;
	std::cout << "Title: ";
	in >> b.title;
	std::cout << "GSenre: ";
	in >> b.genre;
	std::cout << "Description: ";
	in >> b.description;
	std::cout << "Year: ";
	in >> b.year;
	std::cout << "Keyword: ";
	in >> b.keyword;
	std::cout << "Rating: ";
	in >> b.rating;

	return in;
}
*/
void Book::load(const char* fileName) 
{
	std::ifstream input(fileName);
	Vector<Book> books;

	while(!input.eof())
	{
		char author[50], title[50], genre[50], description[100], keyword[20];
		input >> Id >> author >> title >> genre >> description >> year >> keyword >> rating;
		Book b(author, title, genre, description, year, keyword, rating);
		books.push_back(b);
	}
	books.print();
	input.close();
}

/*
	//std::ifstream input(fileName, std::ios::app);
	//std::ifstream& iFile
	//iFile >> *this;

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
	
	while(!input.eof())
    {
        input >> number >> name >> title >> Genre >> price;
		book b( number, name );
		books.pushback(b);
		books.print();
	}
	
*/


/*
int main()
{
	
	//Book d;
	Book d("Peshko", "iznaglqva", "drama", "shte bichi", 2021, "dosta neshta", 5);
	Book d2("Fifi", "iznasq", "film", "ailqk", 2001, "i sq kvo", 3.59);
	Book d3("MS", "Bibibi", "drama queen", "Ne znae kakvo shte pravi veche", 2021, "neshto nishto", 2.4);
	Book d21("Peshko", "iznaglqva", "drama", "shte bichi", 2021, "dosta neshta", 5);
    Book d31("Maria", "Izchatka", "pusna mi", "Ne znae kakvo shte pravi", 2021, "nishto", 2.1);
	Book d11("MSS", "nimibi", "drama", "Shte ima 2", 2021, "nishto nishto", 2.0);
	d.addToFile("..\\Files\\books.mrs");
	d2.addToFile("..\\Files\\books.mrs");
	//d3.addToFile("..\\Files\\books.mrs");
	//d21.addToFile("..\\Files\\books.mrs");
	//d31.addToFile("..\\Files\\books.mrs");
	//d11.addToFile("..\\Files\\books.mrs");

	//d.load("..\\Files\\books.mrs");
	//d2.load("..\\Files\\books.mrs");

	
	Book d21("Peshko", "iznaglqva", "drama", "shte bichi", 2021, "dosta neshta", 5);
    Book d11("Maria", "Izchatka", "pusna mi", "Ne znae kakvo shte pravi", 2021, "nishto", 2.1);
	Book d31("MSS", "nimibi", "drama", "Shte ima 2", 2021, "nishto nishto", 2.0);
	Book d2("Fifi", "iznasq", "film", "ailqk", 2001, "i sq kvo", 3.59);
    Book d("MIMI", "Poludqva", "drama", "Ne znae kakvo shte pravi", 2021, "neshto", 2.4);
	Book d3("MS", "Bibibi", "drama queen", "Ne znae kakvo shte pravi veche", 2021, "neshto nishto", 2.4);

	std::cout << d21.getId() << std::endl;
	std::cout << d11.getId() << std::endl;
	std::cout << d31.getId() << std::endl;
	std::cout << d.getId() << std::endl;
	std::cout << d3.getId() << std::endl;
	std::cout << d2.getId() << std::endl;
	
}
*/
