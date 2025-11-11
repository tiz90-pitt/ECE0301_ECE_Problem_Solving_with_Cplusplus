#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "bitmap.hpp"
#include "Image.hpp"

#include <cstdint>

/* Provided test cases */
TEST_CASE("Test size constructor", "[image]")
{
    int size = 10;
    Image im(size);

    REQUIRE(im.get_width() == size);
    REQUIRE(im.get_height() == size);
}

TEST_CASE("Test set/get pixels after size construction", "[image]")
{
    int size = 8;
    Image im(size);
    int first = 12;
    int second = 13;
    im.set_pixel(first, BLACK);
    im.set_pixel(second, RED);

    bool match = true;
    for (int i = 0; i < size * size; i++)
    {
        if (i == first)
        {
            match = (im.get_pixel(i) == BLACK);
        }
        else if (i == second)
        {
            match = (im.get_pixel(i) == RED);
        }
        else
        {
            match = (im.get_pixel(i) == GREEN);
        }
        if (!match)
        {
            break;
        }
    }
    REQUIRE(match);
}

TEST_CASE("Test copy constructor", "[image]")
{
    // initial image
    int width = 10;
    int height = 8;
    Image im(width, height);

    int first = 0;
    int last = width * height - 1;
    int middle = (width * height - 1) / 2;

    im.set_pixel(first, BLACK);
    im.set_pixel(last, RED);

    // copy image
    Image imgcopy(im);

    // change initial
    im.set_pixel(first, RED);
    im.set_pixel(middle, BLUE);
    im.set_pixel(last, WHITE);

    // test copy
    bool match = true;
    for (int i = 0; i < width * height; i++)
    {
        if (i == first)
        {
            match = (imgcopy.get_pixel(i) == BLACK);
        }
        else if (i == last)
        {
            match = (imgcopy.get_pixel(i) == RED);
        }
        else
        {
            match = (imgcopy.get_pixel(i) == GREEN);
        }
        if (!match)
        {
            break;
        }
    }
    REQUIRE(match);
}

TEST_CASE("Test operator+", "[image]")
{
    int width = 10;
    int height = 12;
    Image im(width, height);

    for (int i = 0; i < width * height; i++)
    {
        im.set_pixel(i, {0x80, 0x05, 0xAA});
    }

    RGBPIXEL val = {0x21, 0x05, 0xFF};

    Image res = im + val;

    bool match = true;
    for (int i = 0; i < width * height; i++)
    {
        match = (res.get_pixel(i) == im.get_pixel(i) + val);
        if (!match)
        {
            break;
        }
    }
    REQUIRE(match);
}

/* Your test cases here */
TEST_CASE("Test Square Image Constructor", "[image]")
{
    Image im;
    REQUIRE(im.get_width() == 0);
    REQUIRE(im.get_height() == 0);

    Image im2(5);
    REQUIRE(im2.get_width() == 5);
    REQUIRE(im2.get_height() == 5);

    for (int i = 0; i < im2.get_width() * im2.get_height(); i++)
    {
        REQUIRE(im2.get_pixel(i) == GREEN);
    }
}
TEST_CASE("Test Rectangular Image Constructor", "[image]")
{
    Image im;
    REQUIRE(im.get_width() == 0);
    REQUIRE(im.get_height() == 0);

    Image im2(4, 6);
    REQUIRE(im2.get_width() == 4);
    REQUIRE(im2.get_height() == 6);

    for (int i = 0; i < im2.get_width() * im2.get_height(); i++)
    {
        REQUIRE(im2.get_pixel(i) == GREEN);
    }
}
TEST_CASE("Test Deep Copy", "[image]")
{
    Image im(3, 3);
    im1.set_pixel(0, RED); // Color terms are defined in bitmap.hpp
    im1.set_pixel(4, BLUE);

    Image im2 = im; // im2 is declared using copy constructor

    // Changing the colors of im
    im.set_pixel(0, BLACK); 
    im.set_pixel(4, YELLOW);

    // Checking if the copied images stayed the same
    REQUIRE(im2.get_pixel(0) == RED);
    REQUIRE(im2.get_pixel(4) == BLUE);

    Image im3(2, 2);
    im3.set_pixel(0,0,BLACK);

    im4 = im3; // im4 is assigned using copy assignment
    REQUIRE(im4.get_width() == 2);
    REQUIRE(im4.get_height() == 2);
    REQUIRE(im4.get_pixel(0,0) == BLACK);
}
TEST_CASE("Test Overloaded Operator", "[image]") {
    Image im(1,1);
    RGBPIXEL add = YELLOW; // {0x00, 0xFF, 0xFF}
    // Image + RGBPIXEL
    Image result = im + add;
    REQUIRE(result.get_pixel(0,0) == BLUE); // Green + Yellow = Blue
    // RGBPIXEL + Image
    Image result2 = add + im;
    REQUIRE(result2.get_pixel(0,0) == BLUE); // Green + Yellow = Blue
    // Is im unchanged?
    REQUIRE(im.get_pixel(0,0) == GREEN);
    
}