#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
    std::string type;
public:
    Animal();
    Animal(const Animal &other);
    Animal& operator=(const Animal &other);
    virtual  ~Animal(); // delete derived objects through a base class pointer
    const std::string& getType() const;
    virtual void makeSound() const;
};

#endif