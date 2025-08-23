#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Wrong Animal") {}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type) {}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
    if(this != &other)
        this->type = other.type;
    return *this;
}

WrongAnimal::~WrongAnimal() {}

const std::string& WrongAnimal::getType() const
{
    return this->type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound" << std::endl;
}