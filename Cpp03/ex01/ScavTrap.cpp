#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default") //  constructor chaining Bcs scavTrap uses attributes from ClapTrap Show correct constructor chaining in the output
{
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;

    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) // When constructing a ScavTrap, you must initialize the ClapTrap part correctly, with the name
{
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;

    std::cout << "ScavTrap " << name << " created" << std::endl;
}