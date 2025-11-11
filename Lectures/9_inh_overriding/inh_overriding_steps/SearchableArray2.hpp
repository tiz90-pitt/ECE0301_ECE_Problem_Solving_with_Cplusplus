// This is new SearchableArray2.hpp
<<<<<<< HEAD
// 1. "public" at class declaration line describes access permission to base class
// 2. "public" at inside derived class describes client's permission to this derived class
// 3. "using" line tells compiler how to construct a derived class
=======
// 1. "public" at Line 10 describes access permission to base class
// 2. "public" at Line 11 describes object's permission to this derived class
// 3. "using" at Line 15 tells compiler how to construct a derived class
>>>>>>> ad4b5081d9c95051f0fe346333fb5fbe9fa3ed05
// 4. add a new method just for this derived class SearchableArray

#ifndef _SEARCHABLE_ARRAY_HPP
#define _SEARCHABLE_ARRAY_HPP

#include "SafeArray2.hpp"

<<<<<<< HEAD
class SearchableArray : public SafeArray // all public member functions(except constructors) of SafeArray class are inherited
{
public:
    using SafeArray::SafeArray; // this line tells compiler to use constructors from SafeArray
    // above line also tells how to construct a derived class, same as using the following constructors
    // SearchableArray();
    // SearchableArray(int);
    // SearchableArray(const SearchableArray &);
    bool search(int); // new method just for SearchableArray
=======
class SearchableArray: public SafeArray{
    public:
        // all public member functions(except constructors) of SafeArray class are inherited
        
        using SafeArray::SafeArray; 
        // above is how to construct a derived class, same as using the following two lines
        // SearchableArray();
        // SearchableArray(int);
        bool search(int);
>>>>>>> ad4b5081d9c95051f0fe346333fb5fbe9fa3ed05
};

#endif