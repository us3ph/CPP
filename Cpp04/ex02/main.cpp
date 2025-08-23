#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
// #include "Brain.hpp"

int main()
{
// const AAnimal* meta = new AAnimal();  this not work anymore pure virtual base class cant creat instance from it
const AAnimal* j = new Dog();
const AAnimal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound();
j->makeSound();

delete j;
delete i;
return 0;

}

