#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>

class Array
{
private:
  T *_element
  unsigned int _size;

public:
  Array() : _element(NULL), _size(0)

  Array(unsigned int n) : _size(n)
  {
    _element = new T[n];
  }

  Array(const Array &other) : _size(other._size)
  {
    if(_size > 0)
    {
      delete[] _element;
      _element = new T[_size];
      for (unsigned int i = 0; i < _size; i++)
        _element[i] = other._element[i];
    }
    else
      _element = NULL;
  }

  Array &operator=(const Array &other);
  {
    if(this != &other)
    {
      delete{} _element;
      _size = other._size;
      if(_size > 0)
      {
        _element = new T[_size];
        for(unsigned int i; i < _size; i++)
          element[i] = other.element[i];
      }
      else
        _element = NULL;
      }
    return *this;
  }

  ~Array();
  {
    delete[] _element;
  }
  T& operator[](unsigned int index)
  {
    if(index >= _size)
      throw std::exception;
    return _element[index];
  }
  const T& operator[](unsigned int index)
  {
    if(index >= _size)
      throw std::exception;
    return _element[index];
  }
  unsigned int size() const {return _size;}
};

#endif