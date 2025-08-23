#ifndef WRONGANIMAL
#define WRONGANIMAL

#include <iostream>

class WrongAnimal
{
protected:
    std::string type;
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &other);
    WrongAnimal& operator=(const WrongAnimal &other);
    ~WrongAnimal();
    const std::string& getType() const;
    void makeSound() const;
};

#endif