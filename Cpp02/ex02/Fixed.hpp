#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:

  int value;
  static const int fractionalBits = 8;

public:

  Fixed();
  Fixed(const int value); // int constructor
  Fixed(const float value); // float constructor
  Fixed(const Fixed &other);
  Fixed& operator=(const Fixed &other);
  bool operator>(const Fixed &other);
  bool operator<(const Fixed &other);
  bool operator>=(const Fixed &other);
  bool operator<=(const Fixed &other);
  bool operator==(const Fixed &other);
  bool operator!=(const Fixed &other);
  
  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const; // that converts the fixed-point to a floating-point
  int toInt(void) const; // that converts the fixed-point to an integer value.
};

std::ostream& operator<<(std::ostream &out, const Fixed fixed); // insertion operator overload
#endif