// This is SearchableArray3.cpp
// No changes from SearchableArray2.hpp

#ifndef _SEARCHABLE_ARRAY_HPP
#define _SEARCHABLE_ARRAY_HPP

#include "SafeArray3.hpp"

<<<<<<< HEAD
class SearchableArray : public SafeArray
{
public:
    using SafeArray::SafeArray;
    bool search(int);
=======
class SearchableArray: public SafeArray{
    public:
        using SafeArray::SafeArray; 
        bool search(int);
>>>>>>> ad4b5081d9c95051f0fe346333fb5fbe9fa3ed05
};

#endif