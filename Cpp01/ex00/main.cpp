#include "Zombie.hpp"

int main()
{
    randomChump("Foo");  // zombie created in stack
    Zombie *Zombie;
    Zombie = newZombie("FOO"); // zombie in heap
    delete Zombie;          
}