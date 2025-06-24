#include "Zombie.hpp"

Zombie:: Zombie() {}; // default constructor 

Zombie:: Zombie(std::string name) : m_name(name) {};  // constructer difintion m_name(name) {} init the name

Zombie:: ~Zombie() // destructor difinition
{
    std::cout << "Zombie " << m_name << " destroyed" << std::endl;
}

void Zombie:: setName(std::string name) // method to set name
{
    m_name = name;
}

void Zombie::announce() // method to annoncce the zombie
{
    std::cout << m_name <<":"<< " BraiiiiiiinnnzzzZ..." << std::endl;
}

