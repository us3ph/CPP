#include "Fixed.hpp"

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const int value) : value( value << fractionalBits) {}

Fixed::Fixed(const float value) : value(roundf(value * (1 << fractionalBits))) {}

Fixed::Fixed(const Fixed &other) : value(other.value) {}

Fixed &Fixed::operator=(const Fixed &other)
{
  if(this != &other)
    this->value = other.value;
  return *this;
}

Fixed::~Fixed() {}
///////////////////////////////////////////////////////////
int Fixed::getRawBits(void) const
{
  return this->value;
}

void Fixed::setRawBits(int const raw)
{
  this->value = raw;
}
//////////////////////////////////////////////////////////
float Fixed::toFloat( void ) const
{
  return (float)this->value / (1 << fractionalBits);
}

int Fixed::toInt( void ) const
{
  return this->value >> fractionalBits;
}
//////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream &out, const Fixed fixed)
{
  out << fixed.toFloat();
  return out; // Returns reference to the same stream
}
/////////////////////////////////////////////////////////////
bool Fixed::operator>(const Fixed &other) const
{
  return this->getRawBits() > other.getRawBits();
}

 bool Fixed::operator<(const Fixed &other) const
 {
  return this->getRawBits() < other.getRawBits();
 }

 bool Fixed::operator>=(const Fixed &other) const
 {
  return this->getRawBits() >= other.getRawBits();
 }

bool Fixed::operator<=(const Fixed &other) const
{
  return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const
{
  return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const
{
  return this->getRawBits() != other.getRawBits();
}
//////////////////////////////////////////////////////////////
Fixed Fixed::operator+(const Fixed &other) const
{
  Fixed rslt;
  rslt.setRawBits(this->getRawBits() + other.getRawBits());
  return rslt;
}

Fixed Fixed::operator-(const Fixed &other) const
{
  Fixed rslt;
  rslt.setRawBits(this->getRawBits() - other.getRawBits());
  return rslt;
}

Fixed Fixed::operator*(const Fixed &other) const
{
  Fixed rslt;
  rslt.setRawBits((this->getRawBits() * other.getRawBits()) >> fractionalBits);
  return rslt;
}
/* ex for * operator
5.05f → 5.05 * 256 = 1292.8 ≈ 1293

2.0f → 2 * 256 = 512

1293 * 512 = 662016

662016 >> 8 = 2586

2586 / 256 = 10.1016
*/
Fixed Fixed::operator/(const Fixed &other) const
{
  Fixed rslt;
  // adjusts back the scale properly
  rslt.setRawBits((this->getRawBits() << fractionalBits) / other.getRawBits());
  return rslt;
}
//////////////////////////////////////////////////////////////////
Fixed& Fixed::operator++()
{
  this->setRawBits(this->getRawBits() + 1);
  return *this;
}

Fixed Fixed::operator++(int) // int just tells the compiler this is post-increment
{
  Fixed tmp = *this; // make a copy
  this->setRawBits(this->getRawBits() + 1); // increase current object
  return tmp; // return the copy (old value)
}

Fixed& Fixed::operator--()
{
  this->setRawBits(this->getRawBits() - 1);
  return *this;
}

Fixed Fixed::operator--(int)
{
  Fixed tmp = *this;
  this->setRawBits(this->getRawBits() - 1);
  return tmp;
}
/////////////////////////////////////////////////////////////////////////////
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
  if(a < b)
    return a;
  return b;
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
 {
  if(a > b)
    return a;
  return b;
 }

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
  if(a < b)
    return a;
  return b;

}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
  if(a > b)
    return a;
  return b;
}