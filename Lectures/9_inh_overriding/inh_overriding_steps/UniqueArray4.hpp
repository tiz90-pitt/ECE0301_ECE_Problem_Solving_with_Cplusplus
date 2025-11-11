// This is UniqueArray4.hpp
<<<<<<< HEAD
// Add "override" since it expects to override base class function
// "override" reaffirms the "virtual" of SafeArray4.hpp
// "final" is an indicator that UniqueArray::set() cannot be overridden in its child classes
=======
// Add "override" at Line 12 since it expects to override base class function
// "override" reaffirms the "virtual" at Line 27 of SafeArray4.hpp
// "final" is an indicator that UniqueArray::set() cannot be overridden in its children classes
>>>>>>> ad4b5081d9c95051f0fe346333fb5fbe9fa3ed05

#ifndef _UNIQUE_ARRAY_HPP
#define _UNIQUE_ARRAY_HPP

#include "SafeArray4.hpp"

<<<<<<< HEAD
class UniqueArray : public SafeArray
{
public:
    using SafeArray::SafeArray;
    void set(int, int) override final;
    // If "virtual" is not added to SafeArray base class, this "override" would cause compile error
    // "virtual" in SafeArray base class is a must, "override" in derived class is optional but recommended

    // "final" is optional but using it prevents further overriding in UniqueArray's child classes
    // it is also okay by using "virtual void set(int, int) override final;"
=======
class UniqueArray: public SafeArray{
    public:
        using SafeArray::SafeArray; 
        void set(int, int) override final;
>>>>>>> ad4b5081d9c95051f0fe346333fb5fbe9fa3ed05
};

#endif