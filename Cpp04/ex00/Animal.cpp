#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal &other)
{
    std::cout << "Animal copy assigment operator called " << std::endl;
    if(this != &other)
        this->type = other.type;
    return *this;
}

Animal:: ~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

const std::string& Animal::getType() const
{
    return this->type;
}

void Animal::makeSound() const
{
    std::cout << "Generic animal sound" << std::endl;
}