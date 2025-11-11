// This is test_inh_overriding1.cpp
// Changes from starter code of test_inh_overriding.cpp
// 1. changing to testing get() and set(), instead of []

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "SafeArray1.hpp"
<<<<<<< HEAD
#include "SearchableArray1.hpp"
#include "UniqueArray1.hpp"

TEST_CASE("Test SafeArray size construction and access using get/set", "[safearray]")
{
=======
#include "SearchableArray.hpp"
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
=======
    REQUIRE_THROWS_AS(arr.set(size,0), std::out_of_range);
>>>>>>> ad4b5081d9c95051f0fe346333fb5fbe9fa3ed05
}