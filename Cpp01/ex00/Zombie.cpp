#include "zombie.hpp"

Zombie:: Zombie(std::string name) : m_name(name) {};  // constructer difintion m_name(name) {} init the name

Zombie:: ~Zombie() // deconstructer difinition
{
    std::cout << "Zombie " << m_name << " destroyed" << std::endl;
}

void Zombie::announce() // method to annoncce the zombie
{
    std::cout << m_name <<":"<< " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie *newZombie(std::string name)  // method to allcate zombie (heap)
{
    return (new Zombie(name));
}