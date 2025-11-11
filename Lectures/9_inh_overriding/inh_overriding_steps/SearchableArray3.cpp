// This is SearchableArray3.cpp
// Changes from SearchableArray2.hpp:
<<<<<<< HEAD
// 1. temporaily switch from using public function get() to directly using member variable
//    to demonstrate the use of "protected" access specifier in base class
=======
// 1. temp switch from public function get() to directly using member variable
>>>>>>> ad4b5081d9c95051f0fe346333fb5fbe9fa3ed05

#include "SearchableArray3.hpp"

// bool SearchableArray::search(int value)
// {
<<<<<<< HEAD
//     for(int i=0; i<get_size(); i++){
=======
//     for(int i=0; i<get_size(); i++){ 
>>>>>>> ad4b5081d9c95051f0fe346333fb5fbe9fa3ed05
//         if (get(i)==value){
//             return true;
//         }
//     }
//     return false;
// }

bool SearchableArray::search(int value)
{
<<<<<<< HEAD
    for (int i = 0; i < get_size(); i++)
    {
        if (dataptr[i] == value)
        { // dataptr is accessible due to "protected"
=======
    for(int i=0; i<get_size(); i++){ 
        if (dataptr[i]==value){      //dataptr is accessible due to "protected"
>>>>>>> ad4b5081d9c95051f0fe346333fb5fbe9fa3ed05
            return true;
        }
    }
    return false;
}