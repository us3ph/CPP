#include "Brain.hpp"

  Brain::Brain()
  {
    std::cout << "Brain default constructor called" << std::endl;
  }

  Brain::Brain(const Brain &other)
  {
    std::cout << "Brain copy construcotr called" << std::endl;
    for(int i = 0; i < 100; i++)
      ideas[i] = other.ideas[i];
  }

  Brain& Brain::operator=(const Brain &other)
  {
    if(this != &other)
    {
      for(int i= 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
    }
    return *this;
  }

  Brain::~Brain()
  {
    std::cout << "Brain Destructor called" << std::endl;
  }