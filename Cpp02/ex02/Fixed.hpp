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

  bool operator>(const Fixed &other) const; // overload comparison operators
  bool operator<(const Fixed &other) const;
  bool operator>=(const Fixed &other) const;
  bool operator<=(const Fixed &other) const;
  bool operator==(const Fixed &other) const;
  bool operator!=(const Fixed &other) const;

  Fixed operator+(const Fixed &other) const; // overload arithmitic operators
  Fixed operator-(const Fixed &other) const;
  Fixed operator*(const Fixed &other) const;
  Fixed operator/(const Fixed &other) const;

  Fixed& operator++(); // pre increment
  Fixed operator++(int); // post increment
  Fixed& operator--(); // pre decrement
  Fixed operator--(int); // post-decrement operator >>+ ()

  static Fixed& min(Fixed& a, Fixed& b); // overloaded member functions
  static Fixed& max(Fixed& a, Fixed& b);
  static const Fixed& min(const Fixed& a, const Fixed& b);
  static const Fixed& max(const Fixed& a, const Fixed& b);

  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const; // converts the fixed-point to a floating-point
  int toInt(void) const; // converts the fixed-point to an integer value
};

std::ostream& operator<<(std::ostream &out, const Fixed fixed); // insertion operator overload
#endif