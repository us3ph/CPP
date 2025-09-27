#include "Span.hpp"

Span::Span() {}
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
unsigned int Span::shortesSpan() const
{
    if(numbers.size() < 2)
        throw std::runtime_error("cannot find span, need at least 2 numbers");
    unsigned int minSpan = UINT_MAX;
    for(unsigned int i = 0; i < numbers.size(), i++)
        for(unsigned int j = i + 1; j < numbers.size(); j++)


}
unsigned int Span::longestSpan() const
{

}
