#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
    brain = new Brain();
}

Dog::Dog(const Dog &other)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    *this = other;
    brain = new Brain(*other.brain); // creat new brain  (deep copy)
}

Dog& Dog::operator=(const Dog &other)
{
    if(this != &other)
    {
        AAnimal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

void Dog::makeSound() const
{
    std::cout << "Woof! Woof!" << std::endl;
}