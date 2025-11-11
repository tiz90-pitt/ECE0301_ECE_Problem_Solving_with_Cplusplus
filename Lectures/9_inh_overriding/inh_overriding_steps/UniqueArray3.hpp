// This is new UniqueArray3.hpp
// 1. a derived class method set( , ) is added
<<<<<<< HEAD
// 2. based on "virtual" or not in base class, set() here overrides or redefines set() of base class
=======
// 2. based on "virtual" or not in base class, this one overrides or redefines base class
>>>>>>> ad4b5081d9c95051f0fe346333fb5fbe9fa3ed05

#ifndef _UNIQUE_ARRAY_HPP
#define _UNIQUE_ARRAY_HPP

#include "SafeArray3.hpp"

<<<<<<< HEAD
class UniqueArray : public SafeArray // all public member functions(except constructors) of SafeArray class are inherited
{
public:
    using SafeArray::SafeArray;
    // above line also tells how to construct a derived class, same as using the following constructors
    // SearchableArray();
    // SearchableArray(int);
    // SearchableArray(const SearchableArray &);

    void set(int, int); // derived class function overriding or redefining base class function
    // If "virtual" is not added to SafeArray base class, this redefines derived class function
    // If "virtual" is added to SafeArray base class, this overrides derived class function
=======
class UniqueArray: public SafeArray{
    public:
        // all public member functions(except constructors) of SafeArray class are inherited
        
        using SafeArray::SafeArray; 
        // above is how to construct a derived class, same as using the following two lines
        // SearchableArray();
        // SearchableArray(int);
        
        void set(int, int);         //overridden derived class function
        //if "virtual" is not added to SafeArray base class, 
        //this simply redefines derived class function
>>>>>>> ad4b5081d9c95051f0fe346333fb5fbe9fa3ed05
};

#endif