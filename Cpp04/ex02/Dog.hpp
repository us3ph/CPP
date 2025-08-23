#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
private:
    std::string type;
    Brain *brain;
public:
    Dog();
    Dog(const Dog &other);
    Dog& operator=(const Dog &other);
    virtual ~Dog();
    void makeSound() const;
};

#endif