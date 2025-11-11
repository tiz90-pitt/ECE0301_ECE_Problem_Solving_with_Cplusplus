#ifndef _IMAGE_HPP
#define _IMAGE_HPP

#include <string>
#include <cstdint>

#include "bitmap.hpp"

class Image
{
public:
    Image();
    // TODO: size constructors
    Image(int size)
    {
        width = size;
        height = size;
        image_data = new RGBPIXEL[width * height];
        for (int i = 0; i < width * height; i++)
        {
            image_data[i] = GREEN; // All pixels should be set to Green
        }
    }
    Image(int w, int h)
    {
        width = w;
        height = h;
        image_data = new RGBPIXEL[width * height];
        for (int i = 0; i < width * height; i++)
        {
            image_data[i] = GREEN; // All pixels should be set to Green
        }
    }

    // TODO: copy constructor
    Image(const Image &im)
    {
        width = im.width;
        height = im.height;
        image_data = new RGBPIXEL[width * height];
        for (int i = 0; i < width * height; i++)
        {
            image_data[i] = im.image_data[i];
        }
    }

    // TODO: destructor
    ~Image()
    {
        delete[] image_data;
    }

    // TODO: copy assignment
    Image &operator=(Image im)
    {
        width = im.width; // Passing values
        height = im.height;
        std::swap(image_data, im.image_data); // Swapping pointers
        return *this;
    }

    int get_width() const;
    int get_height() const;

    RGBPIXEL get_pixel(int index) const;
    void set_pixel(int index, const RGBPIXEL color);

    // BONUS: file read/write
    bool load_from_file(std::string filename);
    bool save_to_file(std::string filename);

private:
    int width;
    int height;
    RGBPIXEL *image_data;
};

// TODO: non-member overloaded addition operator
Image operator+(const Image &im, const RGBPIXEL &val)
{
    Image result(im.get_width(), im.get_height());
    // element-wise adding val
    for (int i = 0; i < im.get_width() * im.get_height(); i++)
    {
        result.set_pixel(i, im.get_pixel(i) + val);
    }
    return result;
}
Image operator+(const RGBPIXEL &val, const Image &im)
{
    return operator+(im, val);
}

// This will be useful if attempting bonus
// // OPTIONAL for bonus: subtraction operator
// Image operator-(const Image &im, const RGBPIXEL &val);
// Image operator-(const RGBPIXEL &val, const Image &im);

#endif