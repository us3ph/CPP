#include "Animal.hpp"

AAnimal::AAnimal() : type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = other;
}

AAnimal& AAnimal::operator=(const AAnimal &other)
{
    if(this != &other)
        this->type = other.type;
    return *this;
}

AAnimal:: ~AAnimal()
{
    std::cout << "Animal destructor called" << std::endl;
}

const std::string& AAnimal::getType() const
{
    return this->type;
}