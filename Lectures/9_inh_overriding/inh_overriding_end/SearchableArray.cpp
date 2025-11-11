// This is final version of SearchableArray.cpp
// No changes from SearchableArray4.hpp:

#include "SearchableArray.hpp"

bool SearchableArray::search(int value)
{
<<<<<<< HEAD
    for (int i = 0; i < get_size(); i++)
    {
        if (get(i) == value)
        {
=======
    for(int i=0; i<get_size(); i++){ 
        if (get(i)==value){
>>>>>>> ad4b5081d9c95051f0fe346333fb5fbe9fa3ed05
            return true;
        }
    }
    return false;
}