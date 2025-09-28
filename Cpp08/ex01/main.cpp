#include "Span.hpp"

int main()
{
    std::cout << "test basic case\n";
    try
    {
        Span span(5);
        span.addNunber(6);
        span.addNunber(3);
        span.addNunber(17);
        span.addNunber(9);
        span.addNunber(11);
        std::cout << "added number : 6,3,17,9,11\n";
        std::cout << "shortest span : " << span.shortestSpan() << std::endl;
        std::cout << "longest span : " << span.longestSpan() << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "test capacity\n";
    try
    {
        Span span(3);
        span.addNunber(5);
        span.addNunber(9);
        span.addNunber(2);
        span.addNunber(6);
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "test empty\n";
    try
    {
        Span empty(10);
        empty.longestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "test only one number\n";
    try
    {
        Span one(10);
        one.addNunber(13);
        one.shortestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "test edge cases\n";
    try
    {
        Span edge(4);
        edge.addNunber(5);
        edge.addNunber(5);
        edge.addNunber(-10);
        edge.addNunber(100);
        std::cout << "shortest span : " << edge.shortestSpan() << std::endl;
        std::cout << "longest span : " << edge.longestSpan() << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    
    

}