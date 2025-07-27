#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>

class ClapTrap
{
private:

    std::string Name;
    int HitPoints;
    int EnergyPoints;
    int AttackDamage;

public:
    ClapTrap();
    ClapTrap(std::string Name); 
    ClapTrap(const ClapTrap &other);
    ClapTrap& operator=(const ClapTrap &other);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};


#endif