// This is new SearchableArray2.cpp
// 1. implement the new method added for derived class SearchableArray
// 2. due to "using" line in .hpp file, no need to implement constructor
<<<<<<< HEAD
// 3. get_size() and get(int) functions are inherited and therefore can be used here
=======
// 3. get_size() and get(int) functions are inherited
>>>>>>> ad4b5081d9c95051f0fe346333fb5fbe9fa3ed05

#include "SearchableArray2.hpp"

bool SearchableArray::search(int value)
{
<<<<<<< HEAD
    // SearchableArray can use public method from SafeArray, e.g., get_size()
    for (int i = 0; i < get_size(); i++)
    {
        if (get(i) == value)
        { // same as above, get() is available to use
=======
    //SearchableArray can use public method from SafeArray, e.g., get_size()
    for(int i=0; i<get_size(); i++){ 
        if (get(i)==value){        //same as above, get() is available to use
>>>>>>> ad4b5081d9c95051f0fe346333fb5fbe9fa3ed05
            return true;
        }
    }
    return false;
}