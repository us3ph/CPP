#include "Span.hpp"

Span::Span() : maxSize(0) {}

Span::Span(unsigned int n) : maxSize(n) {}

Span::Span(const Span &other) : numbers(other.numbers), maxSize(other.maxSize) {}

Span& Span::operator=(const Span &other)
{
    if(this != &other)
    {
        this->numbers = other.numbers;
        this->maxSize = other.maxSize;
    }
    return *this;
}

Span::~Span() {}

void Span::addNunber(int num)
{
    if(numbers.size() >= maxSize)
        throw std::runtime_error("span is full");
    numbers.push_back(num);
}

unsigned int Span::shortestSpan() const
{
    if(numbers.size() < 2)
        throw std::runtime_error("cannot find span, need at least 2 numbers");
    unsigned int minSpan = UINT_MAX; // store larget value
    for(unsigned int i = 0; i < numbers.size(); i++)
    {
        for(unsigned int j = i + 1; j < numbers.size(); j++)
        {
            unsigned int currentSpan = std::abs(numbers[i] - numbers[j]);
            if(currentSpan < minSpan)
                minSpan = currentSpan; // always track the smallets span
        }
    }
    return minSpan;
}

unsigned int Span::longestSpan() const
{
    if(numbers.size() < 2)
        throw std::runtime_error("cannot find span, need at least 2 numbers");
    std::vector<int>::const_iterator maxIter = std::max_element(numbers.begin(), numbers.end());
    std::vector<int>::const_iterator minIter = std::min_element(numbers.begin(), numbers.end()); // check later what is const_iterator and what is this iterator

    int maxValue = *maxIter;
    int minValue = *minIter;
    return static_cast<unsigned int>(std::abs(maxValue - minValue));  
}
