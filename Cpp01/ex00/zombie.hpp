#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
    std::string m_name;

public:
    Zombie(std::string name); // consructor
    ~Zombie();                // destructor
    
    void announce();
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);
#endif