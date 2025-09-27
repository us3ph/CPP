#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <climits>
#include <cstdlib>
#include <algorithm>

class Span
{
private:
    std::vector<int> numbers;
    unsigned int maxSize;

public:
    Span();
    Span(unsigned int n);
    Span(const Span &other);
    Span& operator=(const Span &other);
    ~Span();
    void addNunber(int num);
    unsigned int shortesSpan() const;
    unsigned int longestSpan() const;
};


#endif