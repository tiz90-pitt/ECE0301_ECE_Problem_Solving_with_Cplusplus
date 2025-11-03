#include "SafeArray.hpp"

SafeArray::SafeArray() : size(0), dataptr(nullptr)
{
  // stub
  //  size = 0
  //  dataptr = nullptr
}
SafeArray::SafeArray(int s) : size(s)
{
  dataptr = new int(size);
  for (int i = 0; 1 < size; i++)
  {
    dataptr[i] = 0;
  }
}