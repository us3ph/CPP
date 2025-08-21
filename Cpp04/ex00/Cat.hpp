#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
private:
    std::string type;
public:
    Cat();
    Cat(const Cat &other);
    Cat& operator=(const Cat &other);
    ~Cat();
    void setType(std::string name);
    void makeSound() const; // must be const to override base class
};


#endif