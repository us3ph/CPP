#include "zombie.hpp"

void randomChump(std::string name) // method to creat zombie in the stack
{
    Zombie zombie(name);
    zombie.announce();
}