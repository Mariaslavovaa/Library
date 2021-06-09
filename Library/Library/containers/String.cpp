#pragma once
#include "String.h"
#include <iostream>


void String::resize(unsi size)
{
    capacity += size;
    char* newString = new char[capacity];
    for(size_t i = 0; i < size; i++)
    {
        newString[i] = data[i];
    }
    destroy();
    data = newString;
}

void String::destroy()
{
    delete[] data;
}

String::String()
{
	this->capacity = 8;
	this->size = 0;
	this->data = nullptr;  //data = new char[capacity];
}

String::String(const String& other)
{
	this->capacity = other.capacity;
	this->size = other.size;
	this->data = new char[other.capacity];
	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

String::String(const char* other)
{
	unsi sizeOther = 0;
    for (size_t i = 0; other[i] != '\0'; i++)
    {
        sizeOther++;
    }

    this->size = sizeOther;
    this->capacity = sizeOther + 1;
    this->data = new char[capacity]; 
    for(size_t i = 0; i < size; i++)
    {
        data[i] = other[i];
    }
}

String::~String()
{
	destroy();
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		destroy();

		this->capacity = other.capacity;
		this->size = other.size;
		this->data = new char[other.capacity];

		for (size_t i = 0; i < size; i++)
		{
			data[i] = other.data[i];
		}
	}
	return *this;
}

const bool String::operator==(const String& other)
{
    if(this->getSize() != other.getSize())
    {
        return false;
    }

    for (size_t i = 0; i < this->getSize(); i++)
    {
        if (data[i] != other[i])
        {
            return false;
        }
    }
    return true;
}

const bool String::operator==(const char* other)
{
    unsi size = 0;
    for (size_t i = 0; other[i] != '\0'; i++)
    {
        size++;
    }
    
    if(size != this->getSize())
    {
        return false;
    }

    for (size_t k = 0; k < getSize(); k++)
    {
        if (data[k] != other[k])
        {
            return false;
        }
    }
    return true;
}

char String::operator[](unsi i) const
{
    if(i < size)
    {
        return data[i];
    }
    throw std::out_of_range("Index was out of range");
}

char& String::operator[](unsi i)
{
    if(i < size)
    {
        return data[i];
    }
    throw std::out_of_range("Index was out of range");
}

/*void String::push_back(const unsi& newElement)  
{
	if (size >= capacity)
	{
		capacity = capacity * 2;
		char* biggerString = new char[capacity];

		for (size_t i = 0; i < size; i++)
		{
			biggerString[i] = this->data[i];
		}

		destroy();
		this->data = biggerString;
	}
	data[size] = newElement;
	size++;
}
*/

void String::push_back(const char& newChar)
{
    if(size >= capacity)
    {
        resize(capacity * 2);
    }
    data[size++] = newChar;
}

void String::push_back(const char* str)
{
    size_t _size = 0;
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        _size++;
    }
    
    if(size + _size >= capacity)
    {
        resize(size + _size);
    }

    for (size_t i = size, j = 0; i < size + _size, j < _size; i++, j++)
    {
        data[i] = str[j];
    }
}

void String::push_back(const String &other)
{
    
    if(size + other.size >= capacity)
    {
        resize(size + other.size);
    }
    
    for (size_t i = size, j = 0; i < size + other.size; i++, j++)
    {
        data[i] = other[j];
    }
}

void String::pop_back()
{
	if (size > 0)
	{
		size--;
	}
}

unsi String::getSize() const
{
    return size;
}

unsi String::getCapacity() const
{
    return capacity;
}

std::ostream& operator<<(std::ostream& out, const String& c)
{
    for (size_t i = 0; i < c.getSize(); i++)
    {
        out << c.data[i];
    }
    return out;
}

std::istream& operator>>(std::istream& in, const String& c)
{
    for (size_t i = 0; i < c.getSize(); i++)
    {
        in >> c.data[i];
    }
    return in;
}