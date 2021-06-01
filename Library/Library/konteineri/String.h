#pragma once
#include <iostream>

using unsi = unsigned short int;

class String
{
	private:
	char* data;
	unsi capacity;
	unsi size;

    void resize(unsi size);
	void destroy();

	public:
	String();
	String(const String& other);
	String(const char* other);
	~String();
	String& operator=(const String& other);
	const bool operator==(const char* other);

	char operator[](unsi i) const; 
	char& operator[](unsi i); 

	//void push_back(const unsi& newElement); 
	void push_back(const char& newChar); 
    void push_back(const char* str); 
    void push_back(const String& other); 
	void pop_back();
	unsi getSize() const;
	unsi getCapacity() const;

	friend std::ostream& operator<<(std::ostream& out, const String&);
	friend std::istream& operator>>(std::istream& in, const String&);
};