// This is test_inh_overriding2.cpp
// Changes from test_inh_overriding1.cpp
// 1. add test cases of inheritance
<<<<<<< HEAD
// 2. methods of base class and derived class are both available
=======
// 2. methods of base class and derived class are both available 
>>>>>>> ad4b5081d9c95051f0fe346333fb5fbe9fa3ed05

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "SafeArray2.hpp"
#include "SearchableArray2.hpp"
<<<<<<< HEAD
#include "UniqueArray2.hpp"

TEST_CASE("Test SafeArray size construction and access using get/set", "[safearray]")
{
=======
#include "UniqueArray.hpp"

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
    SearchableArray arr(size); // use constructor inherited from SafeArray

    REQUIRE(arr.get_size() == 5);

    for (int i = 0; i < size; i++)
    {
        arr.set(i, i);            // inherited from base class
        REQUIRE(arr.get(i) == i); // inherited from base class
        REQUIRE(arr.search(i));   // derived class method
    }

    REQUIRE_FALSE(arr.search(-2));                         // derived class method
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
>>>>>>> ad4b5081d9c95051f0fe346333fb5fbe9fa3ed05
    REQUIRE_THROWS_AS(arr.set(10, 10), std::out_of_range); // inherited from base class
}