#pragma once
#include <iostream>

template <typename T>
class Vector
{
    private:
    T* data;
    size_t size;
    size_t capacity;

    void resize();
    void destroy();
    void copy(const Vector& other);

    public:
    Vector();
    Vector(const Vector& other);
    Vector<T>& operator=(const Vector& other);
    ~Vector();
//--------------------------------------------
    bool isEmpty () const;
    size_t getSize() const;
    size_t getCapacity() const;
//--------------------------------------------
    T operator[](size_t index) const;
//--------------------------------------------
    void push_back(const T& newElement);
    void pop_back();
//--------------------------------------------
    void print() const;

};
