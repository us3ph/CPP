#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
// #include "Brain.hpp"

int main()
{
// const Animal* meta = new Animal();
// const Animal* j = new Dog();
// const Animal* i = new Cat();
// std::cout << j->getType() << " " << std::endl;
// std::cout << i->getType() << " " << std::endl;
// i->makeSound(); //will output the cat sound!
// j->makeSound();
// meta->makeSound();

// delete meta;
// delete j;
// delete i;
// return 0;

  const Animal *j = new Dog();
  const Animal *i = new Cat();

  delete j;
  delete i;

  Animal *animal[4];

  for(int i = 0; i < 2; i++)
      animal[i] = new Dog();
  for(int i = 2; i < 4 ;i++)
      animal[i] = new Cat();
  std:: cout << "this is the part of dogs" << std::endl;
  for(int i = 0; i < 2; i++)
    animal[i]->makeSound();
  std:: cout << "this is the part of cats" << std::endl;
  for(int i = 2; i < 4 ; i++)
    animal[i]->makeSound();
  for(int i = 0; i < 4; i++)
    delete animal[i];
  
}

