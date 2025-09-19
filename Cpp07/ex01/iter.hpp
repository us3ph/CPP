#ifndef ITER_HPP
#define ITER_HPP

#include "iostream"

template<typename T, typename F>
void iter(T *arr, size_t len, F func) 
{
    for(size_t i = 0; i < len; i++)
    {
        func(arr[i]);
    }
}

template< typename T>
void print(T& element){std::cout << element <<std::endl;}

template<typename T> 
void increment(T& element){element++;}


#endif