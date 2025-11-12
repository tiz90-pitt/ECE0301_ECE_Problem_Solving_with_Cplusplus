#ifndef EXAM2_HPP
#define EXAM2_HPP

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <vector>

// declare your class here
class SampleClass
{
private:
  // private data members can be declared here
public:
  void displayMessage() const;
  // ...
};
class chip{
private:
double res;
int volA, volB;
std::string name;
public:
chip(){res=0; volA=0; volB=0;}
chip(double r, int va, int vb){res=r; volA=va; volB=vb;}

void set_res(double r) {res=r;};
void set_chip_name(std::string n) {name=n;};

double get_res() const {return res;};
double get_vol_diff() const {return volA-volB;};

virtual double get_current() const {return 0;};
};
class chip_74 : public chip{
  public:
    using ::chip::chip;
    double get_current() const {return get_vol_diff() / get_res();
  }
};
#endif