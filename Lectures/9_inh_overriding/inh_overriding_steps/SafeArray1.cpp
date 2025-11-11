// This is SafeArray1.cpp
// Changes from starter code of SafeArray.cpp
// 1. implementing get() for accessing
<<<<<<< HEAD
// 2. implementing set( , ) for updating
// 3. updating + operator accordingly

#include "SafeArray1.hpp"
#include <stdexcept>
#include <algorithm>
=======
// 2. implementing set ( , ) for updating
// 3. updating + operator accordingly

#include "SafeArray1.hpp"
#include<stdexcept>
#include<algorithm>
>>>>>>> ad4b5081d9c95051f0fe346333fb5fbe9fa3ed05

SafeArray::SafeArray() : size(0), dataptr(nullptr)
{
}

SafeArray::SafeArray(int s) : size(s)
{
    dataptr = new int[size];
<<<<<<< HEAD
    for (int i = 0; i < size; i++)
    {
        dataptr[i] = 0;
=======
    for (int i=0; i<size; i++){
        dataptr[i]=0;
>>>>>>> ad4b5081d9c95051f0fe346333fb5fbe9fa3ed05
    }
}

SafeArray::~SafeArray()
{
<<<<<<< HEAD
    delete[] dataptr;
=======
    delete [] dataptr;
>>>>>>> ad4b5081d9c95051f0fe346333fb5fbe9fa3ed05
}

SafeArray::SafeArray(const SafeArray &s)
{
    size = s.size;
    dataptr = new int[size];
<<<<<<< HEAD
    for (int i = 0; i < size; i++)
    {
        dataptr[i] = s.dataptr[i];
    }
}

SafeArray &SafeArray::operator=(SafeArray s)
=======
    for (int i=0; i<size; i++){
        dataptr[i]=s.dataptr[i];
    }
}

SafeArray & SafeArray::operator=(SafeArray s)
>>>>>>> ad4b5081d9c95051f0fe346333fb5fbe9fa3ed05
{
    size = s.size;
    std::swap(dataptr, s.dataptr); // this requires <algorithm>
    return *this;
    // 1.copy-2.swap-idiom: 1.passing by value, 2.swap with others, 3.return *this
}

int SafeArray::get_size() const
{
    return size;
}

// int SafeArray::operator[](int idx) const
// {
//     if (idx<0 || idx>=size){
//         throw std::out_of_range("Index out of range");
//     }
//     return dataptr[idx];
// }

<<<<<<< HEAD
int SafeArray::get(int idx) const // accessing, similar to operator[], avoid derived class overloading operators
{
    if (idx < 0 || idx >= size)
    {
=======
int SafeArray::get(int idx) const
{
    if (idx<0 || idx>=size){
>>>>>>> ad4b5081d9c95051f0fe346333fb5fbe9fa3ed05
        throw std::out_of_range("Index out of range");
    }
    return dataptr[idx];
}

// int & SafeArray::operator[](int idx)
// {
//     if (idx<0 || idx>=size){
//         throw std::out_of_range("Index out of range");
//     }
//     return dataptr[idx];
// }

<<<<<<< HEAD
void SafeArray::set(int idx, int val) // updating, similar to operator[], avoid derived class overloading operators
{
    if (idx < 0 || idx >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    dataptr[idx] = val;
=======
void SafeArray::set(int idx, int val)
{
    if (idx<0 || idx>=size){
        throw std::out_of_range("Index out of range");
    }
    dataptr[idx]=val;
>>>>>>> ad4b5081d9c95051f0fe346333fb5fbe9fa3ed05
}

// implement a non-member operator overloading function
SafeArray operator+(const SafeArray &a, int b)
{
<<<<<<< HEAD
    SafeArray result(a.get_size()); // element-wise adding b
    for (int i = 0; i < result.get_size(); i++)
    {
        result.set(i, a.get(i) + b);
=======
    SafeArray result(a.get_size());  // element-wise adding b
    for (int i=0; i<result.get_size(); i++){
        result.set(i, a.get(i)+b);
>>>>>>> ad4b5081d9c95051f0fe346333fb5fbe9fa3ed05
    }
    return result;
}

SafeArray operator+(int a, const SafeArray &b)
{
<<<<<<< HEAD
    return operator+(b, a);
=======
    return operator+(b,a);
>>>>>>> ad4b5081d9c95051f0fe346333fb5fbe9fa3ed05
}