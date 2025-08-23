#include "Cat.hpp"


Cat::Cat()
{
    std::cout << "Cat default constructor called" << std::endl;
    this->type = "Cat";
    brain = new Brain(); // for deep copy
}

Cat::Cat(const Cat &other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
    brain = new Brain(*other.brain); // creat new brain for deep copy
}

Cat& Cat::operator=(const Cat &other)
{
    if(this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain); // new brain for deep copy
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete brain;
}


void Cat::makeSound() const
{
    std::cout << "Meow! Meow!" << std::endl;
}
