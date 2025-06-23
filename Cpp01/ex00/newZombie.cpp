#include "Zombie.hpp"

Zombie *newZombie(std::string name)  // method to allcate zombie (heap)
{
    return (new Zombie(name));
}