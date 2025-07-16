#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>


class Fixed
{
private:

  int value; // store the fixed point value
  static const int fractionalBits = 8; // always 8

public:

  Fixed(); // default constructor
  Fixed(const Fixed &other); // copy constructor
  Fixed& operator=(const Fixed &other); // copy assignment operator overload
  ~Fixed(); // destructor

  int getRawBits(void) const; // that returns the raw value of the fixed-point value
  void setRawBits(int const raw); // that sets the raw value of the fixed-point number
};



#endif
