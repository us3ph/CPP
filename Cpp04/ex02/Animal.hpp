#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class AAnimal //  pure virtual class
{
protected:
    std::string type;
public:
    AAnimal();
    AAnimal(const AAnimal &other);
    AAnimal& operator=(const AAnimal &other);
    virtual  ~AAnimal();
    const std::string& getType() const;
    virtual void makeSound() const = 0; // pure virtual function

};

#endif