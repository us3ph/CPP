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

int Fixed::getRawBits(void) const
{
  return this->value;
}

void Fixed::setRawBits(int const raw)
{
  this->value = raw;
}

float Fixed::toFloat( void ) const
{
  return (float)this->value / (1 << fractionalBits);
}

int Fixed::toInt( void ) const
{
  return this->value >> fractionalBits;
}

std::ostream& operator<<(std::ostream &out, const Fixed fixed)
{
  out << fixed.toFloat();
  return out; // Returns reference to the same stream
}