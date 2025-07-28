#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>

class ClapTrap
{
protected: //  allow child class to acess base class members

    std::string Name;
    int HitPoints;
    int EnergyPoints;
    int AttackDamage;

public:
    ClapTrap();
    ClapTrap(const std::string &Name);
    ClapTrap(const ClapTrap &other);
    ClapTrap& operator=(const ClapTrap &other);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};


#endif