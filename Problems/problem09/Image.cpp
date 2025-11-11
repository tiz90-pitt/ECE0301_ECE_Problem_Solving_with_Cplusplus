#include "Image.hpp"

#include <stdexcept>

Image::Image() : width(0), height(0), image_data(nullptr) {}

Image::Image(int size)
{
    // TODO
    width = size;
    height = size;
    // Square image of size x size are the same as the Rectangle
    image_data = new RGBPIXEL[width * height];
    for (int i = 0; i < width * height; i++)
    {
        image_data[i] = GREEN; // All pixels should be set to Green
    }
}

Image::Image(int w, int h)
{
    // TODO
    // Rectangle image of width w and height h have the same equation as the Square image
    width = w;
    height = h;
    image_data = new RGBPIXEL[width * height]; // So this is using the same logic
    for (int i = 0; i < width * height; i++)
    {
        image_data[i] = GREEN; // All pixels are set to Green
    }
}
// Rule of 3 - Copy Constructor
Image::Image(const Image &im)
{
    // TODO: make sure to apply deep copy
    width = im.width;
    height = im.height;
    image_data = new RGBPIXEL[width * height];
    for (int i = 0; i < width * height; i++)
    {
        image_data[i] = im.image_data[i];
    }
}
// Rule of 3 - Destructor
Image::~Image()
{
    // TODO
    delete[] image_data;
}
// Rule of 3 - Copy Assignment
Image &Image::operator=(Image im)
{
    // TODO: make sure to apply copy-swap-idiom
    width = im.width; // Passing values
    height = im.height;
    std::swap(image_data, im.image_data); // Swapping pointers
    return *this;
}

int Image::get_width() const
{
    return width;
}

int Image::get_height() const
{
    return height;
}

RGBPIXEL Image::get_pixel(int index) const
{
    if (index >= width * height)
    {
        throw std::out_of_range("Pixel index out of range");
    }
    return image_data[index];
}

void Image::set_pixel(int index, const RGBPIXEL color)
{
    if (index >= width * height)
    {
        throw std::out_of_range("Pixel index out of range");
    }
    image_data[index] = color;
}

bool Image::load_from_file(std::string filename)
{
    // BONUS
    delete[] image_data; // Free existing data
    RGBIMAGEDATA imdata = import_bmp(filename);
    if (imdata.data != nullptr)
    {
        width = imdata.width;
        height = imdata.height;
        image_data = imdata.data;
        return true;
    }
    width = 0;
    height = 0;
    image_data = nullptr;
    return false;
}

bool Image::save_to_file(std::string filename)
{
    // BONUS
    if (image_data == nullptr){
        return false;
    }
    return export_bmp({image_data, width, height}, filename);
}

Image operator+(const Image &im, const RGBPIXEL &val)
{
    // TODO - Based on SafeArray5
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
    // TODO
    return operator+(val, im);
}

// This will be useful if attempting bonus
Image operator-(const Image &im, const RGBPIXEL &val)
{
    // OPTIONAL for bonus, to simply return im is wrong
    Image result(im.get_width(), im.get_height());
    // element-wise subtracting val
    for (int i = 0; i < im.get_width() * im.get_height(); i++)
    {
        result.set_pixel(i, im.get_pixel(i) - val);
    }
    return result;
}

Image operator-(const RGBPIXEL &val, const Image &im)
{
    // OPTIONAL for bonus, to simply return im is wrong
    return operator-(im, val);
}