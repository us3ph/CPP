#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "iostream"
#include "exception"

template <typename T>

class Array
{
private:
  T *_element;
  unsigned int _size;

public:
  Array() : _element(0), _size(0) {};

  Array(unsigned int n) : _size(n)
  {
    if(n < 1)
      _element = 0;
    else {
      _element = new T[n];
      for (unsigned int i = 0; i < n; ++i)
      _element[i] = 0;
    }
  };

  Array(const Array &other) : _size(other._size)
  {
    if(_size > 0)
    {
      std::cout << _size << std::endl;
      _element = new T[_size];
      for (unsigned int i = 0; i < _size; i++)
      {
        _element[i] = other._element[i];
      }
    }
    else
      _element = 0;
  };

  Array &operator=(const Array &other)
  {
    if(this != &other)
    {
      delete[] _element;
      _size = other._size;
      if(_size > 0)
      {
        _element = new T[_size];
        for(unsigned int i = 0; i < _size; i++)
          _element[i] = other._element[i];
      }
      else
        _element = 0;
      }
    return *this;
  }

  ~Array()
  {
    delete[] _element;
  }

  T& operator[](unsigned int index)
  {
    if(index >= _size)
      throw std::exception();
    return _element[index];
  }
  const T& operator[](unsigned int index) const
  {
    if(index >= _size)
      throw std::exception();
    return _element[index];
  }
  unsigned int size() const {return _size;}

};

#endif