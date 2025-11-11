// This is test_inh_overriding3.cpp
// Changes from test_inh_overriding2.cpp
// 1. add test case of inheritance permission of "protected"
// 2. test of overriding and redefining derived class method

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "SafeArray3.hpp"
#include "SearchableArray3.hpp"
#include "UniqueArray3.hpp"

<<<<<<< HEAD
TEST_CASE("Test SafeArray size construction and access using get/set", "[safearray]")
{
=======
TEST_CASE("Test SafeArray size construction and access using get/set", "[safearray]") {
>>>>>>> ad4b5081d9c95051f0fe346333fb5fbe9fa3ed05
    int size = 5;
    SafeArray arr(size);

    REQUIRE(arr.get_size() == size);
<<<<<<< HEAD
    for (int i = 0; i < size; i++)
    {
=======
    for (int i=0; i<size; i++) {
>>>>>>> ad4b5081d9c95051f0fe346333fb5fbe9fa3ed05
        arr.set(i, i);
        REQUIRE(arr.get(i) == i);
    }

    REQUIRE_THROWS_AS(arr.get(size), std::out_of_range);
<<<<<<< HEAD
    REQUIRE_THROWS_AS(arr.set(size, 0), std::out_of_range);
}

TEST_CASE("Test inheritance and search", "[inh]")
{
    int size = 5;
    SearchableArray arr(size);

    REQUIRE(arr.get_size() == 5);

    for (int i = 0; i < size; i++)
    {
        arr.set(i, i);            // inherited from base class
        REQUIRE(arr.get(i) == i); // inherited from base class
        REQUIRE(arr.search(i));   // derived class method
    }

    REQUIRE_FALSE(arr.search(-2));                         // derived class method
    REQUIRE_THROWS_AS(arr.set(10, 10), std::out_of_range); // inherited from base class
}

TEST_CASE("Test inheritance access permission", "[inh]")
{
    int size = 5;
    SearchableArray arr(size);
    REQUIRE(arr.search(0)); // derived class method built on "protected" var
}

TEST_CASE("Test inheritance and redefine/override", "[inh]")
{
    int size = 5;
    UniqueArray uarr(size);

    REQUIRE(uarr.get_size() == 5);

    for (int i = 0; i < size; i++)
    {
        // set uarr to be [1,2,3,4,5]
        uarr.set(i, i + 1);            // overridden set functions
        REQUIRE(uarr.get(i) == i + 1); // test success of overriding
    }

    // arr[0]=5 would trigger uniqueness exception since arr[4] is already 5
    REQUIRE_THROWS_AS(uarr.set(0, 5), std::logic_error);
    REQUIRE_NOTHROW(uarr.set(0, -2)); // arr[0]=-2 is okay
    REQUIRE(uarr.get(0) == -2);

    // these following 3 lines demonstrates dynamic binding
    // delete "virtual" keyword of SafeArray3.hpp and try it again
    SafeArray *sa_ptr = new UniqueArray(2);
    sa_ptr->set(0, 100);
    REQUIRE_THROWS_AS(sa_ptr->set(1, 100), std::logic_error);

    // dynamic binding is also called late binding or runtime binding
    // it works only when base class function is declared as "virtual"
    // and the function is called by using base class pointer(*) or reference(&)

    // more explanations will be given in later steps
=======
    REQUIRE_THROWS_AS(arr.set(size,0), std::out_of_range);
}

TEST_CASE("Test inheritance and search", "[inh]") {
    int size = 5;
    SearchableArray arr(size);

    REQUIRE(arr.get_size()==5);

    for (int i=0; i<size; i++){
        arr.set(i,i);                  // inherited from base class 
        REQUIRE(arr.get(i)==i);        // inherited from base class
        REQUIRE(arr.search(i));        // derived class method
    }

    REQUIRE_FALSE(arr.search(-2));     // derived class method
    REQUIRE_THROWS_AS(arr.set(10, 10), std::out_of_range); // inherited from base class
}

TEST_CASE("Test inheritance access permission", "[inh]") {
    int size = 5;
    SearchableArray arr(size);
    REQUIRE(arr.search(0));     // derived class method built on "protected" var
}

TEST_CASE("Test inheritance and redefine/override", "[inh]") {
    int size = 5;
    UniqueArray uarr(size);

    REQUIRE(uarr.get_size()==5);

    for (int i=0; i<size; i++){
        // set uarr to be [1,2,3,4,5]
        uarr.set(i,i+1);                // overridden set functions
        REQUIRE(uarr.get(i)==i+1);      // test success of overriding
    }

    //arr[0]=5 would trigger exception since arr[4]=5
    REQUIRE_THROWS_AS(uarr.set(0, 5), std::logic_error);
    REQUIRE_NOTHROW(uarr.set(0, -2));   //arr[0]=-2 is okay
    REQUIRE(uarr.get(0)==-2);

    // these following 3 lines demonstrates dynamic binding
    // delete "virtual" at Line 27 of SafeArray3.hpp and try it again
    SafeArray *sa_ptr = new UniqueArray(2);
    sa_ptr->set(0, 100);
    REQUIRE_THROWS_AS(sa_ptr->set(1, 100), std::logic_error);
>>>>>>> ad4b5081d9c95051f0fe346333fb5fbe9fa3ed05
}