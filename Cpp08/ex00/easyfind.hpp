#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <list>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator rslt = std::find(container.begin(), container.end(), value);
    if(rslt == container.end())
        throw std::runtime_error("element not found");
    else
        return rslt;
}
#endif