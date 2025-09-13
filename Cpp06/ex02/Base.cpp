#include "Base.hpp"

Base::~Base() {}

Base * generate(void)
{
    int random = rand() % 3;
    if(random ==  0)
        return new A;
    else if(random == 1)
        return new B;
    else
        return new C;
}
void identify(Base* p)
{
    if(dynamic_cast<A*>(p)) // return valid pointer if object is type A otherwise return nullptr 
        std::cout << "A" << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if(dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}
void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p); // succeeds if object is type A otherwise throw exeption std::bad_cast
        std::cout << "A" << std::endl;
        return;
    }
    catch(...) {} // Catch all exceptions don't print anything silent do nothing 

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch(...) {}
    
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch(...) {}  
}

// std::bad_cast is an exception type thrown when a dynamic_cast to a reference type fails at runtime. This typically occurs when attempting to cast a base class reference to a derived class reference