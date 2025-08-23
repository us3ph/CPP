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
    // *other.brain - dereferences the pointer to get the actual Brain object
    // Brain(*other.brain) - calls Brain's copy constructor with that object
    // new Brain(...) - creates a new Brain object on the heap
    // brain = ...    - assigns the new Brain pointer to our brain
}

Dog& Dog::operator=(const Dog &other)
{
    if(this != &other)
    {
        Animal::operator=(other); // call cp assigment of base class animal and copy type
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