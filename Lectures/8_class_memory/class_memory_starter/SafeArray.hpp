#ifndef _SAFE_ARRAY_HPP
#define _SAFE_ARRAY_HPP

class SafeArray
{
private:
  int *dataptr;
  int size;

public:
  SafeArray();
  SafeArray(int);
  int get_size() const;
};

#endif