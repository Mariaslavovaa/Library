#pragma once
#include "Vector.h"
#include <iostream>

template<typename T>
void Vector<T>::resize()
{
    capacity = capacity * 2;
    T* newBuff = new T[capacity];
    for(size_t i = 0; i < size; i++)
    {
        newBuff[i] = data[i];
    }
    delete[] data;
    data = newBuff;
}

template<typename T>
void Vector<T>::destroy()
{
    delete[] data;
}

template<typename T>
void Vector<T>::copy(const Vector& other)
{
    size = other.size;
    capacity = other.capacity;
    data = new T[capacity];

    for(size_t i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }
}

template<typename T>
Vector<T>::Vector()
{
    capacity = 8;
    size = 0;
    data = new T[capacity];
}

template<typename T>
Vector<T>::Vector(const Vector<T>& other)
{
    copy(other);
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& other)
{
    if(this != &other)
    {
        destroy();
        copy(other);
    }
    return *this;
}

template<typename T>
Vector<T>::~Vector()
{
    destroy();
}

template<typename T>
bool Vector<T>::isEmpty () const
{
    return size == 0;
}

template<typename T>
size_t Vector<T>::getSize() const
{
    return size;
}

template<typename T>
size_t Vector<T>::getCapacity() const
{
    return capacity;
}

template<typename T>
T Vector<T>::operator[](size_t index) const
{
    if(index < size)
    {
        return data[index];
    }
    else
    {
        std::cout << "Invalid index!";
        return;
    }
}

template<typename T>
void Vector<T>::push_back(const T& newElement)
{
    if(size == capacity)
    {
        resize();
    }
    data[size++] = newElement;
}

template<typename T>
void Vector<T>::pop_back()
{
    if(isEmpty())
    {
        std::cout << "The vector is empty!" << std::endl;
		return;
    }
    T* newBuff = new T[size - 1];
    for (size_t i = 0; i < size - 1; i++) 
    {
        newBuff[i] = data[i];
    }
    destroy();
    --size;
    data = newBuff;
}

template<typename T>
void Vector<T>::print() const 
{
	for (size_t i = 0; i < size; i++) 
    {
		std::cout << data[i] << ' ';
	}
}